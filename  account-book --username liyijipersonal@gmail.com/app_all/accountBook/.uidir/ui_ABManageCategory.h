/********************************************************************************
** Form generated from reading UI file 'ABManageCategory.ui'
**
** Created: Mon Apr 16 19:07:38 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABMANAGECATEGORY_H
#define UI_ABMANAGECATEGORY_H

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

class Ui_ABManageCategoryDialog
{
public:
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *line_3;
    QRadioButton *radioNew;
    QLabel *label;
    QComboBox *comboNewBig;
    QComboBox *comboNewMid;
    QLineEdit *lineNewMid;
    QLineEdit *lineNewSmall;
    QFrame *line;
    QRadioButton *radioRename;
    QLabel *label_2;
    QComboBox *comboRenameBig;
    QComboBox *comboRenameMid;
    QComboBox *comboRenameSmall;
    QLineEdit *lineRenameMid;
    QLineEdit *lineRenameSmall;
    QFrame *line_2;
    QRadioButton *radioDelete;
    QLabel *label_3;
    QComboBox *comboDeleteBig;
    QComboBox *comboDeleteMid;
    QComboBox *comboDeleteSmall;
    QSpacerItem *verticalSpacer;
    QLabel *labelErrMsg;

    void setupUi(QDialog *ABManageCategoryDialog)
    {
        if (ABManageCategoryDialog->objectName().isEmpty())
            ABManageCategoryDialog->setObjectName(QString::fromUtf8("ABManageCategoryDialog"));
        ABManageCategoryDialog->resize(662, 422);
        gridLayout_2 = new QGridLayout(ABManageCategoryDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        buttonBox = new QDialogButtonBox(ABManageCategoryDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 3, 0, 1, 1);

        groupBox = new QGroupBox(ABManageCategoryDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 3, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 4, 1, 1);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 1, 0, 1, 5);

        radioNew = new QRadioButton(groupBox);
        radioNew->setObjectName(QString::fromUtf8("radioNew"));

        gridLayout->addWidget(radioNew, 2, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 1, 1, 1);

        comboNewBig = new QComboBox(groupBox);
        comboNewBig->setObjectName(QString::fromUtf8("comboNewBig"));

        gridLayout->addWidget(comboNewBig, 3, 2, 1, 1);

        comboNewMid = new QComboBox(groupBox);
        comboNewMid->setObjectName(QString::fromUtf8("comboNewMid"));

        gridLayout->addWidget(comboNewMid, 3, 3, 1, 1);

        lineNewMid = new QLineEdit(groupBox);
        lineNewMid->setObjectName(QString::fromUtf8("lineNewMid"));

        gridLayout->addWidget(lineNewMid, 4, 3, 1, 1);

        lineNewSmall = new QLineEdit(groupBox);
        lineNewSmall->setObjectName(QString::fromUtf8("lineNewSmall"));

        gridLayout->addWidget(lineNewSmall, 4, 4, 1, 1);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 5, 0, 1, 5);

        radioRename = new QRadioButton(groupBox);
        radioRename->setObjectName(QString::fromUtf8("radioRename"));

        gridLayout->addWidget(radioRename, 6, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 7, 1, 1, 1);

        comboRenameBig = new QComboBox(groupBox);
        comboRenameBig->setObjectName(QString::fromUtf8("comboRenameBig"));

        gridLayout->addWidget(comboRenameBig, 7, 2, 1, 1);

        comboRenameMid = new QComboBox(groupBox);
        comboRenameMid->setObjectName(QString::fromUtf8("comboRenameMid"));

        gridLayout->addWidget(comboRenameMid, 7, 3, 1, 1);

        comboRenameSmall = new QComboBox(groupBox);
        comboRenameSmall->setObjectName(QString::fromUtf8("comboRenameSmall"));

        gridLayout->addWidget(comboRenameSmall, 7, 4, 1, 1);

        lineRenameMid = new QLineEdit(groupBox);
        lineRenameMid->setObjectName(QString::fromUtf8("lineRenameMid"));

        gridLayout->addWidget(lineRenameMid, 8, 3, 1, 1);

        lineRenameSmall = new QLineEdit(groupBox);
        lineRenameSmall->setObjectName(QString::fromUtf8("lineRenameSmall"));

        gridLayout->addWidget(lineRenameSmall, 8, 4, 1, 1);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 9, 0, 1, 5);

        radioDelete = new QRadioButton(groupBox);
        radioDelete->setObjectName(QString::fromUtf8("radioDelete"));

        gridLayout->addWidget(radioDelete, 10, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 11, 1, 1, 1);

        comboDeleteBig = new QComboBox(groupBox);
        comboDeleteBig->setObjectName(QString::fromUtf8("comboDeleteBig"));

        gridLayout->addWidget(comboDeleteBig, 11, 2, 1, 1);

        comboDeleteMid = new QComboBox(groupBox);
        comboDeleteMid->setObjectName(QString::fromUtf8("comboDeleteMid"));

        gridLayout->addWidget(comboDeleteMid, 11, 3, 1, 1);

        comboDeleteSmall = new QComboBox(groupBox);
        comboDeleteSmall->setObjectName(QString::fromUtf8("comboDeleteSmall"));

        gridLayout->addWidget(comboDeleteSmall, 11, 4, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        labelErrMsg = new QLabel(ABManageCategoryDialog);
        labelErrMsg->setObjectName(QString::fromUtf8("labelErrMsg"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(118, 116, 108, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        labelErrMsg->setPalette(palette);

        gridLayout_2->addWidget(labelErrMsg, 2, 0, 1, 1);


        retranslateUi(ABManageCategoryDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ABManageCategoryDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ABManageCategoryDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ABManageCategoryDialog);
    } // setupUi

    void retranslateUi(QDialog *ABManageCategoryDialog)
    {
        ABManageCategoryDialog->setWindowTitle(QApplication::translate("ABManageCategoryDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ABManageCategoryDialog", "Manage Category", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ABManageCategoryDialog", "Big Type", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ABManageCategoryDialog", "Middle Type", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ABManageCategoryDialog", "Small Type", 0, QApplication::UnicodeUTF8));
        radioNew->setText(QApplication::translate("ABManageCategoryDialog", "Add new category", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ABManageCategoryDialog", "Name of new category :", 0, QApplication::UnicodeUTF8));
        radioRename->setText(QApplication::translate("ABManageCategoryDialog", "Rename existed category", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ABManageCategoryDialog", "Choose a category :", 0, QApplication::UnicodeUTF8));
        radioDelete->setText(QApplication::translate("ABManageCategoryDialog", "Delete existed category", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ABManageCategoryDialog", "Choose a category :", 0, QApplication::UnicodeUTF8));
        labelErrMsg->setText(QApplication::translate("ABManageCategoryDialog", "Error Message :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ABManageCategoryDialog: public Ui_ABManageCategoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABMANAGECATEGORY_H
