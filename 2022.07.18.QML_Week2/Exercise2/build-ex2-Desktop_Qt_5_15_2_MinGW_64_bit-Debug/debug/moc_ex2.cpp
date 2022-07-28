/****************************************************************************
** Meta object code from reading C++ file 'ex2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ex2/ex2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ex2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_addingButton_t {
    QByteArrayData data[12];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_addingButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_addingButton_t qt_meta_stringdata_addingButton = {
    {
QT_MOC_LITERAL(0, 0, 12), // "addingButton"
QT_MOC_LITERAL(1, 13, 12), // "shapeChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "colorChanged"
QT_MOC_LITERAL(4, 40, 13), // "numberChanged"
QT_MOC_LITERAL(5, 54, 7), // "addItem"
QT_MOC_LITERAL(6, 62, 3), // "_sh"
QT_MOC_LITERAL(7, 66, 2), // "_c"
QT_MOC_LITERAL(8, 69, 2), // "_n"
QT_MOC_LITERAL(9, 72, 5), // "shape"
QT_MOC_LITERAL(10, 78, 5), // "color"
QT_MOC_LITERAL(11, 84, 6) // "number"

    },
    "addingButton\0shapeChanged\0\0colorChanged\0"
    "numberChanged\0addItem\0_sh\0_c\0_n\0shape\0"
    "color\0number"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addingButton[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       3,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int,    6,    7,    8,

 // properties: name, type, flags
       9, QMetaType::Int, 0x00495103,
      10, QMetaType::QString, 0x00495103,
      11, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void addingButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<addingButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->shapeChanged(); break;
        case 1: _t->colorChanged(); break;
        case 2: _t->numberChanged(); break;
        case 3: _t->addItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (addingButton::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&addingButton::shapeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (addingButton::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&addingButton::colorChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (addingButton::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&addingButton::numberChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<addingButton *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->shape(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->color(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->number(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<addingButton *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setShape(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setColor(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setNumber(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject addingButton::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_addingButton.data,
    qt_meta_data_addingButton,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *addingButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addingButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_addingButton.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int addingButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void addingButton::shapeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void addingButton::colorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void addingButton::numberChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
