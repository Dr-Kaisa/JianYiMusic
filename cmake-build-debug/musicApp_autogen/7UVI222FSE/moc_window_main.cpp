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
    QByteArrayData data[23];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_main_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_main_t qt_meta_stringdata_Window_main = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Window_main"
QT_MOC_LITERAL(1, 12, 20), // "trans_bot_favoChange"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "Song"
QT_MOC_LITERAL(4, 39, 4), // "song"
QT_MOC_LITERAL(5, 44, 11), // "load_config"
QT_MOC_LITERAL(6, 56, 17), // "enableResizeEvent"
QT_MOC_LITERAL(7, 74, 16), // "play_target_song"
QT_MOC_LITERAL(8, 91, 15), // "handle_bot_favo"
QT_MOC_LITERAL(9, 107, 17), // "handle_bot_deFavo"
QT_MOC_LITERAL(10, 125, 10), // "handleLast"
QT_MOC_LITERAL(11, 136, 10), // "handlePlay"
QT_MOC_LITERAL(12, 147, 10), // "handleNext"
QT_MOC_LITERAL(13, 158, 12), // "handleCircle"
QT_MOC_LITERAL(14, 171, 13), // "handleFavoSig"
QT_MOC_LITERAL(15, 185, 10), // "targetSong"
QT_MOC_LITERAL(16, 196, 15), // "handleDeFavoSig"
QT_MOC_LITERAL(17, 212, 15), // "changeContainer"
QT_MOC_LITERAL(18, 228, 6), // "target"
QT_MOC_LITERAL(19, 235, 12), // "changeVolume"
QT_MOC_LITERAL(20, 248, 5), // "value"
QT_MOC_LITERAL(21, 254, 12), // "handleSearch"
QT_MOC_LITERAL(22, 267, 3) // "str"

    },
    "Window_main\0trans_bot_favoChange\0\0"
    "Song\0song\0load_config\0enableResizeEvent\0"
    "play_target_song\0handle_bot_favo\0"
    "handle_bot_deFavo\0handleLast\0handlePlay\0"
    "handleNext\0handleCircle\0handleFavoSig\0"
    "targetSong\0handleDeFavoSig\0changeContainer\0"
    "target\0changeVolume\0value\0handleSearch\0"
    "str"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window_main[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    1,   94,    2, 0x08 /* Private */,
       8,    1,   97,    2, 0x08 /* Private */,
       9,    1,  100,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    1,  107,    2, 0x08 /* Private */,
      16,    1,  110,    2, 0x08 /* Private */,
      17,    1,  113,    2, 0x08 /* Private */,
      19,    1,  116,    2, 0x08 /* Private */,
      21,    1,  119,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   15,
    QMetaType::Void, 0x80000000 | 3,   15,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QString,   22,

       0        // eod
};

void Window_main::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Window_main *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->trans_bot_favoChange((*reinterpret_cast< Song(*)>(_a[1]))); break;
        case 1: _t->load_config(); break;
        case 2: _t->enableResizeEvent(); break;
        case 3: _t->play_target_song((*reinterpret_cast< Song(*)>(_a[1]))); break;
        case 4: _t->handle_bot_favo((*reinterpret_cast< Song(*)>(_a[1]))); break;
        case 5: _t->handle_bot_deFavo((*reinterpret_cast< Song(*)>(_a[1]))); break;
        case 6: _t->handleLast(); break;
        case 7: _t->handlePlay(); break;
        case 8: _t->handleNext(); break;
        case 9: _t->handleCircle(); break;
        case 10: _t->handleFavoSig((*reinterpret_cast< Song(*)>(_a[1]))); break;
        case 11: _t->handleDeFavoSig((*reinterpret_cast< Song(*)>(_a[1]))); break;
        case 12: _t->changeContainer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->changeVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->handleSearch((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Window_main::*)(Song );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Window_main::trans_bot_favoChange)) {
                *result = 0;
                return;
            }
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Window_main::trans_bot_favoChange(Song _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
