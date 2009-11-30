/********************************************************************************
** Form generated from reading ui file 'oslabpath.ui'
**
** Created: Thu Aug 20 09:59:19 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_OSLABPATH_H
#define UI_OSLABPATH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OslabPath
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTreeView *treeView;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *OslabPath)
    {
        if (OslabPath->objectName().isEmpty())
            OslabPath->setObjectName(QString::fromUtf8("OslabPath"));
        OslabPath->resize(400, 300);
        OslabPath->setModal(true);
        verticalLayout = new QVBoxLayout(OslabPath);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(OslabPath);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        treeView = new QTreeView(OslabPath);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout->addWidget(treeView);

        lineEdit = new QLineEdit(OslabPath);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(OslabPath);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(OslabPath);

        QMetaObject::connectSlotsByName(OslabPath);
    } // setupUi

    void retranslateUi(QDialog *OslabPath)
    {
        OslabPath->setWindowTitle(QApplication::translate("OslabPath", "\350\256\276\347\275\256oslab\350\267\257\345\276\204", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OslabPath", "\350\257\267\351\200\211\346\213\251oslab\346\211\271\345\244\204\347\220\206\345\221\275\344\273\244\346\211\200\345\234\250\347\232\204\347\233\256\345\275\225", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("OslabPath", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(OslabPath);
    } // retranslateUi

};

namespace Ui {
    class OslabPath: public Ui_OslabPath {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSLABPATH_H
