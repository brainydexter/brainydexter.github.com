/****************************************************************************
** Meta object code from reading C++ file 'GameGL.h'
**
** Created: Mon Apr 12 04:15:10 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GameGL.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameGL.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameGL[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,    8,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,    8,    7,    7, 0x0a,
      48,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GameGL[] = {
    "GameGL\0\0status\0GameOver(int)\0"
    "GameCompleted(int)\0setNum_AI_Players(int)\0"
};

const QMetaObject GameGL::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GameGL,
      qt_meta_data_GameGL, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameGL::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameGL::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameGL))
        return static_cast<void*>(const_cast< GameGL*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GameGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: GameOver((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: GameCompleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: setNum_AI_Players((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void GameGL::GameOver(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
