
#include "ABInputPassword.h"

ABInputPassword::ABInputPassword(bool bShowConfirm, QWidget *parent) : QDialog(parent)
{
    ui = new Ui_ABInpurPasswordDialog;
    ui->setupUi(this);
    ui->label_2->setVisible(bShowConfirm);
    ui->lineEdit_2->setVisible(bShowConfirm);

    resize(1, 1);
}

ABInputPassword::~ABInputPassword()
{
    if (ui) {
        delete ui;
        ui = 0;
    }
}


QString ABInputPassword::getPwd()
{
    return ui->lineEdit->text();
}
