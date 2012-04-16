/********************************************************************************
** Form generated from reading UI file 'ABManageAccount.ui'
**
** Created: Mon Apr 16 19:07:38 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABMANAGEACCOUNT_H
#define UI_ABMANAGEACCOUNT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ABManageAccountDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QLabel *labelErrMsg;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *radioAdd;
    QLabel *label_3;
    QLineEdit *lineNew;
    QFrame *line_3;
    QRadioButton *radioRename;
    QLabel *label_2;
    QComboBox *comboEdit;
    QLabel *label;
    QLineEdit *lineEdit;
    QFrame *line_2;
    QRadioButton *radioDelete;
    QLabel *label_4;
    QComboBox *comboDelete;
    QLabel *label_6;

    void setupUi(QDialog *ABManageAccountDialog)
    {
        if (ABManageAccountDialog->objectName().isEmpty())
            ABManageAccountDialog->setObjectName(QString::fromUtf8("ABManageAccountDialog"));
        ABManageAccountDialog->resize(542, 546);
        gridLayout = new QGridLayout(ABManageAccountDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(ABManageAccountDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);

        labelErrMsg = new QLabel(ABManageAccountDialog);
        labelErrMsg->setObjectName(QString::fromUtf8("labelErrMsg"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(119, 119, 119, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        labelErrMsg->setPalette(palette);

        gridLayout->addWidget(labelErrMsg, 2, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 2);

        groupBox = new QGroupBox(ABManageAccountDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        radioAdd = new QRadioButton(groupBox);
        radioAdd->setObjectName(QString::fromUtf8("radioAdd"));

        gridLayout_2->addWidget(radioAdd, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 1, 1, 1);

        lineNew = new QLineEdit(groupBox);
        lineNew->setObjectName(QString::fromUtf8("lineNew"));

        gridLayout_2->addWidget(lineNew, 1, 2, 1, 1);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 2, 0, 1, 3);

        radioRename = new QRadioButton(groupBox);
        radioRename->setObjectName(QString::fromUtf8("radioRename"));

        gridLayout_2->addWidget(radioRename, 3, 0, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 4, 1, 1, 1);

        comboEdit = new QComboBox(groupBox);
        comboEdit->setObjectName(QString::fromUtf8("comboEdit"));

        gridLayout_2->addWidget(comboEdit, 4, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 5, 1, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 5, 2, 1, 1);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 6, 0, 1, 3);

        radioDelete = new QRadioButton(groupBox);
        radioDelete->setObjectName(QString::fromUtf8("radioDelete"));

        gridLayout_2->addWidget(radioDelete, 7, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 8, 1, 1, 1);

        comboDelete = new QComboBox(groupBox);
        comboDelete->setObjectName(QString::fromUtf8("comboDelete"));

        gridLayout_2->addWidget(comboDelete, 8, 2, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 9, 1, 1, 2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(ABManageAccountDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ABManageAccountDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ABManageAccountDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ABManageAccountDialog);
    } // setupUi

    void retranslateUi(QDialog *ABManageAccountDialog)
    {
        ABManageAccountDialog->setWindowTitle(QApplication::translate("ABManageAccountDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        labelErrMsg->setText(QApplication::translate("ABManageAccountDialog", "Error Message", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ABManageAccountDialog", "Manage Account", 0, QApplication::UnicodeUTF8));
        radioAdd->setText(QApplication::translate("ABManageAccountDialog", "Add new account", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ABManageAccountDialog", "Name of new account :", 0, QApplication::UnicodeUTF8));
        radioRename->setText(QApplication::translate("ABManageAccountDialog", "Rename existed account", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ABManageAccountDialog", "Choose an account :", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ABManageAccountDialog", "New name :", 0, QApplication::UnicodeUTF8));
        radioDelete->setText(QApplication::translate("ABManageAccountDialog", "Delete existed account", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ABManageAccountDialog", "Choose an account :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ABManageAccountDialog", "( Can only delete an account which surplus is 0. )", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ABManageAccountDialog: public Ui_ABManageAccountDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABMANAGEACCOUNT_H
