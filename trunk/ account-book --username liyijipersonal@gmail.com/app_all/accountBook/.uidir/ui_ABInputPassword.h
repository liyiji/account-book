/********************************************************************************
** Form generated from reading UI file 'ABInputPassword.ui'
**
** Created: Mon Apr 16 19:07:38 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABINPUTPASSWORD_H
#define UI_ABINPUTPASSWORD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ABInpurPasswordDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineCur;
    QLabel *label_2;
    QLineEdit *lineNew;
    QLabel *label_3;
    QLineEdit *lineConfirm;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QLabel *label_4;
    QLabel *labelErr;
    QLabel *label_5;

    void setupUi(QDialog *ABInpurPasswordDialog)
    {
        if (ABInpurPasswordDialog->objectName().isEmpty())
            ABInpurPasswordDialog->setObjectName(QString::fromUtf8("ABInpurPasswordDialog"));
        ABInpurPasswordDialog->resize(396, 179);
        gridLayout = new QGridLayout(ABInpurPasswordDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ABInpurPasswordDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineCur = new QLineEdit(ABInpurPasswordDialog);
        lineCur->setObjectName(QString::fromUtf8("lineCur"));
        lineCur->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(lineCur, 0, 1, 1, 1);

        label_2 = new QLabel(ABInpurPasswordDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineNew = new QLineEdit(ABInpurPasswordDialog);
        lineNew->setObjectName(QString::fromUtf8("lineNew"));
        lineNew->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(lineNew, 2, 1, 1, 1);

        label_3 = new QLabel(ABInpurPasswordDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        lineConfirm = new QLineEdit(ABInpurPasswordDialog);
        lineConfirm->setObjectName(QString::fromUtf8("lineConfirm"));
        lineConfirm->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(lineConfirm, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 2);

        buttonBox = new QDialogButtonBox(ABInpurPasswordDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 7, 1, 1, 1);

        label_4 = new QLabel(ABInpurPasswordDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        labelErr = new QLabel(ABInpurPasswordDialog);
        labelErr->setObjectName(QString::fromUtf8("labelErr"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        labelErr->setPalette(palette);

        gridLayout->addWidget(labelErr, 6, 0, 1, 2);

        label_5 = new QLabel(ABInpurPasswordDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 1, 1, 1);


        retranslateUi(ABInpurPasswordDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ABInpurPasswordDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ABInpurPasswordDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ABInpurPasswordDialog);
    } // setupUi

    void retranslateUi(QDialog *ABInpurPasswordDialog)
    {
        ABInpurPasswordDialog->setWindowTitle(QApplication::translate("ABInpurPasswordDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ABInpurPasswordDialog", "Current Password :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ABInpurPasswordDialog", "New Password :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ABInpurPasswordDialog", "Confirm :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ABInpurPasswordDialog", "Leave a blank if NO current password.", 0, QApplication::UnicodeUTF8));
        labelErr->setText(QApplication::translate("ABInpurPasswordDialog", "Error :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ABInpurPasswordDialog", "Leave blanks if you want to delete password.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ABInpurPasswordDialog: public Ui_ABInpurPasswordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABINPUTPASSWORD_H
