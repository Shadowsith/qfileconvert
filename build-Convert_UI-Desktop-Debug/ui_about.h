/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConvertGui
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ConvertGui)
    {
        if (ConvertGui->objectName().isEmpty())
            ConvertGui->setObjectName(QStringLiteral("ConvertGui"));
        ConvertGui->resize(612, 290);
        centralWidget = new QWidget(ConvertGui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 170, 80, 26));
        ConvertGui->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ConvertGui);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ConvertGui->setStatusBar(statusBar);

        retranslateUi(ConvertGui);

        QMetaObject::connectSlotsByName(ConvertGui);
    } // setupUi

    void retranslateUi(QMainWindow *ConvertGui)
    {
        ConvertGui->setWindowTitle(QApplication::translate("ConvertGui", "ConvertGui", nullptr));
        pushButton->setText(QApplication::translate("ConvertGui", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConvertGui: public Ui_ConvertGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
