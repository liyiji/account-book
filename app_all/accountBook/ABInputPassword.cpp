
#include <cassert>

#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

#include "ABInputPassword.h"
#include "ABDefines.h"
#include "ABFunction.h"
#include "ABSqlQuery.h"

ABInputPassword::ABInputPassword(InputPasswordDialogType iType, QWidget *parent) : QDialog(parent)
{
    ui = new Ui_ABInpurPasswordDialog;
    ui->setupUi(this);

    ui->lineCur->setEchoMode(QLineEdit::Password);
    ui->lineNew->setEchoMode(QLineEdit::Password);
    ui->lineConfirm->setEchoMode(QLineEdit::Password);

    m_iType = iType;
    if (m_iType == SetPwd) {
        setWindowTitle("Set new password.");
    } else if (m_iType == InputPwd) {
        setWindowTitle("Please input current password to start program.");
    } else {
        assert(0);
    }

    m_strConfirmedPwd.clear();

    ui->labelErr->setVisible(false);
    if (m_iType == SetPwd) {
        connect(ui->lineNew, SIGNAL(textChanged(QString)), this, SLOT(slotChangeNewOrConfirmPassword()));
        connect(ui->lineConfirm, SIGNAL(textChanged(QString)), this, SLOT(slotChangeNewOrConfirmPassword()));
    } else if (m_iType == InputPwd) {
        ui->lineNew->setVisible(false);
        ui->lineConfirm->setVisible(false);
        ui->label_2->setVisible(false);
        ui->label_3->setVisible(false);
        ui->label_4->setVisible(false);
        ui->label_5->setVisible(false);
    }

    resize(1, 1);
}

ABInputPassword::~ABInputPassword()
{
    if (ui) {
        delete ui;
        ui = 0;
    }
}

void ABInputPassword::slotChangeNewOrConfirmPassword()
{
    ui->labelErr->setVisible(true);
    if (ui->lineNew->text() != ui->lineConfirm->text()) {
        QString errMsg = "Error : Two passwords are different.";
        ui->labelErr->setText(errMsg);
        setLabelErrorColor(Qt::red);
        m_strConfirmedPwd.clear();
    } else {
        QString errMsg = "Two passwords are same.";
        ui->labelErr->setText(errMsg);
        setLabelErrorColor(Qt::blue);
        m_strConfirmedPwd = ui->lineNew->text();
    }
}

bool ABInputPassword::apply()
{
    extern QString g_WorkDir;
    extern bool g_UsePassword;
    if (m_iType == InputPwd) {
        QString fn = g_WorkDir + g_DatabaseDir + g_PwdFile;
        QFile f(fn);
        if (!f.exists()) {
            QMessageBox::critical(this, "Error!",
                                  "Password file doesn't exist, you can not start program!");

            return false;
        }
        f.open(QFile::ReadOnly);
        QTextStream ts(&f);
        QString pwdMd5 = ts.readLine();
        QString inputMd5 = QString::fromStdString(getMD5(ui->lineCur->text().toStdString()));
        if (inputMd5 != pwdMd5) {
            QString errMsg = "Error : Password is wrong!";
            ui->labelErr->setText(errMsg);
            setLabelErrorColor(Qt::red);
            ui->labelErr->setVisible(true);
            return false;
        } else {
            return true;
        }
    } else if (m_iType == SetPwd) {
        if (g_UsePassword) {
            QString fn = g_WorkDir + g_DatabaseDir + g_PwdFile;
            QFile f(fn);
            if (!f.exists()) {
                QMessageBox::critical(this, "Error!",
                                      "Password file doesn't exist, some error occured!");

                return false;
            }
            if (m_strConfirmedPwd.isEmpty()) {
                QFile::remove(fn);
                g_UsePassword = false;
                dropPwdtable();
                return true;
            } else {
                /// TODO :
                f.open(QFile::ReadOnly);
                QTextStream ts(&f);
                QString pwdMd5 = ts.readLine();
                QString InputMd5 = QString::fromStdString(getMD5(ui->lineCur->text().toStdString()));
                if (pwdMd5 != InputMd5) {
                    QString errMsg = "Error : Current password is wrong!";
                    ui->labelErr->setText(errMsg);
                    setLabelErrorColor(Qt::red);
                    ui->labelErr->setVisible(true);
                    f.close();
                    return false;
                }
                if (f.isOpen()) {
                    f.close();
                }

                f.open(QFile::WriteOnly);
                QTextStream ts2(&f);
                QString md5Final = QString::fromStdString(getMD5(m_strConfirmedPwd.toStdString()));
                ts2 << md5Final;
                f.close();

                return true;
            }
        } else {
            if (!ui->lineCur->text().isEmpty()) {
                QString errMsg = "Error : Current password is wrong!";
                ui->labelErr->setText(errMsg);
                setLabelErrorColor(Qt::red);
                ui->labelErr->setVisible(true);
                return false;
            }
            QString fn = g_WorkDir + g_DatabaseDir + g_PwdFile;
            if (!m_strConfirmedPwd.isEmpty()) {
                /// TODO :
                QFile f(fn);
                f.open(QFile::WriteOnly);
                QTextStream ts(&f);
                QString md5Final = QString::fromStdString(getMD5(m_strConfirmedPwd.toStdString()));
                ts << md5Final;
                f.close();
                g_UsePassword = true;
                createPwdTable();
            }
            return true;
        }
    }

    assert(0);
    return false;
}

void ABInputPassword::accept()
{
    if (apply()) {
        QDialog::accept();
    }
}

void ABInputPassword::setLabelErrorColor(QColor c)
{
    QPalette palette = ui->labelErr->palette();
    palette.setColor(ui->labelErr->foregroundRole(), c);
    ui->labelErr->setPalette(palette);
}
