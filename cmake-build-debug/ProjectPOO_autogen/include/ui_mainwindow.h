/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButtonEnviarDados;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayoutColunas;
    QLabel *labelNColunas;
    QLineEdit *lineEditNColunas;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelNLinhas;
    QLineEdit *lineEditNLinhas;
    QLabel *labelStatus;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 281, 111));
        pushButtonEnviarDados = new QPushButton(groupBox);
        pushButtonEnviarDados->setObjectName(QString::fromUtf8("pushButtonEnviarDados"));
        pushButtonEnviarDados->setGeometry(QRect(10, 80, 251, 24));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 30, 110, 48));
        verticalLayoutColunas = new QVBoxLayout(layoutWidget);
        verticalLayoutColunas->setObjectName(QString::fromUtf8("verticalLayoutColunas"));
        verticalLayoutColunas->setContentsMargins(0, 0, 0, 0);
        labelNColunas = new QLabel(layoutWidget);
        labelNColunas->setObjectName(QString::fromUtf8("labelNColunas"));

        verticalLayoutColunas->addWidget(labelNColunas);

        lineEditNColunas = new QLineEdit(layoutWidget);
        lineEditNColunas->setObjectName(QString::fromUtf8("lineEditNColunas"));

        verticalLayoutColunas->addWidget(lineEditNColunas);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 110, 48));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelNLinhas = new QLabel(layoutWidget1);
        labelNLinhas->setObjectName(QString::fromUtf8("labelNLinhas"));

        verticalLayout_2->addWidget(labelNLinhas);

        lineEditNLinhas = new QLineEdit(layoutWidget1);
        lineEditNLinhas->setObjectName(QString::fromUtf8("lineEditNLinhas"));

        verticalLayout_2->addWidget(lineEditNLinhas);

        labelStatus = new QLabel(centralwidget);
        labelStatus->setObjectName(QString::fromUtf8("labelStatus"));
        labelStatus->setGeometry(QRect(310, 30, 211, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Dados Iniciais", nullptr));
        pushButtonEnviarDados->setText(QApplication::translate("MainWindow", "Enviar Dados", nullptr));
        labelNColunas->setText(QApplication::translate("MainWindow", "N. Colunas", nullptr));
        labelNLinhas->setText(QApplication::translate("MainWindow", "N. Linhas", nullptr));
        labelStatus->setText(QApplication::translate("MainWindow", "Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
