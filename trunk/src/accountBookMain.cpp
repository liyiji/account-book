
#include <cassert>

#include <QDir>
#include <QObject>
#include <QApplication>
#include <QMessageBox>

#include "ABMainWindow.h"
#include "ABFunction.h"

/**
  TODO :
  ���ܣ�
  1�������룬ʧ��T_T
  2���޸�Category
  3������·����
  4��menuBar��Action
  5��table���Ҽ������contextMenu
  6�����/�޸� transaction��ʱ���ж��Ƿ���δ��ʱ��
  7��
  8��
  ���棺
  1��TreeWidget����ʾ������
  2���޸�Category
  3��

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

  CANCELED :
  tableWidget * 4��ΪTreeWidget * 4
  */

QString g_WorkDir;

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
