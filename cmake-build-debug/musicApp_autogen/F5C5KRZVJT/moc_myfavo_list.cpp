/****************************************************************************
** Meta object code from reading C++ file 'myfavo_list.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/main/myfavo_list/myfavo_list.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myfavo_list.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Myfavo_list_t {
    QByteArrayData data[11];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Myfavo_list_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Myfavo_list_t qt_meta_stringdata_Myfavo_list = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Myfavo_list"
QT_MOC_LITERAL(1, 12, 7), // "tranSig"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "Song"
QT_MOC_LITERAL(4, 26, 4), // "song"
QT_MOC_LITERAL(5, 31, 7), // "favoSig"
QT_MOC_LITERAL(6, 39, 9), // "deFavoSig"
QT_MOC_LITERAL(7, 49, 9), // "tranSlot1"
QT_MOC_LITERAL(8, 59, 9), // "tranSlot2"
QT_MOC_LITERAL(9, 69, 9), // "tranSlot3"
QT_MOC_LITERAL(10, 79, 14) // "bot_favoChange"

    },
    "Myfavo_list\0tranSig\0\0Song\0song\0favoSig\0"
    "deFavoSig\0tranSlot1\0tranSlot2\0tranSlot3\0"
    "bot_favoChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Myfavo_list[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   58,    2, 0x0a /* Public */,
       8,    1,   61,    2, 0x0a /* Public */,
       9,    1,   64,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void Myfavo_list::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Myfavo_list *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tranSig((*reinterpret_cast< Song(*)>(_a[1]))); break;
        case 1: _t->favoSig((*reinterpret_cast< Song(*)>(_a[1]))); break;
        case 2: _t->deFavoSig((*reinterpret_cast< Song(*)>(_a[1]))); break;
        case 3: _t->tranSlot1((*reinterpret_cast< Song(*)>(_a[1]))); break;
        case 4: _t->tranSlot2((*reinterpret_cast< Song(*)>(_a[1]))); break;
        case 5: _t->tranSlot3((*reinterpret_cast< Song(*)>(_a[1]))); break;
        case 6: _t->bot_favoChange((*reinterpret_cast< Song(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Myfavo_list::*)(Song );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Myfavo_list::tranSig)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Myfavo_list::*)(Song );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Myfavo_list::favoSig)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Myfavo_list::*)(Song );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Myfavo_list::deFavoSig)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Myfavo_list::staticMetaObject = { {
    QMetaObject::SuperData::link<QScrollArea::staticMetaObject>(),
    qt_meta_stringdata_Myfavo_list.data,
    qt_meta_data_Myfavo_list,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Myfavo_list::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Myfavo_list::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Myfavo_list.stringdata0))
        return static_cast<void*>(this);
    return QScrollArea::qt_metacast(_clname);
}

int Myfavo_list::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Myfavo_list::tranSig(Song _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Myfavo_list::favoSig(Song _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Myfavo_list::deFavoSig(Song _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
