#include <QApplication>
#include "brightness.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Brightness br;
    br.show();

    return app.exec();
}
