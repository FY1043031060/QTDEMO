#ifndef WORKBENCH_H
#define WORKBENCH_H

#include <QWidget>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMouseEvent>

namespace Ui {
class Workbench;
}
class QGridLayout;
class CompassFactory;

class Workbench : public QWidget
{
    Q_OBJECT

public:
    explicit Workbench(QWidget *parent = 0);
    ~Workbench();

    void initConnect();
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);

public slots:
    void slotAddControls(QString& strCtl);
    void slotAddCompass(int iTypeCompass);
    void slotAddSpeedoMeter();
    void slotAddQuick();
    void dragMoveEvent(QDragMoveEvent *event);

private:
    Ui::Workbench *ui;
    QGridLayout* m_pBaseLayout;
    CompassFactory* m_pCompassFactory;
};

#endif // WORKBENCH_H
