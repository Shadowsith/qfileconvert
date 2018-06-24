#include "convertgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConvertGui w;
    const int fHeight = w.height();
    const int fWidth = w.width();
    w.setFixedSize(fWidth, fHeight);
    w.getLineEdits();
    w.checkRequirements();
    w.show();

    return a.exec();
}
