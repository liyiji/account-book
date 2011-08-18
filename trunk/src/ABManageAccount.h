#ifndef ABMANAGEACCOUNT_H
#define ABMANAGEACCOUNT_H

#include "ui_ABManageAccount.h"

class ABMainWindow;

class ABManageAccount : public QDialog {
    Q_OBJECT

    Ui_ABManageAccountDialog *ui;
    ABMainWindow *m_pMainWindow;

public:
    ABManageAccount(ABMainWindow *parent);
    virtual ~ABManageAccount();

private:
    void initUi();
    void initConnection();
    void initAccountData();

    bool apply();

private slots:
    void accept();
    void slotClickButtonBox(QAbstractButton*);
};

#endif // ABMANAGEACCOUNT_H
