/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Mon Aug 24 10:56:10 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *action_NewFile;
    QAction *action_Open;
    QAction *newProject;
    QAction *delProject;
    QAction *action_Copy;
    QAction *action_cut;
    QAction *action_paste;
    QAction *action_undo;
    QAction *action_redo;
    QAction *action_F;
    QAction *action_Save;
    QAction *action_5;
    QAction *action_E;
    QAction *selectProject;
    QAction *action_saveAs;
    QAction *action_showLeft;
    QAction *action_showBottom;
    QAction *action_help;
    QAction *action_make;
    QAction *action_run;
    QAction *action_4;
    QAction *actionMount;
    QAction *actionUmount;
    QAction *action_6;
    QAction *action;
    QAction *action_Option;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_newPro1;
    QLabel *label_newPro2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_recentPro1;
    QLabel *label_recentPro2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QLabel *label_recentPro;
    QLabel *label_6;
    QLabel *label_recentd;
    QLabel *label_recentFile;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_T;
    QMenu *menu_H;
    QMenu *menu_E;
    QMenu *menu_W;
    QMenu *menuOslab;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_12;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout_13;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(674, 530);
        MainWindowClass->setDocumentMode(true);
        MainWindowClass->setTabShape(QTabWidget::Triangular);
        MainWindowClass->setUnifiedTitleAndToolBarOnMac(true);
        action_NewFile = new QAction(MainWindowClass);
        action_NewFile->setObjectName(QString::fromUtf8("action_NewFile"));
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/new.png")), QIcon::Normal, QIcon::Off);
        action_NewFile->setIcon(icon);
        action_Open = new QAction(MainWindowClass);
        action_Open->setObjectName(QString::fromUtf8("action_Open"));
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/open.png")), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon1);
        newProject = new QAction(MainWindowClass);
        newProject->setObjectName(QString::fromUtf8("newProject"));
        QIcon icon2;
        icon2.addPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/addgroup.png")), QIcon::Normal, QIcon::Off);
        newProject->setIcon(icon2);
        delProject = new QAction(MainWindowClass);
        delProject->setObjectName(QString::fromUtf8("delProject"));
        QIcon icon3;
        icon3.addPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/relaxView.png")), QIcon::Normal, QIcon::Off);
        delProject->setIcon(icon3);
        action_Copy = new QAction(MainWindowClass);
        action_Copy->setObjectName(QString::fromUtf8("action_Copy"));
        QIcon icon4;
        icon4.addPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/copy.png")), QIcon::Normal, QIcon::Off);
        action_Copy->setIcon(icon4);
        action_cut = new QAction(MainWindowClass);
        action_cut->setObjectName(QString::fromUtf8("action_cut"));
        QIcon icon5;
        icon5.addPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/cut.png")), QIcon::Normal, QIcon::Off);
        action_cut->setIcon(icon5);
        action_paste = new QAction(MainWindowClass);
        action_paste->setObjectName(QString::fromUtf8("action_paste"));
        QIcon icon6;
        icon6.addPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/paste.png")), QIcon::Normal, QIcon::Off);
        action_paste->setIcon(icon6);
        action_undo = new QAction(MainWindowClass);
        action_undo->setObjectName(QString::fromUtf8("action_undo"));
        QIcon icon7;
        icon7.addPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/undo.png")), QIcon::Normal, QIcon::Off);
        action_undo->setIcon(icon7);
        action_redo = new QAction(MainWindowClass);
        action_redo->setObjectName(QString::fromUtf8("action_redo"));
        QIcon icon8;
        icon8.addPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/redo.png")), QIcon::Normal, QIcon::Off);
        action_redo->setIcon(icon8);
        action_F = new QAction(MainWindowClass);
        action_F->setObjectName(QString::fromUtf8("action_F"));
        QIcon icon9;
        icon9.addPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/find.png")), QIcon::Normal, QIcon::Off);
        action_F->setIcon(icon9);
        action_Save = new QAction(MainWindowClass);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        QIcon icon10;
        icon10.addPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/save.png")), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon10);
        action_5 = new QAction(MainWindowClass);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        action_E = new QAction(MainWindowClass);
        action_E->setObjectName(QString::fromUtf8("action_E"));
        selectProject = new QAction(MainWindowClass);
        selectProject->setObjectName(QString::fromUtf8("selectProject"));
        action_saveAs = new QAction(MainWindowClass);
        action_saveAs->setObjectName(QString::fromUtf8("action_saveAs"));
        action_showLeft = new QAction(MainWindowClass);
        action_showLeft->setObjectName(QString::fromUtf8("action_showLeft"));
        action_showBottom = new QAction(MainWindowClass);
        action_showBottom->setObjectName(QString::fromUtf8("action_showBottom"));
        action_help = new QAction(MainWindowClass);
        action_help->setObjectName(QString::fromUtf8("action_help"));
        action_make = new QAction(MainWindowClass);
        action_make->setObjectName(QString::fromUtf8("action_make"));
        QIcon icon11;
        icon11.addPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/compile.png")), QIcon::Normal, QIcon::Off);
        action_make->setIcon(icon11);
        action_run = new QAction(MainWindowClass);
        action_run->setObjectName(QString::fromUtf8("action_run"));
        QIcon icon12;
        icon12.addPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/run.png")), QIcon::Normal, QIcon::Off);
        action_run->setIcon(icon12);
        action_4 = new QAction(MainWindowClass);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        actionMount = new QAction(MainWindowClass);
        actionMount->setObjectName(QString::fromUtf8("actionMount"));
        actionUmount = new QAction(MainWindowClass);
        actionUmount->setObjectName(QString::fromUtf8("actionUmount"));
        action_6 = new QAction(MainWindowClass);
        action_6->setObjectName(QString::fromUtf8("action_6"));
        action = new QAction(MainWindowClass);
        action->setObjectName(QString::fromUtf8("action"));
        action_Option = new QAction(MainWindowClass);
        action_Option->setObjectName(QString::fromUtf8("action_Option"));
        action_Option->setEnabled(false);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setMargin(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMouseTracking(false);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_10 = new QVBoxLayout(tab);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setMargin(11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/1.PNG")));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_5);

        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignCenter);
        label_13->setOpenExternalLinks(true);

        verticalLayout_5->addWidget(label_13);


        verticalLayout_10->addLayout(verticalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_newPro1 = new QLabel(tab);
        label_newPro1->setObjectName(QString::fromUtf8("label_newPro1"));
        label_newPro1->setPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/addgroup.png")));

        horizontalLayout_7->addWidget(label_newPro1);

        label_newPro2 = new QLabel(tab);
        label_newPro2->setObjectName(QString::fromUtf8("label_newPro2"));
        label_newPro2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_newPro2);


        verticalLayout_7->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_recentPro1 = new QLabel(tab);
        label_recentPro1->setObjectName(QString::fromUtf8("label_recentPro1"));
        label_recentPro1->setPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/relaxView.png")));

        horizontalLayout_8->addWidget(label_recentPro1);

        label_recentPro2 = new QLabel(tab);
        label_recentPro2->setObjectName(QString::fromUtf8("label_recentPro2"));
        label_recentPro2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_recentPro2);


        verticalLayout_7->addLayout(horizontalLayout_8);


        verticalLayout_8->addLayout(verticalLayout_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);


        horizontalLayout_9->addLayout(verticalLayout_8);


        horizontalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/Sync.png")));

        horizontalLayout_5->addWidget(label_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);

        verticalLayout_6->addWidget(label_3);

        label_recentPro = new QLabel(tab);
        label_recentPro->setObjectName(QString::fromUtf8("label_recentPro"));

        verticalLayout_6->addWidget(label_recentPro);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_6->addWidget(label_6);

        label_recentd = new QLabel(tab);
        label_recentd->setObjectName(QString::fromUtf8("label_recentd"));
        label_recentd->setFont(font);

        verticalLayout_6->addWidget(label_recentd);

        label_recentFile = new QLabel(tab);
        label_recentFile->setObjectName(QString::fromUtf8("label_recentFile"));

        verticalLayout_6->addWidget(label_recentFile);


        horizontalLayout_5->addLayout(verticalLayout_6);


        verticalLayout_9->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);


        horizontalLayout_10->addLayout(verticalLayout_9);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);


        horizontalLayout->addLayout(horizontalLayout_10);


        verticalLayout_10->addLayout(horizontalLayout);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_10->addWidget(label_2);

        QIcon icon13;
        icon13.addPixmap(QPixmap(QString::fromUtf8(":/iamge/iamges/arrow.png")), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon13, QString());

        horizontalLayout_2->addWidget(tabWidget);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 674, 24));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_T = new QMenu(menuBar);
        menu_T->setObjectName(QString::fromUtf8("menu_T"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QString::fromUtf8("menu_H"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QString::fromUtf8("menu_E"));
        menu_W = new QMenu(menuBar);
        menu_W->setObjectName(QString::fromUtf8("menu_W"));
        menuOslab = new QMenu(menuBar);
        menuOslab->setObjectName(QString::fromUtf8("menuOslab"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMouseTracking(true);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindowClass);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        QPalette palette;
        QBrush brush(QColor(236, 233, 216, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        dockWidget->setPalette(palette);
        dockWidget->setMouseTracking(false);
        QIcon icon14;
        icon14.addPixmap(QPixmap(QString::fromUtf8("E:/pica/\345\233\276\346\240\207/\350\241\250\346\203\205png/2327/\345\217\257\347\210\261QQ\350\241\250\346\203\205\345\233\276\346\240\207\344\270\213\350\275\2752.png")), QIcon::Normal, QIcon::Off);
        dockWidget->setWindowIcon(icon14);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        verticalLayout_12 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setMargin(11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        dockWidget->setWidget(dockWidgetContents_2);
        MainWindowClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        dockWidget_2 = new QDockWidget(MainWindowClass);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        verticalLayout_13 = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setMargin(11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        dockWidget_2->setWidget(dockWidgetContents_3);
        MainWindowClass->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_2);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu_T->menuAction());
        menuBar->addAction(menu_W->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menuBar->addAction(menuOslab->menuAction());
        menu_File->addAction(action_NewFile);
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Save);
        menu_File->addAction(action_saveAs);
        menu_File->addSeparator();
        menu_File->addAction(action_E);
        menu_T->addAction(newProject);
        menu_T->addAction(delProject);
        menu_H->addAction(action_help);
        menu_H->addAction(action_5);
        menu_E->addAction(action_Copy);
        menu_E->addAction(action_cut);
        menu_E->addAction(action_paste);
        menu_E->addSeparator();
        menu_E->addAction(action_undo);
        menu_E->addAction(action_redo);
        menu_E->addSeparator();
        menu_E->addAction(action);
        menu_E->addSeparator();
        menu_E->addAction(action_Option);
        menu_W->addAction(action_showLeft);
        menu_W->addAction(action_showBottom);
        menuOslab->addAction(action_4);
        menuOslab->addAction(action_make);
        menuOslab->addAction(action_run);
        menuOslab->addSeparator();
        menuOslab->addAction(actionMount);
        menuOslab->addAction(actionUmount);
        mainToolBar->addAction(action_make);
        mainToolBar->addAction(action_run);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_NewFile);
        mainToolBar->addAction(action_Open);
        mainToolBar->addAction(action_Save);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_undo);
        mainToolBar->addAction(action_redo);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Copy);
        mainToolBar->addAction(action_cut);
        mainToolBar->addAction(action_paste);
        mainToolBar->addSeparator();
        mainToolBar->addSeparator();
        mainToolBar->addAction(newProject);
        mainToolBar->addAction(delProject);
        mainToolBar->addSeparator();
        mainToolBar->addSeparator();

        retranslateUi(MainWindowClass);
        QObject::connect(action_NewFile, SIGNAL(triggered()), MainWindowClass, SLOT(newFile()));
        QObject::connect(action_Open, SIGNAL(triggered()), MainWindowClass, SLOT(open()));
        QObject::connect(action_Save, SIGNAL(triggered()), MainWindowClass, SLOT(save()));
        QObject::connect(action_saveAs, SIGNAL(triggered()), MainWindowClass, SLOT(saveAs()));
        QObject::connect(action_E, SIGNAL(triggered()), MainWindowClass, SLOT(close()));
        QObject::connect(action_5, SIGNAL(triggered()), MainWindowClass, SLOT(about()));
        QObject::connect(action_Copy, SIGNAL(triggered()), MainWindowClass, SLOT(copy()));
        QObject::connect(action_cut, SIGNAL(triggered()), MainWindowClass, SLOT(cut()));
        QObject::connect(action_paste, SIGNAL(triggered()), MainWindowClass, SLOT(paste()));
        QObject::connect(action_redo, SIGNAL(triggered()), MainWindowClass, SLOT(redo()));
        QObject::connect(action_undo, SIGNAL(triggered()), MainWindowClass, SLOT(undo()));
        QObject::connect(label_newPro2, SIGNAL(linkActivated(QString)), MainWindowClass, SLOT(dealStartLable(QString)));
        QObject::connect(label_recentPro2, SIGNAL(linkActivated(QString)), MainWindowClass, SLOT(dealStartLable(QString)));
        QObject::connect(label_recentFile, SIGNAL(linkActivated(QString)), MainWindowClass, SLOT(dealStartLable(QString)));
        QObject::connect(label_recentPro, SIGNAL(linkActivated(QString)), MainWindowClass, SLOT(dealStartLable(QString)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "CodeView", 0, QApplication::UnicodeUTF8));
        action_NewFile->setText(QApplication::translate("MainWindowClass", "\346\226\260\345\273\272(&N)", 0, QApplication::UnicodeUTF8));
        action_NewFile->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        action_Open->setText(QApplication::translate("MainWindowClass", "\346\211\223\345\274\200(&O)", 0, QApplication::UnicodeUTF8));
        action_Open->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        newProject->setText(QApplication::translate("MainWindowClass", "\346\226\260\345\273\272\345\267\245\347\250\213", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        newProject->setToolTip(QApplication::translate("MainWindowClass", "\346\226\260\345\273\272\345\267\245\347\250\213\344\273\245\344\276\277\345\256\232\344\275\215\346\226\207\344\273\266\344\270\255\347\232\204\346\240\207\350\257\206\347\254\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        delProject->setText(QApplication::translate("MainWindowClass", "\346\211\200\346\234\211\345\267\245\347\250\213", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        delProject->setToolTip(QApplication::translate("MainWindowClass", "\346\237\245\347\234\213\345\271\266\344\270\224\347\274\226\350\276\221\346\211\200\346\234\211\345\267\245\347\250\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_Copy->setText(QApplication::translate("MainWindowClass", "\345\244\215\345\210\266(&C)", 0, QApplication::UnicodeUTF8));
        action_Copy->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        action_cut->setText(QApplication::translate("MainWindowClass", "\345\211\252\345\210\207(&X)", 0, QApplication::UnicodeUTF8));
        action_cut->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        action_paste->setText(QApplication::translate("MainWindowClass", "\347\262\230\350\264\264(&V)", 0, QApplication::UnicodeUTF8));
        action_paste->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        action_undo->setText(QApplication::translate("MainWindowClass", "\344\270\212\344\270\200\346\255\245", 0, QApplication::UnicodeUTF8));
        action_undo->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        action_redo->setText(QApplication::translate("MainWindowClass", "\344\270\213\344\270\200\346\255\245", 0, QApplication::UnicodeUTF8));
        action_redo->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        action_F->setText(QApplication::translate("MainWindowClass", "\345\234\250\346\226\207\346\234\254\344\270\255\346\237\245\346\211\276(&F)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_F->setToolTip(QApplication::translate("MainWindowClass", "\345\215\225\345\207\273\344\273\245\344\276\277\346\211\223\345\274\200\346\226\207\346\234\254\346\237\245\346\211\276\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_F->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        action_Save->setText(QApplication::translate("MainWindowClass", "\344\277\235\345\255\230(&S)", 0, QApplication::UnicodeUTF8));
        action_Save->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        action_5->setText(QApplication::translate("MainWindowClass", "\345\205\263\344\272\216 CodeView", 0, QApplication::UnicodeUTF8));
        action_E->setText(QApplication::translate("MainWindowClass", "\351\200\200\345\207\272(&E)", 0, QApplication::UnicodeUTF8));
        selectProject->setText(QApplication::translate("MainWindowClass", "\351\200\211\346\213\251\345\267\245\347\250\213", 0, QApplication::UnicodeUTF8));
        action_saveAs->setText(QApplication::translate("MainWindowClass", "\345\217\246\345\255\230\344\270\272", 0, QApplication::UnicodeUTF8));
        action_showLeft->setText(QApplication::translate("MainWindowClass", "\345\267\245\347\250\213\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_showLeft->setToolTip(QApplication::translate("MainWindowClass", "\345\215\225\345\207\273\344\273\245\344\276\277\346\211\223\345\274\200\345\267\245\347\250\213\346\220\234\347\264\242\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_showBottom->setText(QApplication::translate("MainWindowClass", "\350\276\223\345\207\272\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_showBottom->setToolTip(QApplication::translate("MainWindowClass", "\345\215\225\345\207\273\344\273\245\344\276\277\346\211\223\345\274\200\346\220\234\347\264\242\347\273\223\346\236\234\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_help->setText(QApplication::translate("MainWindowClass", "CodeView \344\275\277\347\224\250\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
        action_help->setShortcut(QApplication::translate("MainWindowClass", "F1", 0, QApplication::UnicodeUTF8));
        action_make->setText(QApplication::translate("MainWindowClass", "make all ", 0, QApplication::UnicodeUTF8));
        action_make->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+B", 0, QApplication::UnicodeUTF8));
        action_run->setText(QApplication::translate("MainWindowClass", "run", 0, QApplication::UnicodeUTF8));
        action_run->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        action_4->setText(QApplication::translate("MainWindowClass", "clean", 0, QApplication::UnicodeUTF8));
        action_4->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+L", 0, QApplication::UnicodeUTF8));
        actionMount->setText(QApplication::translate("MainWindowClass", "mount", 0, QApplication::UnicodeUTF8));
        actionMount->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+M", 0, QApplication::UnicodeUTF8));
        actionUmount->setText(QApplication::translate("MainWindowClass", "umount", 0, QApplication::UnicodeUTF8));
        actionUmount->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+U", 0, QApplication::UnicodeUTF8));
        action_6->setText(QApplication::translate("MainWindowClass", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MainWindowClass", "\346\225\264\347\220\206\346\240\274\345\274\217", 0, QApplication::UnicodeUTF8));
        action->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+I", 0, QApplication::UnicodeUTF8));
        action_Option->setText(QApplication::translate("MainWindowClass", "\351\200\211\351\241\271(&O)", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        label_13->setText(QApplication::translate("MainWindowClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"http://code.google.com/p/codeview/\"><span style=\" text-decoration: underline; color:#0000ff;\">http://code.google.com/p/codeview/</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_newPro1->setText(QString());
        label_newPro2->setText(QApplication::translate("MainWindowClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"1\"><span style=\" font-size:10pt; text-decoration: underline; color:#0000ff;\">\346\226\260\345\273\272\345\267\245\347\250\213</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_recentPro1->setText(QString());
        label_recentPro2->setText(QApplication::translate("MainWindowClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"2\"><span style=\" font-size:10pt; text-decoration: underline; color:#0000ff;\">\346\211\223\345\274\200\345\267\262\346\234\211\347\232\204\345\267\245\347\250\213</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label_3->setText(QApplication::translate("MainWindowClass", "\346\234\200\350\277\221\346\211\223\345\274\200\347\232\204\345\267\245\347\250\213", 0, QApplication::UnicodeUTF8));
        label_recentPro->setText(QApplication::translate("MainWindowClass", "   \346\227\240\346\234\200\350\277\221\346\211\223\345\274\200\347\232\204\345\267\245\347\250\213", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
        label_recentd->setText(QApplication::translate("MainWindowClass", "\346\234\200\350\277\221\346\211\223\345\274\200\347\232\204\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        label_recentFile->setText(QApplication::translate("MainWindowClass", "   \346\227\240\346\234\200\350\277\221\346\211\223\345\274\200\347\232\204\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindowClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0000ff;\">bug\345\217\215\351\246\210\357\274\232gaohandongde126.com</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindowClass", "\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabToolTip(tabWidget->indexOf(tab), QApplication::translate("MainWindowClass", "start", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindowClass", "\346\226\207\344\273\266(&F)", 0, QApplication::UnicodeUTF8));
        menu_T->setTitle(QApplication::translate("MainWindowClass", "\345\267\245\347\250\213(&P)", 0, QApplication::UnicodeUTF8));
        menu_H->setTitle(QApplication::translate("MainWindowClass", "\345\270\256\345\212\251(H)", 0, QApplication::UnicodeUTF8));
        menu_E->setTitle(QApplication::translate("MainWindowClass", "\347\274\226\350\276\221(&E)", 0, QApplication::UnicodeUTF8));
        menu_W->setTitle(QApplication::translate("MainWindowClass", "\347\252\227\345\217\243(&W)", 0, QApplication::UnicodeUTF8));
        menuOslab->setTitle(QApplication::translate("MainWindowClass", "os&lab", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindowClass", "\345\267\245\345\205\267\346\240\217", 0, QApplication::UnicodeUTF8));
        dockWidget->setWindowTitle(QApplication::translate("MainWindowClass", "\346\234\252\351\200\211\346\213\251\345\267\245\347\250\213", 0, QApplication::UnicodeUTF8));
        dockWidget_2->setWindowTitle(QApplication::translate("MainWindowClass", "\350\276\223\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
