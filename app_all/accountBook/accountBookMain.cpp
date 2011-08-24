
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
    功能：
    menuBar的Action
    table上右键点击的contextMenu
    界面：
    TreeWidget的显示及更新
    许多个图标
    输入密码的时候显示*而不是密码本身

  NEED TEST :
    修改Category

  POSTPONED :
    中文路径名
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
    每次添加Transaction的时候，进行判断，new出来的Category/Account是否与已有的重名，Sum是否为0
    删除Transaction
    修改Transaction
    Category的处理方式要进行大动
    sql操作精简
    添加/修改/删除Account
    Dialog启动最小化
    判断sql操作是否成功
    database的name，自动备份
    添加/删除Category
    ABMainWindow::m_vec都删掉了
    table上双击可以Edit Transaction
    tableAccount的顺序总是出问题
    显示某个时间点时候的所有账户余额
    添加/修改 transaction的时候判断是否在未来时间
    输出txt文件的格式修改，使之对齐
    输出txt文件的时候，如果点击取消，也会显示“备份成功”的bug
    加密码
    密码的加密解密

  CANCELED :
    tableWidget * 4改为TreeWidget * 4
    fd29aca4cfc03f5cfe2593b8b2bd158b
  */
