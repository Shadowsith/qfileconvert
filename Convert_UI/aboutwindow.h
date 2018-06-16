#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QWidget>

namespace Ui {
class AboutWindow;
}

class AboutWindow : public QWidget
{
    Q_OBJECT

private:
    Ui::AboutWindow *win;


public:
    explicit AboutWindow(QWidget *parent = 0);
    ~AboutWindow();

};

#endif // ABOUTWINDOW_H
