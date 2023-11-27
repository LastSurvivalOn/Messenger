#include "chatlist.h"
#include "qscrollbar.h"
#include "ui_chatlist.h"
#include <QInputDialog>
ChatList::ChatList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatList),
    layout1(new QVBoxLayout)
    //fc(nullptr)
{
    ui->setupUi(this);
    layout1->setAlignment(Qt::AlignTop);
    layout1->setSpacing(0);
    /*scrollArea->setWidgetResizable(true);
    QWidget *scrollAreaWidget = new QWidget;
    scrollAreaWidget->setLayout(layout1);
    scrollArea->setWidget(scrollAreaWidget);
    scrollArea->setMaximumWidth(500);
    layout()->addWidget(scrollArea);*/
    ui->scrollArea->setWidgetResizable(true);
    QWidget *scrollAreaWidget = new QWidget;
    scrollAreaWidget->setLayout(layout1);
    ui->scrollArea->setWidget(scrollAreaWidget);
    ui->scrollArea->setFrameStyle(QFrame::NoFrame);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  // Disable horizontal scrollbar
    ui->scrollArea->setWidget(scrollAreaWidget);
    ui->scrollArea->setFixedWidth(500);
    ui->scrollArea->setStyleSheet("background-color: transparent;");
    ui->scrollArea->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { border: 0; background:  rgb(18, 18, 18); width: 10px; }"
                                                       "QScrollBar::handle:vertical { background: rgb(49, 62, 97); }"
                                                       "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { background:  rgb(18, 18, 18); }"
                                                       "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background: rgb(18, 18, 18);}"
                                                       );
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout()->addWidget(ui->scrollArea);
//ChatListItem *newu = new ChatListItem("", "ДОДАТИ НОВОГО", "+", "");
 //   additem(newu);
    QPushButton *b = new QPushButton("ДОДАТИ НОВОГО");
    b->setFixedSize(500, 75);
    b->setStyleSheet("background-color: black; color: white");
    QFont font1 = b->font();
    font1.setPointSize(12);
    font1.setFamily("Open Sans");
    font1.setBold(1);
    b->setFont(font1);
    connect(b, SIGNAL(clicked()), this, SLOT(onButtonClick()));
    layout1->addWidget(b);
    ChatListItem *it1 = new ChatListItem("logo.jpg", "lastsurvivalon", "будеш 1", "14:22");
    ChatListItem *it2 = new ChatListItem("logo.jpg", "lastsurvivalon1", "будеш 2", "14:25");
    ChatListItem *it3 = new ChatListItem("logo.jpg", "lastsurvivalon2", "будеш 3", "14:28");
    ChatListItem *it4 = new ChatListItem("logo.jpg", "lastsurvivalon3", "будеш 4", "14:29");
    additem(it1);
    additem(it2);
    additem(it3);
    additem(it4);

}

ChatList::ChatList(QString author) :
    ui(new Ui::ChatList),
    layout1(new QVBoxLayout),
    //fc(nullptr),
    author(author)
{
    ui->setupUi(this);
    layout1->setAlignment(Qt::AlignTop);
    layout1->setSpacing(0);
    /*scrollArea->setWidgetResizable(true);
    QWidget *scrollAreaWidget = new QWidget;
    scrollAreaWidget->setLayout(layout1);
    scrollArea->setWidget(scrollAreaWidget);
    scrollArea->setMaximumWidth(500);
    layout()->addWidget(scrollArea);*/
    ui->scrollArea->setWidgetResizable(true);
    QWidget *scrollAreaWidget = new QWidget;
    scrollAreaWidget->setLayout(layout1);
    ui->scrollArea->setWidget(scrollAreaWidget);
    ui->scrollArea->setFrameStyle(QFrame::NoFrame);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  // Disable horizontal scrollbar
    ui->scrollArea->setWidget(scrollAreaWidget);
    ui->scrollArea->setFixedWidth(500);
    ui->scrollArea->setStyleSheet("background-color: transparent;");
    ui->scrollArea->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { border: 0; background:  rgb(18, 18, 18); width: 10px; }"
                                                       "QScrollBar::handle:vertical { background: rgb(49, 62, 97); }"
                                                       "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { background:  rgb(18, 18, 18); }"
                                                       "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background: rgb(18, 18, 18);}"
                                                       );
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout()->addWidget(ui->scrollArea);
}


void ChatList::additem(ChatListItem* it){
    items.push_back(it);
    layout1->addWidget(it);
    it->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    update();
}

void ChatList::removeItem(ChatListItem* it){
    items.removeOne(it);
    layout1->removeWidget(it);
    update();
}

ChatList::~ChatList()
{
    delete ui;
    clearLayout(layout1);
    delete layout1->parentWidget();
}

QVector<ChatListItem*> ChatList::get_items(){
    return this->items;
}


void ChatList::clearLayout(QLayout* layout)
{
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr)
    {
        if (item->layout() != nullptr)
        {
            clearLayout(item->layout());
            delete item->layout();
        }
        else if (item->widget() != nullptr)
        {
            delete item->widget();
        }
        delete item;
    }
}

void ChatList::onButtonClick(){
    bool ok;
    QString text = QInputDialog::getText(nullptr, "Введіть імя користувача", "Сюди:", QLineEdit::Normal, "", &ok);
        if (ok && !text.isEmpty()) {
        ChatListItem* n = new ChatListItem("logo.jpg", text, "==========", "");
        additem(n);
        }
}
