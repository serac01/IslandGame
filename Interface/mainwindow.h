#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"
#include <iostream>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow{
    Q_OBJECT
    Ui::MainWindow *ui;
    GameWindow *game;
    Ilha ilh;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonEnviarDados_clicked();
};

#endif
