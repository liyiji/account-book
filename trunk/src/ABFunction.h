#ifndef ABFUNCTION_H
#define ABFUNCTION_H

#include <QString>

/// 返回"2011-12-31 23:59"这样的字符串
QString YMDHM2yyyymmddhhmm(int year, int month, int day, int hour, int minute);

/// 把"2011-12-31 23:59"这样的字符串拆成5个int
void yyyymmddhhmm2YMDHM(QString yyyymmddhhmm, int& year, int& month, int& day, int& hour, int& minute);

/// 返回"2011-12-31"这样的字符串
QString YMD2yyyymmdd(int year, int month, int day);

/// 把"2011-12-31"这样的字符串拆成3个int
void yyyymmdd2YMD(QString yyyymmdd, int& year, int& month, int& day);

/// 返回"23:59"这样的字符串
QString HM2hhmm(int hour, int minute);

/// 把"23:59"这样的字符串拆成2个int
void hhmm2HM(QString hhmm, int& hour, int& minute);

/// 获得每个月的最大天数
int getMaxDateInMonth(int year, int month);

/// 把浮点数转换成xxxx.xx形式
QString getMoneyFormNumber(double sum);

/// 得到当前时间+日期
QString getInsertTime();

/// 得到当前的日期时间，规范一下格式，然后作为数据库文件名的一部分
QString getDatabaseFileNameDateAndTime();

/// 打印 Warning message，表示参数传递错误
void warnMsgParameterInvalid();
/// 打印 Warning message，表示这种操作是不允许的
void warnMsgDisallowedOperation();
/// 打印 Warning message，表示数据库操作失败
void warnMsgDatabaseOperationFailed();
/// 打印 Warning message，表示从数据库中寻找item失败
void warnMsgItemNotExists();
/// 打印 Warning message，表示从数据库中已经存在item
void warnMsgItemAlreadyExists();

/// 根据argv[0]，得到 work dir
QString getWorkDir(QString argv_0);

/// 根据不同的情况，初始化DatabaseFile，返回最终要使用的db文件名
QString initDatabaseFile(QString argv_1 = "");

/// 是否是合法的dbName
bool isValidDatabaseFile(QString fileName);
/// 是否是合法的passwordFileName
bool isValidPasswordFile(QString fileName);
/// 是否是合法的backupDbName
bool isBackupDatabaseFile(QString fileName);

#endif // ABFUNCTION_H
