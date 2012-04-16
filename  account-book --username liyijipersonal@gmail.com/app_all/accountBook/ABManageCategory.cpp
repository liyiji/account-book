
#include <cassert>

#include <QDebug>
#include <QMessageBox>

#include "ABManageCategory.h"
#include "ABSqlQuery.h"
#include "ABMainWindow.h"

ABManageCategory::ABManageCategory(ABMainWindow *parent) : QDialog(parent)
{
    m_pMainWindow = parent;

    ui = new Ui_ABManageCategoryDialog;
    ui->setupUi(this);

    initUi();
    initConnection();
    initCategoryData();

    {
        /// TODO :
//        ui->radioRename->setEnabled(false);
    }

    resize(1, 1);
}

ABManageCategory::~ABManageCategory()
{
    if (ui) {
        delete ui;
        ui = 0;
    }
}

void ABManageCategory::initUi()
{
    setWindowTitle("Manage Category");

    ui->labelErrMsg->setVisible(false);

    ui->radioNew->setChecked(false);
    ui->radioRename->setChecked(false);
    ui->radioDelete->setChecked(false);

    ui->comboNewBig->setEnabled(false);
    ui->comboNewMid->setEnabled(false);
    ui->comboRenameBig->setEnabled(false);
    ui->comboRenameMid->setEnabled(false);
    ui->comboRenameSmall->setEnabled(false);
    ui->comboDeleteBig->setEnabled(false);
    ui->comboDeleteMid->setEnabled(false);
    ui->comboDeleteSmall->setEnabled(false);

    ui->lineNewMid->setEnabled(false);
    ui->lineNewSmall->setEnabled(false);
    ui->lineRenameMid->setEnabled(false);
    ui->lineRenameSmall->setEnabled(false);

    ui->label->setEnabled(false);
    ui->label_2->setEnabled(false);
    ui->label_3->setEnabled(false);
    ui->label_4->setEnabled(false);
    ui->label_5->setEnabled(false);
    ui->label_6->setEnabled(false);
}

void ABManageCategory::initConnection()
{
    connect(ui->buttonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(slotClickButtonBox(QAbstractButton*)));

    connect(ui->radioNew, SIGNAL(toggled(bool)), ui->label, SLOT(setEnabled(bool)));
    connect(ui->radioNew, SIGNAL(toggled(bool)), ui->comboNewBig, SLOT(setEnabled(bool)));
    connect(ui->radioNew, SIGNAL(toggled(bool)), ui->comboNewMid, SLOT(setEnabled(bool)));
    connect(ui->radioNew, SIGNAL(toggled(bool)), ui->lineNewMid, SLOT(setEnabled(bool)));
    connect(ui->radioNew, SIGNAL(toggled(bool)), ui->lineNewSmall, SLOT(setEnabled(bool)));

    connect(ui->radioRename, SIGNAL(toggled(bool)), ui->label_2, SLOT(setEnabled(bool)));
    connect(ui->radioRename, SIGNAL(toggled(bool)), ui->comboRenameBig, SLOT(setEnabled(bool)));
    connect(ui->radioRename, SIGNAL(toggled(bool)), ui->comboRenameMid, SLOT(setEnabled(bool)));
    connect(ui->radioRename, SIGNAL(toggled(bool)), ui->comboRenameSmall, SLOT(setEnabled(bool)));
    connect(ui->radioRename, SIGNAL(toggled(bool)), ui->lineRenameMid, SLOT(setEnabled(bool)));
    connect(ui->radioRename, SIGNAL(toggled(bool)), ui->lineRenameSmall, SLOT(setEnabled(bool)));

    connect(ui->radioDelete, SIGNAL(toggled(bool)), ui->label_3, SLOT(setEnabled(bool)));
    connect(ui->radioDelete, SIGNAL(toggled(bool)), ui->comboDeleteBig, SLOT(setEnabled(bool)));
    connect(ui->radioDelete, SIGNAL(toggled(bool)), ui->comboDeleteMid, SLOT(setEnabled(bool)));
    connect(ui->radioDelete, SIGNAL(toggled(bool)), ui->comboDeleteSmall, SLOT(setEnabled(bool)));

    connect(ui->comboNewBig, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotChangeComboNewBig(QString)));
    connect(ui->comboRenameBig, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotChangeComboRenameBig(QString)));
    connect(ui->comboDeleteBig, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotChangeComboDeleteBig(QString)));

    connect(ui->comboRenameMid, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotChangeComboRenameMid(QString)));
    connect(ui->comboDeleteMid, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotChangeComboDeleteMid(QString)));

    connect(ui->lineNewMid, SIGNAL(textChanged(QString)), this, SLOT(slotChangeLineNewMid(QString)));
}

void ABManageCategory::initCategoryData()
{
    ui->comboNewBig->clear();
    ui->comboNewMid->clear();
    ui->comboRenameBig->clear();
    ui->comboRenameMid->clear();
    ui->comboRenameSmall->clear();
    ui->comboDeleteBig->clear();
    ui->comboDeleteMid->clear();
    ui->comboDeleteSmall->clear();

    ui->comboNewBig->addItem("");
    ui->comboRenameBig->addItem("");
    ui->comboDeleteBig->addItem("");

    ui->comboNewBig->addItem(g_Income);
    ui->comboNewBig->addItem(g_Expense);

    ui->comboRenameBig->addItem(g_Income);
    ui->comboRenameBig->addItem(g_Expense);

    ui->comboDeleteBig->addItem(g_Income);
    ui->comboDeleteBig->addItem(g_Expense);

    ui->comboNewBig->setCurrentIndex(0);
    ui->comboRenameBig->setCurrentIndex(0);
    ui->comboDeleteBig->setCurrentIndex(0);
}

bool ABManageCategory::apply()
{
    ui->labelErrMsg->setVisible(false);

    QStringList errMsgList;
    {
        if (ui->radioNew->isChecked()) {
            if (ui->comboNewBig->currentText().isEmpty()) {
                errMsgList.append("Error : Please choose a Big Type.");
            } else {
                if (ui->lineNewMid->text().isEmpty()) {
                    if (ui->comboNewMid->currentText().isEmpty()) {
                        errMsgList.append("Error : Please choose a Mid Type or write a new one.");
                    } else {
                        if (ui->lineNewSmall->text().isEmpty()) {
                            errMsgList.append("Error : Please write a new Small Type.");
                        } else {
                            QStringList sl = smallTypeList(ui->comboNewBig->currentText(),
                                                           ui->comboNewMid->currentText());
                            if (sl.contains(ui->lineNewSmall->text())) {
                                errMsgList.append("Error : The Small Type you want to add exists.");
                            }
                        }
                    }
                } else {
                    QStringList sl = midTypeList(ui->comboNewBig->currentText());
                    if (sl.contains(ui->lineNewMid->text())) {
                        errMsgList.append("Error : The Mid Type you want to add exists.");
                    }
                }
            }
        } else if (ui->radioRename->isChecked()) {
            /// TODO :

            if (ui->comboRenameBig->currentText().isEmpty()) {
                errMsgList.append("Error : Please choose a Big Type.");
            } else {
                if (ui->comboRenameMid->currentText().isEmpty()) {
                    errMsgList.append("Error : Please choose a original Mid Type.");
                } else if (ui->lineRenameMid->text().isEmpty() && ui->lineRenameSmall->text().isEmpty()){
                    errMsgList.append("Error : Please write a new category.");
                } else {
                    if (ui->comboRenameSmall->currentText().isEmpty()) {
                        if (ui->lineRenameSmall->text().isEmpty()) {
                            QStringList sl = midTypeList(ui->comboRenameBig->currentText());
                            if (sl.contains(ui->lineRenameMid->text())) {
                                errMsgList.append("Error : You can not rename a MidType to another existed MidType.");
                            }
                        } else {
                            /// do nothing
                        }
                    } else {
                        if (ui->lineRenameSmall->text().isEmpty()) {
                            /// do nothing
                        } else {
                            /// do nothing
                        }
                    }
                }
            }
        } else if (ui->radioDelete->isChecked()) {
            if (ui->comboDeleteBig->currentText().isEmpty()) {
                errMsgList.append("Error : Please choose a Big Type.");
            } else {
                if (ui->comboDeleteMid->currentText().isEmpty()) {
                    errMsgList.append("Error : Please choose a Mid Type.");
                }
            }
        }
    }

    if (errMsgList.count() == 0) {
        if (ui->radioNew->isChecked()) {
            QString bigType, midType, smallType;
            bigType = ui->comboNewBig->currentText();
            if (ui->lineNewMid->text().isEmpty()) {
                midType = ui->comboNewMid->currentText();
            } else {
                midType = ui->lineNewMid->text();
            }
            if (ui->lineNewSmall->text().isEmpty()) {
                smallType = g_Default;
            } else {
                smallType = ui->lineNewSmall->text();
            }
            insertItemInCategory(bigType, midType, smallType);
        } else if (ui->radioRename->isChecked()) {
            if (!ui->lineRenameSmall->text().isEmpty() && ui->lineRenameMid->text().isEmpty()) {
                ui->lineRenameMid->setText(ui->comboRenameMid->currentText());
            }
            renameCategory(ui->comboRenameBig->currentText(),
                           ui->comboRenameMid->currentText(),
                           ui->comboRenameSmall->currentText(),
                           ui->lineRenameMid->text(),
                           ui->lineRenameSmall->text());
        } else if (ui->radioDelete->isChecked()) {
            QString bigType, midType, smallType;
            bigType = ui->comboDeleteBig->currentText();
            midType = ui->comboDeleteMid->currentText();
            smallType = ui->comboDeleteSmall->currentText();
            if (smallType.isEmpty()) {
                if (QMessageBox::warning(this, "Warning",
                                     "Do you want to remove the whole MidType?",
                                     QMessageBox::Yes,
                                     QMessageBox::Cancel) == QMessageBox::Yes) {
                    deleteItemInCategory(bigType, midType);
                } else {
                    return false;
                }
            } else {
                deleteItemInCategory(bigType, midType, smallType);
            }
        } else {
            /// do nothing
        }

        initCategoryData();

        m_pMainWindow->loadDataByUi();

        return true;
    } else {
        QString errMsg = errMsgList.join("\n");
        ui->labelErrMsg->setText(errMsg);
        ui->labelErrMsg->setVisible(true);

        return false;
    }
}

void ABManageCategory::accept()
{
    if (apply()) {
        QDialog::accept();
    }
}

void ABManageCategory::slotClickButtonBox(QAbstractButton *btn)
{
    if (btn == (QAbstractButton *)(ui->buttonBox->button(QDialogButtonBox::Apply))) {
        apply();
    }
}

void ABManageCategory::slotChangeComboNewBig(QString str)
{
    ui->comboNewMid->clear();

    if (str.isEmpty()) {
        /// do nothing
    } else if (str == g_Income || str == g_Expense) {
        QStringList sl = midTypeList(str);
        sl.removeAll(g_Default);
        ui->comboNewMid->addItems(sl);
        ui->comboNewMid->setCurrentIndex(0);
    } else {
        assert(0);
    }
}

void ABManageCategory::slotChangeComboRenameBig(QString str)
{
    ui->comboRenameSmall->clear();
    ui->comboRenameMid->clear();

    if (str.isEmpty()) {
        /// do nothing
    } else if (str == g_Income || str == g_Expense) {
        QStringList sl = midTypeList(str);
        sl.removeAll(g_Default);
        ui->comboRenameMid->addItems(sl);
        ui->comboRenameMid->setCurrentIndex(0);
    } else {
        assert(0);
    }
}

void ABManageCategory::slotChangeComboDeleteBig(QString str)
{
    ui->comboDeleteSmall->clear();
    ui->comboDeleteMid->clear();

    if (str.isEmpty()) {
        /// do nothing
    } else if (str == g_Income || str == g_Expense) {
        QStringList sl = midTypeList(str);
        sl.removeAll(g_Default);
        ui->comboDeleteMid->addItems(sl);
        ui->comboDeleteMid->setCurrentIndex(0);
    } else {
        assert(0);
    }
}

void ABManageCategory::slotChangeComboRenameMid(QString str)
{
    ui->comboRenameSmall->clear();

    if (ui->comboRenameBig->currentText().isEmpty()) {
        ui->comboRenameMid->clear();
    } else {
        QStringList sl = smallTypeList(ui->comboRenameBig->currentText(), str);
        sl.removeAll(g_Default);
        ui->comboRenameSmall->addItem("");
        ui->comboRenameSmall->addItems(sl);
        ui->comboRenameSmall->setCurrentIndex(0);
    }
}

void ABManageCategory::slotChangeComboDeleteMid(QString str)
{
    ui->comboDeleteSmall->clear();

    if (ui->comboDeleteMid->currentText().isEmpty()) {
        ui->comboDeleteSmall->clear();
    } else {
        QStringList sl = smallTypeList(ui->comboDeleteBig->currentText(), str);
        sl.removeAll(g_Default);
        ui->comboDeleteSmall->addItem("");
        ui->comboDeleteSmall->addItems(sl);
        ui->comboDeleteSmall->setCurrentIndex(0);
    }
}

void ABManageCategory::slotChangeLineNewMid(QString str)
{
    if (str.isEmpty()) {
        ui->comboNewMid->setEnabled(true);
    } else {
        ui->comboNewMid->setEnabled(false);
    }
}
