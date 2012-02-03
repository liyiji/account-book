#ifndef ABDEFINES_H
#define ABDEFINES_H

#include <QString>

const int     g_CurrentVersionOfCodeForDatabase = 1;

const QString g_IconStr     = QString(":/test.png");

const QString g_DatabaseDir = QString("database_accountBook/");
const QString g_DatabaseName = QString("defaultDatabase.db");
const QString g_PwdFile     = QString("password.dat");
const QString g_BackupDir   = QString("database_accountBook_backup/");

const QString g_Default     = QString("Default");
const QString g_Income      = QString("Income");
const QString g_Expense     = QString("Expense");
const QString g_Liquidity   = QString("Liquidity");
const QString g_Debt        = QString("Debt");
const QString g_Calculate   = QString("Calculate");
const QString g_Cash        = QString("Cash");

const QString CategorySeparator     = QString(" -> ");
const QString g_Minus               = QString("-------------------");

const QString TableNameAccount      = QString("ABAccount");
const QString TableNameCategory     = QString("ABCategory");
const QString TableNameTransaction  = QString("ABTransaction");
const QString TableNamePassword     = QString("ABPassword");
const QString TableNameVersion      = QString("ABVersion");

enum TreeItemType {
    BigTypeItem,
    MidTypeItem,
    SmallTypeItem
};

enum TransactionType {
    Income,
    Expense,
    Liquidity
};

class ABCategory {
public:
    QString bigType;
    QString midType;
    QString smallType;
};

class TransactionItem {
public:
    QString Type;
    QString CategoryMid;
    QString CategorySmall;
    int     Year;
    int     Month;
    int     Day;
    int     Hour;
    int     Minute;
    double  Sum;
    QString FromAccount;
    QString ToAccount;
    QString Detail;
    QString InsertTime;
};

class AccountItem {
public:
    QString Name;
    int     CreateYear;
    int     CreateMonth;
    int     CreateDay;
    int     CreateHour;
    int     CreateMinute;
    double  Surplus;
    QString InsertTime;
};


//  Account
/// Name            char(100),
/// CreateYear      int,
/// CreateMonth     int,
/// CreateDay       int,
/// CreateHour      int,
/// CreateMinute    int,
/// Surplus         double,
/// InsertTime      char(100)
/// Name, CreateYear, CreateMonth, CreateDay, CreateHour, CreateMinute, Surplus, InsertTime

//  Category
/// BigType     char(100),
/// MidType     char(100),
/// SmallType   char(100),
/// InsertTime  char(100)
/// BigType, MidType, SmallType, InsertTime

// Transsaction
/// Type char(100),
/// CategoryMid char(100),
/// CategorySmall char(100),
/// Year int,
/// Month int,
/// Day int,
/// Hour int,
/// Minute int,
/// Sum double,
/// FromAccount char(100),
/// ToAccount char(100),
/// Detail char(100),
/// InsertTime char(100)
/// Type, CategoryMid, CategorySmall, Year, Month, Day, Hour, Minute, Sum, FromAccount, ToAccount, Detail, InsertTime

#endif // ABDEFINES_H
