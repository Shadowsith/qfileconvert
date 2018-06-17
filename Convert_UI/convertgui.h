#ifndef CONVERTGUI_H
#define CONVERTGUI_H

#include <QMainWindow>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qwindow.h>
#include <aboutwindow.h>
#include <converter.h>
#include <vector>

namespace Ui {
class ConvertGui;
}

class ConvertGui : public QMainWindow
{
    Q_OBJECT

private:
    Ui::ConvertGui *ui;
    QList<QLineEdit *> lineEdits;

    void clearLineEdits();
    void openAboutWindow();

public:
    explicit ConvertGui(QWidget *parent = 0);
    AboutWindow *aW;
    ~ConvertGui();
    void useFileExplorer(QLineEdit* le);
    void convertFiles();
    void getLineEdits();

};

#endif // CONVERTGUI_H
