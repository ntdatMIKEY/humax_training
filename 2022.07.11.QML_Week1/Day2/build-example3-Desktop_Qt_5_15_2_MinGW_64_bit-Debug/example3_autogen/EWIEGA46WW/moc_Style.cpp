/****************************************************************************
** Meta object code from reading C++ file 'style.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../example3/style.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'style.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StyleClass_t {
    QByteArrayData data[5];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StyleClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StyleClass_t qt_meta_stringdata_StyleClass = {
    {
QT_MOC_LITERAL(0, 0, 10), // "StyleClass"
QT_MOC_LITERAL(1, 11, 7), // "EnStyle"
QT_MOC_LITERAL(2, 19, 3), // "RED"
QT_MOC_LITERAL(3, 23, 5), // "GREEN"
QT_MOC_LITERAL(4, 29, 4) // "BLUE"

    },
    "StyleClass\0EnStyle\0RED\0GREEN\0BLUE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StyleClass[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    3,   19,

 // enum data: key, value
       2, uint(StyleClass::RED),
       3, uint(StyleClass::GREEN),
       4, uint(StyleClass::BLUE),

       0        // eod
};

void StyleClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject StyleClass::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_StyleClass.data,
    qt_meta_data_StyleClass,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *StyleClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StyleClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StyleClass.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int StyleClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
