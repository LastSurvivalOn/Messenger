#include "field.h"
#include "ui_field.h"
#include <QDateTime>
#include <QMessageBox>
Field::Field(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Field),
    text(new QLineEdit),
    curr(nullptr),
    send(new QPushButton)
{
    ui->setupUi(this);
}

Field::Field(QString a, QString t):
    ui(new Ui::Field),
    text(new QLineEdit),
    author(a),
    talker(t),
    curr(nullptr),
    send(new QPushButton),
    c(new Chat(a,t))
{
    ui->setupUi(this);
    QHBoxLayout *l = new QHBoxLayout;
    l->addWidget(text);
    send->setText(">");
    send->setStyleSheet("background-color: rgb(54, 48, 98); color: white; border-radius: 0px;");
    l->addWidget(send);
    l->setAlignment(Qt::AlignLeft);
    connect(send, SIGNAL(clicked()), this, SLOT(onButtonClick()));
    text->setStyleSheet("background-color: rgb(49, 62, 97); color: white;");
    setLayout(l);
}

Field::~Field()
{
    delete ui;
}

message* Field::get_message(QString a, QString t){
    QDateTime currentDateTime = QDateTime::currentDateTime();
    message *m = new message(a, t, currentDateTime.toString("hh:mm"), 1);
    return m;
}

void Field::onButtonClick(){
    if(text->text().isEmpty()!=1){
        curr=get_message(this->author, text->text());
        text->clear();
        c->add_message(curr);
        curr=nullptr;
    }
}

Chat* Field::get_c(){
    return this->c;
}
