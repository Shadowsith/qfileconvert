#ifndef CONVERTGUI_H
#define CONVERTGUI_H

#include <QMainWindow>
#include <qlineedit.h>

namespace Ui {
class ConvertGui;
}

class ConvertGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConvertGui(QWidget *parent = 0);
    ~ConvertGui();

private:
    Ui::ConvertGui *ui;

private slots:
    void convertFiles();
    void clearPaths();
    void useFileExplorer(QLineEdit* le);
};

#endif // CONVERTGUI_H
