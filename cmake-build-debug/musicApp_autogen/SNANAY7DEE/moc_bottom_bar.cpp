/****************************************************************************
** Meta object code from reading C++ file 'bottom_bar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/main/bottom_bar/bottom_bar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bottom_bar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Bottom_bar_t {
    QByteArrayData data[19];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Bottom_bar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Bottom_bar_t qt_meta_stringdata_Bottom_bar = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Bottom_bar"
QT_MOC_LITERAL(1, 11, 4), // "play"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 4), // "next"
QT_MOC_LITERAL(4, 22, 4), // "last"
QT_MOC_LITERAL(5, 27, 6), // "circle"
QT_MOC_LITERAL(6, 34, 4), // "favo"
QT_MOC_LITERAL(7, 39, 4), // "Song"
QT_MOC_LITERAL(8, 44, 4), // "song"
QT_MOC_LITERAL(9, 49, 6), // "deFavo"
QT_MOC_LITERAL(10, 56, 22), // "bottom_bar_valueChange"
QT_MOC_LITERAL(11, 79, 5), // "value"
QT_MOC_LITERAL(12, 85, 10), // "paintEvent"
QT_MOC_LITERAL(13, 96, 12), // "QPaintEvent*"
QT_MOC_LITERAL(14, 109, 5), // "event"
QT_MOC_LITERAL(15, 115, 15), // "mousePressEvent"
QT_MOC_LITERAL(16, 131, 12), // "QMouseEvent*"
QT_MOC_LITERAL(17, 144, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(18, 162, 16) // "valueChangedSlot"

    },
    "Bottom_bar\0play\0\0next\0last\0circle\0"
    "favo\0Song\0song\0deFavo\0bottom_bar_valueChange\0"
    "value\0paintEvent\0QPaintEvent*\0event\0"
    "mousePressEvent\0QMouseEvent*\0"
    "mouseReleaseEvent\0valueChangedSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Bottom_bar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    0,   72,    2, 0x06 /* Public */,
       6,    1,   73,    2, 0x06 /* Public */,
       9,    1,   76,    2, 0x06 /* Public */,
      10,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   82,    2, 0x0a /* Public */,
      15,    1,   85,    2, 0x0a /* Public */,
      17,    1,   88,    2, 0x0a /* Public */,
      18,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int,   11,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   14,
    QMetaType::Void, 0x80000000 | 16,   14,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void Bottom_bar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Bottom_bar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->play(); break;
        case 1: _t->next(); break;
        case 2: _t->last(); break;
        case 3: _t->circle(); break;
        case 4: _t->favo((*reinterpret_cast< Song(*)>(_a[1]))); break;
        case 5: _t->deFavo((*reinterpret_cast< Song(*)>(_a[1]))); break;
        case 6: _t->bottom_bar_valueChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 8: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 9: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 10: _t->valueChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Bottom_bar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bottom_bar::play)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Bottom_bar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bottom_bar::next)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Bottom_bar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bottom_bar::last)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Bottom_bar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bottom_bar::circle)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Bottom_bar::*)(Song );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bottom_bar::favo)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Bottom_bar::*)(Song );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bottom_bar::deFavo)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Bottom_bar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bottom_bar::bottom_bar_valueChange)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Bottom_bar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Bottom_bar.data,
    qt_meta_data_Bottom_bar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Bottom_bar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Bottom_bar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Bottom_bar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Bottom_bar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Bottom_bar::play()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Bottom_bar::next()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Bottom_bar::last()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Bottom_bar::circle()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Bottom_bar::favo(Song _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Bottom_bar::deFavo(Song _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Bottom_bar::bottom_bar_valueChange(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
