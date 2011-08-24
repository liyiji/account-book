
#include <cassert>

#include <QDebug>
#include <QDir>
#include <QObject>
#include <QApplication>
#include <QMessageBox>

#include "ABMainWindow.h"
#include "ABFunction.h"

/**
  TODO :
    ���ܣ�
    menuBar��Action
    table���Ҽ������contextMenu
    ���棺
    TreeWidget����ʾ������
    ����ͼ��
    ���������ʱ����ʾ*���������뱾��

  NEED TEST :
    �޸�Category

  POSTPONED :
    ����·����
  */

QString g_WorkDir;
bool g_UsePassword;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString strDbName;

    g_WorkDir = getWorkDir(QString(argv[0]));

    QDir dataDir(g_WorkDir + g_DatabaseDir);
    if (!dataDir.exists()) {
        QDir dir;
        dir.mkdir(g_WorkDir + g_DatabaseDir);
    }

    QString argv_1;
    if (argc > 1) {
        argv_1 = QString(argv[1]);
    }
    strDbName = initDatabaseFile(argv_1);

    ABMainWindow accountBook(strDbName);
    app.setActiveWindow(&accountBook);
    accountBook.show();

    return app.exec();
}

/**

  DONE :
    ÿ�����Transaction��ʱ�򣬽����жϣ�new������Category/Account�Ƿ������е�������Sum�Ƿ�Ϊ0
    ɾ��Transaction
    �޸�Transaction
    Category�Ĵ���ʽҪ���д�
    sql��������
    ���/�޸�/ɾ��Account
    Dialog������С��
    �ж�sql�����Ƿ�ɹ�
    database��name���Զ�����
    ���/ɾ��Category
    ABMainWindow::m_vec��ɾ����
    table��˫������Edit Transaction
    tableAccount��˳�����ǳ�����
    ��ʾĳ��ʱ���ʱ��������˻����
    ���/�޸� transaction��ʱ���ж��Ƿ���δ��ʱ��
    ���txt�ļ��ĸ�ʽ�޸ģ�ʹ֮����
    ���txt�ļ���ʱ��������ȡ����Ҳ����ʾ�����ݳɹ�����bug
    ������
    ����ļ��ܽ���

  CANCELED :
    tableWidget * 4��ΪTreeWidget * 4
    fd29aca4cfc03f5cfe2593b8b2bd158b
  */
