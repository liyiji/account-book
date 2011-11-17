
#include <QDebug>
#include <QDate>
#include <QTime>

#include "ABManageAccount.h"
#include "ABSqlQuery.h"
#include "ABMainWindow.h"

ABManageAccount::ABManageAccount(ABMainWindow *parent) : QDialog(parent)
{
    m_pMainWindow = parent;

    ui = new Ui_ABManageAccountDialog;
    ui->setupUi(this);

    initUi();
    initConnection();
    initAccountData();

    resize(1, 1);
}

ABManageAccount::~ABManageAccount()
{
    if (ui) {
        delete ui;
        ui = 0;
    }
}

void ABManageAccount::initUi()
{
    setWindowTitle("Manage Account");

    ui->labelErrMsg->setVisible(false);

    ui->radioAdd->setChecked(false);
    ui->radioDelete->setChecked(false);
    ui->radioRename->setChecked(false);

    ui->comboDelete->setEnabled(false);
    ui->comboEdit->setEnabled(false);

    ui->label->setEnabled(false);
    ui->label_2->setEnabled(false);
    ui->label_3->setEnabled(false);
    ui->label_4->setEnabled(false);
    ui->label_6->setEnabled(false);

    ui->lineNew->setEnabled(false);
    ui->lineEdit->setEnabled(false);
}

void ABManageAccount::initConnection()
{
    connect(ui->buttonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(slotClickButtonBox(QAbstractButton*)));

    connect(ui->radioAdd, SIGNAL(toggled(bool)), ui->label_3, SLOT(setEnabled(bool)));
    connect(ui->radioAdd, SIGNAL(toggled(bool)), ui->lineNew, SLOT(setEnabled(bool)));

    connect(ui->radioRename, SIGNAL(toggled(bool)), ui->comboEdit, SLOT(setEnabled(bool)));
    connect(ui->radioRename, SIGNAL(toggled(bool)), ui->lineEdit, SLOT(setEnabled(bool)));
    connect(ui->radioRename, SIGNAL(toggled(bool)), ui->label, SLOT(setEnabled(bool)));
    connect(ui->radioRename, SIGNAL(toggled(bool)), ui->label_2, SLOT(setEnabled(bool)));

    connect(ui->radioDelete, SIGNAL(toggled(bool)), ui->comboDelete, SLOT(setEnabled(bool)));
    connect(ui->radioDelete, SIGNAL(toggled(bool)), ui->label_4, SLOT(setEnabled(bool)));
    connect(ui->radioDelete, SIGNAL(toggled(bool)), ui->label_6, SLOT(setEnabled(bool)));
}

void ABManageAccount::initAccountData()
{
    ui->comboEdit->clear();
    ui->comboDelete->clear();
    ui->lineEdit->clear();
    ui->lineNew->clear();

    ui->comboEdit->addItem("");
    ui->comboEdit->addItems(accountNameList());

    ui->comboDelete->addItem("");
    ui->comboDelete->addItems(surplus0AccountList());
}

bool ABManageAccount::apply()
{
    ui->labelErrMsg->setVisible(false);

    QStringList errMsgList;
    {
        if (ui->radioAdd->isChecked()) {
            if (ui->lineNew->text().isEmpty()) {
                errMsgList.append("Error : New account name is empty.");
            } else {
                QStringList names = accountNameList();
                for (int i = 0; i < names.count(); i++) {
                    if (names.at(i) == ui->lineNew->text()) {
                        QString str = QString("Error : Account \"") + ui->lineNew->text() + QString("\" exists.");
                        errMsgList.append(str);
                        break;
                    }
                }
            }
        } else if (ui->radioRename->isChecked()) {
            if (ui->comboEdit->currentText().isEmpty()) {
                errMsgList.append("Error : Please choose a existed account.");
            } else if (ui->comboEdit->currentText() == g_Cash) {
                errMsgList.append("Error : \"Cash\" account cannot be renamed.");
            } else {
                if (ui->lineEdit->text().isEmpty()) {
                    errMsgList.append("Error : New account name is empty.");
                } else {
                    QStringList names = accountNameList();
                    for (int i = 0; i < names.count(); i++) {
                        if (names.at(i) == ui->lineEdit->text()) {
                            QString str = QString("Error : Account \"") + ui->lineEdit->text() + QString("\" exists.");
                            errMsgList.append(str);
                            break;
                        }
                    }
                }
            }
        } else if (ui->radioDelete->isChecked()) {
            if (ui->comboDelete->currentText().isEmpty()) {
                errMsgList.append("Error : Please choose a existed account. Surplus of the account must be 0.");
            } else if (ui->comboDelete->currentText() == g_Cash) {
                errMsgList.append("Error : \"Cash\" account cannot be deleted.");
            }
        } else {
            /// do nothing
        }
    }

    if (errMsgList.count() == 0) {
        if (ui->radioAdd->isChecked()) {
            insertItemInAccount(ui->lineNew->text(),
                                QDate::currentDate().year(),
                                QDate::currentDate().month(),
                                QDate::currentDate().day(),
                                QTime::currentTime().hour(),
                                QTime::currentTime().minute());
        } else if (ui->radioRename->isChecked()) {
            renameAccount(ui->comboEdit->currentText(), ui->lineEdit->text());
        } else if (ui->radioDelete->isChecked()) {
            deleteItemInAccount(ui->comboDelete->currentText());
        } else {
            /// do nothing
        }

        initAccountData();

        m_pMainWindow->loadDataByUi();

        return true;
    } else {
        QString errMsg = errMsgList.join("\n");
        ui->labelErrMsg->setText(errMsg);
        ui->labelErrMsg->setVisible(true);

        return false;
    }
}
void ABManageAccount::accept()
{
    if (apply()) {
        QDialog::accept();
    }
}

void ABManageAccount::slotClickButtonBox(QAbstractButton *btn)
{
    if (btn == (QAbstractButton *)(ui->buttonBox->button(QDialogButtonBox::Apply))) {
        apply();
    }
}
