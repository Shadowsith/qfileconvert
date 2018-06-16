#include <convertgui.h>
#include <ui_convertgui.h>
#include <ui_aboutwindow.h>
#include <converter.h>
#include <qdesktopservices.h>
#include <qfiledialog.h>
#include <qtabwidget.h>
#include <qmessagebox.h>
#include <qlineedit.h>
#include <qdir.h>
#include <qurl.h>
#include <qpushbutton.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <string>
#include <qmenu.h>
#include <qaction.h>
#include <QApplication>

ConvertGui::ConvertGui(QWidget *parent) : QMainWindow(parent), ui(new Ui::ConvertGui)
{
    ui->setupUi(this);

    connect(ui->clearBtn, &QPushButton::clicked, [=] {
         clearLineEdits();
    });
    connect(ui->btnPicFrom, &QPushButton::clicked, [=] {
        useFileExplorer(ui->txtPicFrom);
    });
    connect(ui->btnPicTo, &QPushButton::clicked, [=] {
        useFileExplorer(ui->txtPicTo);
    });
    connect(ui->menuAbout, &QMenu::aboutToShow, [=] {
        openAboutWindow();
    });
}

ConvertGui::~ConvertGui()
{
    delete ui;
}

void ConvertGui::convertFiles(){

}

void ConvertGui::useFileExplorer(QLineEdit* le){
    QString path = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home/philip", tr("Image Files (*.png *.jpg *.bmp)"));
    le->insert(path);
}

void ConvertGui::getLineEdits(){
    lineEdits = this->findChildren<QLineEdit *>();
}

void ConvertGui::clearLineEdits(){
    for(auto const& value : lineEdits) {
       value->setText("");
    }
}

void ConvertGui::openAboutWindow() {
    aW = new AboutWindow();
    aW->show();
}

