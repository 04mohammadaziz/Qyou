/****************************************************************************
** Meta object code from reading C++ file 'eventModel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../qYouCalendar/eventModel.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eventModel.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_EventModel_t {
    uint offsetsAndSizes[22];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[12];
    char stringdata5[9];
    char stringdata6[5];
    char stringdata7[10];
    char stringdata8[8];
    char stringdata9[12];
    char stringdata10[3];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_EventModel_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_EventModel_t qt_meta_stringdata_EventModel = {
    {
        QT_MOC_LITERAL(0, 10),  // "EventModel"
        QT_MOC_LITERAL(11, 13),  // "eventsForDate"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 4),  // "date"
        QT_MOC_LITERAL(31, 11),  // "createEvent"
        QT_MOC_LITERAL(43, 8),  // "addEvent"
        QT_MOC_LITERAL(52, 4),  // "name"
        QT_MOC_LITERAL(57, 9),  // "startTime"
        QT_MOC_LITERAL(67, 7),  // "endTime"
        QT_MOC_LITERAL(75, 11),  // "removeEvent"
        QT_MOC_LITERAL(87, 2)   // "id"
    },
    "EventModel",
    "eventsForDate",
    "",
    "date",
    "createEvent",
    "addEvent",
    "name",
    "startTime",
    "endTime",
    "removeEvent",
    "id"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_EventModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x02,    1 /* Public */,
       4,    0,   41,    2, 0x02,    3 /* Public */,
       5,    4,   42,    2, 0x02,    4 /* Public */,
       9,    1,   51,    2, 0x02,    9 /* Public */,

 // methods: parameters
    QMetaType::QVariantList, QMetaType::QDateTime,    3,
    QMetaType::QObjectStar,
    QMetaType::Void, QMetaType::QString, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString,    6,    3,    7,    8,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject EventModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EventModel.offsetsAndSizes,
    qt_meta_data_EventModel,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_EventModel_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<EventModel, std::true_type>,
        // method 'eventsForDate'
        QtPrivate::TypeAndForceComplete<QVariantList, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime &, std::false_type>,
        // method 'createEvent'
        QtPrivate::TypeAndForceComplete<QObject *, std::false_type>,
        // method 'addEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'removeEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>
    >,
    nullptr
} };

void EventModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EventModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QVariantList _r = _t->eventsForDate((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 1: { QObject* _r = _t->createEvent();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 2: _t->addEvent((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 3: _t->removeEvent((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *EventModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EventModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EventModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
