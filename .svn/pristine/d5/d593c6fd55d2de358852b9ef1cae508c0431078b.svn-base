#include "ToolWindow.h"
#include "ui_ToolWindow.h"

ToolWindow::ToolWindow(QWidget *parent) :
    QListWidget(parent),
    ui(new Ui::ToolWindow)
{
    ui->setupUi(this);
    initListItems();
    this->setDragDropMode(DragOnly);
}

ToolWindow::~ToolWindow()
{
    delete ui;
}

void ToolWindow::initListItems()
{
    this->addItem(QString("chart"));
    this->addItem(QString("bar"));
}
