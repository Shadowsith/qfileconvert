#include <aboutwindow.h>
#include <ui_aboutwindow.h>
#include <qpushbutton.h>
#include <qmetaobject.h>
#include <qobject.h>

AboutWindow::AboutWindow(QWidget *parent) : QWidget(parent), win(new Ui::AboutWindow)
{
    win->setupUi(this);
    connect(win->btnCloseAw, &QPushButton::clicked, [=] {
        close();
        delete win;
    });
}

AboutWindow::~AboutWindow()
{
    delete win;
}
