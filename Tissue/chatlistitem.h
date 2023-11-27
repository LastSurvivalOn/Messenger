#ifndef CHATLISTITEM_H
#define CHATLISTITEM_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QPalette>
#include <QMessageBox>
#include <QFont>
#include <QPalette>
#include "fullchat.h"
namespace Ui {
class ChatListItem;
}

class ChatListItem : public QWidget
{
    Q_OBJECT

public:
    explicit ChatListItem(QWidget *parent = nullptr);
    ChatListItem(QString n, QString username, QString last, QString time1);
    ~ChatListItem();
    void set_a(QString a);
    void mousePressEvent(QMouseEvent *event);
    void loadcontent(QString n, QString username, QString last, QString time);
    void open_chat();
    FullChat*get_fc();
private:
    Ui::ChatListItem *ui;
    QString author;
    FullChat *fc;
    QString fp, un, l, t;
};

#endif // CHATLISTITEM_H
