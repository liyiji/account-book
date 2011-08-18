#ifndef ABINPUTPASSWORD_H
#define ABINPUTPASSWORD_H

#include <QDialog>
#include <QString>

#include <ui_ABInputPassword.h>

class ABInputPassword : public QDialog
{
    Q_OBJECT

    Ui_ABInpurPasswordDialog* ui;

public:
    ABInputPassword(bool bShowConfirm, QWidget *parent = 0);
    virtual ~ABInputPassword();

    QString getPwd();

};

#endif // ABINPUTPASSWORD_H
