#include <convertgui.h>
#include <ui_convertgui.h>
#include <converter.h>
#include <qdesktopservices.h>
#include <qfiledialog.h>
#include <qtabwidget.h>
#include <qmessagebox.h>
#include <qlineedit.h>
#include <qdir.h>
#include <qurl.h>
#include <qpushbutton.h>
#include <qobject.h>
#include <string>

ConvertGui::ConvertGui(QWidget *parent) : QMainWindow(parent), ui(new Ui::ConvertGui)
{
    ui->setupUi(this);
    //connect(ui->convBt, SIGNAL(clicked()), SLOT());
    connect(ui->clearBtn, SIGNAL(clicked()), SLOT(clearLineEdits()));
    /*
    connect(ui->convBt, &QPushButton::clicked, [=] {
        QMessageBox msg;
        msg.setText("click");
        msg.show();
        //clearPaths();
    });
    connect(ui->clearBtn, &QPushButton::clicked, [=] {
        QMessageBox msg;
        msg.setText("click");
        msg.show();
        clearLineEdits();
    });
    */
    connect(ui->btnPicFrom, &QPushButton::clicked, [=] {
        useFileExplorer(ui->txtPicFrom);
    });
    connect(ui->btnPicTo, &QPushButton::clicked, [=] {
        useFileExplorer(ui->txtPicTo);
    });
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

