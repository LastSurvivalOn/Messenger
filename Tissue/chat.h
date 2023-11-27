#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QVector>
#include "message.h"
#include <QGridLayout>
#include <QScrollArea>
namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = nullptr);
    ~Chat();
    void add_message(message*);
    Chat(QString a, QString t);
private:
    Ui::Chat *ui;
    QVector<message*> messages;
    QString talker;
    QString author;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
};

#endif // CHAT_H
