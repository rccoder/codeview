/****************************************************************************
** Meta object code from reading C++ file 'linenumberarea.h'
**
** Created: Sun Sep 13 16:44:37 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "linenumberarea.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linenumberarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CodeEditer[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      26,   12,   11,   11, 0x08,
      57,   11,   11,   11, 0x08,
      82,   80,   11,   11, 0x08,
     120,  114,   11,   11, 0x08,
     132,   11,   11,   11, 0x28,
     141,  114,   11,   11, 0x08,
     154,   11,   11,   11, 0x28,
     164,   11,   11,   11, 0x08,
     173,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CodeEditer[] = {
    "CodeEditer\0\0newBlockCount\0"
    "updateLineNumberAreaWidth(int)\0"
    "highlightCurrentLine()\0,\0"
    "updateLineNumberArea(QRect,int)\0range\0"
    "zoomIn(int)\0zoomIn()\0zoomOut(int)\0"
    "zoomOut()\0setTab()\0setFileChange(bool)\0"
};

const QMetaObject CodeEditer::staticMetaObject = {
    { &QPlainTextEdit::staticMetaObject, qt_meta_stringdata_CodeEditer,
      qt_meta_data_CodeEditer, 0 }
};

const QMetaObject *CodeEditer::metaObject() const
{
    return &staticMetaObject;
}

void *CodeEditer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CodeEditer))
        return static_cast<void*>(const_cast< CodeEditer*>(this));
    return QPlainTextEdit::qt_metacast(_clname);
}

int CodeEditer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateLineNumberAreaWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: highlightCurrentLine(); break;
        case 2: updateLineNumberArea((*reinterpret_cast< const QRect(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: zoomIn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: zoomIn(); break;
        case 5: zoomOut((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: zoomOut(); break;
        case 7: setTab(); break;
        case 8: setFileChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
