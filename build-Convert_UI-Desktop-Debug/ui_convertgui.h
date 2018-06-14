/********************************************************************************
** Form generated from reading UI file 'convertgui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTGUI_H
#define UI_CONVERTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConvertGui
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *convBt;
    QPushButton *clearBtn;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *lblPicFrom;
    QComboBox *cmbPicFrom;
    QLineEdit *txtPicFrom;
    QPushButton *btnPicFrom;
    QLabel *lblPicTo;
    QComboBox *cmbPicTo;
    QLineEdit *txtPicTo;
    QPushButton *btnPicTo;
    QWidget *tab2;
    QMenuBar *menuBar;
    QMenu *menuTest;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ConvertGui)
    {
        if (ConvertGui->objectName().isEmpty())
            ConvertGui->setObjectName(QStringLiteral("ConvertGui"));
        ConvertGui->resize(586, 294);
        centralWidget = new QWidget(ConvertGui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 210, 187, 28));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(25);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        convBt = new QPushButton(layoutWidget);
        convBt->setObjectName(QStringLiteral("convBt"));

        horizontalLayout->addWidget(convBt);

        clearBtn = new QPushButton(layoutWidget);
        clearBtn->setObjectName(QStringLiteral("clearBtn"));

        horizontalLayout->addWidget(clearBtn);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 671, 191));
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        tab1->setEnabled(true);
        layoutWidget1 = new QWidget(tab1);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 561, 91));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lblPicFrom = new QLabel(layoutWidget1);
        lblPicFrom->setObjectName(QStringLiteral("lblPicFrom"));

        gridLayout->addWidget(lblPicFrom, 0, 0, 1, 1);

        cmbPicFrom = new QComboBox(layoutWidget1);
        cmbPicFrom->addItem(QString());
        cmbPicFrom->addItem(QString());
        cmbPicFrom->addItem(QString());
        cmbPicFrom->addItem(QString());
        cmbPicFrom->setObjectName(QStringLiteral("cmbPicFrom"));

        gridLayout->addWidget(cmbPicFrom, 0, 1, 1, 1);

        txtPicFrom = new QLineEdit(layoutWidget1);
        txtPicFrom->setObjectName(QStringLiteral("txtPicFrom"));

        gridLayout->addWidget(txtPicFrom, 0, 2, 1, 1);

        btnPicFrom = new QPushButton(layoutWidget1);
        btnPicFrom->setObjectName(QStringLiteral("btnPicFrom"));

        gridLayout->addWidget(btnPicFrom, 0, 3, 1, 1);

        lblPicTo = new QLabel(layoutWidget1);
        lblPicTo->setObjectName(QStringLiteral("lblPicTo"));

        gridLayout->addWidget(lblPicTo, 1, 0, 1, 1);

        cmbPicTo = new QComboBox(layoutWidget1);
        cmbPicTo->addItem(QString());
        cmbPicTo->addItem(QString());
        cmbPicTo->addItem(QString());
        cmbPicTo->addItem(QString());
        cmbPicTo->setObjectName(QStringLiteral("cmbPicTo"));

        gridLayout->addWidget(cmbPicTo, 1, 1, 1, 1);

        txtPicTo = new QLineEdit(layoutWidget1);
        txtPicTo->setObjectName(QStringLiteral("txtPicTo"));

        gridLayout->addWidget(txtPicTo, 1, 2, 1, 1);

        btnPicTo = new QPushButton(layoutWidget1);
        btnPicTo->setObjectName(QStringLiteral("btnPicTo"));

        gridLayout->addWidget(btnPicTo, 1, 3, 1, 1);

        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        tabWidget->addTab(tab2, QString());
        ConvertGui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ConvertGui);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 586, 23));
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(true);
        menuTest = new QMenu(menuBar);
        menuTest->setObjectName(QStringLiteral("menuTest"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        ConvertGui->setMenuBar(menuBar);
        statusBar = new QStatusBar(ConvertGui);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ConvertGui->setStatusBar(statusBar);

        menuBar->addAction(menuTest->menuAction());
        menuBar->addAction(menuAbout->menuAction());

        retranslateUi(ConvertGui);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConvertGui);
    } // setupUi

    void retranslateUi(QMainWindow *ConvertGui)
    {
        ConvertGui->setWindowTitle(QApplication::translate("ConvertGui", "ConvertGui", nullptr));
        convBt->setText(QApplication::translate("ConvertGui", "Convert", nullptr));
        clearBtn->setText(QApplication::translate("ConvertGui", "Clear", nullptr));
        lblPicFrom->setText(QApplication::translate("ConvertGui", "From:", nullptr));
        cmbPicFrom->setItemText(0, QApplication::translate("ConvertGui", "PDF", nullptr));
        cmbPicFrom->setItemText(1, QApplication::translate("ConvertGui", "JPG", nullptr));
        cmbPicFrom->setItemText(2, QApplication::translate("ConvertGui", "PNG", nullptr));
        cmbPicFrom->setItemText(3, QApplication::translate("ConvertGui", "GIF", nullptr));

        btnPicFrom->setText(QApplication::translate("ConvertGui", "...", nullptr));
        lblPicTo->setText(QApplication::translate("ConvertGui", "To:", nullptr));
        cmbPicTo->setItemText(0, QApplication::translate("ConvertGui", "PDF", nullptr));
        cmbPicTo->setItemText(1, QApplication::translate("ConvertGui", "JPG", nullptr));
        cmbPicTo->setItemText(2, QApplication::translate("ConvertGui", "PNG", nullptr));
        cmbPicTo->setItemText(3, QApplication::translate("ConvertGui", "GIF", nullptr));

        btnPicTo->setText(QApplication::translate("ConvertGui", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("ConvertGui", "Pictures", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("ConvertGui", "Video", nullptr));
        menuTest->setTitle(QApplication::translate("ConvertGui", "Test", nullptr));
        menuAbout->setTitle(QApplication::translate("ConvertGui", "Abo&ut", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConvertGui: public Ui_ConvertGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTGUI_H
