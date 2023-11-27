#include "fullchat.h"
#include "ui_fullchat.h"

FullChat::FullChat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FullChat),
    b(nullptr)
    //c(nullptr),
    //f(nullptr)
{
    ui->setupUi(this);
}

FullChat::~FullChat()
{
    delete ui;
}

FullChat::FullChat(QString author, QString talker):
    ui(new Ui::FullChat),
    b(new bar(author, talker)),
    //c(new Chat(author, talker)),
    //f(new Field(author, talker)),
    author(author),
    talker(talker)
{
    ui->setupUi(this);
    QVBoxLayout *lay = new QVBoxLayout;
    lay->addWidget(b);
    lay->addWidget(b->get_f()->get_c());
    lay->addWidget(b->get_f());
    setLayout(lay);
}
