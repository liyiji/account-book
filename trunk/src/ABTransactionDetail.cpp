
#include <cassert>

#include <QDebug>
#include <QSqlQuery>

#include "ABTransactionDetail.h"
#include "ABFunction.h"

ABTransactionDetail::ABTransactionDetail(TransactionType dialogType, QWidget *parent) : QDialog(parent)
{
    ui = new Ui_ABTransactionDetailDialog;
    ui->setupUi(this);

    if (dialogType == Income || dialogType == Expense || dialogType == Liquidity)
        m_dialogType = dialogType;
    else
        return;

    slotChangeDataSpinValue();
    initUiByType(m_dialogType);

    m_iYear   = ui->dateEdit->date().year();
    m_iMonth  = ui->dateEdit->date().month();
    m_iDay    = ui->dateEdit->date().day();
    m_iHour   = ui->timeEdit->time().hour();
    m_iMinute = ui->timeEdit->time().minute();
    m_fSum    = ui->doubleSpinBox->value();
    if (m_dialogType == Income) {
        m_strCategory       = ui->comboBox->currentText();
        m_strFromAccount    = g_Income;
        m_strToAccount      = ui->comboBox_2->currentText();
    } else if (m_dialogType == Expense) {
        m_strCategory       = ui->comboBox->currentText();
        m_strFromAccount    = ui->comboBox_2->currentText();
        m_strToAccount      = g_Expense;
    } else if (m_dialogType == Liquidity) {
        m_strCategory       = g_Default + CategorySeparator + g_Default;
        m_strFromAccount    = ui->comboBox->currentText();
        m_strToAccount      = ui->comboBox_2->currentText();
    }
    m_strDetail         = ui->lineEdit->text();
    m_bNewCategory      = false;
    m_bNewToAccount     = false;
    m_bDataChanged      = false;

    initConnection();

    resize(1, 1);
}

ABTransactionDetail::~ABTransactionDetail()
{
    if (ui) {
        delete ui;
        ui = 0;
    }
}

void ABTransactionDetail::setInitData(QDate date,
                                     QTime time,
                                     ABCategory category,
                                     QString fromAccount,
                                     QString toAccount,
                                     float sum,
                                     QString detail)
{
    ui->dateEdit->setDate(date);
    ui->calendarWidget->setSelectedDate(date);
    ui->timeEdit->setTime(time);
    ui->doubleSpinBox->setValue(sum);
    ui->lineEdit->setText(detail);

    if (m_dialogType == Income) {
        QString strCategory = category.midType + CategorySeparator + category.smallType;;
        for (int i = 0; i < ui->comboBox->count(); i++) {
            if (ui->comboBox->itemText(i) == strCategory) {
                ui->comboBox->setCurrentIndex(i);
                break;
            }
        }

        for (int i = 0; i < ui->comboBox_2->count(); i++) {
            if (ui->comboBox_2->itemText(i) == toAccount) {
                ui->comboBox_2->setCurrentIndex(i);
                break;
            }
        }
    } else if (m_dialogType == Expense) {
        QString strCategory = category.midType + CategorySeparator + category.smallType;
        for (int i = 0; i < ui->comboBox->count(); i++) {
            if (ui->comboBox->itemText(i) == strCategory) {
                ui->comboBox->setCurrentIndex(i);
                break;
            }
        }

        for (int i = 0; i < ui->comboBox_2->count(); i++) {
            if (ui->comboBox_2->itemText(i) == fromAccount) {
                ui->comboBox_2->setCurrentIndex(i);
                break;
            }
        }
    } else if (m_dialogType == Liquidity) {
        for (int i = 0; i < ui->comboBox->count(); i++) {
            if (ui->comboBox->itemText(i) == fromAccount) {
                ui->comboBox->setCurrentIndex(i);
                break;
            }
        }

        for (int i = 0; i < ui->comboBox_2->count(); i++) {
            if (ui->comboBox_2->itemText(i) == toAccount) {
                ui->comboBox_2->setCurrentIndex(i);
                break;
            }
        }
    } else {
        assert(0);
    }

    m_bDataChanged = false;
}


QString ABTransactionDetail::getTypeStr()
{
    if (m_dialogType == Income) {
        return g_Income;
    } else if (m_dialogType == Expense) {
        return g_Expense;
    } else if (m_dialogType == Liquidity) {
        return g_Liquidity;
    }

    assert(0);
    return QString();
}

TransactionType ABTransactionDetail::getType()
{
    return m_dialogType;
}

bool ABTransactionDetail::isDataChanged()
{
    return m_bDataChanged;
}

void ABTransactionDetail::initUiByType(TransactionType dialogType)
{
    ui->lineEditNewCategory->setVisible(ui->checkNewCategory->isChecked());
    ui->label_7->setVisible(ui->checkNewCategory->isChecked());
    ui->comboBoxParentCategory->setVisible(ui->checkNewCategory->isChecked());
    ui->comboBox->setEnabled(!ui->checkNewCategory->isChecked());

    ui->lineEditNewAccount->setVisible(ui->checkBoxNewAccount->isChecked());
    ui->comboBox_2->setEnabled(!ui->checkBoxNewAccount->isChecked());

    if (dialogType == Income) {
        setWindowTitle(QString("Add New ") + g_Income);
        ui->label_5->setText("To Account :");

        /// 初始化 Category 列表
        QSqlQuery q1;
        QString s1;
        s1.append("SELECT MidType, SmallType FROM ");
        s1.append(TableNameCategory);
        s1.append(" WHERE BigType = '");
        s1.append(g_Income);
        s1.append("' ORDER BY MidType, SmallType");
        if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();

        while (q1.next()) {
            QString strMid = q1.value(0).toString();
            QString strSmall=  q1.value(1).toString();
            ui->comboBox->addItem(strMid + CategorySeparator + strSmall);
        }

        /// 初始化 parent Category 列表
        QSqlQuery q2;
        QString s2;
        s2.append("SELECT DISTINCT MidType FROM ");
        s2.append(TableNameCategory);
        s2.append(" WHERE BigType = '");
        s2.append(g_Income);
        s2.append("' ORDER BY MidType");
        if (!q2.exec(s2)) warnMsgDatabaseOperationFailed();

        ui->comboBoxParentCategory->addItem("");
        while (q2.next()) {
            QString strMid = q2.value(0).toString();
            ui->comboBoxParentCategory->addItem(strMid);
        }

        /// 初始化 To Account 列表
        QSqlQuery q3;
        QString s3;
        s3.append("SELECT Name FROM ");
        s3.append(TableNameAccount);
        s3.append(" ORDER BY Name");
        if (!q3.exec(s3)) warnMsgDatabaseOperationFailed();

        while (q3.next()) {
            QString accountName = q3.value(0).toString();
            ui->comboBox_2->addItem(accountName);
        }
    } else if (dialogType == Expense) {
        setWindowTitle(QString("Add New ") + g_Expense);
        ui->label_5->setText("From Account :");
        ui->checkBoxNewAccount->setVisible(false);

        /// 初始化 Category 列表
        QSqlQuery q1;
        QString s1;
        s1.append("SELECT MidType, SmallType FROM ");
        s1.append(TableNameCategory);
        s1.append(" WHERE BigType = '");
        s1.append(g_Expense);
        s1.append("' ORDER BY MidType, SmallType");
        if (!q1.exec(s1)) warnMsgDatabaseOperationFailed();

        while (q1.next()) {
            QString strMid = q1.value(0).toString();
            QString strSmall=  q1.value(1).toString();
            ui->comboBox->addItem(strMid + CategorySeparator + strSmall);
        }

        /// 初始化 parent Category 列表
        QSqlQuery q2;
        QString s2;
        s2.append("SELECT DISTINCT MidType FROM ");
        s2.append(TableNameCategory);
        s2.append(" WHERE BigType = '");
        s2.append(g_Expense);
        s2.append("' ORDER BY MidType");
        if (!q2.exec(s2)) warnMsgDatabaseOperationFailed();

        ui->comboBoxParentCategory->addItem("");
        while (q2.next()) {
            QString strMid = q2.value(0).toString();
            ui->comboBoxParentCategory->addItem(strMid);
        }

        /// 初始化 From Account 列表
        QSqlQuery q3;
        QString s3;
        s3.append("SELECT Name FROM ");
        s3.append(TableNameAccount);
        s3.append(" ORDER BY Name");
        if (!q3.exec(s3)) warnMsgDatabaseOperationFailed();

        while (q3.next()) {
            QString accountName = q3.value(0).toString();
            ui->comboBox_2->addItem(accountName);
        }
    } else if (dialogType == Liquidity) {
        setWindowTitle(QString("Add New ") + g_Liquidity);
        ui->label_3->setText("From Account :");
        ui->label_5->setText("To Account :");
        ui->checkNewCategory->setVisible(false);

        /// 初始化 From Account 列表
        QSqlQuery q2;
        QString s2;
        s2.append("SELECT Name FROM ");
        s2.append(TableNameAccount);
        s2.append(" ORDER BY Name");
        if (!q2.exec(s2)) warnMsgDatabaseOperationFailed();

        while (q2.next()) {
            QString accountName = q2.value(0).toString();
            ui->comboBox->addItem(accountName);
        }

        /// 初始化 To Account 列表
        QSqlQuery q3;
        QString s3;
        s3.append("SELECT Name FROM ");
        s3.append(TableNameAccount);
        s3.append(" ORDER BY Name");
        if (!q3.exec(s3)) warnMsgDatabaseOperationFailed();

        while (q3.next()) {
            QString accountName = q3.value(0).toString();
            ui->comboBox_2->addItem(accountName);
        }
    } else {
        assert(0);
    }

    ui->labelErrorMessage->setVisible(false);
}

void ABTransactionDetail::initConnection()
{
    m_bDataChanged = false;

    connect(ui->calendarWidget, SIGNAL(selectionChanged()), this, SLOT(slotChangeDataSpinValue()));
    connect(ui->calendarWidget, SIGNAL(currentPageChanged(int,int)), this, SLOT(slotCalenderWidgetPageChange()));
    connect(ui->pushButton, SIGNAL(released()), this, SLOT(slotSelectCalenderWidget()));

    connect(ui->dateEdit, SIGNAL(dateChanged(QDate)), this, SLOT(slotChangeDate(QDate)));
    connect(ui->timeEdit, SIGNAL(timeChanged(QTime)), this, SLOT(slotChangeTime(QTime)));
    connect(ui->doubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(slotChangeSum(double)));
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(slotChangeDetail(QString)));

    if (m_dialogType == Income) {
        connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotChangeCategory()));
        connect(ui->comboBox_2, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotChangeToAccount()));
    } else if (m_dialogType == Expense) {
        connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotChangeCategory()));
        connect(ui->comboBox_2, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotChangeFromAccount(QString)));
    } else if (m_dialogType == Liquidity) {
        connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotChangeFromAccount(QString)));
        connect(ui->comboBox_2, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotChangeToAccount()));
    }

    connect(ui->lineEditNewCategory, SIGNAL(textChanged(QString)), this, SLOT(slotChangeCategory()));
    connect(ui->checkNewCategory, SIGNAL(toggled(bool)), this, SLOT(slotChangeCategory()));
    connect(ui->comboBoxParentCategory,SIGNAL(currentIndexChanged(QString)), this, SLOT(slotChangeCategory()));

    connect(ui->lineEditNewAccount, SIGNAL(textChanged(QString)), this, SLOT(slotChangeToAccount()));
    connect(ui->checkBoxNewAccount, SIGNAL(toggled(bool)), this, SLOT(slotChangeToAccount()));
}

void ABTransactionDetail::accept()
{
    bool bFoundError = false;
    QStringList errMsgList;
    {
        /// 检查参数正确性
        if (m_fSum == 0.0) {
            errMsgList.append("Error : Sum is 0.");
            bFoundError = true;
        }
        if (m_iYear > QDate::currentDate().year()) {
            errMsgList.append("Error : Transaction occurs in future.");
            bFoundError = true;
        } else if (m_iMonth > QDate::currentDate().month()) {
            errMsgList.append("Error : Transaction occurs in future.");
            bFoundError = true;
        } else if (m_iDay > QDate::currentDate().day()) {
            errMsgList.append("Error : Transaction occurs in future.");
            bFoundError = true;
        } else if (m_iHour > QTime::currentTime().hour()) {
            errMsgList.append("Error : Transaction occurs in future.");
            bFoundError = true;
        } else if (m_iMinute > QTime::currentTime().minute()) {
            errMsgList.append("Error : Transaction occurs in future.");
            bFoundError = true;
        }
        if (m_dialogType == Income) {
            if (m_bNewCategory) {
                for (int i = 0; i < ui->comboBox->count(); i++) {
                    if (ui->comboBox->itemText(i) == m_strCategory) {
                        errMsgList.append("Error : Category already exists.");
                        bFoundError = true;
                        break;
                    }
                }

                if (ui->lineEditNewCategory->text().contains("->")) {
                    errMsgList.append("Error : Category name should not contains '->'.");
                    bFoundError = true;
                }
            }
            if (m_bNewToAccount) {
                for (int i = 0; i < ui->comboBox_2->count(); i++) {
                    if (ui->comboBox_2->itemText(i) == m_strToAccount) {
                        errMsgList.append("Error : Account already exists.");
                        bFoundError = true;
                        break;
                    }
                }
            }
        } else if (m_dialogType == Expense) {
            if (m_bNewCategory) {
                for (int i = 0; i < ui->comboBox->count(); i++) {
                    if (ui->comboBox->itemText(i) == m_strCategory) {
                        errMsgList.append("Error : Category already exists.");
                        bFoundError = true;
                        break;
                    }
                }

                if (ui->lineEditNewCategory->text().contains("->")) {
                    errMsgList.append("Error : Category name should not contains '->'.");
                    bFoundError = true;
                }
            }
        } else if (m_dialogType == Liquidity) {
            if (m_bNewToAccount) {
                for (int i = 0; i < ui->comboBox_2->count(); i++) {
                    if (ui->comboBox_2->itemText(i) == m_strToAccount) {
                        errMsgList.append("Error : Account already exists.");
                        bFoundError = true;
                        break;
                    }
                }
            }

            if (m_strFromAccount == m_strToAccount) {
                errMsgList.append("Error : Money liquid to the same account.");
                bFoundError = true;
            }
        } else {
            assert(0);
        }
    }

    if (bFoundError == false) {
        QDialog::accept();
    } else {
        QString errMsg = errMsgList.join("\n");
        ui->labelErrorMessage->setText(errMsg);
        ui->labelErrorMessage->setVisible(true);
    }
}

void ABTransactionDetail::slotChangeDataSpinValue()
{
    ui->dateEdit->setDate(ui->calendarWidget->selectedDate());
    m_bDataChanged = true;
}

void ABTransactionDetail::slotSelectCalenderWidget()
{
    QDate curDate = QDate::currentDate();
    ui->calendarWidget->setCurrentPage(curDate.year(), curDate.month());
    ui->calendarWidget->setSelectedDate(curDate);
    m_bDataChanged = true;
}

void ABTransactionDetail::slotCalenderWidgetPageChange()
{
    QDate dateOfDateEdit = ui->dateEdit->date();

    int changedDay = dateOfDateEdit.day();
    if (changedDay > getMaxDateInMonth(ui->calendarWidget->yearShown(), ui->calendarWidget->monthShown())) {
        changedDay = getMaxDateInMonth(ui->calendarWidget->yearShown(), ui->calendarWidget->monthShown());
    }

    dateOfDateEdit.setYMD(ui->calendarWidget->yearShown(), ui->calendarWidget->monthShown(), changedDay);
    ui->dateEdit->setDate(dateOfDateEdit);
    m_bDataChanged = true;
}

void ABTransactionDetail::slotChangeDate(QDate dt)
{
    m_iYear  = dt.year();
    m_iMonth = dt.month();
    m_iDay   = dt.day();
    m_bDataChanged = true;
}

void ABTransactionDetail::slotChangeTime(QTime tm)
{
    m_iHour = tm.hour();
    m_iMinute = tm.minute();
    m_bDataChanged = true;
}

void ABTransactionDetail::slotChangeSum(double sum)
{
    m_fSum = sum;
    m_bDataChanged = true;
}

void ABTransactionDetail::slotChangeDetail(QString dt)
{
    m_strDetail = dt;
    m_bDataChanged = true;
}

void ABTransactionDetail::slotChangeCategory()
{
    if (ui->checkNewCategory->isChecked() && ui->lineEditNewCategory->text().isEmpty() == false) {
        if (ui->comboBoxParentCategory->currentText().isEmpty()) {
            m_strCategory = ui->lineEditNewCategory->text() + CategorySeparator + g_Default;
        } else {
            m_strCategory = ui->comboBoxParentCategory->currentText() + CategorySeparator + ui->lineEditNewCategory->text();
        }
        m_bNewCategory = true;
    } else {
        m_strCategory = ui->comboBox->currentText();
        m_bNewCategory = false;
    }
    m_bDataChanged = true;
}

void ABTransactionDetail::slotChangeFromAccount(QString acFrom)
{
    m_strFromAccount = acFrom;
    m_bDataChanged = true;
}

void ABTransactionDetail::slotChangeToAccount()
{
    if (ui->checkBoxNewAccount->isChecked() && ui->lineEditNewAccount->text().isEmpty() == false) {
        m_strToAccount = ui->lineEditNewAccount->text();
        m_bNewToAccount = true;
    } else {
        m_strToAccount = ui->comboBox_2->currentText();
        m_bNewToAccount = false;
    }
    m_bDataChanged = true;
}
