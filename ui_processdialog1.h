/********************************************************************************
** Form generated from reading ui file 'processdialog1.ui'
**
** Created: Thu Aug 20 09:59:19 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PROCESSDIALOG1_H
#define UI_PROCESSDIALOG1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProcessDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QDialog *ProcessDialog)
    {
        if (ProcessDialog->objectName().isEmpty())
            ProcessDialog->setObjectName(QString::fromUtf8("ProcessDialog"));
        ProcessDialog->resize(525, 58);
        verticalLayout = new QVBoxLayout(ProcessDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ProcessDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        progressBar = new QProgressBar(ProcessDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);


        retranslateUi(ProcessDialog);

        QMetaObject::connectSlotsByName(ProcessDialog);
    } // setupUi

    void retranslateUi(QDialog *ProcessDialog)
    {
        ProcessDialog->setWindowTitle(QApplication::translate("ProcessDialog", "\346\255\243\345\234\250\347\264\242\345\274\225\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ProcessDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ProcessDialog);
    } // retranslateUi

};

namespace Ui {
    class ProcessDialog: public Ui_ProcessDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSDIALOG1_H
