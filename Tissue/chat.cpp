#include "chat.h"
#include "qscrollbar.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chat),
    gridLayout(new QGridLayout),
    scrollArea(new QScrollArea)
{
    ui->setupUi(this);
    this->author = "me";
    this->talker = "1";
    setFixedWidth(1300);
    setFixedHeight(1000);
    setAttribute(Qt::WA_StyledBackground);
    //QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameStyle(QFrame::NoFrame);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    scrollArea->setStyleSheet("background-color: transparent;");
    scrollArea->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { border: 0; background: rgb(18, 18, 18); width: 10px; }"
                                                   "QScrollBar::handle:vertical { background: rgb(49, 62, 97); }"
                                                   "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { background: rgb(18, 18, 18); }"
                                                   "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background: rgb(18, 18, 18);}"
                                                   );
    QWidget *scrollAreaWidget = new QWidget;
    scrollAreaWidget->setLayout(gridLayout);
    gridLayout->setAlignment(Qt::AlignTop);
    scrollAreaWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
    scrollArea->setWidget(scrollAreaWidget);
    //scrollAreaWidget->setStyleSheet("background-color:rgb(55,70,108);");
    layout()->addWidget(scrollArea);

    adjustSize();
}

Chat::~Chat()
{
    delete ui;
}

void Chat::add_message(message *m){
    if (this->author == m->get_auth()) {
        m->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        this->gridLayout->addWidget(m, this->gridLayout->rowCount(), 1, Qt::AlignRight|Qt::AlignTop);
    } else if (this->talker == m->get_auth()) {
        m->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        this->gridLayout->addWidget(m, this->gridLayout->rowCount(), 0, Qt::AlignLeft|Qt::AlignTop);
    }
    messages.push_back(m);
    //scrollArea->verticalScrollBar()->setValue(scrollArea->verticalScrollBar()->maximum());
//adjustSize();
}

Chat::Chat(QString a, QString t):
    ui(new Ui::Chat),
    gridLayout(new QGridLayout)
{
ui->setupUi(this);
this->author = a;
this->talker = t;
setFixedWidth(1400);
QScrollArea *scrollArea = new QScrollArea;
scrollArea->setWidgetResizable(true);
scrollArea->setFrameStyle(QFrame::NoFrame);
scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
scrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
scrollArea->setStyleSheet("background-color: transparent;");
scrollArea->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { border: 0; background: rgb(18, 18, 18); width: 10px; }"
                                               "QScrollBar::handle:vertical { background: rgb(49, 62, 97); }"
                                               "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { background: rgb(18, 18, 18); }"
                                               "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background: rgb(18, 18, 18);}"
                                               );
message* m = new message("Me", "HELLOw", "22:22", 1);
message* m1 = new message("talker", "HEL1LOw", "22:22", 0);
message* m2 = new message("Me", "HEdddLLOw", "22:22", 1);
message* m3 = new message("talker", "HELddLyghgggggggggggggggggggggggggggggggggggggggggggggggggg hh ggggOw", "22:22", 0);
add_message(m);
add_message(m1);
add_message(m2);
add_message(m3);
message* m10 = new message("Me", "HELLOw", "22:22", 1);
message* m11 = new message("Me", "HEL1hjhgvhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhf fffLOw", "22:22", 1);
message* m21 = new message("Me", "HEdddLLOw", "22:22", 1);
message* m31 = new message("talker", "HELddLOw", "22:22", 0);
add_message(m10);
add_message(m11);
add_message(m21);
add_message(m31);
message* m100 = new message("Me", "HELLOw", "22:22", 1);
message* m111 = new message("talker", "HEL1LOw", "22:22", 0);
message* m211 = new message("Me", "HEdddLLOw", "22:22", 1);
message* m311 = new message("talker", "HELddLOw", "22:22", 0);
add_message(m100);
add_message(m111);
add_message(m211);
add_message(m311);
QWidget *scrollAreaWidget = new QWidget;
scrollAreaWidget->setLayout(gridLayout);
scrollAreaWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
scrollArea->setWidget(scrollAreaWidget);
//scrollAreaWidget->setStyleSheet("background-color:rgb(55,70,108);");
layout()->addWidget(scrollArea);

adjustSize();
}

/*
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameStyle(QFrame::NoFrame);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    scrollArea->setStyleSheet("background-color: transparent;");
    scrollArea->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { border: 0; background: rgb(18, 18, 18); width: 10px; }"
                                                   "QScrollBar::handle:vertical { background: rgb(49, 62, 97); }"
                                                   "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { background: rgb(18, 18, 18); }"
                                                   "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background: rgb(18, 18, 18);}"
                                                   );
    QWidget *scrollAreaWidget = new QWidget;
    scrollAreaWidget->setLayout(gridLayout);
    scrollArea->setWidget(scrollAreaWidget);
    scrollAreaWidget->setStyleSheet("background-color:rgb(55,70,108);");
    layout()->addWidget(scrollArea);
*/
