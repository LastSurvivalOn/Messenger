#ifndef FULLCHAT_H
#define FULLCHAT_H

#include <QWidget>
#include "bar.h"
#include "field.h"
#include <QVBoxLayout>
namespace Ui {
class FullChat;
}

class FullChat : public QWidget
{
    Q_OBJECT

public:
    explicit FullChat(QWidget *parent = nullptr);
    ~FullChat();
    FullChat(QString author, QString talker);
    bar* get_b();
    //Chat* get_c();
    //Field* get_f();
private:
    Ui::FullChat *ui;
    QString author;
    QString talker;
    bar* b;
    //Field *f;
};

#endif // FULLCHAT_H
