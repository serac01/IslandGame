/********************************************************************************
** Form generated from reading UI file 'gamedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEDIALOG_H
#define UI_GAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>

QT_BEGIN_NAMESPACE

class Ui_gridGame
{
public:
    QGridLayout *gridLayout;

    void setupUi(QDialog *gridGame)
    {
        if (gridGame->objectName().isEmpty())
            gridGame->setObjectName(QString::fromUtf8("gridGame"));
        gridGame->resize(692, 367);
        gridLayout = new QGridLayout(gridGame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        retranslateUi(gridGame);

        QMetaObject::connectSlotsByName(gridGame);
    } // setupUi

    void retranslateUi(QDialog *gridGame)
    {
        gridGame->setWindowTitle(QApplication::translate("gridGame", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gridGame: public Ui_gridGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEDIALOG_H
