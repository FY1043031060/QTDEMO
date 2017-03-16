#include "Workbench.h"
#include "ui_Workbench.h"
#include <QDebug>
#include <QMimeData>
#include <QtQuickWidgets/QQuickWidget>
#include <QtCharts>
#include <CompassFactory.h>

using namespace QtCharts;

Workbench::Workbench(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Workbench)
{
    ui->setupUi(this);
    m_pBaseLayout = new QGridLayout;
    m_pCompassFactory = new CompassFactory(this);
    setLayout(m_pBaseLayout);
    this->setAcceptDrops(true);
    QChart* chart = new QChart();
}

Workbench::~Workbench()
{
    delete ui;
}

void Workbench::initConnect()
{

}

void Workbench::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<<__FUNCTION__<<QTime::currentTime();
    if(event->mimeData()->formats() == QStringList("application/x-qabstractitemmodeldatalist"))
    {
        if(event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

void Workbench::dragMoveEvent(QDragMoveEvent *event)
{
    qDebug()<<QString("%1,drop is move,%2.")\
              .arg(__FUNCTION__)\
              .arg(QTime::currentTime().toString());
}

void Workbench::dropEvent(QDropEvent *event)
{
    qDebug()<<QString("%1,drop is happen.").arg(__FUNCTION__);
    /*获取MINEDATA数据分析*/
    const QMimeData *temp = event->mimeData();
    QByteArray encoded = event->mimeData()->data("application/x-qabstractitemmodeldatalist");

    QListWidget *pListWidget = dynamic_cast<QListWidget *>(event->source());
    int nType = pListWidget->currentItem()->type();
    QString strItem = pListWidget->currentItem()->text();
    qDebug()<<QString("TYPE : %1").arg(nType)<<"::"<<strItem;

    //test
    if(QString("chart") == strItem)
    {
//        slotAddControls(strItem);
        slotAddQuick();
    }else if(QString("bar") == strItem)
    {
        int iNum = rand()%5;
        slotAddCompass(iNum);
    }
}

void Workbench::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<QString("%1 is happen,%2.").\
              arg(__FUNCTION__).\
              arg(QTime::currentTime().toString());
}

void Workbench::slotAddControls(QString &strCtl)
{
    //![1]
    QBarSet *set0 = new QBarSet("Jane");
    QBarSet *set1 = new QBarSet("John");
    QBarSet *set2 = new QBarSet("Axel");
    QBarSet *set3 = new QBarSet("Mary");
    QBarSet *set4 = new QBarSet("Samantha");

    *set0 << 1 << 2 << 3 << 4 << 5 << 6;
    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
    *set4 << 9 << 7 << 5 << 3 << 1 << 2;
    //![1]

    //![2]
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    //![2]

    //![3]
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple barchart example");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    //![3]

    //![4]
    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    //![4]

    //![5]
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    //![5]

    //![6]

    QChartView *chartView =new QChartView(chart);

    chartView->setAcceptDrops(true);
    chartView->setDragMode(QGraphicsView::RubberBandDrag);
    chartView->setRenderHint(QPainter::Antialiasing);

    //![6]
//    QHBoxLayout* pHLayout = new QHBoxLayout;
//    pHLayout->addWidget(chartView);
//    this->setLayout(pHLayout);
    m_pBaseLayout->addWidget(chartView);
}

void Workbench::slotAddCompass(int iTypeCompass)
{
    QWidget* compass =m_pCompassFactory->createCompass(iTypeCompass);
    m_pBaseLayout->addWidget(compass);
}

void Workbench::slotAddSpeedoMeter()
{

}

void Workbench::slotAddQuick()
{
    QQuickWidget* qwidget = new QQuickWidget(this);
    qwidget->setSource((QUrl("qrc:/QML/qml/chart.qml")));
    qwidget->setResizeMode(QQuickWidget::SizeViewToRootObject );
    qwidget->show();
    m_pBaseLayout->addWidget(qwidget);
}
