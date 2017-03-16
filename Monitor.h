#ifndef MONITOR_H
#define MONITOR_H

#include <QMainWindow>
#include "Workbench.h"
#include "ToolWindow.h"
#include "SettingWindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>

class SettingWindow;
class ToolWindow;
class Workbench;

namespace Ui {
class Monitor;
}

class Monitor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Monitor(QWidget *parent = 0);
    ~Monitor();

    void initComponent();
    void initToolBar();
    void initMenuBar();
private:
    Ui::Monitor *ui;
    SettingWindow * m_pSettingWindow;
    ToolWindow* m_pToolWindow;
    Workbench* m_pWorkbench;

    QMenuBar* m_pMenuBar;
    QToolBar* m_pToolBar;

};

#endif // MONITOR_H
