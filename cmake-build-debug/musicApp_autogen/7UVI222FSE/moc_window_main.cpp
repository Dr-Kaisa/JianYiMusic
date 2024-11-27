/****************************************************************************
** Meta object code from reading C++ file 'window_main.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/window_main/window_main.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window_main.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Window_main_t {
    QByteArrayData data[13];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_main_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_main_t qt_meta_stringdata_Window_main = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Window_main"
QT_MOC_LITERAL(1, 12, 11), // "load_config"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 17), // "enableResizeEvent"
QT_MOC_LITERAL(4, 43, 16), // "play_target_song"
QT_MOC_LITERAL(5, 60, 4), // "Song"
QT_MOC_LITERAL(6, 65, 4), // "song"
QT_MOC_LITERAL(7, 70, 10), // "handleFavo"
QT_MOC_LITERAL(8, 81, 10), // "handleLast"
QT_MOC_LITERAL(9, 92, 10), // "handlePlay"
QT_MOC_LITERAL(10, 103, 10), // "handleNext"
QT_MOC_LITERAL(11, 114, 12), // "handleCircle"
QT_MOC_LITERAL(12, 127, 13) // "handleFavoSig"

    },
    "Window_main\0load_config\0\0enableResizeEvent\0"
    "play_target_song\0Song\0song\0handleFavo\0"
    "handleLast\0handlePlay\0handleNext\0"
    "handleCircle\0handleFavoSig"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window_main[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    1,   61,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,
      11,    0,   68,    2, 0x08 /* Private */,
      12,    1,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void Window_main::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Window_main *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->load_config(); break;
        case 1: _t->enableResizeEvent(); break;
        case 2: _t->play_target_song((*reinterpret_cast< Song(*)>(_a[1]))); break;
        case 3: _t->handleFavo(); break;
        case 4: _t->handleLast(); break;
        case 5: _t->handlePlay(); break;
        case 6: _t->handleNext(); break;
        case 7: _t->handleCircle(); break;
        case 8: _t->handleFavoSig((*reinterpret_cast< Song(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Window_main::staticMetaObject = { {
    QMetaObject::SuperData::link<QStackedWidget::staticMetaObject>(),
    qt_meta_stringdata_Window_main.data,
    qt_meta_data_Window_main,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Window_main::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window_main::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Window_main.stringdata0))
        return static_cast<void*>(this);
    return QStackedWidget::qt_metacast(_clname);
}

int Window_main::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStackedWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
