/*
 * Copyright (C) 2007, 2008, 2013, 2015 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Apple Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef Database_h
#define Database_h

#include "DatabaseBasicTypes.h"
#include "DatabaseError.h"
#include "SQLiteDatabase.h"
#include <wtf/Deque.h>
#include <wtf/Lock.h>
#include <wtf/text/WTFString.h>

namespace WebCore {

class ChangeVersionData;
class DatabaseCallback;
class DatabaseDetails;
class DatabaseContext;
class ScriptExecutionContext;
class SecurityOrigin;
class SQLTransaction;
class SQLTransactionBackend;
class SQLTransactionCallback;
class SQLTransactionClient;
class SQLTransactionCoordinator;
class SQLTransactionErrorCallback;
class VoidCallback;

class Database final : public ThreadSafeRefCounted<Database> {
public:
    virtual ~Database();

    virtual bool openAndVerifyVersion(bool setVersionInNewDatabase, DatabaseError&, String& errorMessage);
    void close();

    bool opened() const { return m_opened; }
    bool isNew() const { return m_new; }

    unsigned long long maximumSize() const;

    PassRefPtr<SQLTransactionBackend> runTransaction(PassRefPtr<SQLTransaction>, bool readOnly, const ChangeVersionData*);
    void scheduleTransactionStep(SQLTransactionBackend*);
    void inProgressTransactionCompleted();

    bool hasPendingTransaction();

    bool hasPendingCreationEvent() const { return m_hasPendingCreationEvent; }
    void setHasPendingCreationEvent(bool value) { m_hasPendingCreationEvent = value; }

    SQLTransactionClient* transactionClient() const;
    SQLTransactionCoordinator* transactionCoordinator() const;

    // Direct support for the DOM API
    String version() const;
    void changeVersion(const String& oldVersion, const String& newVersion, PassRefPtr<SQLTransactionCallback>,
                       PassRefPtr<SQLTransactionErrorCallback>, PassRefPtr<VoidCallback> successCallback);
    void transaction(PassRefPtr<SQLTransactionCallback>, PassRefPtr<SQLTransactionErrorCallback>, PassRefPtr<VoidCallback> successCallback);
    void readTransaction(PassRefPtr<SQLTransactionCallback>, PassRefPtr<SQLTransactionErrorCallback>, PassRefPtr<VoidCallback> successCallback);

    // Internal engine support
    String stringIdentifier() const;
    String displayName() const;
    unsigned long estimatedSize() const;
    String fileName() const;
    DatabaseDetails details() const;
    SQLiteDatabase& sqliteDatabase() { return m_sqliteDatabase; }

    void disableAuthorizer();
    void enableAuthorizer();
    void setAuthorizerPermissions(int);
    bool lastActionChangedDatabase();
    bool lastActionWasInsert();
    void resetDeletes();
    bool hadDeletes();
    void resetAuthorizer();

    DatabaseContext* databaseContext() const { return m_databaseContext.get(); }

    ScriptExecutionContext* scriptExecutionContext() { return m_scriptExecutionContext.get(); }
    void logErrorMessage(const String& message);

    Vector<String> tableNames();

    virtual SecurityOrigin* securityOrigin() const;

    virtual void markAsDeletedAndClose();
    bool deleted() const { return m_deleted; }

    void scheduleTransactionCallback(SQLTransaction*);

    bool performOpenAndVerify(bool shouldSetVersionInNewDatabase, DatabaseError&, String& errorMessage);
    Vector<String> performGetTableNames();

    void incrementalVacuumIfNeeded();

private:
    Database(PassRefPtr<DatabaseContext>, const String& name, const String& expectedVersion, const String& displayName, unsigned long estimatedSize);

    void closeDatabase();

    bool getVersionFromDatabase(String& version, bool shouldCacheVersion = true);
    bool setVersionInDatabase(const String& version, bool shouldCacheVersion = true);
    void setExpectedVersion(const String&);
    const String& expectedVersion() const { return m_expectedVersion; }
    String getCachedVersion()const;
    void setCachedVersion(const String&);
    bool getActualVersionForTransaction(String& version);

    void scheduleTransaction();

    void runTransaction(RefPtr<SQLTransactionCallback>&&, RefPtr<SQLTransactionErrorCallback>&&, RefPtr<VoidCallback>&& successCallback, bool readOnly, const ChangeVersionData* = nullptr);

#if !LOG_DISABLED || !ERROR_DISABLED
    String databaseDebugName() const;
#endif

    RefPtr<ScriptExecutionContext> m_scriptExecutionContext;
    RefPtr<SecurityOrigin> m_contextThreadSecurityOrigin;
    RefPtr<SecurityOrigin> m_databaseThreadSecurityOrigin;
    RefPtr<DatabaseContext> m_databaseContext;

    bool m_deleted;
    bool m_hasPendingCreationEvent { false };

    String m_name;
    String m_expectedVersion;
    String m_displayName;
    unsigned long m_estimatedSize;
    String m_filename;

    DatabaseGuid m_guid;
    bool m_opened;
    bool m_new;

    SQLiteDatabase m_sqliteDatabase;

    RefPtr<DatabaseAuthorizer> m_databaseAuthorizer;

    Deque<RefPtr<SQLTransactionBackend>> m_transactionQueue;
    Lock m_transactionInProgressMutex;
    bool m_transactionInProgress;
    bool m_isTransactionQueueEnabled;

    friend class ChangeVersionWrapper;
    friend class DatabaseManager;
    friend class DatabaseServer; // FIXME: remove this when the backend has been split out.
    friend class SQLTransaction;
    friend class SQLTransactionBackend;
};

} // namespace WebCore

#endif // Database_h
