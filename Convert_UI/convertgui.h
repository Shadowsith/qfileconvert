#ifndef CONVERTGUI_H
#define CONVERTGUI_H

#include <QMainWindow>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <vector>

namespace Ui {
class ConvertGui;
}

class ConvertGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConvertGui(QWidget *parent = 0);
    ~ConvertGui();
    void useFileExplorer(QLineEdit* le);
    void convertFiles();
    void getLineEdits();

private:
    Ui::ConvertGui *ui;
    QList<QLineEdit *> lineEdits;

private slots:
    void clearPaths();
    void clearLineEdits();


};

#endif // CONVERTGUI_H
