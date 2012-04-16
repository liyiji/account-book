/****************************************************************************
** Meta object code from reading C++ file 'ABTransactionDetail.h'
**
** Created: Mon Apr 16 19:07:56 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ABTransactionDetail.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ABTransactionDetail.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ABTransactionDetail[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      30,   20,   20,   20, 0x08,
      56,   20,   20,   20, 0x08,
      83,   20,   20,   20, 0x08,
     114,   20,   20,   20, 0x08,
     136,   20,   20,   20, 0x08,
     158,   20,   20,   20, 0x08,
     180,   20,   20,   20, 0x08,
     206,   20,   20,   20, 0x08,
     227,   20,   20,   20, 0x08,
     258,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ABTransactionDetail[] = {
    "ABTransactionDetail\0\0accept()\0"
    "slotChangeDataSpinValue()\0"
    "slotSelectCalenderWidget()\0"
    "slotCalenderWidgetPageChange()\0"
    "slotChangeDate(QDate)\0slotChangeTime(QTime)\0"
    "slotChangeSum(double)\0slotChangeDetail(QString)\0"
    "slotChangeCategory()\0"
    "slotChangeFromAccount(QString)\0"
    "slotChangeToAccount()\0"
};

const QMetaObject ABTransactionDetail::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ABTransactionDetail,
      qt_meta_data_ABTransactionDetail, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ABTransactionDetail::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ABTransactionDetail::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ABTransactionDetail::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ABTransactionDetail))
        return static_cast<void*>(const_cast< ABTransactionDetail*>(this));
    return QDialog::qt_metacast(_clname);
}

int ABTransactionDetail::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: accept(); break;
        case 1: slotChangeDataSpinValue(); break;
        case 2: slotSelectCalenderWidget(); break;
        case 3: slotCalenderWidgetPageChange(); break;
        case 4: slotChangeDate((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 5: slotChangeTime((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 6: slotChangeSum((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: slotChangeDetail((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: slotChangeCategory(); break;
        case 9: slotChangeFromAccount((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: slotChangeToAccount(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
