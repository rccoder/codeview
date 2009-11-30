/********************************************************************************
** Form generated from reading ui file 'pathdialog.ui'
**
** Created: Sat Aug 22 12:26:35 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PATHDIALOG_H
#define UI_PATHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PathDialogClass
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_path;
    QPushButton *pushButton_browse;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_h;
    QLabel *label_3;
    QLineEdit *lineEdit_filter;
    QCheckBox *checkBox_hpp;
    QCheckBox *checkBox_s;
    QCheckBox *checkBox_c;
    QCheckBox *checkBox_cpp;
    QCheckBox *checkBox_S;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox_digui;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_indexer;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *PathDialogClass)
    {
        if (PathDialogClass->objectName().isEmpty())
            PathDialogClass->setObjectName(QString::fromUtf8("PathDialogClass"));
        PathDialogClass->resize(344, 301);
        PathDialogClass->setModal(false);
        verticalLayout = new QVBoxLayout(PathDialogClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(PathDialogClass);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEdit_path = new QLineEdit(PathDialogClass);
        lineEdit_path->setObjectName(QString::fromUtf8("lineEdit_path"));

        horizontalLayout_3->addWidget(lineEdit_path);

        pushButton_browse = new QPushButton(PathDialogClass);
        pushButton_browse->setObjectName(QString::fromUtf8("pushButton_browse"));

        horizontalLayout_3->addWidget(pushButton_browse);


        verticalLayout->addLayout(horizontalLayout_3);

        groupBox = new QGroupBox(PathDialogClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBox_h = new QCheckBox(groupBox);
        checkBox_h->setObjectName(QString::fromUtf8("checkBox_h"));
        checkBox_h->setChecked(true);

        gridLayout->addWidget(checkBox_h, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 3);

        lineEdit_filter = new QLineEdit(groupBox);
        lineEdit_filter->setObjectName(QString::fromUtf8("lineEdit_filter"));

        gridLayout->addWidget(lineEdit_filter, 5, 0, 1, 3);

        checkBox_hpp = new QCheckBox(groupBox);
        checkBox_hpp->setObjectName(QString::fromUtf8("checkBox_hpp"));

        gridLayout->addWidget(checkBox_hpp, 1, 0, 1, 1);

        checkBox_s = new QCheckBox(groupBox);
        checkBox_s->setObjectName(QString::fromUtf8("checkBox_s"));
        checkBox_s->setEnabled(false);

        gridLayout->addWidget(checkBox_s, 2, 0, 1, 1);

        checkBox_c = new QCheckBox(groupBox);
        checkBox_c->setObjectName(QString::fromUtf8("checkBox_c"));
        checkBox_c->setChecked(true);

        gridLayout->addWidget(checkBox_c, 0, 1, 1, 1);

        checkBox_cpp = new QCheckBox(groupBox);
        checkBox_cpp->setObjectName(QString::fromUtf8("checkBox_cpp"));

        gridLayout->addWidget(checkBox_cpp, 1, 1, 1, 1);

        checkBox_S = new QCheckBox(groupBox);
        checkBox_S->setObjectName(QString::fromUtf8("checkBox_S"));
        checkBox_S->setEnabled(false);

        gridLayout->addWidget(checkBox_S, 2, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(PathDialogClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setMargin(11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        checkBox_digui = new QCheckBox(groupBox_2);
        checkBox_digui->setObjectName(QString::fromUtf8("checkBox_digui"));
        checkBox_digui->setChecked(true);

        verticalLayout_3->addWidget(checkBox_digui);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_indexer = new QPushButton(PathDialogClass);
        pushButton_indexer->setObjectName(QString::fromUtf8("pushButton_indexer"));

        horizontalLayout_2->addWidget(pushButton_indexer);

        pushButton_cancel = new QPushButton(PathDialogClass);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout_2->addWidget(pushButton_cancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(PathDialogClass);

        QMetaObject::connectSlotsByName(PathDialogClass);
    } // setupUi

    void retranslateUi(QDialog *PathDialogClass)
    {
        PathDialogClass->setWindowTitle(QApplication::translate("PathDialogClass", "\345\273\272\347\253\213\345\267\245\347\250\213", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PathDialogClass", "\350\257\267\351\200\211\346\213\251\346\211\200\350\246\201\347\264\242\345\274\225\347\232\204\351\241\271\347\233\256\347\232\204\346\240\271\347\233\256\345\275\225", 0, QApplication::UnicodeUTF8));
        pushButton_browse->setText(QApplication::translate("PathDialogClass", "\346\265\217\350\247\210", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PathDialogClass", "\346\226\207\344\273\266\347\247\215\347\261\273", 0, QApplication::UnicodeUTF8));
        checkBox_h->setText(QApplication::translate("PathDialogClass", "*.h", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PathDialogClass", "\346\210\226\345\220\253\357\274\210\346\240\274\345\274\217\357\274\232*.h|*.c \344\270\215\345\217\257\350\276\223\345\205\245\347\251\272\346\240\274,\345\217\257\350\276\223\345\205\245\345\256\214\346\225\264\346\226\207\344\273\266\345\220\215\357\274\211", 0, QApplication::UnicodeUTF8));
        checkBox_hpp->setText(QApplication::translate("PathDialogClass", "*.hpp", 0, QApplication::UnicodeUTF8));
        checkBox_s->setText(QApplication::translate("PathDialogClass", "*.s", 0, QApplication::UnicodeUTF8));
        checkBox_c->setText(QApplication::translate("PathDialogClass", "*.c", 0, QApplication::UnicodeUTF8));
        checkBox_cpp->setText(QApplication::translate("PathDialogClass", "*.cpp", 0, QApplication::UnicodeUTF8));
        checkBox_S->setText(QApplication::translate("PathDialogClass", "*.S", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("PathDialogClass", "\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
        checkBox_digui->setText(QApplication::translate("PathDialogClass", "\351\200\222\345\275\222\346\220\234\347\264\242\345\255\220\347\233\256\345\275\225", 0, QApplication::UnicodeUTF8));
        pushButton_indexer->setText(QApplication::translate("PathDialogClass", "\345\274\200\345\247\213\347\264\242\345\274\225", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("PathDialogClass", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(PathDialogClass);
    } // retranslateUi

};

namespace Ui {
    class PathDialogClass: public Ui_PathDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHDIALOG_H
