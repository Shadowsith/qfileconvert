#include <aboutwindow.h>
#include <convertgui.h>
#include <ui_aboutwindow.h>
#include <qpushbutton.h>
#include <qmetaobject.h>
#include <qobject.h>

AboutWindow::AboutWindow(QWidget *parent) : QWidget(parent), win(new Ui::AboutWindow)
{
    win->setupUi(this);
    connect(win->btnCloseAw, &QPushButton::clicked, [=] {
        close();
    });
}

AboutWindow::~AboutWindow()
{
    delete win;
}

AboutWindow* AboutWindow::instance = 0;

AboutWindow* AboutWindow::openWindow() {
    if(!instance) {
        instance = new AboutWindow();
        return instance;
    } else {
        return instance;
    }
}
