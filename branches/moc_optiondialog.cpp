/****************************************************************************
** Meta object code from reading C++ file 'optiondialog.h'
**
** Created: Fri Aug 28 19:48:45 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "optiondialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OptionDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      32,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OptionDialog[] = {
    "OptionDialog\0\0browseOslabPath()\0"
    "writeSettings()\0"
};

const QMetaObject OptionDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_OptionDialog,
      qt_meta_data_OptionDialog, 0 }
};

const QMetaObject *OptionDialog::metaObject() const
{
    return &staticMetaObject;
}

void *OptionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OptionDialog))
        return static_cast<void*>(const_cast< OptionDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int OptionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: browseOslabPath(); break;
        case 1: writeSettings(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
