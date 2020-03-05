/****************************************************************************
** Meta object code from reading C++ file 'StateMgr.h'
**
** Created: Mon Apr 12 04:15:07 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../StateMgr.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StateMgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StateMgr[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      27,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_StateMgr[] = {
    "StateMgr\0\0MenuWidgetSlot()\0OverWidgetSlot()\0"
};

const QMetaObject StateMgr::staticMetaObject = {
    { &QStackedWidget::staticMetaObject, qt_meta_stringdata_StateMgr,
      qt_meta_data_StateMgr, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StateMgr::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StateMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StateMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StateMgr))
        return static_cast<void*>(const_cast< StateMgr*>(this));
    return QStackedWidget::qt_metacast(_clname);
}

int StateMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStackedWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: MenuWidgetSlot(); break;
        case 1: OverWidgetSlot(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
