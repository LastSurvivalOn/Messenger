#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "fullchat.h".h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    list(new ChatList)
{
    ui->setupUi(this);

    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *layout1 = new QHBoxLayout(centralWidget);
    layout1->setSpacing(0);
    layout1->addWidget(list);
    FullChat *fc=new FullChat("Me", "talker");
    layout1->addWidget(fc);
    layout1->setAlignment(Qt::AlignLeft);

    //n->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    centralWidget->setLayout(layout1);
    setCentralWidget(centralWidget);
    showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
    for (auto f : list->get_items())
    {
        if (f != nullptr)
        {
            list->removeItem(f);
            delete f;
        }
    }
}

