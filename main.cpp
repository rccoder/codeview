#include <QtGui/QApplication>
#include <QtCore/QTextCodec>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

    MainWindow w;
    w.show();
    return a.exec();
}
