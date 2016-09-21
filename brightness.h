#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include <QWidget>
#include <QSlider>
#include <QSystemTrayIcon>
#include <QMenu>

class Brightness : public QSlider
{
    Q_OBJECT
private:
    QSystemTrayIcon *mpTrayIcon;
    QMenu *mpMenu;

    void moveApplication();
public:
    explicit Brightness(QSlider *parent = 0);

signals:

private slots:
    void slotChangeBrightness(int bright);
    void slotShowHide();
};

#endif // BRIGHTNESS_H
