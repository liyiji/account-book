
#include <cassert>

#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

#include "ABInputPassword.h"
#include "ABDefines.h"
#include "ABSqlQuery.h"

ABInputPassword::ABInputPassword(int iType, QWidget *parent) : QDialog(parent)
{
    ui = new Ui_ABInpurPasswordDialog;
    ui->setupUi(this);

    m_iType = iType;
    /// 0 : Reset password
    /// 1 : Input password to start program
    if (m_iType == 0) {
        setWindowTitle("Set new password.");
    } else if (m_iType == 1) {
        setWindowTitle("Please input current password to start program.");
    } else {
        assert(0);
    }

    m_strConfirmedPwd.clear();

    ui->labelErr->setVisible(false);
    if (iType == 0) {
        connect(ui->lineNew, SIGNAL(textChanged(QString)), this, SLOT(slotChangeNewOrConfirmPassword()));
        connect(ui->lineConfirm, SIGNAL(textChanged(QString)), this, SLOT(slotChangeNewOrConfirmPassword()));
    } else if (iType == 1) {
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

QString ABInputPassword::getConfirmedPwd()
{
    return m_strConfirmedPwd;
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
    if (m_iType == 1) {
        QString fn = g_WorkDir + g_DatabaseDir + g_PwdFile;
        QFile f(fn);
        if (!f.exists()) {
            QMessageBox::critical(this, "Error!",
                                  "Password file doesn't exist, you can not start program!");

            return false;
        }
        f.open(QFile::ReadOnly);
        QTextStream ts(&f);
        QString pwd = ts.readLine();
        if (ui->lineCur->text() != pwd) {
            QString errMsg = "Error : Password is wrong!";
            ui->labelErr->setText(errMsg);
            setLabelErrorColor(Qt::red);
            ui->labelErr->setVisible(true);
            return false;
        } else {
            return true;
        }
    } else if (m_iType == 0) {
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
                f.open(QFile::ReadOnly);
                QTextStream ts(&f);
                QString pwd = ts.readLine();
                if (ui->lineCur->text() != pwd) {
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
                ts2 << m_strConfirmedPwd;
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
                QFile f(fn);
                f.open(QFile::WriteOnly);
                QTextStream ts(&f);
                ts << m_strConfirmedPwd;
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
