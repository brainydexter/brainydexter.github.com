/****************************************************************************
** Meta object code from reading C++ file 'GameOverWidget.h'
**
** Created: Mon Apr 12 04:15:09 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GameOverWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameOverWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameOverWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      25,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   32,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GameOverWidget[] = {
    "GameOverWidget\0\0active()\0done()\0status\0"
    "GameStatusUpdated(int)\0"
};

const QMetaObject GameOverWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GameOverWidget,
      qt_meta_data_GameOverWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameOverWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameOverWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameOverWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameOverWidget))
        return static_cast<void*>(const_cast< GameOverWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int GameOverWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: active(); break;
        case 1: done(); break;
        case 2: GameStatusUpdated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void GameOverWidget::active()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GameOverWidget::done()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
