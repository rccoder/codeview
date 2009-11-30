/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Sep 13 16:44:36 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   11,   11,   11, 0x0a,
      63,   58,   11,   11, 0x0a,
      95,   11,   11,   11, 0x08,
     110,   11,   11,   11, 0x08,
     144,  130,   11,   11, 0x08,
     174,   11,   11,   11, 0x08,
     183,   11,   11,   11, 0x08,
     204,   11,   11,   11, 0x08,
     231,   11,   11,   11, 0x08,
     238,   11,   11,   11, 0x08,
     245,   11,   11,   11, 0x08,
     254,   11,   11,   11, 0x08,
     260,   11,   11,   11, 0x08,
     267,   11,   11,   11, 0x08,
     275,   11,   11,   11, 0x08,
     283,   11,   11,   11, 0x08,
     290,   11,   11,   11, 0x08,
     297,   11,   11,   11, 0x08,
     308,   11,   11,   11, 0x08,
     321,   11,   11,   11, 0x08,
     334,   11,   11,   11, 0x08,
     348,   11,   11,   11, 0x08,
     372,   11,   11,   11, 0x08,
     379,   11,   11,   11, 0x08,
     398,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0startLabelRecentProClicked(QString)\0"
    "newFile()\0path\0showFileWithLineNumber(QString)\0"
    "startIndexer()\0findInText(QString)\0"
    "filename,line\0createCodeEditor(QString,int)\0"
    "delPro()\0delProQueue(QString)\0"
    "setCurrentProject(QString)\0open()\0"
    "save()\0saveAs()\0cut()\0copy()\0paste()\0"
    "about()\0redo()\0undo()\0showLeft()\0"
    "showBottom()\0showOption()\0closeTab(int)\0"
    "dealStartLable(QString)\0help()\0"
    "dealFindCombo(int)\0format()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startLabelRecentProClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: newFile(); break;
        case 2: showFileWithLineNumber((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: startIndexer(); break;
        case 4: findInText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: createCodeEditor((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: delPro(); break;
        case 7: delProQueue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: setCurrentProject((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: open(); break;
        case 10: save(); break;
        case 11: saveAs(); break;
        case 12: cut(); break;
        case 13: copy(); break;
        case 14: paste(); break;
        case 15: about(); break;
        case 16: redo(); break;
        case 17: undo(); break;
        case 18: showLeft(); break;
        case 19: showBottom(); break;
        case 20: showOption(); break;
        case 21: closeTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: dealStartLable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: help(); break;
        case 24: dealFindCombo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: format(); break;
        default: ;
        }
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::startLabelRecentProClicked(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
