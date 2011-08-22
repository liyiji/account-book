#ifndef ABINPUTPASSWORD_H
#define ABINPUTPASSWORD_H

#include <ui_ABInputPassword.h>

class ABInputPassword : public QDialog
{
    Q_OBJECT

    Ui_ABInpurPasswordDialog*   ui;
    int                         m_iType;
    QString                     m_strConfirmedPwd;

public:
    /// iType
    /// 0 : Reset password
    /// 1 : Input password to start program
    ABInputPassword(int iType, QWidget *parent = 0);
    virtual ~ABInputPassword();

    QString getConfirmedPwd();

private slots:
    void slotChangeNewOrConfirmPassword();

private:
    bool apply();
    void accept();

    void setLabelErrorColor(QColor);

};

#endif // ABINPUTPASSWORD_H
