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

enum FileType {
    IMAGE = 0,
    AUIDO,
    VIDEO,
    AUDIO_VIDEO,
    TEXT
};

enum Target {
    SOURCE = 0,
    DEST
};

class ConvertGui : public QMainWindow
{
    Q_OBJECT

private:
    Ui::ConvertGui *ui;
    QList<QLineEdit *> lineEdits;
    //QString imgFiles = "Image Files (*.png, *.jpg, *.png, *.dds)"; //"Image Files (*.bmp, *.dds, *.gif, *.jpeg, *.jpg, *.pdf, *.png, *.psd, *.tga, *.thm, *.tif, *.tiff, *.yuv)";
    //QString audioFiles = "Audio Files (*.aif, *.flac, *.iff, *.m3u, *.m4a, *.mid, *.mp3, *.mp4, *.wav, *.wma)";
    //QString videoFiles = "Video Files (*.3g2, *.3gp, *.asf, *.avi, *.flv, *.m4v, *.mov, *.mp4, *.mpg, *.rm, *.srt, *.swf, *.vob, *.wmv)";
    //QString textFiles = "Text Files (*.doc, *.docx, *.log, *.msg, *.odt, *.pages, *.rtf, *.tex, *.txt, *.wpd, *.wps)";

    void clearLineEdits();
    void openAboutWindow();

public:
    explicit ConvertGui(QWidget *parent = 0);
    AboutWindow *aW;
    ~ConvertGui();
    void useFileExplorer(QLineEdit* le, FileType search, Target target);
    void convertFiles();
    void getLineEdits();

};

#endif // CONVERTGUI_H
