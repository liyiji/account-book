#ifndef ABMAINWINDOW_H
#define ABMAINWINDOW_H

#include "ui_ABMainWindow.h"
#include "ABDefines.h"

class ABMainWindow : public QMainWindow {
    Q_OBJECT

    Ui_accountBookMainWindow *ui;

    QString                 m_strDatabaseName;

public:
    ABMainWindow(QString strDatabaseFileName, QWidget *parent = 0);
    virtual ~ABMainWindow();

    void loadDataByUi();

private:
    virtual void closeEvent(QCloseEvent *);
    virtual void keyPressEvent(QKeyEvent *);

    void initUi();
    void initStatisticsTree();
    void initTabCalc();
    void initConnection();
    void loadData(int iYear, QString strMonth);
    void showTransactionData(int iYear, QString strMonth);
    void showCategoryData(int iYear, QString strMonth);
    void showAccountData(QDateTime dt);
    void resetTableWidgetsSettings(bool bTableAccount   = false,
                                   bool btableIncome    = false,
                                   bool btableExpense   = false,
                                   bool btableLiquidity = false);
    QTreeWidgetItem* searchItemInStatisticsTree(QString bigType, QString midType = g_Default, QString smallType = g_Default);
    void resizeTableWidgetAccount();
    void resizeTableWidgetIncomeExpenseLiquidity();
    void resizeTreeStatistics();

    /// 如果bManual == true，则弹出对话框，告知用户是否成功
    void backupDatabaseFile(bool bManual);

    void exportTransactionsAsTextFile(bool bNotice);
    void setNewPassword();
    void updateCalcLabels();

private slots:
    void slotMenuAction(QAction *);

    void slotChangeEditDeleteButtonEnable();
    void slotChangeYearOrMonth();
    void slotManageAccout();
    void slotManageCategory();
    void slotAddNewIncome();
    void slotAddNewExpense();
    void slotAddNewLiquidity();
    void slotEditCurrentTransactionItem();
    void slotDeleteCurrentTransactionItem();
    void slotRecalculateSurplusOfAllAccounts();
    void slotResizeColumnsAndRow();
    void slotLoadDataOfCurMonth();
    void slotShowBigTypeInTree();
    void slotShowMidTypeInTree();
    void slotShowSmallTypeInTree();

    void slotPlus();
    void slotMinus();
    void slotMultiply();
    void slotDivide();

    void slotDoubleClickTableTransaction(QTableWidgetItem*);
    void slotReloadCurTimeAccountStatus();
    void slotReloadAccountStatusByDataTime(QDateTime);
};

#endif // ABMAINWINDOW_H
