/****************************************************************************
** Meta object code from reading C++ file 'pathdialog.h'
**
** Created: Fri Aug 28 19:48:39 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pathdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pathdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PathDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      23,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PathDialog[] = {
    "PathDialog\0\0traverse()\0addRootPath()\0"
};

const QMetaObject PathDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PathDialog,
      qt_meta_data_PathDialog, 0 }
};

const QMetaObject *PathDialog::metaObject() const
{
    return &staticMetaObject;
}

void *PathDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PathDialog))
        return static_cast<void*>(const_cast< PathDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PathDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: traverse(); break;
        case 1: addRootPath(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
