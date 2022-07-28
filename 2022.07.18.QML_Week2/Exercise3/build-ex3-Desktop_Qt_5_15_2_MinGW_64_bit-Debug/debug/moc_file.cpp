/****************************************************************************
** Meta object code from reading C++ file 'file.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ex3/file.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'file.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StaffList_t {
    QByteArrayData data[20];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StaffList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StaffList_t qt_meta_stringdata_StaffList = {
    {
QT_MOC_LITERAL(0, 0, 9), // "StaffList"
QT_MOC_LITERAL(1, 10, 10), // "cidChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "listChanged"
QT_MOC_LITERAL(4, 34, 8), // "getStaff"
QT_MOC_LITERAL(5, 43, 3), // "pos"
QT_MOC_LITERAL(6, 47, 12), // "loadFromFile"
QT_MOC_LITERAL(7, 60, 10), // "saveToFile"
QT_MOC_LITERAL(8, 71, 8), // "addStaff"
QT_MOC_LITERAL(9, 80, 4), // "name"
QT_MOC_LITERAL(10, 85, 3), // "age"
QT_MOC_LITERAL(11, 89, 4), // "role"
QT_MOC_LITERAL(12, 94, 11), // "updateStaff"
QT_MOC_LITERAL(13, 106, 8), // "new_name"
QT_MOC_LITERAL(14, 115, 7), // "new_age"
QT_MOC_LITERAL(15, 123, 8), // "new_role"
QT_MOC_LITERAL(16, 132, 11), // "deleteStaff"
QT_MOC_LITERAL(17, 144, 3), // "cid"
QT_MOC_LITERAL(18, 148, 4), // "list"
QT_MOC_LITERAL(19, 153, 12) // "QList<Staff>"

    },
    "StaffList\0cidChanged\0\0listChanged\0"
    "getStaff\0pos\0loadFromFile\0saveToFile\0"
    "addStaff\0name\0age\0role\0updateStaff\0"
    "new_name\0new_age\0new_role\0deleteStaff\0"
    "cid\0list\0QList<Staff>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StaffList[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       2,   80, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    1,   56,    2, 0x02 /* Public */,
       6,    0,   59,    2, 0x02 /* Public */,
       7,    0,   60,    2, 0x02 /* Public */,
       8,    3,   61,    2, 0x02 /* Public */,
      12,    4,   68,    2, 0x02 /* Public */,
      16,    1,   77,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::QVariant, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    9,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::Int,    5,   13,   14,   15,
    QMetaType::Void, QMetaType::Int,    5,

 // properties: name, type, flags
      17, QMetaType::Int, 0x00495103,
      18, 0x80000000 | 19, 0x0049510b,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void StaffList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StaffList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cidChanged(); break;
        case 1: _t->listChanged(); break;
        case 2: { QVariant _r = _t->getStaff((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->loadFromFile(); break;
        case 4: _t->saveToFile(); break;
        case 5: _t->addStaff((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->updateStaff((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 7: _t->deleteStaff((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StaffList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StaffList::cidChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (StaffList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StaffList::listChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<StaffList *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->cid(); break;
        case 1: *reinterpret_cast< QList<Staff>*>(_v) = _t->list(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<StaffList *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setList(*reinterpret_cast< QList<Staff>*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject StaffList::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_StaffList.data,
    qt_meta_data_StaffList,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *StaffList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StaffList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StaffList.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int StaffList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void StaffList::cidChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void StaffList::listChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
