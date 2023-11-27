/********************************************************************************
** Form generated from reading UI file 'fullchat.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FULLCHAT_H
#define UI_FULLCHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FullChat
{
public:

    void setupUi(QWidget *FullChat)
    {
        if (FullChat->objectName().isEmpty())
            FullChat->setObjectName("FullChat");
        FullChat->resize(400, 300);

        retranslateUi(FullChat);

        QMetaObject::connectSlotsByName(FullChat);
    } // setupUi

    void retranslateUi(QWidget *FullChat)
    {
        FullChat->setWindowTitle(QCoreApplication::translate("FullChat", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FullChat: public Ui_FullChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FULLCHAT_H
