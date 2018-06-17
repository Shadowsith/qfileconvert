#include <convertgui.h>
#include <ui_convertgui.h>
#include <ui_aboutwindow.h>
#include <converter.h>
#include <qdesktopservices.h>
#include <qstring.h>
#include <qfiledialog.h>
#include <qtabwidget.h>
#include <qmessagebox.h>
#include <qcombobox.h>
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

    connect(ui->convBt, &QPushButton::clicked, [=] {
        convertFiles();
    });
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
    Converter conv(ui->cmbPicFrom->currentText().toStdString(),
                         ui->cmbPicFrom->currentText().toStdString());

    const std::string txtPicF = ui->txtPicFrom->text().toStdString();
    std::string txtPicT = ui->txtPicTo->text().toStdString();

    int num = conv.convertImg(txtPicF, txtPicT);

    QMessageBox msg;
    msg.setText(QString::fromStdString(std::to_string(num)) + " " +
                QString::fromStdString(conv.getFileExtension(txtPicF)));
    msg.exec();

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

