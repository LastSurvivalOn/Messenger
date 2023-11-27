#ifndef FIELD_H
#define FIELD_H

#include <QLineEdit>
#include <QWidget>
#include <message.h>
#include <QHBoxLayout>
#include <QPushButton>
#include "chat.h"
namespace Ui {
class Field;
}

class Field : public QWidget
{
    Q_OBJECT

public:
    explicit Field(QWidget *parent = nullptr);
    ~Field();
    QString get_message();
    Field(QString author, QString talker);
    message* get_message(QString, QString);
    message* get_cur();
    Chat* get_c();
public slots:
    void onButtonClick();
private:
    Ui::Field *ui;
    QLineEdit *text;
    QString content;
    QString time;
    QString author;
    message* curr;
    QPushButton *send;
    QString talker;
    Chat* c;
};

#endif // FIELD_H
