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
    explicit AboutWindow(QWidget *parent = 0);
    ~AboutWindow();
    static AboutWindow* instance;
    Ui::AboutWindow *win;

public:
    static AboutWindow* openWindow();

};

#endif // ABOUTWINDOW_H
