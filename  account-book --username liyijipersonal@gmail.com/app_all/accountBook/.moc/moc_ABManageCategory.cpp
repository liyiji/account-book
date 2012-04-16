/****************************************************************************
** Meta object code from reading C++ file 'ABManageCategory.h'
**
** Created: Mon Apr 16 19:07:59 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ABManageCategory.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ABManageCategory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ABManageCategory[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      27,   17,   17,   17, 0x08,
      64,   17,   17,   17, 0x08,
      95,   17,   17,   17, 0x08,
     129,   17,   17,   17, 0x08,
     163,   17,   17,   17, 0x08,
     197,   17,   17,   17, 0x08,
     231,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ABManageCategory[] = {
    "ABManageCategory\0\0accept()\0"
    "slotClickButtonBox(QAbstractButton*)\0"
    "slotChangeComboNewBig(QString)\0"
    "slotChangeComboRenameBig(QString)\0"
    "slotChangeComboDeleteBig(QString)\0"
    "slotChangeComboRenameMid(QString)\0"
    "slotChangeComboDeleteMid(QString)\0"
    "slotChangeLineNewMid(QString)\0"
};

const QMetaObject ABManageCategory::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ABManageCategory,
      qt_meta_data_ABManageCategory, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ABManageCategory::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ABManageCategory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ABManageCategory::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ABManageCategory))
        return static_cast<void*>(const_cast< ABManageCategory*>(this));
    return QDialog::qt_metacast(_clname);
}

int ABManageCategory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: accept(); break;
        case 1: slotClickButtonBox((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 2: slotChangeComboNewBig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: slotChangeComboRenameBig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: slotChangeComboDeleteBig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: slotChangeComboRenameMid((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: slotChangeComboDeleteMid((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: slotChangeLineNewMid((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
