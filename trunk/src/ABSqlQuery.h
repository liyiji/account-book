#ifndef ABSQLQUERY_H
#define ABSQLQUERY_H

#include <QString>
#include <QDateTime>
#include <QSqlDatabase>

#include <ABDefines.h>

/// 以下均为数据库操作

/// 数据库操作的语法，以避免忘掉
/// SELECT store_name FROM Store_Information
/// INSERT INTO Store_Information (store_name, Sales, Date) VALUES ('Los Angeles', 900, 'Jan-10-1999')
/// UPDATE Store_Information SET Sales = 500 WHERE store_name = "Los Angeles" AND Date = "Jan-08-1999"
/// DELETE FROM Store_Information WHERE store_name = "Los Angeles"

/// 连接数据库
bool createConnection(QString strDbName, QString strPwd = "");

/// 对数据库进行初始化
void initDatabase(QSqlDatabase& db);

/// 创建Table
void createAccountTable();
void createCategoryTable();
void createTransactionTable();
void createPwdTable();

/// drop table
void dropPwdtable();

/// Insert item
void insertItemInAccount(QString Name,
                         int CreateYear, int CreateMonth, int CreateDay, int CreateHour, int CreateMinute,
                         /*float Surplus, */QString InsertTime = "");

void insertItemInCategory(QString BigType, QString MidType, QString SmallType = "", QString InsertTime = "");

void insertItemInTransaction(QString Type, QString CategoryMid, QString CategorySmall,
                             int Year, int Month, int Day, int Hour, int Minute,
                             float Sum,
                             QString FromAccount, QString ToAccount,
                             QString Detail,
                             QString InsertTime = "");

/// 只有符合下列条件的Account才可以删除
/// 1、余额(Surplus)为0
/// 2、表Transaction中没有相关的记录
/// 否则很难处理，因此不允许进行删除，直接return
void deleteItemInAccount(QString Name);

/// 删除当前Category
/// 禁止删除MidType和SmallType都为"Default"的Category
/// 如果当前Category的SmallType为"Default"
/// 则递归删除MidType等于当前MidType的Category，所有的Transaction转移到相应的"BigType -> Default -> Default"下
/// 如果当前Category的SmallType不为"Default"
/// 则删除当前Category，把所有当前Category下的Transaction转移到相应的"BigType -> MidType -> Default"下
void deleteItemInCategory(QString BigType,
                          QString MidType,
                          QString SmallType = "");

/// 删除符合条件的一个Transaction
/// 并处理FromAccount和ToAccount的Surplus
void deleteItemInTransaction(QString Type,
                             QString CategoryMid,
                             QString CategorySmall,
                             int Year,
                             int Month,
                             int Day,
                             int Hour,
                             int Minute,
                             float Sum,
                             QString FromAccount = "",
                             QString ToAccount   = "",
                             QString Detail      = "",
                             QString InsertTime  = "");

/// 重命名一个Account
/// 此函数结束之后，所有用到Account的地方，都需要从数据库中重新取一遍
void renameAccount(QString oriName, QString newName);

/// 给一个Account更新Surplus
/// 需要保证此Account已经存在，否则直接return
void updateSurplusOfAccount(QString accountName, float sumChange);

/// 修改一个Category的名字
void renameCategory(ABCategory oriCtg, ABCategory newCtg);
void renameCategory(QString bigType,
                    QString oriMidType, QString oriSmallType,
                    QString newMidType, QString newSmallType);

/// 修改一个Transaction
void updateTransaction(TransactionItem oriItem, TransactionItem newItem);

/// 返回当前的Account Name List
QStringList accountList();

/// 返回Surplus为0的Account Name List
QStringList surplus0AccountList();

/// 根据bigType返回Category List
/// 如果bigType为空，则返回所有的Category，如果为"Income"或者"Expense"，则返回该类的Category
QVector<ABCategory> categoryList(QString bigType = "");

/// 根据bigType返回midType的List，是Distinct的
QStringList midTypeList(QString bigType);

/// 根据bigType, midType返回smallType的List，是Distinct的
QStringList smallTypeList(QString bigType, QString midType);

/// 按照时间排序，返回所有的Transaction
QStringList transactionList(int beginYear = 0,
                            int beginMonth = 1,
                            int beginDay = 1,
                            int beginHour = 0,
                            int beginMinute = 0,
                            int endYear = 3000,
                            int endMonth = 12,
                            int endDay = 31,
                            int endHour = 23,
                            int endMinute = 59);

/// 判断bigType是否等于"Income"或者"Expense"
bool invalidBigType(QString bigType);

/// 判断account是否已经存在
bool accountExists(QString accountName);

/// 判断Category是否存在
bool categoryExists(QString bigType, QString midType, QString smallType = "");

/// 根据日期时间dt，得到，到dt为止，所有的account的surplus
/// 在当前时间点发生的交易，按照已经发生结束计算
/// QStringList的每一个条目的格式是"accountName -> surplus"
/// bDESC为True时候，输出的QStringList是倒序的
QStringList getAllAccountSurplusByDateTime(QDateTime dt, bool bDESC = true);

/// 判断dt是否比最新的Transaction的发生时间还新
bool isDtLaterThanLatestTransaction(QDateTime dt);

/// 单纯的往三个Table里边insert item，不进行任何判断
/// 请勿在其他地方调用这三个函数，ABSqlQuery.h的其他函数中进行调用
void singleInsertItemInAccount(QString Name,
                               int CreateYear, int CreateMonth, int CreateDay, int CreateHour, int CreateMinute,
                               float Surplus, QString InsertTime);
void singleInsertItemInCategory(QString BigType, QString MidType, QString SmallType, QString InsertTime);
void singleInsertItemInTransaction(QString Type, QString CategoryMid, QString CategorySmall,
                                   int Year, int Month, int Day, int Hour, int Minute,
                                   float Sum,
                                   QString FromAccount, QString ToAccount,
                                   QString Detail,
                                   QString InsertTime);

void singleDeleteItemInCategory(QString BigType,
                                QString MidType,
                                QString SmallType);


#endif // ABSQLQUERY_H
