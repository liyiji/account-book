#ifndef ABFUNCTION_H
#define ABFUNCTION_H

#include <QString>

/// ����"2011-12-31 23:59"�������ַ���
QString YMDHM2yyyymmddhhmm(int year, int month, int day, int hour, int minute);

/// ��"2011-12-31 23:59"�������ַ������5��int
void yyyymmddhhmm2YMDHM(QString yyyymmddhhmm, int& year, int& month, int& day, int& hour, int& minute);

/// ����"2011-12-31"�������ַ���
QString YMD2yyyymmdd(int year, int month, int day);

/// ��"2011-12-31"�������ַ������3��int
void yyyymmdd2YMD(QString yyyymmdd, int& year, int& month, int& day);

/// ����"23:59"�������ַ���
QString HM2hhmm(int hour, int minute);

/// ��"23:59"�������ַ������2��int
void hhmm2HM(QString hhmm, int& hour, int& minute);

/// ���ÿ���µ��������
int getMaxDateInMonth(int year, int month);

/// �Ѹ�����ת����xxxx.xx��ʽ
QString getMoneyFormNumber(double sum);

/// �õ���ǰʱ��+����
QString getInsertTime();

/// �õ���ǰ������ʱ�䣬�淶һ�¸�ʽ��Ȼ����Ϊ���ݿ��ļ�����һ����
QString getDatabaseFileNameDateAndTime();

/// ��ӡ Warning message����ʾ�������ݴ���
void warnMsgParameterInvalid();
/// ��ӡ Warning message����ʾ���ֲ����ǲ������
void warnMsgDisallowedOperation();
/// ��ӡ Warning message����ʾ���ݿ����ʧ��
void warnMsgDatabaseOperationFailed();
/// ��ӡ Warning message����ʾ�����ݿ���Ѱ��itemʧ��
void warnMsgItemNotExists();
/// ��ӡ Warning message����ʾ�����ݿ����Ѿ�����item
void warnMsgItemAlreadyExists();

/// ����argv[0]���õ� work dir
QString getWorkDir(QString argv_0);

/// ���ݲ�ͬ���������ʼ��DatabaseFile����������Ҫʹ�õ�db�ļ���
QString initDatabaseFile(QString argv_1 = "");

/// �Ƿ��ǺϷ���dbName
bool isValidDatabaseFile(QString fileName);
/// �Ƿ��ǺϷ���passwordFileName
bool isValidPasswordFile(QString fileName);
/// �Ƿ��ǺϷ���backupDbName
bool isBackupDatabaseFile(QString fileName);

#endif // ABFUNCTION_H
