/********************************************************************************
** Form generated from reading UI file 'field.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIELD_H
#define UI_FIELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Field
{
public:

    void setupUi(QWidget *Field)
    {
        if (Field->objectName().isEmpty())
            Field->setObjectName("Field");
        Field->resize(400, 300);

        retranslateUi(Field);

        QMetaObject::connectSlotsByName(Field);
    } // setupUi

    void retranslateUi(QWidget *Field)
    {
        Field->setWindowTitle(QCoreApplication::translate("Field", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Field: public Ui_Field {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIELD_H
