#ifndef ABMANAGECATEGORY_H
#define ABMANAGECATEGORY_H

#include "ui_ABManageCategory.h"

class ABMainWindow;

class ABManageCategory : public QDialog {
    Q_OBJECT

    Ui_ABManageCategoryDialog *ui;
    ABMainWindow* m_pMainWindow;

public:
    ABManageCategory(ABMainWindow *parent);
    virtual ~ABManageCategory();

private:
    void initUi();
    void initConnection();
    void initCategoryData();

    bool apply();

private slots:
    void accept();
    void slotClickButtonBox(QAbstractButton*);

    void slotChangeComboNewBig(QString);
    void slotChangeComboRenameBig(QString);
    void slotChangeComboDeleteBig(QString);

    void slotChangeComboRenameMid(QString);
    void slotChangeComboDeleteMid(QString);

    void slotChangeLineNewMid(QString);
};

#endif // ABMANAGECATEGORY_H
