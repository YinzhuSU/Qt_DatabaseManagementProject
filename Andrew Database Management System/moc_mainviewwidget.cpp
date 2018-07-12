/****************************************************************************
** Meta object code from reading C++ file 'mainviewwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DatebaseManagement/mainviewwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainviewwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainViewWidget_t {
    QByteArrayData data[15];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainViewWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainViewWidget_t qt_meta_stringdata_MainViewWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MainViewWidget"
QT_MOC_LITERAL(1, 15, 12), // "returnSignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 20), // "on_btnLogOut_clicked"
QT_MOC_LITERAL(4, 50, 21), // "on_btnSaveOne_clicked"
QT_MOC_LITERAL(5, 72, 21), // "on_btnSaveAll_clicked"
QT_MOC_LITERAL(6, 94, 20), // "on_btnSearch_clicked"
QT_MOC_LITERAL(7, 115, 24), // "on_btnImportFile_clicked"
QT_MOC_LITERAL(8, 140, 23), // "on_btnDeleteAll_clicked"
QT_MOC_LITERAL(9, 164, 18), // "on_btnView_clicked"
QT_MOC_LITERAL(10, 183, 20), // "on_btnUpdate_clicked"
QT_MOC_LITERAL(11, 204, 20), // "on_btnDelete_clicked"
QT_MOC_LITERAL(12, 225, 20), // "on_btnExport_clicked"
QT_MOC_LITERAL(13, 246, 24), // "on_btnExportPath_clicked"
QT_MOC_LITERAL(14, 271, 18) // "on_btnTest_clicked"

    },
    "MainViewWidget\0returnSignal\0\0"
    "on_btnLogOut_clicked\0on_btnSaveOne_clicked\0"
    "on_btnSaveAll_clicked\0on_btnSearch_clicked\0"
    "on_btnImportFile_clicked\0"
    "on_btnDeleteAll_clicked\0on_btnView_clicked\0"
    "on_btnUpdate_clicked\0on_btnDelete_clicked\0"
    "on_btnExport_clicked\0on_btnExportPath_clicked\0"
    "on_btnTest_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainViewWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainViewWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainViewWidget *_t = static_cast<MainViewWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnSignal(); break;
        case 1: _t->on_btnLogOut_clicked(); break;
        case 2: _t->on_btnSaveOne_clicked(); break;
        case 3: _t->on_btnSaveAll_clicked(); break;
        case 4: _t->on_btnSearch_clicked(); break;
        case 5: _t->on_btnImportFile_clicked(); break;
        case 6: _t->on_btnDeleteAll_clicked(); break;
        case 7: _t->on_btnView_clicked(); break;
        case 8: _t->on_btnUpdate_clicked(); break;
        case 9: _t->on_btnDelete_clicked(); break;
        case 10: _t->on_btnExport_clicked(); break;
        case 11: _t->on_btnExportPath_clicked(); break;
        case 12: _t->on_btnTest_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainViewWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainViewWidget::returnSignal)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MainViewWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainViewWidget.data,
      qt_meta_data_MainViewWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainViewWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainViewWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainViewWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainViewWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainViewWidget::returnSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
