
#include <QDir>
#include <QDate>
#include <QTime>
#include <QMessageBox>

#include "ABFunction.h"
#include "ABDefines.h"

QString YMDHM2yyyymmddhhmm(int year, int month, int day, int hour, int minute)
{
    QString str;
    str.append(YMD2yyyymmdd(year, month, day));
    str.append(" ");
    str.append(HM2hhmm(hour, minute));

    return str;
}

void yyyymmddhhmm2YMDHM(QString yyyymmddhhmm, int& year, int& month, int& day, int& hour, int& minute)
{
//    yyyymmddhhmm�ĸ�ʽΪ"2000-12-31 23:59"
    QStringList stl = yyyymmddhhmm.split(" ");
    yyyymmdd2YMD(stl[0], year, month, day);
    hhmm2HM(stl[1], hour, minute);
}


QString YMD2yyyymmdd(int year, int month, int day)
{
    QString str;
    str.append(QString::number(year));
    str.append("-");
    if (month < 10) {
        str.append("0");
    }
    str.append(QString::number(month));
    str.append("-");
    if (day < 10) {
        str.append("0");
    }
    str.append(QString::number(day));

    return str;
}

void yyyymmdd2YMD(QString yyyymmdd, int& year, int& month, int& day)
{
    QStringList stl = yyyymmdd.split("-");

    year = stl[0].toInt();
    month = stl[1].toInt();
    day = stl[2].toInt();
}

QString HM2hhmm(int hour, int minute)
{
    QString str;
    if (hour < 10) {
        str.append("0");
    }
    str.append(QString::number(hour));
    str.append(":");
    if (minute < 10) {
        str.append("0");
    }
    str.append(QString::number(minute));

    return str;
}

void hhmm2HM(QString hhmm, int& hour, int& minute)
{
    QStringList stl = hhmm.split(":");

    hour = stl[0].toInt();
    minute = stl[1].toInt();
}

int getMaxDateInMonth(int year, int month)
{
    int maxDateInMonth = -1;
    switch(month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: {
            maxDateInMonth = 31;
            break;
        }
    case 4:
    case 6:
    case 9:
    case 11: {
            maxDateInMonth = 30;
            break;
        }
    case 2: {
            if (year % 4 != 0) {
                maxDateInMonth = 28;
            } else {
                if (year % 100 != 0) {
                    maxDateInMonth = 29;
                } else {
                    if (year % 400 == 0) {
                        maxDateInMonth = 29;
                    } else {
                        maxDateInMonth = 28;
                    }
                }
            }
            break;
        }
    default: {
            break;
        }
    }

    return maxDateInMonth;
}

QString getMoneyFormNumber(double sum)
{
    QString str;
    str.sprintf("%.2f", sum);
    return str;
}

QString getInsertTime()
{
    return QDate::currentDate().toString() + QString(", ") + QTime::currentTime().toString();
}

QString getDatabaseFileNameDateAndTime()
{
    /// ���ؽ��Ӧ���� 20991231-2359 �������ַ���
    QDate dt = QDate::currentDate();
    QTime tm = QTime::currentTime();
    QString str, t;

    str.append("-");

    t.sprintf("%4d", dt.year());
    str.append(t);
    if (dt.month() < 10) {
        t.sprintf("0");
        t.append(QString::number(dt.month()));
    } else {
        t = QString::number(dt.month());
    }
    str.append(t);
    if (dt.day() < 10) {
        t.sprintf("0");
        t.append(QString::number(dt.day()));
    } else {
        t = QString::number(dt.day());
    }
    str.append(t);

    str.append("-");

    if (tm.hour() < 10) {
        t.sprintf("0");
        t.append(QString::number(tm.hour()));
    } else {
        t = QString::number(tm.hour());
    }
    str.append(t);
    if (tm.minute() < 10) {
        t.sprintf("0");
        t.append(QString::number(tm.minute()));
    } else {
        t = QString::number(tm.minute());
    }
    str.append(t);

    return str;
}

void warnMsgParameterInvalid()
{
    QString str = "Parameters invalid!";
    QMessageBox::warning(0, "Warning", str);
    printf("%s\n", str.toLocal8Bit().constData());
    fflush(0);
}

void warnMsgDisallowedOperation()
{
    QString str = "Disallowed operation!";
    QMessageBox::warning(0, "Warning", str);
    printf("%s\n", str.toLocal8Bit().constData());
    fflush(0);
}

void warnMsgDatabaseOperationFailed()
{
    QString str = "Database operation failed!";
    QMessageBox::warning(0, "Warning", str);
    printf("%s\n", str.toLocal8Bit().constData());
    fflush(0);
}

void warnMsgItemNotExists()
{
    QString str = "Item doesn't exist!";
    QMessageBox::warning(0, "Warning", str);
    printf("%s\n", str.toLocal8Bit().constData());
    fflush(0);
}

void warnMsgItemAlreadyExists()
{
    QString str = "Item already exist!";
    QMessageBox::warning(0, "Warning", str);
    printf("%s\n", str.toLocal8Bit().constData());
    fflush(0);
}

QString getWorkDir(QString argv_0)
{
    /// TODO : ΪʲôDebug��Release��ʱ���ļ����ָ�����һ����....
    QString strWorkDir;

    QString s1 = "/";
    QString s2 = "\\";

    QStringList sl1 = argv_0.split(s1);
    QStringList sl2 = argv_0.split(s2);

    if (sl1.count() >= 2 && sl2.count() >= 2) {
        QMessageBox::critical(0,
                              "Error",
                              "sl1.count >= 2 && sl2.count >= 2");
    }

#ifdef WIN32
    // do nothing
#else
    strWorkDir.append(s1);
#endif

    if (sl1.count() >= 2) {
        sl1.removeAt(sl1.count() - 1);
        strWorkDir = sl1.join(s1);
    } else if (sl2.count() >= 2) {
        sl2.removeAt(sl2.count() - 1);
        strWorkDir = sl2.join(s1);
    }
    strWorkDir.append(s1);

    return strWorkDir;
}

QString initDatabaseFile(QString argv_1)
{
    QString strDbName;

    extern QString g_WorkDir;
    QDir dataDir(g_WorkDir + g_DatabaseDir);
    if (!dataDir.exists()) {
        QDir dir;
        dir.mkdir(g_WorkDir + g_DatabaseDir);
    }

    QDir backupDir(g_WorkDir + g_BackupDir);
    if (!backupDir.exists()) {
        QDir dir;
        dir.mkdir(g_WorkDir + g_BackupDir);
    }

    if (argv_1.isEmpty()) {
        /// ���û�д���ʹ�õ�dbName

        /// ɾ���������ļ���������в���defaultDatabase.dbҲ����password.dat���ļ�
        QStringList sl = dataDir.entryList();
        for (int i = 0; i < sl.count(); i++) {
            QString str = sl.at(i);
            if (isValidDatabaseFile(str) || isValidPasswordFile(str)) {
                continue;
            }
            QFile::remove(g_WorkDir + g_DatabaseDir + str);
        }
        strDbName = g_WorkDir + g_DatabaseDir + g_DatabaseName;
    } else {
        /// ���ָ����Ҫʹ�õ�dbName

        strDbName = argv_1;
        QStringList sl = dataDir.entryList();
        if (!sl.contains(g_DatabaseName)) {
            /// ���Ĭ�ϵ�db�ļ������ڣ����argv[1]���������ļ����������db�ļ�copy��Ĭ�ϵ�db�ļ���������
            QFile::copy(strDbName, g_WorkDir + g_DatabaseDir + g_DatabaseName);
            strDbName = g_WorkDir + g_DatabaseDir + g_DatabaseName;
        }
    }

    return strDbName;
}

bool isValidDatabaseFile(QString fileName)
{
    /// "defaultDatabase.db"
    if (fileName == g_DatabaseName)
        return true;

    return false;
}

bool isValidPasswordFile(QString fileName)
{
    /// "password.dat"
    if (fileName == g_PwdFile)
        return true;

    return false;
}

bool isBackupDatabaseFile(QString fileName)
{
    /// "defaultDatabase-20111231-2359.db"�����ļ������ǺϷ���
    if (fileName.startsWith("defaultDatabase") && fileName.endsWith(".db") && fileName.count() == 32)
        return true;

    return false;
}
