/****************************************************************************
** Meta object code from reading C++ file 'bluetooth.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Portable_Climate_Sensor/bluetooth.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetooth.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Bluetooth_t {
    QByteArrayData data[26];
    char stringdata0[328];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Bluetooth_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Bluetooth_t qt_meta_stringdata_Bluetooth = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Bluetooth"
QT_MOC_LITERAL(1, 10, 17), // "sendToTextBrowser"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "text"
QT_MOC_LITERAL(4, 34, 16), // "sendToListWidget"
QT_MOC_LITERAL(5, 51, 15), // "QListWidgetItem"
QT_MOC_LITERAL(6, 67, 4), // "item"
QT_MOC_LITERAL(7, 72, 23), // "enableObjectsMainWindow"
QT_MOC_LITERAL(8, 96, 14), // "updateElements"
QT_MOC_LITERAL(9, 111, 15), // "pushButton_show"
QT_MOC_LITERAL(10, 127, 9), // "addDevice"
QT_MOC_LITERAL(11, 137, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(12, 158, 4), // "info"
QT_MOC_LITERAL(13, 163, 12), // "scanFinished"
QT_MOC_LITERAL(14, 176, 11), // "pairingDone"
QT_MOC_LITERAL(15, 188, 17), // "QBluetoothAddress"
QT_MOC_LITERAL(16, 206, 7), // "address"
QT_MOC_LITERAL(17, 214, 30), // "QBluetoothLocalDevice::Pairing"
QT_MOC_LITERAL(18, 245, 7), // "pairing"
QT_MOC_LITERAL(19, 253, 15), // "socketConnected"
QT_MOC_LITERAL(20, 269, 8), // "readData"
QT_MOC_LITERAL(21, 278, 9), // "printData"
QT_MOC_LITERAL(22, 288, 8), // "QString&"
QT_MOC_LITERAL(23, 297, 4), // "data"
QT_MOC_LITERAL(24, 302, 10), // "enableList"
QT_MOC_LITERAL(25, 313, 14) // "connectionLost"

    },
    "Bluetooth\0sendToTextBrowser\0\0text\0"
    "sendToListWidget\0QListWidgetItem\0item\0"
    "enableObjectsMainWindow\0updateElements\0"
    "pushButton_show\0addDevice\0"
    "QBluetoothDeviceInfo\0info\0scanFinished\0"
    "pairingDone\0QBluetoothAddress\0address\0"
    "QBluetoothLocalDevice::Pairing\0pairing\0"
    "socketConnected\0readData\0printData\0"
    "QString&\0data\0enableList\0connectionLost"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Bluetooth[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       7,    0,   80,    2, 0x06 /* Public */,
       8,    1,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   84,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    2,   88,    2, 0x08 /* Private */,
      19,    0,   93,    2, 0x08 /* Private */,
      20,    0,   94,    2, 0x08 /* Private */,
      21,    1,   95,    2, 0x08 /* Private */,
      24,    0,   98,    2, 0x08 /* Private */,
      25,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 17,   16,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Bluetooth::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Bluetooth *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendToTextBrowser((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sendToListWidget((*reinterpret_cast< QListWidgetItem(*)>(_a[1]))); break;
        case 2: _t->enableObjectsMainWindow(); break;
        case 3: _t->updateElements((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->addDevice((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 5: _t->scanFinished(); break;
        case 6: _t->pairingDone((*reinterpret_cast< const QBluetoothAddress(*)>(_a[1])),(*reinterpret_cast< QBluetoothLocalDevice::Pairing(*)>(_a[2]))); break;
        case 7: _t->socketConnected(); break;
        case 8: _t->readData(); break;
        case 9: _t->printData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->enableList(); break;
        case 11: _t->connectionLost(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothAddress >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothLocalDevice::Pairing >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Bluetooth::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bluetooth::sendToTextBrowser)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Bluetooth::*)(QListWidgetItem );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bluetooth::sendToListWidget)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Bluetooth::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bluetooth::enableObjectsMainWindow)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Bluetooth::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bluetooth::updateElements)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Bluetooth::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Bluetooth.data,
    qt_meta_data_Bluetooth,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Bluetooth::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Bluetooth::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Bluetooth.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Bluetooth::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Bluetooth::sendToTextBrowser(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Bluetooth::sendToListWidget(QListWidgetItem _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Bluetooth::enableObjectsMainWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Bluetooth::updateElements(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
