/****************************************************************************
** Meta object code from reading C++ file 'light_adaptor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../light_adaptor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'light_adaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyLightAdaptor_t {
    QByteArrayData data[10];
    char stringdata0[317];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyLightAdaptor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyLightAdaptor_t qt_meta_stringdata_MyLightAdaptor = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MyLightAdaptor"
QT_MOC_LITERAL(1, 15, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 31, 13), // "local.MyLight"
QT_MOC_LITERAL(3, 45, 19), // "D-Bus Introspection"
QT_MOC_LITERAL(4, 65, 217), // "  <interface name=\"local.MyL..."
QT_MOC_LITERAL(5, 263, 12), // "lightChanged"
QT_MOC_LITERAL(6, 276, 0), // ""
QT_MOC_LITERAL(7, 277, 7), // "turnOff"
QT_MOC_LITERAL(8, 285, 6), // "turnOn"
QT_MOC_LITERAL(9, 292, 4) // "isOn"

    },
    "MyLightAdaptor\0D-Bus Interface\0"
    "local.MyLight\0D-Bus Introspection\0"
    "  <interface name=\"local.MyLight\">\n    <property access=\"readwrite"
    "\" type=\"b\" name=\"isOn\"/>\n    <signal name=\"lightChanged\"/>\n  "
    "  <method name=\"turnOn\"/>\n    <method name=\"turnOff\"/>\n  </inter"
    "face>\n\0"
    "lightChanged\0\0turnOff\0turnOn\0isOn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyLightAdaptor[] = {

 // content:
       8,       // revision
       0,       // classname
       2,   14, // classinfo
       3,   18, // methods
       1,   36, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // signals: name, argc, parameters, tag, flags
       5,    0,   33,    6, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   34,    6, 0x0a /* Public */,
       8,    0,   35,    6, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       9, QMetaType::Bool, 0x00095103,

       0        // eod
};

void MyLightAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyLightAdaptor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lightChanged(); break;
        case 1: _t->turnOff(); break;
        case 2: _t->turnOn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyLightAdaptor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLightAdaptor::lightChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MyLightAdaptor *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isOn(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MyLightAdaptor *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setIsOn(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MyLightAdaptor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractAdaptor::staticMetaObject>(),
    qt_meta_stringdata_MyLightAdaptor.data,
    qt_meta_data_MyLightAdaptor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyLightAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyLightAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyLightAdaptor.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int MyLightAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MyLightAdaptor::lightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
