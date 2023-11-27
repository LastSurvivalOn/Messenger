#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>

namespace Ui {
class message;
}

class message : public QWidget
{
    Q_OBJECT

public:
    explicit message(QWidget *parent = nullptr);
    ~message();
    message(QString, QString, QString, bool);
    QString get_auth(){return this->author;}

private:
    Ui::message *ui;
    QString author;
    QString content;
    QString time;
    bool ismine;
};

#endif // MESSAGE_H
