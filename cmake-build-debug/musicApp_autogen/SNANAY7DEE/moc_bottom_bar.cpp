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
    QByteArrayData data[13];
    char stringdata0[116];
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
QT_MOC_LITERAL(5, 27, 4), // "favo"
QT_MOC_LITERAL(6, 32, 6), // "circle"
QT_MOC_LITERAL(7, 39, 10), // "paintEvent"
QT_MOC_LITERAL(8, 50, 12), // "QPaintEvent*"
QT_MOC_LITERAL(9, 63, 5), // "event"
QT_MOC_LITERAL(10, 69, 15), // "mousePressEvent"
QT_MOC_LITERAL(11, 85, 12), // "QMouseEvent*"
QT_MOC_LITERAL(12, 98, 17) // "mouseReleaseEvent"

    },
    "Bottom_bar\0play\0\0next\0last\0favo\0circle\0"
    "paintEvent\0QPaintEvent*\0event\0"
    "mousePressEvent\0QMouseEvent*\0"
    "mouseReleaseEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Bottom_bar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   59,    2, 0x0a /* Public */,
      10,    1,   62,    2, 0x0a /* Public */,
      12,    1,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    9,
    QMetaType::Void, 0x80000000 | 11,    9,

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
        case 3: _t->favo(); break;
        case 4: _t->circle(); break;
        case 5: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 6: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bottom_bar::favo)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Bottom_bar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bottom_bar::circle)) {
                *result = 4;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
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
void Bottom_bar::favo()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Bottom_bar::circle()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
