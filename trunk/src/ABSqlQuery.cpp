
#include <cassert>

#include <QMap>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

#include "ABSqlQuery.h"
#include "ABFunction.h"

bool createConnection(QString strDbName, QString strPwd)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(strDbName);
    if (!strPwd.isEmpty()) {
        db.setPassword(strPwd);
    }
    if (!db.open()) {
        QMessageBox::critical(0, QObject::tr("Database Error"),
                              db.lastError().text());
        return false;
    }

    initDatabase(db);
    return true;
}

void initDatabase(QSqlDatabase& db)
{
    QStringList slTables = db.tables();

    /// 3个默认Table
    /// TableNameAccount
    /// TableNameCategory
    /// TableNameTransaction

    /// Account中默认条目
    /// "'Cash', 1988, 1, 1, 0, 0, 0, 'xxxxxxxx(InsertTime)'"
    if (slTables.contains(TableNameAccount) == false) {
        createAccountTable();
    }
    insertItemInAccount(g_Cash, 1988, 1, 1, 0, 0, getInsertTime());

    /// Category中默认条目
    /// "'Income', 'Default', 'Default', 'xxxxxxxx(InsertTime)'"
    /// "'Expense', 'Default', 'Default', 'xxxxxxxx(InsertTime)'"
    if (slTables.contains(TableNameCategory) == false) {
        createCategoryTable();
    }
    insertItemInCategory(g_Income, g_Default, g_Default, getInsertTime());
    insertItemInCategory(g_Expense, g_Default, g_Default, getInsertTime());

    /// Transaction中没有默认条目
    if (slTables.contains(TableNameTransaction) == false) {
        createTransactionTable();
    }
}

void createAccountTable()
{
    QSqlQuery q1;
    QString s1;
    s1.append("CREATE TABLE ");
    s1.append(TableNameAccount);
    s1.append(" (");
    s1.append("Name         char(100), ");
    s1.append("CreateYear   int, ");
    s1.append("CreateMonth  int, ");
    s1.append("CreateDay    int, ");
    s1.append("CreateHour   int, ");
    s1.append("CreateMinute int, ");
    s1.append("Surplus      float, ");
    s1.append("InsertTime   char(100)");
    s1.append(")");
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
}

void createCategoryTable()
{
    QSqlQuery q1;
    QString s1;
    s1.append("CREATE TABLE ");
    s1.append(TableNameCategory);
    s1.append(" (");
    s1.append("BigType      char(100), ");
    s1.append("MidType      char(100), ");
    s1.append("SmallType    char(100), ");
    s1.append("InsertTime   char(100)");
    s1.append(")");
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
}

void createTransactionTable()
{
    QSqlQuery q1;
    QString s1;
    s1.append("CREATE TABLE ");
    s1.append(TableNameTransaction);
    s1.append(" (");
    s1.append("Type             char(100), ");
    s1.append("CategoryMid      char(100), ");
    s1.append("CategorySmall    char(100), ");
    s1.append("Year             int, ");
    s1.append("Month            int, ");
    s1.append("Day              int, ");
    s1.append("Hour             int, ");
    s1.append("Minute           int, ");
    s1.append("Sum              float, ");
    s1.append("FromAccount      char(100), ");
    s1.append("ToAccount        char(100), ");
    s1.append("Detail           char(100), ");
    s1.append("InsertTime       char(100)");
    s1.append(")");
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
}

void insertItemInAccount(QString Name,
                         int CreateYear, int CreateMonth, int CreateDay, int CreateHour, int CreateMinute,
                         /*float Surplus, */QString InsertTime)
{
    if (Name == g_Income || Name == g_Expense) {
        warnMsgParameterInvalid();
        return;
    }

    if (!accountExists(Name)) {
        float Surplus = 0.0;
        if (InsertTime.isEmpty()) {
            InsertTime = getInsertTime();
        }

        singleInsertItemInAccount(Name, CreateYear, CreateMonth, CreateDay, CreateHour, CreateMinute, Surplus, InsertTime);
    }
}

void insertItemInCategory(QString BigType, QString MidType, QString SmallType, QString InsertTime)
{
    if (invalidBigType(BigType)) {
        warnMsgParameterInvalid();
        return;
    }
    if (MidType.isEmpty()){
        MidType = g_Default;
    }
    if (SmallType.isEmpty()) {
        SmallType = g_Default;
    }

    if (MidType == g_Default) {
        if (SmallType != g_Default) {
            warnMsgDisallowedOperation();
            return;
        }
    }

    if (InsertTime.isEmpty()) {
        InsertTime = getInsertTime();
    }

    if (!categoryExists(BigType, MidType)) {
        singleInsertItemInCategory(BigType, MidType, g_Default, InsertTime);
    }
    if (!categoryExists(BigType, MidType, SmallType)) {
        singleInsertItemInCategory(BigType, MidType, SmallType, InsertTime);
    }
}

void insertItemInTransaction(QString Type, QString CategoryMid, QString CategorySmall,
                             int Year, int Month, int Day, int Hour, int Minute,
                             float Sum,
                             QString FromAccount, QString ToAccount,
                             QString Detail,
                             QString InsertTime)
{
    if (Type == g_Income) {
        FromAccount = g_Income;
    } else if (Type == g_Expense) {
        ToAccount = g_Expense;
    } else if (Type == g_Liquidity) {
        CategoryMid = g_Default;
        CategorySmall = g_Default;
    } else {
        assert(0);
    }

    if (InsertTime.isEmpty()) {
        InsertTime = getInsertTime();
    }

    if (FromAccount != g_Income) {
        if (!accountExists(FromAccount)) {
            insertItemInAccount(FromAccount, Year, Month, Day, Hour, Minute, InsertTime);
        }
    }
    if (ToAccount != g_Expense) {
        if (!accountExists(ToAccount)) {
            insertItemInAccount(ToAccount, Year, Month, Day, Hour, Minute, InsertTime);
        }
    }
    if (Type == g_Income || Type == g_Expense) {
        if (!categoryExists(Type, CategoryMid, CategorySmall)) {
            insertItemInCategory(Type, CategoryMid, CategorySmall, InsertTime);
        }
    }

    singleInsertItemInTransaction(Type, CategoryMid, CategorySmall, Year, Month, Day, Hour, Minute, Sum, FromAccount, ToAccount, Detail, InsertTime);

    if (FromAccount != g_Income) {
        updateSurplusOfAccount(FromAccount, -Sum);
    }
    if (ToAccount != g_Expense) {
        updateSurplusOfAccount(ToAccount, Sum);
    }
}

void deleteItemInAccount(QString Name)
{
    /// 取出Name帐户的余额，检查是否为0
    QSqlQuery q1;
    QString s1;
    s1.append("SELECT Surplus FROM ");
    s1.append(TableNameAccount);
    s1.append(" WHERE Name = '");
    s1.append(Name);
    s1.append("'");
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
    while (q1.next()) {
        float surplusOfName = q1.value(0).toDouble();
        if (surplusOfName != 0) {
            warnMsgDisallowedOperation();
            return;
        }
    }

    /// 检查所有Transaction中是否有与Name帐户相关的
    QSqlQuery q2;
    QString s2;
    s2.append("SELECT * FROM ");
    s2.append(TableNameTransaction);
    s2.append(" FromAccount = '");
    s2.append(Name);
    s2.append("' OR ToAccount = '");
    s2.append(Name);
    s2.append("'");
    if (!q2.exec(s2)) warnMsgDatabaseOperationFailed();
    while (q2.next()) {
        warnMsgDisallowedOperation();
        return;
    }

    /// 符合删除条件，删除Name帐户
    QSqlQuery q3;
    QString s3;
    s3.append("DELETE FROM ");
    s3.append(TableNameAccount);
    s3.append(" WHERE Name = '");
    s3.append(Name);
    s3.append("'");
    if (!q3.exec(s3)) warnMsgDatabaseOperationFailed();
}

void deleteItemInCategory(QString BigType,
                          QString MidType,
                          QString SmallType)
{
    if (invalidBigType(BigType)) {
        warnMsgParameterInvalid();
        return;
    }

    if (SmallType.isEmpty()) {
        SmallType = g_Default;
    }

    if (MidType == g_Default) {
        if (SmallType == g_Default) {
            warnMsgDisallowedOperation();
        } else {
            warnMsgParameterInvalid();
        }
        return;
    }

    if (SmallType == g_Default) {
        QSqlQuery q1;
        QString s1;
        s1.append("UPDATE ");
        s1.append(TableNameTransaction);
        s1.append(" SET CategoryMid = '");
        s1.append(g_Default);
        s1.append("' AND CategorySmall = '");
        s1.append(g_Default);
        s1.append("' WHERE Type = '");
        s1.append(BigType);
        s1.append("' AND CategoryMid = '");
        s1.append(MidType);
        s1.append("'");
        if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
    } else {
        QSqlQuery q1;
        QString s1;
        s1.append("UPDATE ");
        s1.append(TableNameTransaction);
        s1.append(" SET CategorySmall = '");
        s1.append(g_Default);
        s1.append("' WHERE Type = '");
        s1.append(BigType);
        s1.append("' AND CategoryMid = '");
        s1.append(MidType);
        s1.append("' AND CategorySmall = '");
        s1.append(SmallType);
        s1.append("'");
        if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
    }

    singleDeleteItemInCategory(BigType, MidType, SmallType);
}

void deleteItemInTransaction(QString Type,
                             QString CategoryMid,
                             QString CategorySmall,
                             int Year,
                             int Month,
                             int Day,
                             int Hour,
                             int Minute,
                             float Sum,
                             QString FromAccount,
                             QString ToAccount,
                             QString Detail,
                             QString InsertTime)
{
    if (Type == g_Income) {
        FromAccount = g_Income;
    } else if (Type == g_Expense) {
        ToAccount == g_Expense;
    }

    QSqlQuery q6;
    QString s6;
    s6.append("SELECT * FROM ");
    s6.append(TableNameTransaction);
    s6.append(" WHERE Type = '");
    s6.append(Type);
    s6.append("' AND CategoryMid = '");
    s6.append(CategoryMid);
    s6.append("' AND CategorySmall = '");
    s6.append(CategorySmall);
    s6.append("' AND Year = ");
    s6.append(QString::number(Year));
    s6.append(" AND Month = ");
    s6.append(QString::number(Month));
    s6.append(" AND Day = ");
    s6.append(QString::number(Day));
    s6.append(" AND Hour = ");
    s6.append(QString::number(Hour));
    s6.append(" AND Minute = ");
    s6.append(QString::number(Minute));
    s6.append(" AND Sum = ");
    s6.append(QString::number(Sum));
    if (!FromAccount.isEmpty()) {
        s6.append(" AND FromAccount = '");
        s6.append(FromAccount);
        s6.append("'");
    }
    if (!ToAccount.isEmpty()) {
        s6.append(" AND ToAccount = '");
        s6.append(ToAccount);
        s6.append("'");
    }
    if (!Detail.isEmpty()) {
        s6.append(" AND Detail = '");
        s6.append(Detail);
        s6.append("'");
    }
    if (!InsertTime.isEmpty()) {
        s6.append(" AND InsertTime = '");
        s6.append(InsertTime);
        s6.append("'");
    }
    if (!q6.exec(s6)) warnMsgDatabaseOperationFailed();
    int nFoundCount = 0;
    while (q6.next()) {
        nFoundCount++;
    }
    if (nFoundCount == 0) {
        warnMsgItemNotExists();
        return;
    } else if (nFoundCount == 1) {
        /// do nothing
    } else if (nFoundCount > 1) {
        assert(0);
    }

    if (Type == g_Income) {
        updateSurplusOfAccount(ToAccount, -Sum);
    } else if (Type == g_Expense) {
        updateSurplusOfAccount(FromAccount, Sum);
    } else if (Type == g_Liquidity) {
        updateSurplusOfAccount(ToAccount, -Sum);
        updateSurplusOfAccount(FromAccount, Sum);
    } else {
        assert(0);
    }

    QSqlQuery q5;
    QString s5;
    s5.append("DELETE FROM ");
    s5.append(TableNameTransaction);
    s5.append(" WHERE Type = '");
    s5.append(Type);
    s5.append("' AND CategoryMid = '");
    s5.append(CategoryMid);
    s5.append("' AND CategorySmall = '");
    s5.append(CategorySmall);
    s5.append("' AND Year = ");
    s5.append(QString::number(Year));
    s5.append(" AND Month = ");
    s5.append(QString::number(Month));
    s5.append(" AND Day = ");
    s5.append(QString::number(Day));
    s5.append(" AND Hour = ");
    s5.append(QString::number(Hour));
    s5.append(" AND Minute = ");
    s5.append(QString::number(Minute));
    s5.append(" AND Sum = ");
    s5.append(QString::number(Sum));
    if (!FromAccount.isEmpty()) {
        s5.append(" AND FromAccount = '");
        s5.append(FromAccount);
        s5.append("'");
    }
    if (!ToAccount.isEmpty()) {
        s5.append(" AND ToAccount = '");
        s5.append(ToAccount);
        s5.append("'");
    }
    if (!Detail.isEmpty()) {
        s5.append(" AND Detail = '");
        s5.append(Detail);
        s5.append("'");
    }
    if (!InsertTime.isEmpty()) {
        s5.append(" AND InsertTime = '");
        s5.append(InsertTime);
        s5.append("'");
    }

    if (!q5.exec(s5)) warnMsgDatabaseOperationFailed();
}

void renameAccount(QString oriName, QString newName)
{
    if (oriName == g_Cash ||
        oriName.isEmpty() ||
        newName.isEmpty() ||
        oriName == newName) {
        warnMsgParameterInvalid();
        return;
    }

    /// 检查是否与已有的Account重名
    if (accountExists(newName)) {
        warnMsgItemAlreadyExists();
        return;
    }

    /// 更新Table Account
    QSqlQuery q2;
    QString s2;
    s2.append("UPDATE ");
    s2.append(TableNameAccount);
    s2.append(" SET Name = '");
    s2.append(newName);
    s2.append("' WHERE Name = '");
    s2.append(oriName);
    s2.append("'");
    if (!q2.exec(s2)) warnMsgDatabaseOperationFailed();

    /// 更新Table Transaction
    QSqlQuery q3;
    QString s3;
    s3.append("UPDATE ");
    s3.append(TableNameTransaction);
    s3.append(" SET FromAccount = '");
    s3.append(newName);
    s3.append("' WHERE FromAccount = '");
    s3.append(oriName);
    s3.append("'");
    if (!q3.exec(s3)) warnMsgDatabaseOperationFailed();

    QSqlQuery q4;
    QString s4;
    s4.append("UPDATE ");
    s4.append(TableNameTransaction);
    s4.append(" SET ToAccount = '");
    s4.append(newName);
    s4.append("' WHERE ToAccount = '");
    s4.append(oriName);
    s4.append("'");
    if (!q4.exec(s4)) warnMsgDatabaseOperationFailed();
}

void updateSurplusOfAccount(QString accountName, float sumChange)
{
    if (accountName == g_Income || accountName == g_Expense || sumChange == 0.0) {
        warnMsgParameterInvalid();
        return;
    }

    float oriSurplus = 0.0;

    if (!accountExists(accountName)) {
        warnMsgParameterInvalid();
        return;
    }

    QSqlQuery q1;
    QString s1;
    s1.append("SELECT Surplus FROM ");
    s1.append(TableNameAccount);
    s1.append(" WHERE Name = '");
    s1.append(accountName);
    s1.append("'");
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
    while (q1.next()) {
        oriSurplus = q1.value(0).toDouble();
    }

    QSqlQuery q2;
    QString s2;
    s2.append("UPDATE ");
    s2.append(TableNameAccount);
    s2.append(" SET Surplus = ");
    s2.append(QString::number(oriSurplus + sumChange));
    s2.append(" WHERE Name = '");
    s2.append(accountName);
    s2.append("'");
    if (!q2.exec(s2)) warnMsgDatabaseOperationFailed();
}

void renameCategory(ABCategory oriCtg, ABCategory newCtg)
{
    if (oriCtg.bigType != newCtg.bigType) {
        /// BigType不能变
        warnMsgParameterInvalid();
        return;
    }

    renameCategory(oriCtg.bigType,
                   oriCtg.midType, oriCtg.smallType,
                   newCtg.midType, newCtg.smallType);
}

void renameCategory(QString bigType,
                    QString oriMidType, QString oriSmallType,
                    QString newMidType, QString newSmallType)
{
    if (invalidBigType(bigType)) {
        warnMsgParameterInvalid();
        return;
    }
    if (oriMidType == g_Default || newMidType == g_Default) {
        /// 不能把"xxx -> Default -> Default"变成其他的
        /// 也不能把category变成"xxx -> Default -> Default"，因为这相当于删除操作，因此不允许
        warnMsgParameterInvalid();
        return;
    }

    if (oriSmallType.isEmpty()) {
        oriSmallType = g_Default;
    }
    if (newSmallType.isEmpty()) {
        newSmallType = g_Default;
    }

    if (oriSmallType == g_Default) {
        if (newSmallType == g_Default) {
            if (categoryExists(bigType, newMidType, newSmallType)) {
                warnMsgDisallowedOperation();
            } else {
                QSqlQuery q1;
                QString s1;
                s1.append("UPDATE ");
                s1.append(TableNameTransaction);
                s1.append(" SET CategoryMid = '");
                s1.append(newMidType);
                s1.append("' WHERE CategoryMid = '");
                s1.append(oriMidType);
                s1.append("'");
                if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();

                QSqlQuery q2;
                QString s2;
                s2.append("UPDATE ");
                s2.append(TableNameCategory);
                s2.append(" SET MidType = '");
                s2.append(newMidType);
                s2.append("' WHERE MidType = '");
                s2.append(oriMidType);
                s2.append("'");
                if (!q2.exec(s2)) warnMsgDatabaseOperationFailed();
            }
        } else {
            if (!categoryExists(bigType, newMidType, newSmallType)) {
                if (!categoryExists(bigType, newMidType)) {
                    insertItemInCategory(bigType, newMidType);
                }
                insertItemInCategory(bigType, newMidType, newSmallType);
            }

            QSqlQuery q1;
            QString s1;
            s1.append("UPDATE ");
            s1.append(TableNameTransaction);
            s1.append(" SET CategoryMid = '");
            s1.append(newMidType);
            s1.append("' AND CategorySmall = '");
            s1.append(newSmallType);
            s1.append("' WHERE CategoryMid = '");
            s1.append(oriMidType);
            s1.append("'");
            if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();

            deleteItemInCategory(bigType, oriMidType);
        }
    } else {
        if (newSmallType == g_Default) {
            if (!categoryExists(bigType, newMidType)) {
                insertItemInCategory(bigType, newMidType);
            }

            QSqlQuery q1;
            QString s1;
            s1.append("UPDATE ");
            s1.append(TableNameTransaction);
            s1.append(" SET CategoryMid = '");
            s1.append(newMidType);
            s1.append("' AND CategorySmall = '");
            s1.append(newSmallType);
            s1.append("' WHERE CategoryMid = '");
            s1.append(oriMidType);
            s1.append("' AND CategorySmall = '");
            s1.append(oriSmallType);
            s1.append("'");
            if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();

            deleteItemInCategory(bigType, oriMidType, oriSmallType);
        } else {
            if (!categoryExists(bigType, newMidType, newSmallType)) {
                if (!categoryExists(bigType, newMidType)) {
                    insertItemInCategory(bigType, newMidType);
                }
                insertItemInCategory(bigType, newMidType, newSmallType);
            }

            QSqlQuery q1;
            QString s1;
            s1.append("UPDATE ");
            s1.append(TableNameTransaction);
            s1.append(" SET CategoryMid = '");
            s1.append(newMidType);
            s1.append("' AND CategorySmall = '");
            s1.append(newSmallType);
            s1.append("' WHERE CategoryMid = '");
            s1.append(oriMidType);
            s1.append("' AND CategorySmall = '");
            s1.append(oriSmallType);
            s1.append("'");
            if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();

            deleteItemInCategory(bigType, oriMidType, oriSmallType);
        }
    }
}

void updateTransaction(TransactionItem oriItem, TransactionItem newItem)
{
    deleteItemInTransaction(oriItem.Type,
                            oriItem.CategoryMid,
                            oriItem.CategorySmall,
                            oriItem.Year,
                            oriItem.Month,
                            oriItem.Day,
                            oriItem.Hour,
                            oriItem.Minute,
                            oriItem.Sum,
                            oriItem.FromAccount,
                            oriItem.ToAccount,
                            oriItem.Detail,
                            oriItem.InsertTime);

    insertItemInTransaction(newItem.Type,
                            newItem.CategoryMid,
                            newItem.CategorySmall,
                            newItem.Year,
                            newItem.Month,
                            newItem.Day,
                            newItem.Hour,
                            newItem.Minute,
                            newItem.Sum,
                            newItem.FromAccount,
                            newItem.ToAccount,
                            newItem.Detail,
                            newItem.InsertTime);
}

QStringList accountList()
{
    QStringList names;

    QSqlQuery q1;
    QString s1;
    s1 = QString("SELECT Name FROM ") + TableNameAccount + QString(" ORDER BY Name");
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
    while (q1.next()) {
        names.append(q1.value(0).toString());
    }

    return names;
}

QStringList surplus0AccountList()
{
    QStringList names;

    QSqlQuery q1;
    QString s1;
    s1 = QString("SELECT Name FROM ") + TableNameAccount + QString(" WHERE Surplus = 0 ORDER BY Name");
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
    while (q1.next()) {
        names.append(q1.value(0).toString());
    }

    return names;
}

QVector<ABCategory> categoryList(QString bigType)
{
    QVector<ABCategory> vec;

    if (!bigType.isEmpty() && invalidBigType(bigType)) {
        warnMsgParameterInvalid();
        return vec;
    }

    QSqlQuery queryIncome, queryExpense;
    QString strQueryIncome, strQueryExpense;
    strQueryIncome = QString("SELECT * FROM ")
                     + TableNameCategory
                     + QString(" WHERE BigType = '")
                     + g_Income
                     + QString("' ORDER BY MidType, SmallType");
    strQueryExpense = QString("SELECT * FROM ")
                      + TableNameCategory
                      + QString(" WHERE BigType = '")
                      + g_Expense
                      + QString("' ORDER BY MidType, SmallType");
    if (bigType.isEmpty() || bigType == g_Income) {
        if (!queryIncome.exec(strQueryIncome)) warnMsgDatabaseOperationFailed();
        while (queryIncome.next()) {
            ABCategory ctg;
            ctg.bigType = queryIncome.value(0).toString();
            ctg.midType = queryIncome.value(1).toString();
            ctg.smallType = queryIncome.value(2).toString();
            vec.append(ctg);
        }
    }
    if (bigType.isEmpty() || bigType == g_Expense) {
        if (!queryExpense.exec(strQueryExpense)) warnMsgDatabaseOperationFailed();
        while (queryExpense.next()) {
            ABCategory ctg;
            ctg.bigType = queryExpense.value(0).toString();
            ctg.midType = queryExpense.value(1).toString();
            ctg.smallType = queryExpense.value(2).toString();
            vec.append(ctg);
        }
    }

    return vec;
}

QStringList midTypeList(QString bigType)
{
    QStringList sl;
    if (invalidBigType(bigType)) {
        warnMsgParameterInvalid();
        return sl;
    }

    QSqlQuery q1;
    QString s1;
    s1 = QString("SELECT DISTINCT MidType FROM ")
         + TableNameCategory
         + QString(" WHERE BigType = '")
         + bigType
         + QString("' ORDER BY MidType");
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
    while (q1.next()) {
        sl.append(q1.value(0).toString());
    }

    return sl;
}

QStringList smallTypeList(QString bigType, QString midType)
{
    QStringList sl;
    if (invalidBigType(bigType)) {
        warnMsgParameterInvalid();
        return sl;
    }

    QSqlQuery q1;
    QString s1;
    s1 = QString("SELECT DISTINCT SmallType FROM ")
         + TableNameCategory
         + QString(" WHERE BigType = '")
         + bigType
         + QString("' AND MidType = '")
         + midType
         + QString("' ORDER BY SmallType");
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
    while (q1.next()) {
        sl.append(q1.value(0).toString());
    }

    return sl;
}

QStringList transactionList(int beginYear, int beginMonth, int beginDay, int beginHour, int beginMinute,
                            int endYear, int endMonth, int endDay, int endHour, int endMinute)
{
    QStringList sl;

    QSqlQuery q1;
    QString s1;
    s1 = QString("SELECT * FROM ")
            + TableNameTransaction

            + QString(" WHERE Year >= ")
            + QString::number(beginYear)
            + QString(" AND Year <= ")
            + QString::number(endYear)

            + QString(" AND Month >= ")
            + QString::number(beginMonth)
            + QString(" AND Month <= ")
            + QString::number(endMonth)

            + QString(" AND Day >= ")
            + QString::number(beginDay)
            + QString(" AND Day <= ")
            + QString::number(endDay)

            + QString(" AND Hour >= ")
            + QString::number(beginHour)
            + QString(" AND Hour <= ")
            + QString::number(endHour)

            + QString(" AND Minute >= ")
            + QString::number(beginMinute)
            + QString(" AND Minute <= ")
            + QString::number(endMinute)

            + QString(" ORDER BY Year, Month, Day, Hour, Minute");
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
    int bigMax = 0;
    int midMax = 0;
    int smallMax = 0;
    int sumMax = 0;
    int fromMax = 0;
    int toMax = 0;
    int detailMax = 0;
    QStringList slBig, slMid, slSmall, slDt, slSum, slFrom, slTo, slDetail;

    while (q1.next()) {
        QString bigType = q1.value(0).toString();
        QString midType = q1.value(1).toString();
        QString smallType = q1.value(2).toString();
        int year = q1.value(3).toInt();
        int month = q1.value(4).toInt();
        int day = q1.value(5).toInt();
        int hour = q1.value(6).toInt();
        int minute = q1.value(7).toInt();
        float sum = q1.value(8).toDouble();
        QString fromAccount = q1.value(9).toString();
        QString toAccount = q1.value(10).toString();
        QString detail = q1.value(11).toString();

        QString dt = YMDHM2yyyymmddhhmm(year, month, day, hour, minute);
        QString sSum = getMoneyFormNumber(sum);

        if (bigMax < bigType.count())
            bigMax = bigType.count();
        if (midMax < midType.count())
            midMax = midType.count();
        if (smallMax < smallType.count())
            smallMax = smallType.count();
        if (sumMax < sSum.count())
            sumMax = sSum.count();
        if (fromMax < fromAccount.count())
            fromMax = fromAccount.count();
        if (toMax < toAccount.count())
            toMax = toAccount.count();
        if (detailMax < detail.count())
            detailMax = detail.count();

        slBig.append(bigType);
        slMid.append(midType);
        slSmall.append(smallType);
        slDt.append(dt);
        slSum.append(sSum);
        slFrom.append(fromAccount);
        slTo.append(toAccount);
        slDetail.append(detail);
    }

    for (int i = 0; i < slBig.count(); i++) {
        QString type;
        type.append(slBig.at(i));
        if (slBig.at(i).count() < bigMax) {
            int j = bigMax - slBig.at(i).count();
            for (int k = 0; k < j; k++) {
                type.append(" ");
            }
        }
        type.append(CategorySeparator);
        type.append(slMid.at(i));
        if (slMid.at(i).count() < midMax) {
            int j = midMax - slMid.at(i).count();
            for (int k = 0; k < j; k++) {
                type.append(" ");
            }
        }
        type.append(CategorySeparator);
        type.append(slSmall.at(i));
        if (slSmall.at(i).count() < smallMax) {
            int j = smallMax - slSmall.at(i).count();
            for (int k = 0; k < j; k++) {
                type.append(" ");
            }
        }

        QString fromTo;
        fromTo.append(slFrom.at(i));
        if (slFrom.at(i).count() < fromMax) {
            int j = fromMax - slFrom.at(i).count();
            for (int k = 0; k < j; k++) {
                fromTo.append(" ");
            }
        }
        fromTo.append(CategorySeparator);
        fromTo.append(slTo.at(i));
        if (slTo.at(i).count() < toMax) {
            int j = toMax - slTo.at(i).count();
            for (int k = 0; k < j; k++) {
                fromTo.append(" ");
            }
        }

        QString sSum;
        if (slSum.at(i).count() < sumMax) {
            int j = sumMax - slSum.at(i).count();
            for (int k = 0; k < j; k++) {
                sSum.append(" ");
            }
        }
        sSum.append(slSum.at(i));


        QString tran = slDt.at(i)
                + QString(" ")
                + type
                + QString("\t")
                + sSum
                + QString("\t")
                + fromTo
                + QString("\t")
                + slDetail.at(i);

        sl.append(tran);
    }
    return sl;
}

bool invalidBigType(QString bigType)
{
    if (bigType != g_Income && bigType != g_Expense) {
        /// warnMsgParameterInvalid();
        /// 这里不用warn，因为之后都warn了
        return true;
    }

    return false;
}

bool accountExists(QString accountName)
{
    if (accountName.isEmpty()) {
        return false;
    }

    QSqlQuery q1;
    QString s1;
    s1.append("SELECT Name FROM ");
    s1.append(TableNameAccount);
    s1.append(" WHERE Name = '");
    s1.append(accountName);
    s1.append("'");
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
    int nCount = 0;
    while (q1.next()) {
        nCount++;
    }
    if (nCount == 0) {
        return false;
    } else if (nCount == 1) {
        return true;
    } else {
        assert(0);
    }

    return true;
}

bool categoryExists(QString bigType, QString midType, QString smallType)
{
    if (invalidBigType(bigType)) {
        return false;
    }

    if (midType.isEmpty()) {
        midType = g_Default;
        smallType = g_Default;
    } else if (smallType.isEmpty()) {
        smallType = g_Default;
    }

    QStringList slSmall;

    QSqlQuery q1;
    QString s1;
    s1.append("SELECT SmallType FROM ");
    s1.append(TableNameCategory);
    s1.append(" WHERE BigType = '");
    s1.append(bigType);
    s1.append("' AND MidType = '");
    s1.append(midType);
    s1.append("'");
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
    while (q1.next()) {
        slSmall.append(q1.value(0).toString());
    }
    if (slSmall.count() == 0) {
        return false;
    } else {
        if (!slSmall.contains(g_Default)) {
            assert(0);
        } else {
            if (slSmall.contains(smallType)) {
                return true;
            } else {
                return false;
            }
        }
    }
}

QStringList getAllAccountSurplusByDateTime(QDateTime dt, bool bDESC)
{
    QStringList sl;

    /// 判断dt是否比所有Transaction最新的时间还往后，如果是的话，直接取Surplus，否则要计算
    bool b = isDtLaterThanLatestTransaction(dt);

    QMap<QString, float> map;
    QStringList slAccountName = accountList();
    for (int i = 0; i < slAccountName.count(); i++) {
        map.insert(slAccountName.at(i), 0.0);
    }

    if (b) {
        QSqlQuery q1;
        QString s1;
        s1.append("SELECT Name, Surplus FROM ");
        s1.append(TableNameAccount);
        if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
        while (q1.next()) {
            QString strName;
            float fSurplus;
            strName = q1.value(0).toString();
            fSurplus = q1.value(1).toDouble();
            map[strName] = fSurplus;
        }
    } else {
        QSqlQuery q1;
        QString s1;
        s1.append("SELECT Year, Month, Day, Hour, Minute, FromAccount, ToAccount, Sum FROM ");
        s1.append(TableNameTransaction);
        s1.append(" ORDER BY Year, Month, Day, Hour, Minute");
        if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
        while (q1.next()) {
            int year = q1.value(0).toInt();
            int month = q1.value(1).toInt();
            int day = q1.value(2).toInt();
            int hour = q1.value(3).toInt();
            int minute = q1.value(4).toInt();
            QString fromAccount = q1.value(5).toString();
            QString toAccount = q1.value(6).toString();
            float sum = q1.value(7).toDouble();

            QDateTime dtTran(QDate(year, month, day),
                             QTime(hour, minute));
            if (dtTran > dt) {
                continue;
            }

            if (fromAccount != g_Income) {
                map[fromAccount] = map[fromAccount] - sum;
            }
            if (toAccount != g_Expense) {
                map[toAccount] = map[toAccount] + sum;
            }
        }
    }

    if (bDESC) {
        QMap<QString, float>::const_iterator it = map.constEnd();
        while (it != map.constBegin()) {
            --it;
            sl.append(it.key() + CategorySeparator + QString::number(it.value()));
        }
    } else {
        QMap<QString, float>::const_iterator it = map.constBegin();
        while (it != map.constEnd()) {
            sl.append(it.key() + CategorySeparator + QString::number(it.value()));
            ++it;
        }
    }

    return sl;
}

bool isDtLaterThanLatestTransaction(QDateTime dt)
{
    bool bLater = false;
    bool bFoundTransaction = false;

    QSqlQuery q1;
    QString s1;
    s1.append("SELECT Year, Month, Day, Hour, Minute FROM ");
    s1.append(TableNameTransaction);
    s1.append(" ORDER BY Year DESC, Month DESC, Day DESC, Hour DESC, Minute DESC");
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
    while (q1.next()) {
        bFoundTransaction = true;
        int year = q1.value(0).toInt();
        int month = q1.value(1).toInt();
        int day = q1.value(2).toInt();
        int hour = q1.value(3).toInt();
        int minute = q1.value(4).toInt();

        QDateTime dtMax = QDateTime(QDate(year, month, day), QTime(hour, minute));
        if (dt >= dtMax) {
            bLater = true;
        }
        break;
    }

    if (!bFoundTransaction) {
        bLater = true;
    }
    return bLater;
}

void singleInsertItemInAccount(QString Name,
                               int CreateYear, int CreateMonth, int CreateDay, int CreateHour, int CreateMinute,
                               float Surplus, QString InsertTime)
{
    QSqlQuery q1;
    QString s1;
    s1.append("INSERT INTO ");
    s1.append(TableNameAccount);
    s1.append(" (Name, CreateYear, CreateMonth, CreateDay, CreateHour, CreateMinute, Surplus, InsertTime) VALUES ('");
    s1.append(Name);
    s1.append("', ");
    s1.append(QString::number(CreateYear));
    s1.append(", ");
    s1.append(QString::number(CreateMonth));
    s1.append(", ");
    s1.append(QString::number(CreateDay));
    s1.append(", ");
    s1.append(QString::number(CreateHour));
    s1.append(", ");
    s1.append(QString::number(CreateMinute));
    s1.append(", ");
    s1.append(QString::number(Surplus));
    s1.append(", '");
    s1.append(InsertTime);
    s1.append("')");
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
}

void singleInsertItemInCategory(QString BigType, QString MidType, QString SmallType, QString InsertTime)
{
    QSqlQuery q1;
    QString s1;
    s1.append("INSERT INTO ");
    s1.append(TableNameCategory);
    s1.append(" (BigType, MidType, SmallType, InsertTime) VALUES ('");
    s1.append(BigType);
    s1.append("', '");
    s1.append(MidType);
    s1.append("', '");
    s1.append(SmallType);
    s1.append("', '");
    s1.append(InsertTime);
    s1.append("')");
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
}

void singleInsertItemInTransaction(QString Type, QString CategoryMid, QString CategorySmall,
                                   int Year, int Month, int Day, int Hour, int Minute,
                                   float Sum,
                                   QString FromAccount, QString ToAccount,
                                   QString Detail,
                                   QString InsertTime)
{
    QSqlQuery q1;
    QString s1;
    s1.append("INSERT INTO ");
    s1.append(TableNameTransaction);
    s1.append(" (Type, CategoryMid, CategorySmall, Year, Month, Day, Hour, Minute, Sum, FromAccount, ToAccount, Detail, InsertTime) VALUES ('");
    s1.append(Type);
    s1.append("', '");
    s1.append(CategoryMid);
    s1.append("', '");
    s1.append(CategorySmall);
    s1.append("', ");
    s1.append(QString::number(Year));
    s1.append(", ");
    s1.append(QString::number(Month));
    s1.append(", ");
    s1.append(QString::number(Day));
    s1.append(", ");
    s1.append(QString::number(Hour));
    s1.append(", ");
    s1.append(QString::number(Minute));
    s1.append(", ");
    s1.append(QString::number(Sum));
    s1.append(", '");
    s1.append(FromAccount);
    s1.append("', '");
    s1.append(ToAccount);
    s1.append("', '");
    s1.append(Detail);
    s1.append("', '");
    s1.append(InsertTime);
    s1.append("')");
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
}

void singleDeleteItemInCategory(QString BigType,
                                QString MidType,
                                QString SmallType)
{
    if (SmallType.isEmpty()) {
        SmallType = g_Default;
    }

    if (SmallType == g_Default) {
        QSqlQuery q1;
        QString s1;
        s1.append("DELETE FROM ");
        s1.append(TableNameCategory);
        s1.append(" WHERE BigType = '");
        s1.append(BigType);
        s1.append("' AND MidType = '");
        s1.append(MidType);
        s1.append("'");
        if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
    } else {
        QSqlQuery q1;
        QString s1;
        s1.append("DELETE FROM ");
        s1.append(TableNameCategory);
        s1.append(" WHERE BigType = '");
        s1.append(BigType);
        s1.append("' AND MidType = '");
        s1.append(MidType);
        s1.append("' AND SmallType = '");
        s1.append(SmallType);
        s1.append("'");
        if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
    }
}
