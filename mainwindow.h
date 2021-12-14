#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"

//Telling the .ui file to include this mainwindow in UI
namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow{
    //Tells QT that we are going to use GUI application and we are going to use signals and slot,
    //so if we use this it allows us to create signals and slots for our widgets
    Q_OBJECT

public:
    //Constructor and Destructor
    MainWindow(QWidget *parent = nullptr);
    //delete all the pointers objects
    ~MainWindow();
private slots:
    /*void on_pushButtonClose_clicked();

    void on_pushButtonCheck_clicked();*/
    void on_pushButtonEnviarDados_clicked();

private:
    //object of main window
    //This object is going to access all the widgets that we will add in your main window and UI
    Ui::MainWindow *ui;
    gamewindow *game;
};

#endif
