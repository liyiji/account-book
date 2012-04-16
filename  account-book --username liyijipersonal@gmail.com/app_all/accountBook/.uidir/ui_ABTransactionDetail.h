/********************************************************************************
** Form generated from reading UI file 'ABTransactionDetail.ui'
**
** Created: Mon Apr 16 19:07:38 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABTRANSACTIONDETAIL_H
#define UI_ABTRANSACTIONDETAIL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_ABTransactionDetailDialog
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateEdit;
    QPushButton *pushButton;
    QCalendarWidget *calendarWidget;
    QLabel *label_2;
    QTimeEdit *timeEdit;
    QLabel *label_3;
    QComboBox *comboBox;
    QGridLayout *gridLayout;
    QCheckBox *checkNewCategory;
    QLineEdit *lineEditNewCategory;
    QLabel *label_7;
    QComboBox *comboBoxParentCategory;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBoxNewAccount;
    QLineEdit *lineEditNewAccount;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;
    QLabel *labelErrorMessage;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ABTransactionDetailDialog)
    {
        if (ABTransactionDetailDialog->objectName().isEmpty())
            ABTransactionDetailDialog->setObjectName(QString::fromUtf8("ABTransactionDetailDialog"));
        ABTransactionDetailDialog->resize(437, 479);
        gridLayout_2 = new QGridLayout(ABTransactionDetailDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(ABTransactionDetailDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        dateEdit = new QDateEdit(ABTransactionDetailDialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout->addWidget(dateEdit);

        pushButton = new QPushButton(ABTransactionDetailDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);

        calendarWidget = new QCalendarWidget(ABTransactionDetailDialog);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        gridLayout_2->addWidget(calendarWidget, 1, 1, 1, 1);

        label_2 = new QLabel(ABTransactionDetailDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        timeEdit = new QTimeEdit(ABTransactionDetailDialog);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setTime(QTime(8, 0, 0));

        gridLayout_2->addWidget(timeEdit, 2, 1, 1, 1);

        label_3 = new QLabel(ABTransactionDetailDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        comboBox = new QComboBox(ABTransactionDetailDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(comboBox, 3, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkNewCategory = new QCheckBox(ABTransactionDetailDialog);
        checkNewCategory->setObjectName(QString::fromUtf8("checkNewCategory"));

        gridLayout->addWidget(checkNewCategory, 0, 0, 1, 1);

        lineEditNewCategory = new QLineEdit(ABTransactionDetailDialog);
        lineEditNewCategory->setObjectName(QString::fromUtf8("lineEditNewCategory"));

        gridLayout->addWidget(lineEditNewCategory, 0, 1, 1, 1);

        label_7 = new QLabel(ABTransactionDetailDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        comboBoxParentCategory = new QComboBox(ABTransactionDetailDialog);
        comboBoxParentCategory->setObjectName(QString::fromUtf8("comboBoxParentCategory"));

        gridLayout->addWidget(comboBoxParentCategory, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 4, 1, 1, 1);

        label_4 = new QLabel(ABTransactionDetailDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 5, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(ABTransactionDetailDialog);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMaximum(1e+06);

        gridLayout_2->addWidget(doubleSpinBox, 5, 1, 1, 1);

        label_5 = new QLabel(ABTransactionDetailDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 6, 0, 1, 1);

        comboBox_2 = new QComboBox(ABTransactionDetailDialog);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout_2->addWidget(comboBox_2, 6, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkBoxNewAccount = new QCheckBox(ABTransactionDetailDialog);
        checkBoxNewAccount->setObjectName(QString::fromUtf8("checkBoxNewAccount"));

        horizontalLayout_3->addWidget(checkBoxNewAccount);

        lineEditNewAccount = new QLineEdit(ABTransactionDetailDialog);
        lineEditNewAccount->setObjectName(QString::fromUtf8("lineEditNewAccount"));

        horizontalLayout_3->addWidget(lineEditNewAccount);


        gridLayout_2->addLayout(horizontalLayout_3, 7, 1, 1, 1);

        label_6 = new QLabel(ABTransactionDetailDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 8, 0, 1, 1);

        lineEdit = new QLineEdit(ABTransactionDetailDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 8, 1, 1, 1);

        buttonBox = new QDialogButtonBox(ABTransactionDetailDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 11, 1, 1, 1);

        labelErrorMessage = new QLabel(ABTransactionDetailDialog);
        labelErrorMessage->setObjectName(QString::fromUtf8("labelErrorMessage"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(119, 119, 119, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        labelErrorMessage->setPalette(palette);

        gridLayout_2->addWidget(labelErrorMessage, 10, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 9, 0, 1, 2);

        QWidget::setTabOrder(calendarWidget, dateEdit);
        QWidget::setTabOrder(dateEdit, pushButton);
        QWidget::setTabOrder(pushButton, timeEdit);
        QWidget::setTabOrder(timeEdit, comboBox);
        QWidget::setTabOrder(comboBox, doubleSpinBox);
        QWidget::setTabOrder(doubleSpinBox, comboBox_2);
        QWidget::setTabOrder(comboBox_2, lineEdit);
        QWidget::setTabOrder(lineEdit, buttonBox);

        retranslateUi(ABTransactionDetailDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ABTransactionDetailDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ABTransactionDetailDialog, SLOT(reject()));
        QObject::connect(dateEdit, SIGNAL(dateChanged(QDate)), calendarWidget, SLOT(setSelectedDate(QDate)));
        QObject::connect(calendarWidget, SIGNAL(clicked(QDate)), dateEdit, SLOT(setDate(QDate)));
        QObject::connect(checkBoxNewAccount, SIGNAL(toggled(bool)), lineEditNewAccount, SLOT(setVisible(bool)));
        QObject::connect(checkBoxNewAccount, SIGNAL(toggled(bool)), comboBox_2, SLOT(setDisabled(bool)));
        QObject::connect(checkNewCategory, SIGNAL(toggled(bool)), comboBoxParentCategory, SLOT(setVisible(bool)));
        QObject::connect(checkNewCategory, SIGNAL(toggled(bool)), label_7, SLOT(setVisible(bool)));
        QObject::connect(checkNewCategory, SIGNAL(toggled(bool)), lineEditNewCategory, SLOT(setVisible(bool)));
        QObject::connect(checkNewCategory, SIGNAL(toggled(bool)), comboBox, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(ABTransactionDetailDialog);
    } // setupUi

    void retranslateUi(QDialog *ABTransactionDetailDialog)
    {
        ABTransactionDetailDialog->setWindowTitle(QApplication::translate("ABTransactionDetailDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ABTransactionDetailDialog", "Date :", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("ABTransactionDetailDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ABTransactionDetailDialog", "Today", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ABTransactionDetailDialog", "Time", 0, QApplication::UnicodeUTF8));
        timeEdit->setDisplayFormat(QApplication::translate("ABTransactionDetailDialog", "hh:mm", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ABTransactionDetailDialog", "Category :", 0, QApplication::UnicodeUTF8));
        checkNewCategory->setText(QApplication::translate("ABTransactionDetailDialog", "New Category", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ABTransactionDetailDialog", "Parent Category :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ABTransactionDetailDialog", "Sum (RMB \324\252):", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ABTransactionDetailDialog", "Text :", 0, QApplication::UnicodeUTF8));
        checkBoxNewAccount->setText(QApplication::translate("ABTransactionDetailDialog", "New Account", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ABTransactionDetailDialog", "Detail :", 0, QApplication::UnicodeUTF8));
        labelErrorMessage->setText(QApplication::translate("ABTransactionDetailDialog", "Error Message", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ABTransactionDetailDialog: public Ui_ABTransactionDetailDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABTRANSACTIONDETAIL_H
