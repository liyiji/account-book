
#include <cassert>

#include <QDebug>
#include <QDir>
#include <QDateTime>
#include <QSqlQuery>
#include <QMessageBox>
#include <QKeyEvent>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>

#include "ABMainWindow.h"
#include "ABDefines.h"
#include "ABFunction.h"
#include "ABSqlQuery.h"
#include "ABInputPassword.h"
#include "ABManageAccount.h"
#include "ABManageCategory.h"
#include "ABTransactionDetail.h"

ABMainWindow::ABMainWindow(QString strDatabaseFileName, QWidget *parent) : QMainWindow(parent)
{
    ui = new Ui_accountBookMainWindow;
    ui->setupUi(this);

    m_strDatabaseName = strDatabaseFileName;
    createConnection(m_strDatabaseName);

    extern bool g_UsePassword;
    if (g_UsePassword) {
        ABInputPassword dlg(1);
        if (dlg.exec() != QDialog::Accepted) {
            assert(0);
        }
    }

    initUi();
    initConnection();
    slotLoadDataOfCurMonth(); /// 从数据库中读取
    slotResizeColumnsAndRow(); /// TODO : 是否应该留下

    resize(1, 1);
}

ABMainWindow::~ABMainWindow()
{
    if (ui) {
        delete ui;
        ui = 0;
    }
}

void ABMainWindow::loadDataByUi()
{
    slotChangeYearOrMonth();
}

void ABMainWindow::closeEvent(QCloseEvent *event)
{
#ifndef DEBUG_VERSION
    if (QMessageBox::warning(this, "Exit", "Do you really want to exit?", QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes) {
#endif
        backupDatabaseFile(false);
        event->accept();
#ifndef DEBUG_VERSION
    } else {
        event->ignore();
    }
#endif
}

void ABMainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();

    if (key == Qt::Key_R) {
        if (event->modifiers() & Qt::AltModifier) {
            slotResizeColumnsAndRow();
        }
    }
    else {
        /// TODO : 可以添加一些其他的键盘快捷方式
    }
}

void ABMainWindow::initUi()
{
    QString strWindowTitle("accountBook");
    setWindowTitle(strWindowTitle);

#ifndef DEBUG_VERSION
//    ui->menuImport_Export->setEnabled(false);
//    ui->actionExport_Data_As_Text_File->setEnabled(false);
    ui->actionImport_another_data_file->setEnabled(false);
    ui->actionOptions->setEnabled(false);
//    ui->actionSet_Password->setEnabled(false);
#endif

    int index = -1;

    index = ui->mainTabWidget->indexOf(ui->tabStatistics);
    ui->mainTabWidget->setTabText(index, "Statistics");
    index = ui->mainTabWidget->indexOf(ui->tabIncome);
    ui->mainTabWidget->setTabText(index, g_Income);
    index = ui->mainTabWidget->indexOf(ui->tabExpense);
    ui->mainTabWidget->setTabText(index, g_Expense);
    index = ui->mainTabWidget->indexOf(ui->tabLiquidity);
    ui->mainTabWidget->setTabText(index, g_Liquidity);

    ui->mainTabWidget->setCurrentIndex(ui->mainTabWidget->indexOf(ui->tabStatistics));

    QDate curDate = QDate::currentDate();
    int iCurYear = curDate.year();
    int iCurMonth = curDate.month();
    int iFirstYear = ui->comboBox->itemText(0).toInt();
    if (iFirstYear != 0 && iCurYear > iFirstYear) {
        for (int iYear = iFirstYear + 1; iYear <= iCurYear; iYear++) {
            ui->comboBox->addItem(QString::number(iYear));
        }
    }
    ui->comboBox->setCurrentIndex(ui->comboBox->count() - 1);
    ui->comboBox_2->setCurrentIndex(iCurMonth);

    ui->buttonEdit->setEnabled(false);
    ui->buttonDelete->setEnabled(false);

    /// 禁止编辑
    ui->tableAccount->setEditTriggers(QTableWidget::NoEditTriggers);
    ui->tableIncome->setEditTriggers(QTableWidget::NoEditTriggers);
    ui->tableExpense->setEditTriggers(QTableWidget::NoEditTriggers);
    ui->tableLiquidity->setEditTriggers(QTableWidget::NoEditTriggers);

    QHeaderView *headerView[4];
    headerView[0] = ui->tableAccount->horizontalHeader();
    headerView[1] = ui->tableIncome->horizontalHeader();
    headerView[2] = ui->tableExpense->horizontalHeader();
    headerView[3] = ui->tableLiquidity->horizontalHeader();
    for (int i = 0; i < 4; i++) {
        headerView[i]->setMovable(false);
    }
    /// 每列宽度、每行高度自动设置为合适的大小
    resizeTableWidgetAccount();
    resizeTableWidgetIncomeExpenseLiquidity();

    /// 竖着的表头可见
    ui->tableAccount->verticalHeader()->setVisible(true);
    ui->tableIncome->verticalHeader()->setVisible(true);
    ui->tableExpense->verticalHeader()->setVisible(true);
    ui->tableLiquidity->verticalHeader()->setVisible(true);

    /// 横着的表头点击排序
    ui->tableAccount->setSortingEnabled(true);
    ui->tableIncome->setSortingEnabled(true);
    ui->tableExpense->setSortingEnabled(true);
    ui->tableLiquidity->setSortingEnabled(true);

    /// 按行选中
    ui->tableAccount->setSelectionBehavior(QTableWidget::SelectRows);
    ui->tableIncome->setSelectionBehavior(QTableWidget::SelectRows);
    ui->tableExpense->setSelectionBehavior(QTableWidget::SelectRows);
    ui->tableLiquidity->setSelectionBehavior(QTableWidget::SelectRows);

    /// 只能单选
    ui->tableAccount->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableIncome->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableExpense->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableLiquidity->setSelectionMode(QAbstractItemView::SingleSelection);

    initStatisticsTree();
}

void ABMainWindow::initStatisticsTree()
{
    QVector<ABCategory> vecCategory = categoryList();

    ui->treeStatistics->header()->setMovable(false);

    QStringList sl;
    sl.append("Category");
    sl.append("Detail");
    sl.append("Remark");
    ui->treeStatistics->setColumnCount(sl.count());
    ui->treeStatistics->setHeaderLabels(sl);

    ui->treeStatistics->clear();

    bool bExpandMidItems = true;

    QTreeWidgetItem *pIncomeItem = new QTreeWidgetItem(BigTypeItem);
    pIncomeItem->setText(0, g_Income);
    pIncomeItem->setText(1, g_Minus);
    pIncomeItem->setTextAlignment(1, 0x82);
    ui->treeStatistics->addTopLevelItem(pIncomeItem);

    {
        QTreeWidgetItem *pDefaultMidItem = new QTreeWidgetItem(MidTypeItem);
        pDefaultMidItem->setText(0, g_Default);
        pDefaultMidItem->setText(1, getMoneyFormNumber(0));
        pDefaultMidItem->setTextAlignment(1, 0x82);
        pDefaultMidItem->setTextColor(1, Qt::red);
        pIncomeItem->addChild(pDefaultMidItem);
        pIncomeItem->setExpanded(true);

        QTreeWidgetItem *pDefaultSmallItem = new QTreeWidgetItem(SmallTypeItem);
        pDefaultSmallItem->setText(0, g_Default);
        pDefaultSmallItem->setText(1, getMoneyFormNumber(0));
        pDefaultSmallItem->setTextAlignment(1, 0x82);
        pDefaultMidItem->addChild(pDefaultSmallItem);
        if (bExpandMidItems)
            pDefaultMidItem->setExpanded(true);
    }

    QTreeWidgetItem *pExpenseItem = new QTreeWidgetItem(BigTypeItem);
    pExpenseItem->setText(0, g_Expense);
    pExpenseItem->setText(1, g_Minus);
    pExpenseItem->setTextAlignment(1, 0x82);
    ui->treeStatistics->addTopLevelItem(pExpenseItem);

    {
        QTreeWidgetItem *pDefaultMidItem = new QTreeWidgetItem(MidTypeItem);
        pDefaultMidItem->setText(0, g_Default);
        pDefaultMidItem->setText(1, getMoneyFormNumber(0));
        pDefaultMidItem->setTextAlignment(1, 0x82);
        pDefaultMidItem->setTextColor(1, Qt::red);
        pExpenseItem->addChild(pDefaultMidItem);
        pExpenseItem->setExpanded(true);

        QTreeWidgetItem *pDefaultSmallItem = new QTreeWidgetItem(SmallTypeItem);
        pDefaultSmallItem->setText(0, g_Default);
        pDefaultSmallItem->setText(1, getMoneyFormNumber(0));
        pDefaultSmallItem->setTextAlignment(1, 0x82);
        pDefaultMidItem->addChild(pDefaultSmallItem);
        if (bExpandMidItems)
            pDefaultMidItem->setExpanded(true);
    }

    for (int i = 0; i < vecCategory.count(); i++) {
        QTreeWidgetItem *pBigItem = 0;
        ABCategory ctg = vecCategory[i];
        if (ctg.bigType == g_Income) {
            pBigItem = pIncomeItem;
        } else if (ctg.bigType == g_Expense) {
            pBigItem = pExpenseItem;
        } else {
            assert(0);
        }

        bool bFoundMidItem = false;
        for (int j = 0; j < pBigItem->childCount(); j++) {
            QTreeWidgetItem *pMidItem = pBigItem->child(j);
            if (ctg.midType == pMidItem->text(0)) {
                bFoundMidItem = true;
                if (ctg.smallType == g_Default) {
                    /// ctg也是一个midType
                } else {
                    bool bFoundSmallItem = false;
                    for (int k = 0; k < pMidItem->childCount(); k++) {
                        QTreeWidgetItem *pSmallItem = pMidItem->child(k);
                        if (ctg.smallType == pSmallItem->text(0)) {
                            /// 找到一个同样的Item
                            bFoundSmallItem = true;
                            break;
                        }
                    }
                    if (bFoundSmallItem == false) {
                        QTreeWidgetItem *pNewSmallItem = new QTreeWidgetItem(SmallTypeItem);
                        pNewSmallItem->setText(0, ctg.smallType);
                        pNewSmallItem->setText(1, getMoneyFormNumber(0));
                        pNewSmallItem->setTextAlignment(1, 0x82);
                        pMidItem->addChild(pNewSmallItem);
                    }
                }
                break;
            }
        }
        if (bFoundMidItem == false) {
            QTreeWidgetItem *pNewMidItem = new QTreeWidgetItem(MidTypeItem);
            pNewMidItem->setText(0, ctg.midType);
            pNewMidItem->setText(1, getMoneyFormNumber(0));
            pNewMidItem->setTextAlignment(1, 0x82);
            pNewMidItem->setTextColor(1, Qt::red);
            pBigItem->addChild(pNewMidItem);

            QTreeWidgetItem *pNewSmallItem = new QTreeWidgetItem(SmallTypeItem);
            pNewSmallItem->setText(0, g_Default);
            pNewSmallItem->setText(1, getMoneyFormNumber(0));
            pNewSmallItem->setTextAlignment(1, 0x82);
            pNewMidItem->addChild(pNewSmallItem);
            if (bExpandMidItems)
                pNewMidItem->setExpanded(true);

            if (ctg.smallType != g_Default) {
                QTreeWidgetItem *pNewSmallItem2 = new QTreeWidgetItem(SmallTypeItem);
                pNewSmallItem2->setText(0, ctg.smallType);
                pNewSmallItem2->setText(1, getMoneyFormNumber(0));
                pNewSmallItem2->setTextAlignment(1, 0x82);
                pNewMidItem->addChild(pNewSmallItem2);
            }
        }
    }

    slotShowMidTypeInTree();
    resizeTreeStatistics();
}

void ABMainWindow::initConnection()
{
    connect(ui->menubar, SIGNAL(triggered(QAction*)), this, SLOT(slotMenuAction(QAction*)));

    connect(ui->mainTabWidget, SIGNAL(currentChanged(int)), this, SLOT(slotChangeEditDeleteButtonEnable()));
    connect(ui->tableIncome, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(slotChangeEditDeleteButtonEnable()));
    connect(ui->tableExpense, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(slotChangeEditDeleteButtonEnable()));
    connect(ui->tableLiquidity, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(slotChangeEditDeleteButtonEnable()));

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotChangeYearOrMonth()));
    connect(ui->comboBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(slotChangeYearOrMonth()));
    connect(ui->buttonBackToToday, SIGNAL(released()), this, SLOT(slotLoadDataOfCurMonth()));

    connect(ui->buttonManageAccount, SIGNAL(released()), this, SLOT(slotManageAccout()));
    connect(ui->buttonManageCategory, SIGNAL(released()), this, SLOT(slotManageCategory()));

    connect(ui->buttonNewIncome, SIGNAL(released()), this, SLOT(slotAddNewIncome()));
    connect(ui->buttonNewExpense, SIGNAL(released()), this, SLOT(slotAddNewExpense()));
    connect(ui->buttonNewLiquidity, SIGNAL(released()), this, SLOT(slotAddNewLiquidity()));

    connect(ui->buttonEdit, SIGNAL(released()), this, SLOT(slotEditCurrentTransactionItem()));
    connect(ui->buttonDelete, SIGNAL(released()), this, SLOT(slotDeleteCurrentTransactionItem()));

    connect(ui->buttonShowBigType, SIGNAL(released()), this, SLOT(slotShowBigTypeInTree()));
    connect(ui->buttonShowMidType, SIGNAL(released()), this, SLOT(slotShowMidTypeInTree()));
    connect(ui->buttonShowSmallType, SIGNAL(released()), this, SLOT(slotShowSmallTypeInTree()));

    connect(ui->buttonResize, SIGNAL(released()), this, SLOT(slotResizeColumnsAndRow()));

    connect(ui->tableIncome, SIGNAL(itemDoubleClicked(QTableWidgetItem*)),
            this, SLOT(slotDoubleClickTableTransaction(QTableWidgetItem*)));
    connect(ui->tableExpense, SIGNAL(itemDoubleClicked(QTableWidgetItem*)),
            this, SLOT(slotDoubleClickTableTransaction(QTableWidgetItem*)));
    connect(ui->tableLiquidity, SIGNAL(itemDoubleClicked(QTableWidgetItem*)),
            this, SLOT(slotDoubleClickTableTransaction(QTableWidgetItem*)));

    connect(ui->buttonBackToCurTime, SIGNAL(released()),
            this, SLOT(slotReloadCurTimeAccountStatus()));
    connect(ui->dateTimeEdit, SIGNAL(dateTimeChanged(QDateTime)),
            this, SLOT(slotReloadAccountStatusByDataTime(QDateTime)));
}

void ABMainWindow::loadData(int iYear, QString strMonth)
{
    /// TODO : 这里到底是否应该注释掉........
    /// 横着的表头点击排序
//    ui->tableAccount->setSortingEnabled(false);
    ui->tableIncome->setSortingEnabled(false);
    ui->tableExpense->setSortingEnabled(false);
    ui->tableLiquidity->setSortingEnabled(false);

    showTransactionData(iYear, strMonth);
    showCategoryData(iYear, strMonth);
    slotReloadCurTimeAccountStatus();

    /// 横着的表头点击排序
//    ui->tableAccount->setSortingEnabled(true);
    ui->tableIncome->setSortingEnabled(true);
    ui->tableExpense->setSortingEnabled(true);
    ui->tableLiquidity->setSortingEnabled(true);

    slotResizeColumnsAndRow();
}

void ABMainWindow::showTransactionData(int iYear, QString strMonth)
{
    int iMonth = -1;
    if (strMonth != "All") {
        iMonth = strMonth.toInt();
        if (iMonth <= 0 || iMonth > 12) {
            return;
        }
    }

    ui->tableIncome->setRowCount(0);
    ui->tableExpense->setRowCount(0);
    ui->tableLiquidity->setRowCount(0);

    resetTableWidgetsSettings(false, true, true, true);

    QSqlQuery q1;
    QString s1;
    s1.append("SELECT * FROM ");
    s1.append(TableNameTransaction);
    s1.append(" WHERE Year = ");
    s1.append(QString::number(iYear));
    if (strMonth == "All") {
        s1.append(" ORDER BY Month, Day, Hour, Minute");
    } else {
        s1.append(" and Month = ");
        s1.append(QString::number(iMonth));
        s1.append(" ORDER BY Day, Hour, Minute");
    }
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();

    float wholeIncome = 0.0;
    float wholeExpense = 0.0;
    float wholeSurplus = 0.0;

    while (q1.next()) {

        TransactionItem curItem;
        curItem.Type            = q1.value(0).toString();
        curItem.CategoryMid     = q1.value(1).toString();
        curItem.CategorySmall   = q1.value(2).toString();
        curItem.Year            = q1.value(3).toInt();
        curItem.Month           = q1.value(4).toInt();
        curItem.Day             = q1.value(5).toInt();
        curItem.Hour            = q1.value(6).toInt();
        curItem.Minute          = q1.value(7).toInt();
        curItem.Sum             = q1.value(8).toDouble();
        curItem.FromAccount     = q1.value(9).toString();
        curItem.ToAccount       = q1.value(10).toString();
        curItem.Detail          = q1.value(11).toString();
        curItem.InsertTime      = q1.value(12).toString();

        if (curItem.Type == g_Income) {
            wholeIncome += curItem.Sum;

            ui->tableIncome->insertRow(0);
            int ithRow = 0;
            int ithColume = 0;

            QTableWidgetItem* pItem0 = new QTableWidgetItem(YMDHM2yyyymmddhhmm(curItem.Year, curItem.Month, curItem.Day, curItem.Hour, curItem.Minute));
            ui->tableIncome->setItem(ithRow, ithColume, pItem0);
            ithColume++;

            QString jointCategory;
            jointCategory.append(curItem.CategoryMid);
            jointCategory.append(CategorySeparator);
            jointCategory.append(curItem.CategorySmall);
            QTableWidgetItem* pItem1 = new QTableWidgetItem(jointCategory);
            ui->tableIncome->setItem(ithRow, ithColume, pItem1);
            ithColume++;

            QTableWidgetItem* pItem2 = new QTableWidgetItem(getMoneyFormNumber(curItem.Sum));
            pItem2->setTextAlignment(0x82);
            ui->tableIncome->setItem(ithRow, ithColume, pItem2);
            ithColume++;

            QTableWidgetItem* pItem3 = new QTableWidgetItem(curItem.ToAccount);
            ui->tableIncome->setItem(ithRow, ithColume, pItem3);
            ithColume++;

            QTableWidgetItem* pItem4 = new QTableWidgetItem(curItem.Detail);
            ui->tableIncome->setItem(ithRow, ithColume, pItem4);
        } else if (curItem.Type == g_Expense) {
            wholeExpense += curItem.Sum;

            ui->tableExpense->insertRow(0);
            int ithRow = 0;
            int ithColume = 0;

            QTableWidgetItem* pItem0 = new QTableWidgetItem(YMDHM2yyyymmddhhmm(curItem.Year, curItem.Month, curItem.Day, curItem.Hour, curItem.Minute));
            ui->tableExpense->setItem(ithRow, ithColume, pItem0);
            ithColume++;

            QString jointCategory;
            jointCategory.append(curItem.CategoryMid);
            jointCategory.append(CategorySeparator);
            jointCategory.append(curItem.CategorySmall);
            QTableWidgetItem* pItem1 = new QTableWidgetItem(jointCategory);
            ui->tableExpense->setItem(ithRow, ithColume, pItem1);
            ithColume++;

            QTableWidgetItem* pItem2 = new QTableWidgetItem(getMoneyFormNumber(curItem.Sum));
            pItem2->setTextAlignment(0x82);
            ui->tableExpense->setItem(ithRow, ithColume, pItem2);
            ithColume++;

            QTableWidgetItem* pItem3 = new QTableWidgetItem(curItem.FromAccount);
            ui->tableExpense->setItem(ithRow, ithColume, pItem3);
            ithColume++;

            QTableWidgetItem* pItem4 = new QTableWidgetItem(curItem.Detail);
            ui->tableExpense->setItem(ithRow, ithColume, pItem4);
        } else if (curItem.Type == g_Liquidity) {
            ui->tableLiquidity->insertRow(0);
            int ithRow = 0;
            int ithColume = 0;

            QTableWidgetItem* pItem0 = new QTableWidgetItem(YMDHM2yyyymmddhhmm(curItem.Year, curItem.Month, curItem.Day, curItem.Hour, curItem.Minute));
            ui->tableLiquidity->setItem(ithRow, ithColume, pItem0);
            ithColume++;

            QTableWidgetItem* pItem1 = new QTableWidgetItem(curItem.FromAccount);
            ui->tableLiquidity->setItem(ithRow, ithColume, pItem1);
            ithColume++;

            QTableWidgetItem* pItem2 = new QTableWidgetItem(getMoneyFormNumber(curItem.Sum));
            pItem2->setTextAlignment(0x82);
            ui->tableLiquidity->setItem(ithRow, ithColume, pItem2);
            ithColume++;

            QTableWidgetItem* pItem3 = new QTableWidgetItem(curItem.ToAccount);
            ui->tableLiquidity->setItem(ithRow, ithColume, pItem3);
            ithColume++;

            QTableWidgetItem* pItem4 = new QTableWidgetItem(curItem.Detail);
            ui->tableLiquidity->setItem(ithRow, ithColume, pItem4);
        } else {
            assert(0);
        }
    }

    resizeTableWidgetIncomeExpenseLiquidity();

    wholeSurplus = wholeIncome - wholeExpense;

    if (strMonth != "All") {
        ui->label_7->setText("Current Month Sum :");
    } else {
        ui->label_7->setText("Current Year Sum :");
    }
    ui->label_9->setText(getMoneyFormNumber(wholeIncome));
    ui->label_11->setText(getMoneyFormNumber(wholeExpense));
    ui->label_13->setText(getMoneyFormNumber(wholeSurplus));
}

void ABMainWindow::showCategoryData(int iYear, QString strMonth)
{
    int iMonth = -1;
    if (strMonth != "All") {
        iMonth = strMonth.toInt();
        if (iMonth <= 0 || iMonth > 12) {
            return;
        }
    }

    initStatisticsTree();

    QSqlQuery q1;
    QString s1;
    s1.append("SELECT Type, CategoryMid, CategorySmall, Sum FROM ");
    s1.append(TableNameTransaction);
    s1.append(" WHERE Year = ");
    s1.append(QString::number(iYear));
    if (strMonth == "All") {
        s1.append(" ORDER BY Type, CategoryMid, CategorySmall");
    } else {
        s1.append(" AND Month = ");
        s1.append(QString::number(iMonth));
        s1.append(" ORDER BY Type, CategoryMid, CategorySmall");
    }
    if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();
    while (q1.next()) {
        QString bigType     = q1.value(0).toString();
        QString midType     = q1.value(1).toString();
        QString smallType   = q1.value(2).toString();
        float   sum         = q1.value(3).toDouble();

        if (bigType == g_Liquidity) {
            if (midType == g_Default && smallType == g_Default)
                continue;
            else
                assert(0);
        }

        QTreeWidgetItem* pSmallItem = searchItemInStatisticsTree(bigType, midType, smallType);
        if (pSmallItem == 0) {
            continue;
        }
//        pSmallItem->setTextAlignment(1, 0x82);
        pSmallItem->setText(1, getMoneyFormNumber(pSmallItem->text(1).toDouble() + sum));

        QTreeWidgetItem* pMidItem = pSmallItem->parent();
//        pMidItem->setTextAlignment(1, 0x82);
        pMidItem->setText(1, getMoneyFormNumber(pMidItem->text(1).toDouble() + sum));

//        QTreeWidgetItem* pBigItem = pMidItem->parent();
//        pBigItem->setText(1, getMoneyFormNumber(pBigItem->text(1).toDouble() + sum));
    }
}

void ABMainWindow::showAccountData(QDateTime dt)
{
    ui->tableAccount->setRowCount(0);
    resetTableWidgetsSettings(true, false, false, false);

    float wholeSurplus = 0.0;

    QStringList sl = getAllAccountSurplusByDateTime(dt);
    for (int i = 0; i < sl.count(); i++) {
        QString str = sl.at(i);
        QStringList slSplit = str.split(CategorySeparator);
        QString strName = slSplit.at(0);
        float fSurplus = slSplit.at(1).toDouble();

        wholeSurplus += fSurplus;

        ui->tableAccount->insertRow(0);
        int ithRow = 0;
        int ithColume = 0;

        QTableWidgetItem* pItem0 = new QTableWidgetItem(strName);
        ui->tableAccount->setItem(ithRow, ithColume, pItem0);
        ithColume++;

        QTableWidgetItem* pItem1 = new QTableWidgetItem(getMoneyFormNumber(fSurplus));
        pItem1->setTextAlignment(0x82);
        ui->tableAccount->setItem(ithRow, ithColume, pItem1);

        if (strName == g_Cash || strName.contains("Wage")) {
            pItem0->setTextColor(Qt::red);
            pItem1->setTextColor(Qt::red);
        }
    }

    resizeTableWidgetAccount();

    ui->labelAllMySurplus->setText(getMoneyFormNumber(wholeSurplus));
}

void ABMainWindow::resetTableWidgetsSettings(bool bTableAccount,
                                             bool btableIncome,
                                             bool btableExpense,
                                             bool btableLiquidity)
{
    /// 设置表头内容
    /// TODO : 为什么需要重新设置一遍........

    if (bTableAccount) {
        QStringList sl;
        sl.append("Account");
        sl.append("Surplus");
        ui->tableAccount->setColumnCount(sl.count());
        ui->tableAccount->setHorizontalHeaderLabels(sl);
    }
    if (btableIncome) {
        QStringList sl;
        sl.append("Date and Time");
        sl.append("Category");
        sl.append("Sum");
        sl.append("Account");
        sl.append("Detail");
        ui->tableIncome->setColumnCount(sl.count());
        ui->tableIncome->setHorizontalHeaderLabels(sl);
    }
    if (btableExpense) {
        QStringList sl;
        sl.append("Date and Time");
        sl.append("Category");
        sl.append("Sum");
        sl.append("Account");
        sl.append("Detail");
        ui->tableExpense->setColumnCount(sl.count());
        ui->tableExpense->setHorizontalHeaderLabels(sl);
    }
    if (btableLiquidity) {
        QStringList sl;
        sl.append("Date and Time");
        sl.append("From");
        sl.append("Sum");
        sl.append("To");
        sl.append("Detail");
        ui->tableLiquidity->setColumnCount(sl.count());
        ui->tableLiquidity->setHorizontalHeaderLabels(sl);
    }
}

QTreeWidgetItem* ABMainWindow::searchItemInStatisticsTree(QString bigType, QString midType, QString smallType)
{
    QTreeWidgetItem* pBigTypeItem = 0;
    if (bigType == g_Income) {
        pBigTypeItem = ui->treeStatistics->topLevelItem(0);
    } else if (bigType == g_Expense) {
        pBigTypeItem = ui->treeStatistics->topLevelItem(1);
    } else {
        return pBigTypeItem;
    }

    if (pBigTypeItem == 0)
        return 0;

    QTreeWidgetItem* pMidTypeItem = 0;
    for (int i = 0; i < pBigTypeItem->childCount(); i++) {
        pMidTypeItem = pBigTypeItem->child(i);
        if (pMidTypeItem->text(0) == midType)
            break;
    }
    if (pMidTypeItem == 0)
        return 0;

    QTreeWidgetItem* pSmallTypeItem = 0;
    for (int i = 0; i < pMidTypeItem->childCount(); i++) {
        pSmallTypeItem = pMidTypeItem->child(i);
        if (pSmallTypeItem->text(0) == smallType)
            break;
    }
    return pSmallTypeItem;
}

void ABMainWindow::resizeTableWidgetAccount()
{
    ui->tableAccount->resizeColumnsToContents();
    ui->tableAccount->resizeRowsToContents();
}

void ABMainWindow::resizeTableWidgetIncomeExpenseLiquidity()
{
    ui->tableIncome->resizeColumnsToContents();
    ui->tableIncome->resizeRowsToContents();

    ui->tableExpense->resizeColumnsToContents();
    ui->tableExpense->resizeRowsToContents();

    ui->tableLiquidity->resizeColumnsToContents();
    ui->tableLiquidity->resizeRowsToContents();
}

void ABMainWindow::resizeTreeStatistics()
{
    for (int i = 0; i < ui->treeStatistics->columnCount(); i++) {
        ui->treeStatistics->resizeColumnToContents(i);
    }
}

void ABMainWindow::backupDatabaseFile(bool bManual)
{
    /// 判断默认db文件夹和默认db_backup文件夹是否存在
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

    QStringList sl = backupDir.entryList();
    for (int i = 0; i < sl.count();) {
        QString fileName = sl.at(i);
        if (isBackupDatabaseFile(fileName)) {
            i++;
        } else {
            if (fileName.endsWith(".db")) {
                /// 删除.db结尾但是文件名不符合备份文件规范的文件
                QString strFileName = g_WorkDir + g_BackupDir + sl.at(i);
                QFile::remove(strFileName);
            }
            sl.removeAt(i);
        }
    }

    if (sl.count() >= 5) {
        for (int i = 0; i < sl.count() - 4; i++) {
            /// 删除多余的备份文件
            QString strOldestName = g_WorkDir + g_BackupDir + sl.at(i);
            QFile::remove(strOldestName);
        }
    }

    /// 创建新的备份文件
    QString strNewName = QString(g_WorkDir + g_BackupDir + QString("defaultDatabase") + getDatabaseFileNameDateAndTime() + QString(".db"));
    bool bCopyDone = QFile::copy(m_strDatabaseName, strNewName);

    /// 根据创建是否成功，弹出对话框
    if (bManual) {
        if (bCopyDone) {
            QString msg;
            msg.append("Database file backup succeed! Backup file name is\n");
            msg.append(strNewName);
            QMessageBox::information(this, "Succeed!", msg);
        } else {
            QString msg;
            msg.append("Database file backup failed!");
            QMessageBox::critical(this, "Failed!", msg);
        }
    }
}

void ABMainWindow::exportTransactionsAsTextFile(bool bNotice)
{
    extern QString g_WorkDir;
    QString initDir = g_WorkDir + g_BackupDir;

    QString strFilename = QFileDialog::getSaveFileName(0,
                                                       "Save as",
                                                       initDir,
                                                       QString("*.txt"));

    if (!strFilename.isEmpty()) {
        QStringList transactions = transactionList(/*beginYear, beginMonth, beginDay, beginHour, beginMinute,
                                                   endYear, endMonth, endDay, endHour, endMinute*/);

        bool bAddLineSeparator = false;
        QString sep;
        if (bAddLineSeparator) {
            int maxLength = 0;
            for (int i = 0; i < transactions.count(); i++) {
                int iLength = lengthOfStr(transactions.at(i));
                if (maxLength < iLength) {
                    maxLength = iLength;
                }
            }
            sep.fill('-', maxLength);
        }

        QFile f(strFilename);
        f.open(QFile::WriteOnly);
        QTextStream ts(&f);
        ts << "Transaction count is : " << transactions.count() << "\n\n";

        for (int i = 0; i < transactions.count(); i++) {
            if (bAddLineSeparator) {
                ts << sep << "\n";
            }
            ts << transactions.at(i) << "\n";
        }
        f.close();
        if (bNotice) {
            QMessageBox::about(this,
                               "Succeed",
                               "Export text file done.");
        }
    }
}

void ABMainWindow::setNewPassword()
{
    ABInputPassword dlg(0);
    dlg.exec();
}

void ABMainWindow::slotMenuAction(QAction *action)
{
    if (action == ui->actionExit) {
        close();
    } else if (action == ui->actionResize_Columes_and_Rows) {
        slotResizeColumnsAndRow();
    } else if (action == ui->actionAbout_accountBook) {
        /// TODO : 完善
        QMessageBox::about(this, "About", "An account book small software, by Li Yiji.");
    } else if (action == ui->actionBackup_Data_File) {
        backupDatabaseFile(true);
    } else if (action == ui->actionExport_Data_As_Text_File) {
        exportTransactionsAsTextFile(true);
    } else if (action == ui->actionSet_Password) {
        setNewPassword();
    }
}

void ABMainWindow::slotChangeEditDeleteButtonEnable()
{
    if (ui->mainTabWidget->currentWidget()->objectName().contains("Statistics")) {
        ui->buttonEdit->setEnabled(false);
        ui->buttonDelete->setEnabled(false);
    } else if (ui->mainTabWidget->currentWidget()->objectName().contains(g_Income)) {
        QList<QTableWidgetItem*> list = ui->tableIncome->selectedItems();
        if (list.count()) {
            ui->buttonEdit->setEnabled(true);
            ui->buttonDelete->setEnabled(true);
        } else {
            ui->buttonEdit->setEnabled(false);
            ui->buttonDelete->setEnabled(false);
        }
    } else if (ui->mainTabWidget->currentWidget()->objectName().contains(g_Expense)) {
        QList<QTableWidgetItem*> list = ui->tableExpense->selectedItems();
        if (list.count()) {
            ui->buttonEdit->setEnabled(true);
            ui->buttonDelete->setEnabled(true);
        } else {
            ui->buttonEdit->setEnabled(false);
            ui->buttonDelete->setEnabled(false);
        }
    } else if (ui->mainTabWidget->currentWidget()->objectName().contains(g_Liquidity)) {
        QList<QTableWidgetItem*> list = ui->tableLiquidity->selectedItems();
        if (list.count()) {
            ui->buttonEdit->setEnabled(true);
            ui->buttonDelete->setEnabled(true);
        } else {
            ui->buttonEdit->setEnabled(false);
            ui->buttonDelete->setEnabled(false);
        }
    }
}

void ABMainWindow::slotChangeYearOrMonth()
{
    QString strYear = ui->comboBox->currentText();
    QString strMonth = ui->comboBox_2->currentText();
    bool bOk = false;
    int iYear = strYear.toInt(&bOk);
    if (bOk == false) {
        return;
    }
    loadData(iYear, strMonth);
}

void ABMainWindow::slotManageAccout()
{
    ABManageAccount dlg(this);
    dlg.exec();
}

void ABMainWindow::slotManageCategory()
{
    ABManageCategory dlg(this);
    dlg.exec();
}

void ABMainWindow::slotAddNewIncome()
{
    ABTransactionDetail dlg(Income, this);
    if (dlg.exec() == QDialog::Accepted) {
        TransactionItem item;
        item.Type           = dlg.getTypeStr();
        QStringList strCategory = dlg.m_strCategory.split(CategorySeparator);
        item.CategoryMid    = strCategory.at(0);
        item.CategorySmall  = strCategory.at(1);
        item.Year           = dlg.m_iYear;
        item.Month          = dlg.m_iMonth;
        item.Day            = dlg.m_iDay;
        item.Hour           = dlg.m_iHour;
        item.Minute         = dlg.m_iMinute;
        item.Sum            = dlg.m_fSum;
        item.FromAccount    = dlg.m_strFromAccount;
        item.ToAccount      = dlg.m_strToAccount;
        item.Detail         = dlg.m_strDetail;
        item.InsertTime     = getInsertTime();

        if (dlg.m_bNewCategory) {
            insertItemInCategory(item.Type,
                                 item.CategoryMid,
                                 item.CategorySmall,
                                 item.InsertTime);
        }

        if (dlg.m_bNewToAccount) {
            insertItemInAccount(dlg.m_strToAccount,
                                item.Year, item.Month, item.Day,
                                item.Hour, item.Minute,
                                item.InsertTime);
        }

        insertItemInTransaction(item.Type,
                                item.CategoryMid,
                                item.CategorySmall,
                                item.Year,
                                item.Month,
                                item.Day,
                                item.Hour,
                                item.Minute,
                                item.Sum,
                                item.FromAccount,
                                item.ToAccount,
                                item.Detail);

        loadData(ui->comboBox->currentText().toInt(), ui->comboBox_2->currentText());

        ui->mainTabWidget->setCurrentIndex(ui->mainTabWidget->indexOf(ui->tabIncome));
    }
}

void ABMainWindow::slotAddNewExpense()
{
    ABTransactionDetail dlg(Expense, this);
    if (dlg.exec() == QDialog::Accepted) {
        TransactionItem item;
        item.Type           = dlg.getTypeStr();
        QStringList strCategory = dlg.m_strCategory.split(CategorySeparator);
        item.CategoryMid    = strCategory.at(0);
        item.CategorySmall  = strCategory.at(1);
        item.Year           = dlg.m_iYear;
        item.Month          = dlg.m_iMonth;
        item.Day            = dlg.m_iDay;
        item.Hour           = dlg.m_iHour;
        item.Minute         = dlg.m_iMinute;
        item.Sum            = dlg.m_fSum;
        item.FromAccount    = dlg.m_strFromAccount;
        item.ToAccount      = dlg.m_strToAccount;
        item.Detail         = dlg.m_strDetail;
        item.InsertTime     = getInsertTime();

        if (dlg.m_bNewCategory) {
            insertItemInCategory(item.Type,
                                 item.CategoryMid,
                                 item.CategorySmall,
                                 item.InsertTime);
        }

        insertItemInTransaction(item.Type,
                                item.CategoryMid,
                                item.CategorySmall,
                                item.Year,
                                item.Month,
                                item.Day,
                                item.Hour,
                                item.Minute,
                                item.Sum,
                                item.FromAccount,
                                item.ToAccount,
                                item.Detail);

        loadData(ui->comboBox->currentText().toInt(), ui->comboBox_2->currentText());

        ui->mainTabWidget->setCurrentIndex(ui->mainTabWidget->indexOf(ui->tabExpense));
    }
}

void ABMainWindow::slotAddNewLiquidity()
{
    ABTransactionDetail dlg(Liquidity, this);
    if (dlg.exec() == QDialog::Accepted) {
        TransactionItem item;
        item.Type           = dlg.getTypeStr();
        QStringList strCategory = dlg.m_strCategory.split(CategorySeparator);
        item.CategoryMid    = strCategory.at(0);
        item.CategorySmall  = strCategory.at(1);
        item.Year           = dlg.m_iYear;
        item.Month          = dlg.m_iMonth;
        item.Day            = dlg.m_iDay;
        item.Hour           = dlg.m_iHour;
        item.Minute         = dlg.m_iMinute;
        item.Sum            = dlg.m_fSum;
        item.FromAccount    = dlg.m_strFromAccount;
        item.ToAccount      = dlg.m_strToAccount;
        item.Detail         = dlg.m_strDetail;
        item.InsertTime     = getInsertTime();

        if (dlg.m_bNewToAccount) {
            insertItemInAccount(dlg.m_strToAccount,
                                item.Year, item.Month, item.Day,
                                item.Hour, item.Minute,
                                item.InsertTime);
        }

        insertItemInTransaction(item.Type,
                                item.CategoryMid,
                                item.CategorySmall,
                                item.Year,
                                item.Month,
                                item.Day,
                                item.Hour,
                                item.Minute,
                                item.Sum,
                                item.FromAccount,
                                item.ToAccount,
                                item.Detail);

        loadData(ui->comboBox->currentText().toInt(), ui->comboBox_2->currentText());

        ui->mainTabWidget->setCurrentIndex(ui->mainTabWidget->indexOf(ui->tabLiquidity));
    }
}

void ABMainWindow::slotEditCurrentTransactionItem()
{
    bool bDataChanged = false;

    if (ui->mainTabWidget->currentWidget()->objectName().contains(g_Income)) {
        QList<QTableWidgetItem*> list = ui->tableIncome->selectedItems();
        if (list.count() <= 0) {
            return;
        }

        QString date = list.at(0)->text();
        QString c = list.at(1)->text();
        float sum = list.at(2)->text().toDouble();
        QString toAccount = list.at(3)->text();
        QString detail = list.at(4)->text();

        int year, month, day, hour, minute;
        yyyymmddhhmm2YMDHM(date, year, month, day, hour, minute);
        QDate dt = QDate(year, month, day);
        QTime tm = QTime(hour, minute);

        ABCategory ctg;
        ctg.bigType = g_Income;
        ctg.midType = c.split(CategorySeparator).at(0);
        ctg.smallType = c.split(CategorySeparator).at(1);

        ABTransactionDetail dlg(Income);
        dlg.setInitData(dt, tm, ctg, "", toAccount, sum, detail);
        if (dlg.exec() == QDialog::Accepted) {
            /// 数据库中删掉原来的Item，添加新的Item，对Account/Category/Transaction三个Table进行更新
            if (dlg.isDataChanged()) {
                bDataChanged = true;
                deleteItemInTransaction(ctg.bigType,
                                        ctg.midType,
                                        ctg.smallType,
                                        year,
                                        month,
                                        day,
                                        hour,
                                        minute,
                                        sum,
                                        g_Income,
                                        toAccount,
                                        detail);

                QStringList sl = dlg.m_strCategory.split(CategorySeparator);
                insertItemInTransaction(dlg.getTypeStr(),
                                        sl.at(0),
                                        sl.at(1),
                                        dlg.m_iYear,
                                        dlg.m_iMonth,
                                        dlg.m_iDay,
                                        dlg.m_iHour,
                                        dlg.m_iMinute,
                                        dlg.m_fSum,
                                        dlg.m_strFromAccount,
                                        dlg.m_strToAccount,
                                        dlg.m_strDetail,
                                        getInsertTime());
            }
        }
    } else if (ui->mainTabWidget->currentWidget()->objectName().contains(g_Expense)) {
        QList<QTableWidgetItem*> list = ui->tableExpense->selectedItems();
        if (list.count() <= 0) {
            return;
        }

        QString date = list.at(0)->text();
        QString c = list.at(1)->text();
        float sum = list.at(2)->text().toDouble();
        QString fromAccount = list.at(3)->text();
        QString detail = list.at(4)->text();

        int year, month, day, hour, minute;
        yyyymmddhhmm2YMDHM(date, year, month, day, hour, minute);
        QDate dt = QDate(year, month, day);
        QTime tm = QTime(hour, minute);

        ABCategory ctg;
        ctg.bigType = g_Expense;
        ctg.midType = c.split(CategorySeparator).at(0);
        ctg.smallType = c.split(CategorySeparator).at(1);

        ABTransactionDetail dlg(Expense);
        dlg.setInitData(dt, tm, ctg, fromAccount, "", sum, detail);
        if (dlg.exec() == QDialog::Accepted) {
            /// 数据库中删掉原来的Item，添加新的Item，对Account/Category/Transaction三个Table进行更新
            if (dlg.isDataChanged()) {
                bDataChanged = true;
                deleteItemInTransaction(ctg.bigType,
                                        ctg.midType,
                                        ctg.smallType,
                                        year,
                                        month,
                                        day,
                                        hour,
                                        minute,
                                        sum,
                                        fromAccount,
                                        g_Expense,
                                        detail);

                QStringList sl = dlg.m_strCategory.split(CategorySeparator);
                insertItemInTransaction(dlg.getTypeStr(),
                                        sl.at(0),
                                        sl.at(1),
                                        dlg.m_iYear,
                                        dlg.m_iMonth,
                                        dlg.m_iDay,
                                        dlg.m_iHour,
                                        dlg.m_iMinute,
                                        dlg.m_fSum,
                                        dlg.m_strFromAccount,
                                        dlg.m_strToAccount,
                                        dlg.m_strDetail,
                                        getInsertTime());
            }
        }
    } else if (ui->mainTabWidget->currentWidget()->objectName().contains(g_Liquidity)) {
        QList<QTableWidgetItem*> list = ui->tableLiquidity->selectedItems();
        if (list.count() <= 0) {
            return;
        }

        QString date = list.at(0)->text();
        QString fromAccount = list.at(1)->text();
        float sum = list.at(2)->text().toDouble();
        QString toAccount = list.at(3)->text();
        QString detail = list.at(4)->text();

        int year, month, day, hour, minute;
        yyyymmddhhmm2YMDHM(date, year, month, day, hour, minute);
        QDate dt = QDate(year, month, day);
        QTime tm = QTime(hour, minute);

        ABCategory ctg;
        ctg.bigType = g_Liquidity;
        ctg.midType = g_Default;
        ctg.smallType = g_Default;

        ABTransactionDetail dlg(Liquidity);
        dlg.setInitData(dt, tm, ctg, fromAccount, toAccount, sum, detail);
        if (dlg.exec() == QDialog::Accepted) {
            /// 数据库中删掉原来的Item，添加新的Item，对Account/Category/Transaction三个Table进行更新
            if (dlg.isDataChanged()) {
                bDataChanged = true;
                deleteItemInTransaction(ctg.bigType,
                                        ctg.midType,
                                        ctg.smallType,
                                        year,
                                        month,
                                        day,
                                        hour,
                                        minute,
                                        sum,
                                        fromAccount,
                                        toAccount,
                                        detail);

                QStringList sl = dlg.m_strCategory.split(CategorySeparator);
                insertItemInTransaction(dlg.getTypeStr(),
                                        sl.at(0),
                                        sl.at(1),
                                        dlg.m_iYear,
                                        dlg.m_iMonth,
                                        dlg.m_iDay,
                                        dlg.m_iHour,
                                        dlg.m_iMinute,
                                        dlg.m_fSum,
                                        dlg.m_strFromAccount,
                                        dlg.m_strToAccount,
                                        dlg.m_strDetail,
                                        getInsertTime());
            }
        }
    } else {
        assert(0);
    }

    if (bDataChanged) {
        loadData(ui->comboBox->currentText().toInt(), ui->comboBox_2->currentText());
    }
}

void ABMainWindow::slotDeleteCurrentTransactionItem()
{
    if (ui->mainTabWidget->currentWidget()->objectName().contains(g_Income)) {
        QList<QTableWidgetItem*> list = ui->tableIncome->selectedItems();
        if (list.count() <= 0) {
            return;
        }
        if (QMessageBox::warning(this, "Warning!", "Are you sure to delete this transaction?",
                                 QMessageBox::Ok, QMessageBox::Cancel) != QMessageBox::Ok) {
            return;
        }

        QString date = list.at(0)->text();
        QString c = list.at(1)->text();
        float sum = list.at(2)->text().toDouble();
        QString toAccount = list.at(3)->text();
        QString detail = list.at(4)->text();

        int year, month, day, hour, minute;
        yyyymmddhhmm2YMDHM(date, year, month, day, hour, minute);

        ABCategory ctg;
        ctg.bigType = g_Income;
        ctg.midType = c.split(CategorySeparator).at(0);
        ctg.smallType = c.split(CategorySeparator).at(1);

        deleteItemInTransaction(ctg.bigType,
                                ctg.midType,
                                ctg.smallType,
                                year,
                                month,
                                day,
                                hour,
                                minute,
                                sum,
                                "",
                                toAccount,
                                detail);

    } else if (ui->mainTabWidget->currentWidget()->objectName().contains(g_Expense)) {
        QList<QTableWidgetItem*> list = ui->tableExpense->selectedItems();
        if (list.count() <= 0) {
            return;
        }
        if (QMessageBox::warning(this, "Warning!", "Are you sure to delete this transaction?",
                                 QMessageBox::Ok, QMessageBox::Cancel) != QMessageBox::Ok) {
            return;
        }

        QString date = list.at(0)->text();
        QString c = list.at(1)->text();
        float sum = list.at(2)->text().toDouble();
        QString fromAccount = list.at(3)->text();
        QString detail = list.at(4)->text();

        int year, month, day, hour, minute;
        yyyymmddhhmm2YMDHM(date, year, month, day, hour, minute);

        ABCategory ctg;
        ctg.bigType = g_Expense;
        ctg.midType = c.split(CategorySeparator).at(0);
        ctg.smallType = c.split(CategorySeparator).at(1);

        deleteItemInTransaction(ctg.bigType,
                                ctg.midType,
                                ctg.smallType,
                                year,
                                month,
                                day,
                                hour,
                                minute,
                                sum,
                                fromAccount,
                                "",
                                detail);

    } else if (ui->mainTabWidget->currentWidget()->objectName().contains(g_Liquidity)) {
        QList<QTableWidgetItem*> list = ui->tableLiquidity->selectedItems();
        if (list.count() <= 0) {
            return;
        }
        if (QMessageBox::warning(this, "Warning!", "Are you sure to delete this transaction?",
                                 QMessageBox::Ok, QMessageBox::Cancel) != QMessageBox::Ok) {
            return;
        }

        QString date = list.at(0)->text();
        QString fromAccount = list.at(1)->text();
        float sum = list.at(2)->text().toDouble();
        QString toAccount = list.at(3)->text();
        QString detail = list.at(4)->text();

        int year, month, day, hour, minute;
        yyyymmddhhmm2YMDHM(date, year, month, day, hour, minute);

        ABCategory ctg;
        ctg.bigType = g_Liquidity;
        ctg.midType = g_Default;
        ctg.smallType = g_Default;

        deleteItemInTransaction(ctg.bigType,
                                ctg.midType,
                                ctg.smallType,
                                year,
                                month,
                                day,
                                hour,
                                minute,
                                sum,
                                fromAccount,
                                toAccount,
                                detail);

    } else {
        assert(0);
    }

    loadData(ui->comboBox->currentText().toInt(), ui->comboBox_2->currentText());
}

void ABMainWindow::slotResizeColumnsAndRow()
{
    resizeTableWidgetAccount();
    resizeTableWidgetIncomeExpenseLiquidity();
    resizeTreeStatistics();
}

void ABMainWindow::slotLoadDataOfCurMonth()
{
    QDate curDate = QDate::currentDate();
    int iCurYear = curDate.year();
    int iCurMonth = curDate.month();
    QString strCurMonth = QString::number(iCurMonth);

    disconnect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotChangeYearOrMonth()));
    disconnect(ui->comboBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(slotChangeYearOrMonth()));

    ui->comboBox->setCurrentIndex(ui->comboBox->count() - 1);
    ui->comboBox_2->setCurrentIndex(iCurMonth);

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotChangeYearOrMonth()));
    connect(ui->comboBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(slotChangeYearOrMonth()));

    loadData(iCurYear, strCurMonth);
}

void ABMainWindow::slotShowBigTypeInTree()
{
    for (int i = 0; i < ui->treeStatistics->topLevelItemCount(); i++) {
        QTreeWidgetItem* pItem = ui->treeStatistics->topLevelItem(i);
        pItem->setExpanded(false);
    }

    resizeTreeStatistics();
}

void ABMainWindow::slotShowMidTypeInTree()
{
    for (int i = 0; i < ui->treeStatistics->topLevelItemCount(); i++) {
        QTreeWidgetItem* pItemBig = ui->treeStatistics->topLevelItem(i);
        pItemBig->setExpanded(true);
        for (int j = 0; j < pItemBig->childCount(); j++) {
            QTreeWidgetItem* pItemMid = pItemBig->child(j);
            pItemMid->setExpanded(false);
        }
    }

    resizeTreeStatistics();
}

void ABMainWindow::slotShowSmallTypeInTree()
{
    for (int i = 0; i < ui->treeStatistics->topLevelItemCount(); i++) {
        QTreeWidgetItem* pItemBig = ui->treeStatistics->topLevelItem(i);
        pItemBig->setExpanded(true);
        for (int j = 0; j < pItemBig->childCount(); j++) {
            QTreeWidgetItem* pItemMid = pItemBig->child(j);
            pItemMid->setExpanded(true);
        }
    }

    resizeTreeStatistics();
}

void ABMainWindow::slotDoubleClickTableTransaction(QTableWidgetItem*)
{
    slotEditCurrentTransactionItem();
}

void ABMainWindow::slotReloadCurTimeAccountStatus()
{
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

void ABMainWindow::slotReloadAccountStatusByDataTime(QDateTime dt)
{
    showAccountData(dt);
}
