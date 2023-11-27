#include "chatlistitem.h"
#include "ui_chatlistitem.h"
#include <QFileDialog>
ChatListItem::ChatListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatListItem)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);
    setFixedHeight(75);
    setMaximumWidth(500);
    loadcontent("logo.jpg", "lastsurvivalon", "=================", "14:22");
}

ChatListItem::ChatListItem(QString n, QString username, QString last, QString time1){
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);
    setFixedHeight(75);
    setMaximumWidth(500);
    loadcontent(n, username, last, time1);
    author="-";
    fc= new FullChat(author, username);

}

void ChatListItem::set_a(QString a){
    author=a;
}

ChatListItem::~ChatListItem()
{
    delete ui;
}

void ChatListItem::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        open_chat();
    }
    else if(event->button() == Qt::RightButton){
        QString filePath = QFileDialog::getOpenFileName(this, "Обрати зображення", "", "Зображення (*.png *.jpg *.bmp)");
        if (!filePath.isEmpty()) {
            QLayoutItem *item;
            while ((item = layout()->takeAt(0)) != nullptr) {
                if (QWidget *widget = item->widget()) {
                    delete widget;
                }
                delete item;
            }
            loadcontent(filePath, un, l, t);
        }
    }
    //QWidget::mousePressEvent(event);
}

void ChatListItem::loadcontent(QString n, QString username, QString last, QString time1){
    QPixmap pixmap = QPixmap(n);
    QLabel *imageLabel = new QLabel(this);
    QLabel *lab = new QLabel;
    lab->setText(username);
    QLabel *lab1 = new QLabel;
    lab1->setText(last);
    QPixmap scaledPixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio);
    imageLabel->setPixmap(scaledPixmap);
    QHBoxLayout *layout = new QHBoxLayout;
    fp=n, un=username, l=last, t=time1;
    QVBoxLayout *hei = new QVBoxLayout;

    QFont font = lab->font();
    font.setPointSize(12);
    font.setBold(true);
    font.setFamily("Open Sans");
    lab->setFont(font);
    layout->addWidget(imageLabel);

    QFont font1 = lab->font();
    font1.setPointSize(8);
    font1.setFamily("Open Sans");
    font1.setBold(1);
    lab1->setFont(font1);

    QPalette palette = lab->palette();
    palette.setColor(QPalette::WindowText, Qt::white);
    lab->setPalette(palette);

    QPalette palette1 = lab1->palette();
    palette1.setColor(QPalette::WindowText, Qt::white);
    lab1->setPalette(palette1);

    hei->addWidget(lab);
    hei->addWidget(lab1);

    QLabel *time = new QLabel;
    time->setText(time1);
    QFont font2 = time->font();
    font2.setPointSize(10);
    font2.setBold(true);
    font2.setFamily("Open Sans");
    time->setFont(font2);
    QPalette palette2 = time->palette();
    palette2.setColor(QPalette::WindowText, Qt::white);
    time->setPalette(palette2);

    QHBoxLayout *timeLayout = new QHBoxLayout;
    timeLayout->addStretch();
    timeLayout->addWidget(time);
    timeLayout->setAlignment(Qt::AlignRight);

    layout->addLayout(hei);
    layout->addLayout(timeLayout);
    layout->setAlignment(Qt::AlignLeft);
    this->setLayout(layout);
}

void ChatListItem::open_chat(){
    fc->show();
    fc->setStyleSheet("background-color:black;");
    fc->setWindowTitle("Бесіда");
}

FullChat* ChatListItem::get_fc(){
    return this->fc;
}
