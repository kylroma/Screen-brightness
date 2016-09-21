#include "brightness.h"
#include <cstdlib>
#include <QDebug>
#include <QAction>
#include <QApplication>

Brightness::Brightness(QSlider *parent) : QSlider(parent)
{
    QAction *pQuit = new QAction("&Exit", this);
    connect(pQuit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

    QAction *pHide = new QAction("&Show/Hide", this);
    connect(pHide, SIGNAL(triggered(bool)), this, SLOT(slotShowHide()));

    mpMenu = new QMenu(this);
    mpMenu->addAction(pHide);
    mpMenu->addAction(pQuit);

    mpTrayIcon = new QSystemTrayIcon(this);
    mpTrayIcon->setIcon(QIcon("./img/icon.png"));
    mpTrayIcon->setToolTip("Screen brightness");
    mpTrayIcon->setContextMenu(mpMenu);
    mpTrayIcon->show();

    setRange(20, 100);
    setValue(100);
    resize(15, 100);
    setWindowIcon(QIcon("./img/icon.png"));
    setTickPosition(TicksBothSides);
    setTickInterval(5);
    moveApplication();

    connect(this, SIGNAL(valueChanged(int)), this, SLOT(slotChangeBrightness(int)));
}

void Brightness::slotChangeBrightness(int bright)
{
    QString str = "xrandr --output $(xrandr | grep ' connected'|cut -f1 -d ' ') --brightness ";
    if(bright == 100)
        str += "1.0";
    else
        str += "0." + QString::number(bright);
    system(str.toAscii());
}

void Brightness::slotShowHide()
{
    setVisible(!isVisible());
    if(isVisible())
        moveApplication();
}

void Brightness::moveApplication()
{
    move(QCursor::pos().x() + 10, QCursor::pos().y() - size().height()/4);
}
