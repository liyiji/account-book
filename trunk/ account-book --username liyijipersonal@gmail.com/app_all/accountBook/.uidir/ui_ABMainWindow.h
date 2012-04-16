/********************************************************************************
** Form generated from reading UI file 'ABMainWindow.ui'
**
** Created: Mon Apr 16 19:07:38 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABMAINWINDOW_H
#define UI_ABMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_accountBookMainWindow
{
public:
    QAction *actionBackup_Data_File;
    QAction *actionSet_Password;
    QAction *actionImport_another_data_file;
    QAction *actionExport_Data_As_Text_File;
    QAction *actionExit;
    QAction *actionOptions;
    QAction *actionResize_Columes_and_Rows;
    QAction *actionAbout_accountBook;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonBackToToday;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QFrame *line;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *buttonBackToCurTime;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *labelAllMySurplus;
    QTableWidget *tableAccount;
    QPushButton *buttonResize;
    QFrame *line_2;
    QLabel *labelBanner;
    QPushButton *buttonNewIncome;
    QPushButton *buttonNewExpense;
    QPushButton *buttonNewLiquidity;
    QPushButton *buttonEdit;
    QPushButton *buttonDelete;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *buttonManageAccount;
    QPushButton *buttonManageCategory;
    QTabWidget *mainTabWidget;
    QWidget *tabStatistics;
    QGridLayout *gridLayout_4;
    QTreeWidget *treeStatistics;
    QPushButton *buttonShowBigType;
    QPushButton *buttonShowSmallType;
    QPushButton *buttonShowMidType;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tabIncome;
    QGridLayout *gridLayout_6;
    QTableWidget *tableIncome;
    QWidget *tabExpense;
    QGridLayout *gridLayout_9;
    QTableWidget *tableExpense;
    QWidget *tabLiquidity;
    QGridLayout *gridLayout_7;
    QTableWidget *tableLiquidity;
    QWidget *tabDebt;
    QGridLayout *gridLayout_5;
    QLabel *label_14;
    QSpacerItem *verticalSpacer_2;
    QWidget *tabCalculate;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_12;
    QLabel *label_5;
    QPushButton *buttonPlus;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_16;
    QPushButton *buttonMinus;
    QLabel *label_17;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label_18;
    QPushButton *buttonMultiply;
    QLabel *label_19;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLabel *label_20;
    QPushButton *buttonDivide;
    QLabel *label_21;
    QLineEdit *lineEdit_10;
    QLabel *label_30;
    QLabel *label_35;
    QLabel *label_40;
    QLabel *label_45;
    QLabel *label_50;
    QLabel *label_34;
    QLabel *label_38;
    QLabel *label_43;
    QLabel *label_48;
    QLabel *label_53;
    QLabel *label_33;
    QLabel *label_36;
    QLabel *label_41;
    QLabel *label_46;
    QLabel *label_51;
    QLabel *label_32;
    QLabel *label_37;
    QLabel *label_42;
    QLabel *label_47;
    QLabel *label_52;
    QLabel *label_31;
    QLabel *label_39;
    QLabel *label_44;
    QLabel *label_49;
    QLabel *label_54;
    QLineEdit *lineEdit_9;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuImport_Export;
    QMenu *menuTool;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *accountBookMainWindow)
    {
        if (accountBookMainWindow->objectName().isEmpty())
            accountBookMainWindow->setObjectName(QString::fromUtf8("accountBookMainWindow"));
        accountBookMainWindow->resize(819, 640);
        accountBookMainWindow->setMinimumSize(QSize(0, 640));
        actionBackup_Data_File = new QAction(accountBookMainWindow);
        actionBackup_Data_File->setObjectName(QString::fromUtf8("actionBackup_Data_File"));
        actionSet_Password = new QAction(accountBookMainWindow);
        actionSet_Password->setObjectName(QString::fromUtf8("actionSet_Password"));
        actionImport_another_data_file = new QAction(accountBookMainWindow);
        actionImport_another_data_file->setObjectName(QString::fromUtf8("actionImport_another_data_file"));
        actionExport_Data_As_Text_File = new QAction(accountBookMainWindow);
        actionExport_Data_As_Text_File->setObjectName(QString::fromUtf8("actionExport_Data_As_Text_File"));
        actionExit = new QAction(accountBookMainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionOptions = new QAction(accountBookMainWindow);
        actionOptions->setObjectName(QString::fromUtf8("actionOptions"));
        actionResize_Columes_and_Rows = new QAction(accountBookMainWindow);
        actionResize_Columes_and_Rows->setObjectName(QString::fromUtf8("actionResize_Columes_and_Rows"));
        actionAbout_accountBook = new QAction(accountBookMainWindow);
        actionAbout_accountBook->setObjectName(QString::fromUtf8("actionAbout_accountBook"));
        centralwidget = new QWidget(accountBookMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(228, 0));
        groupBox_2->setMaximumSize(QSize(228, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout_2->addWidget(comboBox_2);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(172, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBackToToday = new QPushButton(groupBox_2);
        buttonBackToToday->setObjectName(QString::fromUtf8("buttonBackToToday"));

        horizontalLayout->addWidget(buttonBackToToday);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(119, 119, 119, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_9->setPalette(palette);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 0, 1, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_11->setPalette(palette1);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 1, 1, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 2, 0, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_13->setPalette(palette2);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        gridLayout_3->addLayout(verticalLayout_2, 2, 0, 1, 1);

        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 3, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 6, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        dateTimeEdit = new QDateTimeEdit(groupBox_2);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        horizontalLayout_4->addWidget(dateTimeEdit);

        buttonBackToCurTime = new QPushButton(groupBox_2);
        buttonBackToCurTime->setObjectName(QString::fromUtf8("buttonBackToCurTime"));

        horizontalLayout_4->addWidget(buttonBackToCurTime);


        gridLayout_3->addLayout(horizontalLayout_4, 7, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        labelAllMySurplus = new QLabel(groupBox_2);
        labelAllMySurplus->setObjectName(QString::fromUtf8("labelAllMySurplus"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        labelAllMySurplus->setPalette(palette3);
        labelAllMySurplus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(labelAllMySurplus);


        gridLayout_3->addLayout(horizontalLayout_3, 8, 0, 1, 1);

        tableAccount = new QTableWidget(groupBox_2);
        if (tableAccount->columnCount() < 2)
            tableAccount->setColumnCount(2);
        tableAccount->setObjectName(QString::fromUtf8("tableAccount"));
        tableAccount->setSortingEnabled(true);
        tableAccount->setColumnCount(2);

        gridLayout_3->addWidget(tableAccount, 9, 0, 1, 1);

        buttonResize = new QPushButton(groupBox_2);
        buttonResize->setObjectName(QString::fromUtf8("buttonResize"));

        gridLayout_3->addWidget(buttonResize, 10, 0, 1, 1);

        line_2 = new QFrame(groupBox_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 5, 0, 1, 1);

        labelBanner = new QLabel(groupBox_2);
        labelBanner->setObjectName(QString::fromUtf8("labelBanner"));
        labelBanner->setMinimumSize(QSize(0, 40));
        labelBanner->setMaximumSize(QSize(16777215, 40));

        gridLayout_3->addWidget(labelBanner, 4, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 2, 1);

        buttonNewIncome = new QPushButton(centralwidget);
        buttonNewIncome->setObjectName(QString::fromUtf8("buttonNewIncome"));

        gridLayout_2->addWidget(buttonNewIncome, 0, 1, 1, 1);

        buttonNewExpense = new QPushButton(centralwidget);
        buttonNewExpense->setObjectName(QString::fromUtf8("buttonNewExpense"));

        gridLayout_2->addWidget(buttonNewExpense, 0, 2, 1, 1);

        buttonNewLiquidity = new QPushButton(centralwidget);
        buttonNewLiquidity->setObjectName(QString::fromUtf8("buttonNewLiquidity"));

        gridLayout_2->addWidget(buttonNewLiquidity, 0, 3, 1, 1);

        buttonEdit = new QPushButton(centralwidget);
        buttonEdit->setObjectName(QString::fromUtf8("buttonEdit"));

        gridLayout_2->addWidget(buttonEdit, 0, 4, 1, 1);

        buttonDelete = new QPushButton(centralwidget);
        buttonDelete->setObjectName(QString::fromUtf8("buttonDelete"));

        gridLayout_2->addWidget(buttonDelete, 0, 5, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 6, 1, 1);

        buttonManageAccount = new QPushButton(centralwidget);
        buttonManageAccount->setObjectName(QString::fromUtf8("buttonManageAccount"));

        gridLayout_2->addWidget(buttonManageAccount, 0, 7, 1, 1);

        buttonManageCategory = new QPushButton(centralwidget);
        buttonManageCategory->setObjectName(QString::fromUtf8("buttonManageCategory"));

        gridLayout_2->addWidget(buttonManageCategory, 0, 8, 1, 1);

        mainTabWidget = new QTabWidget(centralwidget);
        mainTabWidget->setObjectName(QString::fromUtf8("mainTabWidget"));
        mainTabWidget->setMinimumSize(QSize(500, 0));
        tabStatistics = new QWidget();
        tabStatistics->setObjectName(QString::fromUtf8("tabStatistics"));
        gridLayout_4 = new QGridLayout(tabStatistics);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        treeStatistics = new QTreeWidget(tabStatistics);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(2, QString::fromUtf8("3"));
        __qtreewidgetitem->setText(1, QString::fromUtf8("2"));
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeStatistics->setHeaderItem(__qtreewidgetitem);
        treeStatistics->setObjectName(QString::fromUtf8("treeStatistics"));
        treeStatistics->setColumnCount(3);

        gridLayout_4->addWidget(treeStatistics, 0, 0, 5, 5);

        buttonShowBigType = new QPushButton(tabStatistics);
        buttonShowBigType->setObjectName(QString::fromUtf8("buttonShowBigType"));

        gridLayout_4->addWidget(buttonShowBigType, 5, 0, 1, 1);

        buttonShowSmallType = new QPushButton(tabStatistics);
        buttonShowSmallType->setObjectName(QString::fromUtf8("buttonShowSmallType"));

        gridLayout_4->addWidget(buttonShowSmallType, 5, 2, 1, 1);

        buttonShowMidType = new QPushButton(tabStatistics);
        buttonShowMidType->setObjectName(QString::fromUtf8("buttonShowMidType"));

        gridLayout_4->addWidget(buttonShowMidType, 5, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 5, 3, 1, 1);

        mainTabWidget->addTab(tabStatistics, QString());
        tabIncome = new QWidget();
        tabIncome->setObjectName(QString::fromUtf8("tabIncome"));
        gridLayout_6 = new QGridLayout(tabIncome);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        tableIncome = new QTableWidget(tabIncome);
        tableIncome->setObjectName(QString::fromUtf8("tableIncome"));
        tableIncome->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableIncome->verticalHeader()->setVisible(false);

        gridLayout_6->addWidget(tableIncome, 0, 0, 1, 2);

        mainTabWidget->addTab(tabIncome, QString());
        tabExpense = new QWidget();
        tabExpense->setObjectName(QString::fromUtf8("tabExpense"));
        gridLayout_9 = new QGridLayout(tabExpense);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        tableExpense = new QTableWidget(tabExpense);
        tableExpense->setObjectName(QString::fromUtf8("tableExpense"));
        tableExpense->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableExpense->verticalHeader()->setVisible(false);

        gridLayout_9->addWidget(tableExpense, 0, 0, 1, 1);

        mainTabWidget->addTab(tabExpense, QString());
        tabLiquidity = new QWidget();
        tabLiquidity->setObjectName(QString::fromUtf8("tabLiquidity"));
        gridLayout_7 = new QGridLayout(tabLiquidity);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        tableLiquidity = new QTableWidget(tabLiquidity);
        tableLiquidity->setObjectName(QString::fromUtf8("tableLiquidity"));
        tableLiquidity->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableLiquidity->verticalHeader()->setVisible(false);

        gridLayout_7->addWidget(tableLiquidity, 0, 0, 1, 1);

        mainTabWidget->addTab(tabLiquidity, QString());
        tabDebt = new QWidget();
        tabDebt->setObjectName(QString::fromUtf8("tabDebt"));
        gridLayout_5 = new QGridLayout(tabDebt);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_14 = new QLabel(tabDebt);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_5->addWidget(label_14, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 1, 0, 1, 1);

        mainTabWidget->addTab(tabDebt, QString());
        tabCalculate = new QWidget();
        tabCalculate->setObjectName(QString::fromUtf8("tabCalculate"));
        gridLayout_13 = new QGridLayout(tabCalculate);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        label_5 = new QLabel(tabCalculate);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_12->addWidget(label_5, 0, 4, 2, 1);

        buttonPlus = new QPushButton(tabCalculate);
        buttonPlus->setObjectName(QString::fromUtf8("buttonPlus"));

        gridLayout_12->addWidget(buttonPlus, 0, 6, 2, 1);

        label_6 = new QLabel(tabCalculate);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_12->addWidget(label_6, 0, 7, 2, 1);

        lineEdit = new QLineEdit(tabCalculate);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_12->addWidget(lineEdit, 0, 0, 2, 4);

        lineEdit_2 = new QLineEdit(tabCalculate);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_12->addWidget(lineEdit_2, 0, 5, 2, 1);

        label_16 = new QLabel(tabCalculate);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_12->addWidget(label_16, 2, 4, 2, 1);

        buttonMinus = new QPushButton(tabCalculate);
        buttonMinus->setObjectName(QString::fromUtf8("buttonMinus"));

        gridLayout_12->addWidget(buttonMinus, 2, 6, 2, 1);

        label_17 = new QLabel(tabCalculate);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_12->addWidget(label_17, 2, 7, 2, 1);

        lineEdit_5 = new QLineEdit(tabCalculate);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout_12->addWidget(lineEdit_5, 2, 0, 2, 4);

        lineEdit_6 = new QLineEdit(tabCalculate);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout_12->addWidget(lineEdit_6, 2, 5, 2, 1);

        label_18 = new QLabel(tabCalculate);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_12->addWidget(label_18, 4, 4, 2, 1);

        buttonMultiply = new QPushButton(tabCalculate);
        buttonMultiply->setObjectName(QString::fromUtf8("buttonMultiply"));

        gridLayout_12->addWidget(buttonMultiply, 4, 6, 2, 1);

        label_19 = new QLabel(tabCalculate);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_12->addWidget(label_19, 4, 7, 2, 1);

        lineEdit_7 = new QLineEdit(tabCalculate);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        gridLayout_12->addWidget(lineEdit_7, 4, 0, 2, 4);

        lineEdit_8 = new QLineEdit(tabCalculate);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        gridLayout_12->addWidget(lineEdit_8, 4, 5, 2, 1);

        label_20 = new QLabel(tabCalculate);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_12->addWidget(label_20, 6, 4, 2, 1);

        buttonDivide = new QPushButton(tabCalculate);
        buttonDivide->setObjectName(QString::fromUtf8("buttonDivide"));

        gridLayout_12->addWidget(buttonDivide, 6, 6, 2, 1);

        label_21 = new QLabel(tabCalculate);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_12->addWidget(label_21, 6, 7, 2, 1);

        lineEdit_10 = new QLineEdit(tabCalculate);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        gridLayout_12->addWidget(lineEdit_10, 6, 5, 2, 1);

        label_30 = new QLabel(tabCalculate);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_12->addWidget(label_30, 8, 0, 1, 4);

        label_35 = new QLabel(tabCalculate);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout_12->addWidget(label_35, 9, 0, 1, 4);

        label_40 = new QLabel(tabCalculate);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout_12->addWidget(label_40, 10, 0, 1, 4);

        label_45 = new QLabel(tabCalculate);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        gridLayout_12->addWidget(label_45, 11, 0, 1, 4);

        label_50 = new QLabel(tabCalculate);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        gridLayout_12->addWidget(label_50, 12, 0, 1, 4);

        label_34 = new QLabel(tabCalculate);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout_12->addWidget(label_34, 8, 7, 1, 1);

        label_38 = new QLabel(tabCalculate);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        gridLayout_12->addWidget(label_38, 9, 7, 1, 1);

        label_43 = new QLabel(tabCalculate);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        gridLayout_12->addWidget(label_43, 10, 7, 1, 1);

        label_48 = new QLabel(tabCalculate);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        gridLayout_12->addWidget(label_48, 11, 7, 1, 1);

        label_53 = new QLabel(tabCalculate);
        label_53->setObjectName(QString::fromUtf8("label_53"));

        gridLayout_12->addWidget(label_53, 12, 7, 1, 1);

        label_33 = new QLabel(tabCalculate);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout_12->addWidget(label_33, 8, 6, 1, 1);

        label_36 = new QLabel(tabCalculate);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_12->addWidget(label_36, 9, 6, 1, 1);

        label_41 = new QLabel(tabCalculate);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        gridLayout_12->addWidget(label_41, 10, 6, 1, 1);

        label_46 = new QLabel(tabCalculate);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        gridLayout_12->addWidget(label_46, 11, 6, 1, 1);

        label_51 = new QLabel(tabCalculate);
        label_51->setObjectName(QString::fromUtf8("label_51"));

        gridLayout_12->addWidget(label_51, 12, 6, 1, 1);

        label_32 = new QLabel(tabCalculate);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_12->addWidget(label_32, 8, 5, 1, 1);

        label_37 = new QLabel(tabCalculate);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        gridLayout_12->addWidget(label_37, 9, 5, 1, 1);

        label_42 = new QLabel(tabCalculate);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        gridLayout_12->addWidget(label_42, 10, 5, 1, 1);

        label_47 = new QLabel(tabCalculate);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        gridLayout_12->addWidget(label_47, 11, 5, 1, 1);

        label_52 = new QLabel(tabCalculate);
        label_52->setObjectName(QString::fromUtf8("label_52"));

        gridLayout_12->addWidget(label_52, 12, 5, 1, 1);

        label_31 = new QLabel(tabCalculate);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_12->addWidget(label_31, 8, 4, 1, 1);

        label_39 = new QLabel(tabCalculate);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        gridLayout_12->addWidget(label_39, 9, 4, 1, 1);

        label_44 = new QLabel(tabCalculate);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        gridLayout_12->addWidget(label_44, 10, 4, 1, 1);

        label_49 = new QLabel(tabCalculate);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        gridLayout_12->addWidget(label_49, 11, 4, 1, 1);

        label_54 = new QLabel(tabCalculate);
        label_54->setObjectName(QString::fromUtf8("label_54"));

        gridLayout_12->addWidget(label_54, 12, 4, 1, 1);

        lineEdit_9 = new QLineEdit(tabCalculate);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        gridLayout_12->addWidget(lineEdit_9, 6, 0, 2, 4);


        gridLayout_13->addLayout(gridLayout_12, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_13->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        mainTabWidget->addTab(tabCalculate, QString());

        gridLayout_2->addWidget(mainTabWidget, 1, 1, 1, 8);

        accountBookMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(accountBookMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 819, 19));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuImport_Export = new QMenu(menuFile);
        menuImport_Export->setObjectName(QString::fromUtf8("menuImport_Export"));
        menuTool = new QMenu(menubar);
        menuTool->setObjectName(QString::fromUtf8("menuTool"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        accountBookMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(accountBookMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        accountBookMainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuTool->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionBackup_Data_File);
        menuFile->addAction(actionSet_Password);
        menuFile->addSeparator();
        menuFile->addAction(menuImport_Export->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuImport_Export->addAction(actionImport_another_data_file);
        menuImport_Export->addAction(actionExport_Data_As_Text_File);
        menuTool->addAction(actionOptions);
        menuTool->addAction(actionResize_Columes_and_Rows);
        menuHelp->addAction(actionAbout_accountBook);

        retranslateUi(accountBookMainWindow);

        mainTabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(accountBookMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *accountBookMainWindow)
    {
        accountBookMainWindow->setWindowTitle(QApplication::translate("accountBookMainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionBackup_Data_File->setText(QApplication::translate("accountBookMainWindow", "Backup Data File", 0, QApplication::UnicodeUTF8));
        actionSet_Password->setText(QApplication::translate("accountBookMainWindow", "Set Password", 0, QApplication::UnicodeUTF8));
        actionImport_another_data_file->setText(QApplication::translate("accountBookMainWindow", "Import Another Data File", 0, QApplication::UnicodeUTF8));
        actionExport_Data_As_Text_File->setText(QApplication::translate("accountBookMainWindow", "Export Data As Text File", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("accountBookMainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionOptions->setText(QApplication::translate("accountBookMainWindow", "Options", 0, QApplication::UnicodeUTF8));
        actionResize_Columes_and_Rows->setText(QApplication::translate("accountBookMainWindow", "Resize Columes and Rows", 0, QApplication::UnicodeUTF8));
        actionAbout_accountBook->setText(QApplication::translate("accountBookMainWindow", "About accountBook", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("accountBookMainWindow", "Year :", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("accountBookMainWindow", "1988", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("accountBookMainWindow", "Month :", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("accountBookMainWindow", "All", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("accountBookMainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("accountBookMainWindow", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("accountBookMainWindow", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("accountBookMainWindow", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("accountBookMainWindow", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("accountBookMainWindow", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("accountBookMainWindow", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("accountBookMainWindow", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("accountBookMainWindow", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("accountBookMainWindow", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("accountBookMainWindow", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("accountBookMainWindow", "12", 0, QApplication::UnicodeUTF8)
        );
        buttonBackToToday->setText(QApplication::translate("accountBookMainWindow", "Today", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("accountBookMainWindow", "Current Month Sum :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("accountBookMainWindow", "Income :", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("accountBookMainWindow", "Income Count", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("accountBookMainWindow", "Expense :", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("accountBookMainWindow", "Expense Count", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("accountBookMainWindow", "Surplus :", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("accountBookMainWindow", "Surplus Count", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("accountBookMainWindow", "Account Status (at time below):", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("accountBookMainWindow", "yyyy-MM-dd HH:mm", 0, QApplication::UnicodeUTF8));
        buttonBackToCurTime->setText(QApplication::translate("accountBookMainWindow", "Back", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("accountBookMainWindow", "All My Surplus :", 0, QApplication::UnicodeUTF8));
        labelAllMySurplus->setText(QApplication::translate("accountBookMainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        buttonResize->setText(QApplication::translate("accountBookMainWindow", "Resize Columns and Rows", 0, QApplication::UnicodeUTF8));
        labelBanner->setText(QApplication::translate("accountBookMainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        buttonNewIncome->setText(QApplication::translate("accountBookMainWindow", "Add\n"
"Income", 0, QApplication::UnicodeUTF8));
        buttonNewExpense->setText(QApplication::translate("accountBookMainWindow", "Add\n"
"Expense", 0, QApplication::UnicodeUTF8));
        buttonNewLiquidity->setText(QApplication::translate("accountBookMainWindow", "Add\n"
"Liquidity", 0, QApplication::UnicodeUTF8));
        buttonEdit->setText(QApplication::translate("accountBookMainWindow", "Edit\n"
"Transaction", 0, QApplication::UnicodeUTF8));
        buttonDelete->setText(QApplication::translate("accountBookMainWindow", "Delete\n"
"Transaction", 0, QApplication::UnicodeUTF8));
        buttonManageAccount->setText(QApplication::translate("accountBookMainWindow", "Manage\n"
"Account", 0, QApplication::UnicodeUTF8));
        buttonManageCategory->setText(QApplication::translate("accountBookMainWindow", "Manage\n"
"Category", 0, QApplication::UnicodeUTF8));
        buttonShowBigType->setText(QApplication::translate("accountBookMainWindow", "Summary", 0, QApplication::UnicodeUTF8));
        buttonShowSmallType->setText(QApplication::translate("accountBookMainWindow", "Detail", 0, QApplication::UnicodeUTF8));
        buttonShowMidType->setText(QApplication::translate("accountBookMainWindow", "General", 0, QApplication::UnicodeUTF8));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tabStatistics), QApplication::translate("accountBookMainWindow", "Page", 0, QApplication::UnicodeUTF8));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tabIncome), QApplication::translate("accountBookMainWindow", "Tab 2", 0, QApplication::UnicodeUTF8));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tabExpense), QApplication::translate("accountBookMainWindow", "Page", 0, QApplication::UnicodeUTF8));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tabLiquidity), QApplication::translate("accountBookMainWindow", "Page", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("accountBookMainWindow", "This page isn't finished.\n"
"\n"
"Please wait.", 0, QApplication::UnicodeUTF8));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tabDebt), QApplication::translate("accountBookMainWindow", "Page", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("accountBookMainWindow", "+", 0, QApplication::UnicodeUTF8));
        buttonPlus->setText(QApplication::translate("accountBookMainWindow", "=", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("accountBookMainWindow", "-", 0, QApplication::UnicodeUTF8));
        buttonMinus->setText(QApplication::translate("accountBookMainWindow", "=", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("accountBookMainWindow", "*", 0, QApplication::UnicodeUTF8));
        buttonMultiply->setText(QApplication::translate("accountBookMainWindow", "=", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("accountBookMainWindow", "/", 0, QApplication::UnicodeUTF8));
        buttonDivide->setText(QApplication::translate("accountBookMainWindow", "=", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_50->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_43->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_48->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_53->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("accountBookMainWindow", "=", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("accountBookMainWindow", "=", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("accountBookMainWindow", "=", 0, QApplication::UnicodeUTF8));
        label_46->setText(QApplication::translate("accountBookMainWindow", "=", 0, QApplication::UnicodeUTF8));
        label_51->setText(QApplication::translate("accountBookMainWindow", "=", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_47->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_52->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_44->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_49->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        label_54->setText(QApplication::translate("accountBookMainWindow", "N/A", 0, QApplication::UnicodeUTF8));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tabCalculate), QApplication::translate("accountBookMainWindow", "Page", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("accountBookMainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuImport_Export->setTitle(QApplication::translate("accountBookMainWindow", "Import / Export", 0, QApplication::UnicodeUTF8));
        menuTool->setTitle(QApplication::translate("accountBookMainWindow", "Tool", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("accountBookMainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class accountBookMainWindow: public Ui_accountBookMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABMAINWINDOW_H
