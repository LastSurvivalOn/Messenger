#ifndef BAR_H
#define BAR_H

#include "qlabel.h"
#include <QWidget>
#include <QPushButton>
#include "field.h"
namespace Ui {
class bar;
}

class bar : public QWidget
{
    Q_OBJECT

public:
    explicit bar(QWidget *parent = nullptr);
    ~bar();
    bar(QString a, QString t);
    Field *get_f();
public slots:
    void go_back();
private:
    Ui::bar *ui;
    QString author;
    QString talker;
    QPushButton *back;
    Field* f;
};
#endif // BAR_H
