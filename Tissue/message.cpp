#include "message.h"
#include "ui_message.h"
#include <QVBoxLayout>
#include <QLabel>
message::message(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::message)
{
    ui->setupUi(this);
}

message::message(QString a, QString c, QString t, bool s):
    ui(new Ui::message),
    author(a),
    content(c),
    time(t),
    ismine(s)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);
    setFixedHeight(50);
    setMaximumWidth(500);
    //QVBoxLayout *hei = new QVBoxLayout;
    QLabel *text = new QLabel;
    QLabel *time = new QLabel;
    text->setText(this->content);
    time->setText(this->time);
    if(ismine==1){
        this->setStyleSheet("#message{background-color: rgb(54, 48, 98);border: 1px solid black;border-radius: 5px;}"
                            "#message:hover{background-color: rgb(67, 85, 133);}");
    }
    else{
        this->setStyleSheet("#message{background-color: rgb(67, 85, 133);border: 1px solid black;border-radius: 5px;}"
                            "#message:hover{background-color: rgb(129, 143, 180);}");
    }
    QFont font = time->font();
    font.setPointSize(7);
    font.setBold(0);
    font.setFamily("Open Sans");
    time->setFont(font);
    QPalette palette = time->palette();
    palette.setColor(QPalette::WindowText, Qt::white);
    time->setPalette(palette);

    QFont font1 = text->font();
    font1.setPointSize(10);
    font1.setBold(0);
    font1.setFamily("Open Sans");
    text->setFont(font1);
    QPalette palette1 = text->palette();
    palette1.setColor(QPalette::WindowText, Qt::white);
    text->setPalette(palette1);

    text->setMaximumWidth(500);
    text->setWordWrap(true);

    //hei->addWidget(text);
    //hei->addWidget(time);
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(text, 0, 0);
    gridLayout->addWidget(time, 1, 1, Qt::AlignBottom | Qt::AlignRight);
    this->setLayout(gridLayout);
}

message::~message()
{
    delete ui;
}
