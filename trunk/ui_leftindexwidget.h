/********************************************************************************
** Form generated from reading ui file 'leftindexwidget.ui'
**
** Created: Mon Aug 24 10:39:17 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LEFTINDEXWIDGET_H
#define UI_LEFTINDEXWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LeftIndexWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget_2;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_fileFilter;
    QTreeWidget *treeWidget;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_11;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QListView *listView;

    void setupUi(QWidget *LeftIndexWidget)
    {
        if (LeftIndexWidget->objectName().isEmpty())
            LeftIndexWidget->setObjectName(QString::fromUtf8("LeftIndexWidget"));
        LeftIndexWidget->resize(298, 389);
        verticalLayout_3 = new QVBoxLayout(LeftIndexWidget);
        verticalLayout_3->setMargin(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tabWidget_2 = new QTabWidget(LeftIndexWidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_fileFilter = new QLineEdit(tab_2);
        lineEdit_fileFilter->setObjectName(QString::fromUtf8("lineEdit_fileFilter"));

        horizontalLayout->addWidget(lineEdit_fileFilter);


        verticalLayout_2->addLayout(horizontalLayout);

        treeWidget = new QTreeWidget(tab_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeWidget->setColumnCount(1);
        treeWidget->header()->setVisible(false);
        treeWidget->header()->setCascadingSectionResizes(false);
        treeWidget->header()->setStretchLastSection(true);

        verticalLayout_2->addWidget(treeWidget);

        tabWidget_2->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_11 = new QVBoxLayout(tab_3);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);


        verticalLayout_11->addWidget(groupBox_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QFont font;
        font.setPointSize(10);
        lineEdit->setFont(font);

        horizontalLayout_3->addWidget(lineEdit);

        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(9);
        font1.setKerning(false);
        pushButton->setFont(font1);
        pushButton->setMouseTracking(false);
        pushButton->setAutoFillBackground(false);
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8("E:/pica/\345\233\276\346\240\207/\350\241\250\346\203\205png/2327/\345\217\257\347\210\261QQ\350\241\250\346\203\205\345\233\276\346\240\207\344\270\213\350\275\2751.png")), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setCheckable(false);
        pushButton->setAutoExclusive(false);
        pushButton->setAutoDefault(false);
        pushButton->setDefault(false);
        pushButton->setFlat(false);

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_11->addLayout(horizontalLayout_3);

        listView = new QListView(tab_3);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setFont(font);

        verticalLayout_11->addWidget(listView);

        tabWidget_2->addTab(tab_3, QString());

        verticalLayout_3->addWidget(tabWidget_2);


        retranslateUi(LeftIndexWidget);
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_3, SIGNAL(clicked(bool)), pushButton, SLOT(setEnabled(bool)));
        QObject::connect(lineEdit, SIGNAL(returnPressed()), pushButton, SLOT(click()));

        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LeftIndexWidget);
    } // setupUi

    void retranslateUi(QWidget *LeftIndexWidget)
    {
        LeftIndexWidget->setWindowTitle(QApplication::translate("LeftIndexWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LeftIndexWidget", "\346\226\207\344\273\266\345\220\215\350\277\207\346\273\244", 0, QApplication::UnicodeUTF8));
        lineEdit_fileFilter->setInputMask(QString());
        lineEdit_fileFilter->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("LeftIndexWidget", "\346\265\217\350\247\210\345\267\245\347\250\213\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("LeftIndexWidget", "\346\220\234\347\264\242\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("LeftIndexWidget", "\345\207\275\346\225\260\345\220\215", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("LeftIndexWidget", "\347\261\273\345\220\215&&\347\273\223\346\236\204\345\220\215", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("LeftIndexWidget", "\346\231\256\351\200\232\346\240\207\350\257\206\347\254\246", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("LeftIndexWidget", "\346\220\234\347\264\242", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("LeftIndexWidget", "\346\220\234\347\264\242\346\240\207\350\257\206\347\254\246", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(LeftIndexWidget);
    } // retranslateUi

};

namespace Ui {
    class LeftIndexWidget: public Ui_LeftIndexWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFTINDEXWIDGET_H
