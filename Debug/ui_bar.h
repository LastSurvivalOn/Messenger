/********************************************************************************
** Form generated from reading UI file 'bar.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAR_H
#define UI_BAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bar
{
public:

    void setupUi(QWidget *bar)
    {
        if (bar->objectName().isEmpty())
            bar->setObjectName("bar");
        bar->resize(400, 300);

        retranslateUi(bar);

        QMetaObject::connectSlotsByName(bar);
    } // setupUi

    void retranslateUi(QWidget *bar)
    {
        bar->setWindowTitle(QCoreApplication::translate("bar", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bar: public Ui_bar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAR_H
