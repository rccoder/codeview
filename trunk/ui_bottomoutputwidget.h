/********************************************************************************
** Form generated from reading ui file 'bottomoutputwidget.ui'
**
** Created: Sun Aug 23 19:05:01 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_BOTTOMOUTPUTWIDGET_H
#define UI_BOTTOMOUTPUTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BottomOutputWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_14;
    QTableWidget *tableWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QWidget *tab_5;
    QHBoxLayout *horizontalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QSpacerItem *verticalSpacer_5;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBoxDef;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *BottomOutputWidget)
    {
        if (BottomOutputWidget->objectName().isEmpty())
            BottomOutputWidget->setObjectName(QString::fromUtf8("BottomOutputWidget"));
        BottomOutputWidget->resize(519, 173);
        verticalLayout = new QVBoxLayout(BottomOutputWidget);
        verticalLayout->setMargin(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(BottomOutputWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_14 = new QVBoxLayout(tab_4);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        tableWidget = new QTableWidget(tab_4);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(9);
        tableWidget->setFont(font);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(15);
        tableWidget->verticalHeader()->setMinimumSectionSize(15);

        verticalLayout_14->addWidget(tableWidget);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        plainTextEdit = new QPlainTextEdit(tab);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setReadOnly(true);

        horizontalLayout->addWidget(plainTextEdit);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        tabWidget->addTab(tab, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        horizontalLayout_4 = new QHBoxLayout(tab_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        scrollArea = new QScrollArea(tab_5);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 319, 127));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier New"));
        font1.setStyleStrategy(QFont::NoAntialias);
        label->setFont(font1);

        verticalLayout_4->addWidget(label);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_4->addWidget(scrollArea);

        widget = new QWidget(tab_5);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMaximumSize(QSize(200, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        checkBoxDef = new QCheckBox(widget);
        checkBoxDef->setObjectName(QString::fromUtf8("checkBoxDef"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBoxDef->sizePolicy().hasHeightForWidth());
        checkBoxDef->setSizePolicy(sizePolicy1);
        checkBoxDef->setMaximumSize(QSize(200, 16777215));
        QFont font2;
        font2.setStrikeOut(false);
        checkBoxDef->setFont(font2);
        checkBoxDef->setChecked(true);

        verticalLayout_3->addWidget(checkBoxDef);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximumSize(QSize(150, 16777215));
        progressBar->setValue(100);

        verticalLayout_3->addWidget(progressBar);

        horizontalSpacer = new QSpacerItem(20, 59, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(horizontalSpacer);


        horizontalLayout_4->addWidget(widget);

        tabWidget->addTab(tab_5, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(BottomOutputWidget);
        QObject::connect(pushButton, SIGNAL(clicked()), plainTextEdit, SLOT(clear()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BottomOutputWidget);
    } // setupUi

    void retranslateUi(QWidget *BottomOutputWidget)
    {
        BottomOutputWidget->setWindowTitle(QApplication::translate("BottomOutputWidget", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BottomOutputWidget", "\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BottomOutputWidget", "\350\241\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BottomOutputWidget", "\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("BottomOutputWidget", "\347\274\226\350\257\221\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("BottomOutputWidget", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("BottomOutputWidget", "\351\235\236\347\274\226\350\257\221\345\221\275\344\273\244\350\276\223\345\207\272", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        checkBoxDef->setText(QApplication::translate("BottomOutputWidget", "\345\217\252\346\230\276\347\244\272\345\256\232\344\271\211\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("BottomOutputWidget", "\345\214\205\345\220\253\346\255\244\345\205\263\351\224\256\345\255\227\347\232\204\346\211\200\346\234\211\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(BottomOutputWidget);
    } // retranslateUi

};

namespace Ui {
    class BottomOutputWidget: public Ui_BottomOutputWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOTTOMOUTPUTWIDGET_H
