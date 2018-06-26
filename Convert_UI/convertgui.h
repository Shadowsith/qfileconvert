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
    QString m_imgFiles = "Image Files (*.bmp *.dds *.gif *.jpeg, *.jpg *.pdf *.png *.psd *.tga *.tif *.tiff)";
    QString m_audFiles = "Audio Files (*.aif *.flac *.m4a *.mp3 *.mpa *.wav, *.wma)";
    QString m_vidInFiles;
    QString m_vidOutFiles;
    QString m_textInFiles;
    //QString videoFiles = "Video Files (*.3g2, *.3gp, *.asf, *.avi, *.flv, *.m4v, *.mov, *.mp4, *.mpg, *.rm, *.srt, *.swf, *.vob, *.wmv)";
    //QString textFiles = "Text Files (*.doc, *.docx, *.log, *.msg, *.odt, *.pages, *.rtf, *.tex, *.txt, *.wpd, *.wps)";

    void clearLineEdits();
    void openAboutWindow();
    bool checkPathes(QString source, QString dest);

public:
    explicit ConvertGui(QWidget *parent = 0);
    QList<AboutWindow*> aWCon;
    ~ConvertGui();
    void useFileExplorer(QLineEdit* le, FileType search, Target target);
    void convertFiles();
    void getLineEdits();
    void checkRequirements();

};

#endif // CONVERTGUI_H
