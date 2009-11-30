/********************************************************************************
** Form generated from reading ui file 'project.ui'
**
** Created: Thu Aug 20 09:59:19 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PROJECT_H
#define UI_PROJECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Project
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *line;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *projectName;
    QLabel *label_3;
    QLineEdit *projectDcpt;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *next;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Project)
    {
        if (Project->objectName().isEmpty())
            Project->setObjectName(QString::fromUtf8("Project"));
        Project->resize(417, 193);
        Project->setModal(true);
        horizontalLayout_2 = new QHBoxLayout(Project);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Project);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/1.PNG")));

        verticalLayout->addWidget(label);


        horizontalLayout_2->addLayout(verticalLayout);

        line = new QFrame(Project);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(Project);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        projectName = new QLineEdit(Project);
        projectName->setObjectName(QString::fromUtf8("projectName"));

        verticalLayout_2->addWidget(projectName);

        label_3 = new QLabel(Project);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        projectDcpt = new QLineEdit(Project);
        projectDcpt->setObjectName(QString::fromUtf8("projectDcpt"));

        verticalLayout_2->addWidget(projectDcpt);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        next = new QPushButton(Project);
        next->setObjectName(QString::fromUtf8("next"));

        horizontalLayout->addWidget(next);

        pushButton_2 = new QPushButton(Project);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_3);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(projectName);
        label_3->setBuddy(projectDcpt);
#endif // QT_NO_SHORTCUT

        retranslateUi(Project);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Project, SLOT(close()));

        QMetaObject::connectSlotsByName(Project);
    } // setupUi

    void retranslateUi(QDialog *Project)
    {
        Project->setWindowTitle(QApplication::translate("Project", "\346\226\260\345\273\272\345\267\245\347\250\213", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("Project", "\345\267\245\347\250\213\345\220\215\357\274\210\345\255\227\346\257\215\346\225\260\345\255\227\344\270\213\345\210\222\347\272\277\357\274\211\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Project", "\346\217\217\350\277\260\357\274\232", 0, QApplication::UnicodeUTF8));
        next->setText(QApplication::translate("Project", "\344\270\213\344\270\200\346\255\245", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Project", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Project);
    } // retranslateUi

};

namespace Ui {
    class Project: public Ui_Project {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECT_H
