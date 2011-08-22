#ifndef ABSQLQUERY_H
#define ABSQLQUERY_H

#include <QString>
#include <QDateTime>
#include <QSqlDatabase>

#include <ABDefines.h>

/// ���¾�Ϊ���ݿ����

/// ���ݿ�������﷨���Ա�������
/// SELECT store_name FROM Store_Information
/// INSERT INTO Store_Information (store_name, Sales, Date) VALUES ('Los Angeles', 900, 'Jan-10-1999')
/// UPDATE Store_Information SET Sales = 500 WHERE store_name = "Los Angeles" AND Date = "Jan-08-1999"
/// DELETE FROM Store_Information WHERE store_name = "Los Angeles"

/// �������ݿ�
bool createConnection(QString strDbName, QString strPwd = "");

/// �����ݿ���г�ʼ��
void initDatabase(QSqlDatabase& db);

/// ����Table
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

/// ֻ�з�������������Account�ſ���ɾ��
/// 1�����(Surplus)Ϊ0
/// 2����Transaction��û����صļ�¼
/// ������Ѵ�����˲��������ɾ����ֱ��return
void deleteItemInAccount(QString Name);

/// ɾ����ǰCategory
/// ��ֹɾ��MidType��SmallType��Ϊ"Default"��Category
/// �����ǰCategory��SmallTypeΪ"Default"
/// ��ݹ�ɾ��MidType���ڵ�ǰMidType��Category�����е�Transactionת�Ƶ���Ӧ��"BigType -> Default -> Default"��
/// �����ǰCategory��SmallType��Ϊ"Default"
/// ��ɾ����ǰCategory�������е�ǰCategory�µ�Transactionת�Ƶ���Ӧ��"BigType -> MidType -> Default"��
void deleteItemInCategory(QString BigType,
                          QString MidType,
                          QString SmallType = "");

/// ɾ������������һ��Transaction
/// ������FromAccount��ToAccount��Surplus
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

/// ������һ��Account
/// �˺�������֮�������õ�Account�ĵط�������Ҫ�����ݿ�������ȡһ��
void renameAccount(QString oriName, QString newName);

/// ��һ��Account����Surplus
/// ��Ҫ��֤��Account�Ѿ����ڣ�����ֱ��return
void updateSurplusOfAccount(QString accountName, float sumChange);

/// �޸�һ��Category������
void renameCategory(ABCategory oriCtg, ABCategory newCtg);
void renameCategory(QString bigType,
                    QString oriMidType, QString oriSmallType,
                    QString newMidType, QString newSmallType);

/// �޸�һ��Transaction
void updateTransaction(TransactionItem oriItem, TransactionItem newItem);

/// ���ص�ǰ��Account Name List
QStringList accountList();

/// ����SurplusΪ0��Account Name List
QStringList surplus0AccountList();

/// ����bigType����Category List
/// ���bigTypeΪ�գ��򷵻����е�Category�����Ϊ"Income"����"Expense"���򷵻ظ����Category
QVector<ABCategory> categoryList(QString bigType = "");

/// ����bigType����midType��List����Distinct��
QStringList midTypeList(QString bigType);

/// ����bigType, midType����smallType��List����Distinct��
QStringList smallTypeList(QString bigType, QString midType);

/// ����ʱ�����򣬷������е�Transaction
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

/// �ж�bigType�Ƿ����"Income"����"Expense"
bool invalidBigType(QString bigType);

/// �ж�account�Ƿ��Ѿ�����
bool accountExists(QString accountName);

/// �ж�Category�Ƿ����
bool categoryExists(QString bigType, QString midType, QString smallType = "");

/// ��������ʱ��dt���õ�����dtΪֹ�����е�account��surplus
/// �ڵ�ǰʱ��㷢���Ľ��ף������Ѿ�������������
/// QStringList��ÿһ����Ŀ�ĸ�ʽ��"accountName -> surplus"
/// bDESCΪTrueʱ�������QStringList�ǵ����
QStringList getAllAccountSurplusByDateTime(QDateTime dt, bool bDESC = true);

/// �ж�dt�Ƿ�����µ�Transaction�ķ���ʱ�仹��
bool isDtLaterThanLatestTransaction(QDateTime dt);

/// ������������Table���insert item���������κ��ж�
/// �����������ط�����������������ABSqlQuery.h�����������н��е���
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
