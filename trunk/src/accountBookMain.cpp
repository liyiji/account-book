
#include <cassert>

#include <QDir>
#include <QObject>
#include <QApplication>
#include <QMessageBox>

#include "ABMainWindow.h"
#include "ABFunction.h"

/**
  TODO :
  功能：
  1、加密码，失败T_T
  2、修改Category
  3、中文路径名
  4、menuBar的Action
  5、table上右键点击的contextMenu
  6、添加/修改 transaction的时候判断是否在未来时间
  7、
  8、
  界面：
  1、TreeWidget的显示及更新
  2、修改Category
  3、

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

  CANCELED :
  tableWidget * 4改为TreeWidget * 4
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
