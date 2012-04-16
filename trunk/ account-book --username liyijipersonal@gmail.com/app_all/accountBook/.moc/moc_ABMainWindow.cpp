/****************************************************************************
** Meta object code from reading C++ file 'ABMainWindow.h'
**
** Created: Mon Apr 16 19:07:53 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ABMainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ABMainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ABMainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      39,   13,   13,   13, 0x08,
      74,   13,   13,   13, 0x08,
      98,   13,   13,   13, 0x08,
     117,   13,   13,   13, 0x08,
     138,   13,   13,   13, 0x08,
     157,   13,   13,   13, 0x08,
     177,   13,   13,   13, 0x08,
     199,   13,   13,   13, 0x08,
     232,   13,   13,   13, 0x08,
     267,   13,   13,   13, 0x08,
     293,   13,   13,   13, 0x08,
     318,   13,   13,   13, 0x08,
     342,   13,   13,   13, 0x08,
     366,   13,   13,   13, 0x08,
     392,   13,   13,   13, 0x08,
     403,   13,   13,   13, 0x08,
     415,   13,   13,   13, 0x08,
     430,   13,   13,   13, 0x08,
     443,   13,   13,   13, 0x08,
     494,   13,   13,   13, 0x08,
     527,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ABMainWindow[] = {
    "ABMainWindow\0\0slotMenuAction(QAction*)\0"
    "slotChangeEditDeleteButtonEnable()\0"
    "slotChangeYearOrMonth()\0slotManageAccout()\0"
    "slotManageCategory()\0slotAddNewIncome()\0"
    "slotAddNewExpense()\0slotAddNewLiquidity()\0"
    "slotEditCurrentTransactionItem()\0"
    "slotDeleteCurrentTransactionItem()\0"
    "slotResizeColumnsAndRow()\0"
    "slotLoadDataOfCurMonth()\0"
    "slotShowBigTypeInTree()\0slotShowMidTypeInTree()\0"
    "slotShowSmallTypeInTree()\0slotPlus()\0"
    "slotMinus()\0slotMultiply()\0slotDivide()\0"
    "slotDoubleClickTableTransaction(QTableWidgetItem*)\0"
    "slotReloadCurTimeAccountStatus()\0"
    "slotReloadAccountStatusByDataTime(QDateTime)\0"
};

const QMetaObject ABMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ABMainWindow,
      qt_meta_data_ABMainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ABMainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ABMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ABMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ABMainWindow))
        return static_cast<void*>(const_cast< ABMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ABMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotMenuAction((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 1: slotChangeEditDeleteButtonEnable(); break;
        case 2: slotChangeYearOrMonth(); break;
        case 3: slotManageAccout(); break;
        case 4: slotManageCategory(); break;
        case 5: slotAddNewIncome(); break;
        case 6: slotAddNewExpense(); break;
        case 7: slotAddNewLiquidity(); break;
        case 8: slotEditCurrentTransactionItem(); break;
        case 9: slotDeleteCurrentTransactionItem(); break;
        case 10: slotResizeColumnsAndRow(); break;
        case 11: slotLoadDataOfCurMonth(); break;
        case 12: slotShowBigTypeInTree(); break;
        case 13: slotShowMidTypeInTree(); break;
        case 14: slotShowSmallTypeInTree(); break;
        case 15: slotPlus(); break;
        case 16: slotMinus(); break;
        case 17: slotMultiply(); break;
        case 18: slotDivide(); break;
        case 19: slotDoubleClickTableTransaction((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 20: slotReloadCurTimeAccountStatus(); break;
        case 21: slotReloadAccountStatusByDataTime((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
