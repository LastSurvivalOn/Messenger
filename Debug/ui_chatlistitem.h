/********************************************************************************
** Form generated from reading UI file 'chatlistitem.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATLISTITEM_H
#define UI_CHATLISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatListItem
{
public:

    void setupUi(QWidget *ChatListItem)
    {
        if (ChatListItem->objectName().isEmpty())
            ChatListItem->setObjectName("ChatListItem");
        ChatListItem->setEnabled(true);
        ChatListItem->resize(551, 75);
        ChatListItem->setStyleSheet(QString::fromUtf8("#ChatListItem\n"
"{\n"
"background-color: rgb(18, 18, 18);\n"
"border: 0px solid black;\n"
"border-radius: 0px;\n"
"}\n"
"\n"
"#ChatListItem:hover\n"
"{\n"
"background-color: rgb(49, 62, 97);\n"
"}"));

        retranslateUi(ChatListItem);

        QMetaObject::connectSlotsByName(ChatListItem);
    } // setupUi

    void retranslateUi(QWidget *ChatListItem)
    {
        ChatListItem->setWindowTitle(QCoreApplication::translate("ChatListItem", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatListItem: public Ui_ChatListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATLISTITEM_H
