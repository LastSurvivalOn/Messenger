#ifndef CHATLIST_H
#define CHATLIST_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include "chatlistitem.h"
#include <QScrollArea>
#include "fullchat.h"
namespace Ui {
class ChatList;
}

class ChatList : public QWidget
{
    Q_OBJECT

public:
    explicit ChatList(QWidget *parent = nullptr);
    ~ChatList();
    void additem(ChatListItem*);
    void removeItem(ChatListItem* it);
    QVector<ChatListItem*> get_items();
    void clearLayout(QLayout* layout);
    FullChat *get_fc();
    ChatList(QString author);
    void open_chat(QString author);
public slots:
    void onButtonClick();
private:
    Ui::ChatList *ui;
    QVBoxLayout *layout1;
    QVector<ChatListItem*> items;
    //QScrollArea *scrollArea;
    QString author;
    FullChat *fc;
};

#endif // CHATLIST_H
