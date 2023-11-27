#include "bar.h"
#include "ui_bar.h"
#include <QHBoxLayout>
#include <QPalette>
#include <QFont>
bar::bar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bar),
    back(nullptr)
{
    ui->setupUi(this);
}

bar::~bar()
{
    delete ui;
}

bar::bar(QString a, QString t):
    ui(new Ui::bar),
    back(new QPushButton("<")),
    talker(t),
    f(new Field(a, t)),
    author(a)
{
    ui->setupUi(this);
    QLabel *auth = new QLabel;
    auth->setText(talker);
    QHBoxLayout *l = new QHBoxLayout;
    l->addWidget(back, Qt::AlignLeft);
    l->addWidget(auth, Qt::AlignCenter);
    connect(back, SIGNAL(clicked()), this, SLOT(go_back()));
    setLayout(l);

    QFont font1 = auth->font();
    font1.setPointSize(12);
    font1.setFamily("Open Sans");
    font1.setBold(1);
    auth->setFont(font1);

    QPalette palette = auth->palette();
    palette.setColor(QPalette::WindowText, Qt::white);
    auth->setPalette(palette);
    back->setStyleSheet("background-color: rgb(54, 48, 98); color: white; border-radius: 1px;");
}

void bar::go_back(){
    this->get_f()->get_c()->close();
    this->get_f()->close();
    this->close();
}

Field* bar::get_f(){
    return this->f;
}
