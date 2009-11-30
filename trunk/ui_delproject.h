/********************************************************************************
** Form generated from reading ui file 'delproject.ui'
**
** Created: Thu Aug 20 09:59:19 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DELPROJECT_H
#define UI_DELPROJECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DelProject
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QListView *listView;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *currentButton;
    QPushButton *delButton;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QWidget *DelProject)
    {
        if (DelProject->objectName().isEmpty())
            DelProject->setObjectName(QString::fromUtf8("DelProject"));
        DelProject->resize(367, 282);
        horizontalLayout = new QHBoxLayout(DelProject);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(DelProject);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        listView = new QListView(DelProject);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout_2->addWidget(listView);

        label_2 = new QLabel(DelProject);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(DelProject);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setReadOnly(true);

        verticalLayout_2->addWidget(lineEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        currentButton = new QPushButton(DelProject);
        currentButton->setObjectName(QString::fromUtf8("currentButton"));

        verticalLayout->addWidget(currentButton);

        delButton = new QPushButton(DelProject);
        delButton->setObjectName(QString::fromUtf8("delButton"));

        verticalLayout->addWidget(delButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_2 = new QPushButton(DelProject);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout->addLayout(verticalLayout);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(lineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(DelProject);
        QObject::connect(pushButton_2, SIGNAL(clicked()), DelProject, SLOT(close()));

        QMetaObject::connectSlotsByName(DelProject);
    } // setupUi

    void retranslateUi(QWidget *DelProject)
    {
        DelProject->setWindowTitle(QApplication::translate("DelProject", "\346\211\200\346\234\211\345\267\245\347\250\213", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DelProject", "\346\211\200\346\234\211\345\267\245\347\250\213\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DelProject", "\346\217\217\350\277\260\357\274\232", 0, QApplication::UnicodeUTF8));
        currentButton->setText(QApplication::translate("DelProject", "\350\256\276\347\275\256\344\270\272\345\275\223\345\211\215\345\267\245\347\250\213", 0, QApplication::UnicodeUTF8));
        delButton->setText(QApplication::translate("DelProject", "\345\210\240\351\231\244\346\255\244\345\267\245\347\250\213", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("DelProject", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(DelProject);
    } // retranslateUi

};

namespace Ui {
    class DelProject: public Ui_DelProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELPROJECT_H
