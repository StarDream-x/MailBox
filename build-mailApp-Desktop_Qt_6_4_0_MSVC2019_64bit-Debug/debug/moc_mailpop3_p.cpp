/****************************************************************************
** Meta object code from reading C++ file 'mailpop3_p.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mailApp/3rdparty/qtmail/src/mail/mailpop3_p.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mailpop3_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_QxtPop3Private_t {
    uint offsetsAndSizes[24];
    char stringdata0[15];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[29];
    char stringdata4[4];
    char stringdata5[13];
    char stringdata6[11];
    char stringdata7[8];
    char stringdata8[10];
    char stringdata9[5];
    char stringdata10[10];
    char stringdata11[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QxtPop3Private_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QxtPop3Private_t qt_meta_stringdata_QxtPop3Private = {
    {
        QT_MOC_LITERAL(0, 14),  // "QxtPop3Private"
        QT_MOC_LITERAL(15, 11),  // "socketError"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 28),  // "QAbstractSocket::SocketError"
        QT_MOC_LITERAL(57, 3),  // "err"
        QT_MOC_LITERAL(61, 12),  // "disconnected"
        QT_MOC_LITERAL(74, 10),  // "socketRead"
        QT_MOC_LITERAL(85, 7),  // "dequeue"
        QT_MOC_LITERAL(93, 9),  // "terminate"
        QT_MOC_LITERAL(103, 4),  // "code"
        QT_MOC_LITERAL(108, 9),  // "encrypted"
        QT_MOC_LITERAL(118, 13)   // "authenticated"
    },
    "QxtPop3Private",
    "socketError",
    "",
    "QAbstractSocket::SocketError",
    "err",
    "disconnected",
    "socketRead",
    "dequeue",
    "terminate",
    "code",
    "encrypted",
    "authenticated"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QxtPop3Private[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x0a,    1 /* Public */,
       5,    0,   59,    2, 0x0a,    3 /* Public */,
       6,    0,   60,    2, 0x0a,    4 /* Public */,
       7,    0,   61,    2, 0x0a,    5 /* Public */,
       8,    1,   62,    2, 0x0a,    6 /* Public */,
      10,    0,   65,    2, 0x0a,    8 /* Public */,
      11,    0,   66,    2, 0x0a,    9 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject QxtPop3Private::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QxtPop3Private.offsetsAndSizes,
    qt_meta_data_QxtPop3Private,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QxtPop3Private_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QxtPop3Private, std::true_type>,
        // method 'socketError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>,
        // method 'disconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'socketRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dequeue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'terminate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'encrypted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'authenticated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QxtPop3Private::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QxtPop3Private *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->socketError((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 1: _t->disconnected(); break;
        case 2: _t->socketRead(); break;
        case 3: _t->dequeue(); break;
        case 4: _t->terminate((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->encrypted(); break;
        case 6: _t->authenticated(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject *QxtPop3Private::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QxtPop3Private::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QxtPop3Private.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QxtPop3Private::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
