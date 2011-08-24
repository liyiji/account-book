#ifndef ABINPUTPASSWORD_H
#define ABINPUTPASSWORD_H

#include <ui_ABInputPassword.h>

class ABInputPassword : public QDialog
{
    Q_OBJECT

public:
    enum InputPasswordDialogType {
        SetPwd    = 0,
        InputPwd  = 1
    };

private:
    Ui_ABInpurPasswordDialog*   ui;
    InputPasswordDialogType     m_iType;
    QString                     m_strConfirmedPwd;

public:
    ABInputPassword(InputPasswordDialogType iType, QWidget *parent = 0);
    virtual ~ABInputPassword();

private slots:
    void slotChangeNewOrConfirmPassword();

private:
    bool apply();
    void accept();

    void setLabelErrorColor(QColor);
};

#endif // ABINPUTPASSWORD_H
