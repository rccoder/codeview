/****************************************************************************
** Meta object code from reading C++ file 'bottomoutputwidget.h'
**
** Created: Thu Sep 3 09:26:25 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bottomoutputwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bottomoutputwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BottomOutputWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      48,   46,   19,   19, 0x05,
      78,   46,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     130,  108,   19,   19, 0x0a,
     167,   19,   19,   19, 0x0a,
     180,   19,   19,   19, 0x0a,
     188,   19,   19,   19, 0x0a,
     195,   19,   19,   19, 0x0a,
     201,   19,   19,   19, 0x0a,
     209,   19,   19,   19, 0x0a,
     218,   19,   19,   19, 0x0a,
     249,  243,   19,   19, 0x08,
     287,   19,   19,   19, 0x08,
     322,  302,   19,   19, 0x08,
     365,  302,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BottomOutputWidget[] = {
    "BottomOutputWidget\0\0labelLinkClicked(QString)\0"
    ",\0errorFileClicked(QString,int)\0"
    "statusBarMessage(QString,int)\0"
    ",classOrStruct,simple\0"
    "showAllInIt(vector<chain>,bool,bool)\0"
    "clearLabel()\0clean()\0make()\0run()\0"
    "mount()\0umount()\0removingCurrentProject()\0"
    "index\0on_tableWidget_activated(QModelIndex)\0"
    "defOrNotText()\0exitCode,exitStatus\0"
    "showMakeMessages(int,QProcess::ExitStatus)\0"
    "showNotMakeMessages(int,QProcess::ExitStatus)\0"
};

const QMetaObject BottomOutputWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BottomOutputWidget,
      qt_meta_data_BottomOutputWidget, 0 }
};

const QMetaObject *BottomOutputWidget::metaObject() const
{
    return &staticMetaObject;
}

void *BottomOutputWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BottomOutputWidget))
        return static_cast<void*>(const_cast< BottomOutputWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BottomOutputWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: labelLinkClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: errorFileClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: statusBarMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: showAllInIt((*reinterpret_cast< vector<chain>(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: clearLabel(); break;
        case 5: clean(); break;
        case 6: make(); break;
        case 7: run(); break;
        case 8: mount(); break;
        case 9: umount(); break;
        case 10: removingCurrentProject(); break;
        case 11: on_tableWidget_activated((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 12: defOrNotText(); break;
        case 13: showMakeMessages((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 14: showNotMakeMessages((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void BottomOutputWidget::labelLinkClicked(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BottomOutputWidget::errorFileClicked(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BottomOutputWidget::statusBarMessage(const QString & _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
