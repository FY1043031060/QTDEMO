#include "Monitor.h"
#include "ui_Monitor.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

Monitor::Monitor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Monitor)
{
    ui->setupUi(this);
    initToolBar();
    initMenuBar();
    initComponent();
}

Monitor::~Monitor()
{
    delete ui;
}

void Monitor::initComponent(){
    m_pSettingWindow = new SettingWindow(this);
    m_pToolWindow = new ToolWindow(this);
    m_pWorkbench = new Workbench((this));

    QVBoxLayout* pVLayout = new QVBoxLayout;
    pVLayout->insertWidget(0,m_pToolWindow,1);
    pVLayout->insertWidget(1,m_pSettingWindow,1);

    QHBoxLayout* pHLayout = new QHBoxLayout;
    pHLayout->insertLayout(0,pVLayout,1);
    pHLayout->insertWidget(1,m_pWorkbench,3);

    QWidget* pCentralWidget = new QWidget(this);
    this->setCentralWidget(pCentralWidget);
    centralWidget()->setLayout(pHLayout);

}

void Monitor::initToolBar()
{
    QAction* pStart = new QAction(QString("start"),this);
    ui->mainToolBar->addAction(pStart);
}

void Monitor::initMenuBar()
{
    QMenu* pSessction1 = new QMenu(QString("NEW"),this);
    QAction* pStart = new QAction(QString("Creation"),this);
    pSessction1->addAction(pStart);
    ui->menuBar->addMenu(pSessction1);
}
