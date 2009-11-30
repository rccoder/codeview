/****************************************************************************
** Meta object code from reading C++ file 'leftindexwidget.h'
**
** Created: Fri Aug 28 19:48:43 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "leftindexwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'leftindexwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LeftIndexWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      39,   17,   16,   16, 0x05,
      89,   16,   16,   16, 0x05,
     128,   16,   16,   16, 0x05,
     176,  162,   16,   16, 0x05,
     206,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     231,   16,   16,   16, 0x0a,
     270,  265,   16,   16, 0x0a,
     297,   16,   16,   16, 0x08,
     340,   16,   16,   16, 0x08,
     354,  349,   16,   16, 0x08,
     380,   16,   16,   16, 0x08,
     440,  428,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LeftIndexWidget[] = {
    "LeftIndexWidget\0\0,classOrStruct,simple\0"
    "pathsInIdentifierChanged(vector<chain>,bool,bool)\0"
    "tellMainCurrentProjectChanged(QString)\0"
    "tellBottomCurrentProjectChanged()\0"
    "filename,line\0showFileInEditor(QString,int)\0"
    "removingCurrentProject()\0"
    "isRemovingCurrentProject(QString)\0"
    "name\0setCurrentProject(QString)\0"
    "on_lineEdit_fileFilter_textEdited(QString)\0"
    "search()\0text\0enableFindButton(QString)\0"
    "tellBottomPathsInIdentifierChanged(QModelIndex)\0"
    "item,column\0getActivatedFile(QTreeWidgetItem*,int)\0"
};

const QMetaObject LeftIndexWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LeftIndexWidget,
      qt_meta_data_LeftIndexWidget, 0 }
};

const QMetaObject *LeftIndexWidget::metaObject() const
{
    return &staticMetaObject;
}

void *LeftIndexWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LeftIndexWidget))
        return static_cast<void*>(const_cast< LeftIndexWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int LeftIndexWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: pathsInIdentifierChanged((*reinterpret_cast< vector<chain>(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: tellMainCurrentProjectChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: tellBottomCurrentProjectChanged(); break;
        case 3: showFileInEditor((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: removingCurrentProject(); break;
        case 5: isRemovingCurrentProject((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: setCurrentProject((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: on_lineEdit_fileFilter_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: search(); break;
        case 9: enableFindButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: tellBottomPathsInIdentifierChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: getActivatedFile((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void LeftIndexWidget::pathsInIdentifierChanged(vector<chain> _t1, bool _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LeftIndexWidget::tellMainCurrentProjectChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LeftIndexWidget::tellBottomCurrentProjectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void LeftIndexWidget::showFileInEditor(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LeftIndexWidget::removingCurrentProject()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
