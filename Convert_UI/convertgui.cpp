#include "./convertgui.h"
#include <ui_convertgui.h>
#include "./converter.h"
#include "/usr/include/qt/QtGui/qdesktopservices.h"
#include "/usr/include/qt/QtWidgets/qfiledialog.h"
#include "/usr/include/qt/QtWidgets/qtabwidget.h"
#include "/usr/include/qt/QtWidgets/qmessagebox.h"
#include "/usr/include/qt/QtWidgets/qlineedit.h"
#include "/usr/include/qt/QtCore/qdir.h"
#include "/usr/include/qt/QtCore/qurl.h"

ConvertGui::ConvertGui(QWidget *parent) : QMainWindow(parent), ui(new Ui::ConvertGui)
{
    ui->setupUi(this);
    connect(ui->convBt, SIGNAL (clicked()), this, SLOT(convertFiles()));
    connect(ui->clearBtn, SIGNAL (clicked()), this, SLOT(clearPaths()));
    connect(ui->btnPicFrom, SIGNAL(clicked()), this, SLOT(useFileExplorer()));
    connect(ui->btnPicTo, SIGNAL(clicked()), this, SLOT(useFileExplorer()));

}

ConvertGui::~ConvertGui()
{
    delete ui;
}

void ConvertGui::clearPaths() {
    ui->txtPicFrom->setText("");
    ui->txtPicTo->setText("");
    //QMessageBox box;
    //box.setText(QTabWidget::currentIndex(0));
    //box.setText(ui->path1->text());
    //box.exec();
}

void ConvertGui::convertFiles(){
    QString a;
    QString b;

    if(ui->txtPicFrom->text().compare("") != 0){
        a = ui->txtPicFrom->text();
    }
    if(ui->txtPicTo->text().compare("") != 0){
        b = ui->txtPicTo->text();
    }

    QByteArray aa = a.toLatin1();
    QByteArray bb = b.toLatin1();

    if(ui->txtPicFrom->text().compare("") != 0){
        convert(aa.data(),"/home/philip/Projekte/qt/ConvertTest/test1.pdf");
    }
    if(ui->txtPicTo->text().compare("") != 0){
        convert(bb.data(),"/home/philip/Projekte/qt/ConvertTest/test2.pdf");
    }
}

void ConvertGui::useFileExplorer(QLineEdit* le){
    QString path = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home/philip", tr("Image Files (*.png *.jpg *.bmp)"));
    le->insert(path);
}
