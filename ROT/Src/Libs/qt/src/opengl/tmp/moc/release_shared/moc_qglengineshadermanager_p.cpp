/****************************************************************************
** Meta object code from reading C++ file 'qglengineshadermanager_p.h'
**
** Created: Tue Dec 22 18:39:33 2009
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gl2paintengineex/qglengineshadermanager_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qglengineshadermanager_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QGLEngineSharedShaders[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_QGLEngineSharedShaders[] = {
    "QGLEngineSharedShaders\0\0"
    "shaderProgNeedsChanging()\0"
};

const QMetaObject QGLEngineSharedShaders::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QGLEngineSharedShaders,
      qt_meta_data_QGLEngineSharedShaders, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QGLEngineSharedShaders::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QGLEngineSharedShaders::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QGLEngineSharedShaders::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QGLEngineSharedShaders))
        return static_cast<void*>(const_cast< QGLEngineSharedShaders*>(this));
    return QObject::qt_metacast(_clname);
}

int QGLEngineSharedShaders::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: shaderProgNeedsChanging(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QGLEngineSharedShaders::shaderProgNeedsChanging()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_QGLEngineShaderManager[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QGLEngineShaderManager[] = {
    "QGLEngineShaderManager\0\0"
    "shaderProgNeedsChangingSlot()\0"
};

const QMetaObject QGLEngineShaderManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QGLEngineShaderManager,
      qt_meta_data_QGLEngineShaderManager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QGLEngineShaderManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QGLEngineShaderManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QGLEngineShaderManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QGLEngineShaderManager))
        return static_cast<void*>(const_cast< QGLEngineShaderManager*>(this));
    return QObject::qt_metacast(_clname);
}

int QGLEngineShaderManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: shaderProgNeedsChangingSlot(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
