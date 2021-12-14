#include <QMessageBox>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

//Initializing this UI object with a new main window
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    //this object is calling set up UI which is going to open the window
    ui->setupUi(this);
}

//Delete UI object
MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButtonEnviarDados_clicked(){
    ui->labelStatus->setText("Status: Clicked");
    int col = ui->lineEditNColunas->text().toInt();
    int lin = ui->lineEditNLinhas->text().toInt();
    if((lin < 3 || lin > 8) || (col < 3 || col > 16))
        ui->labelStatus->setText("Status: Try Again");
    else{
        ui->labelStatus->setText("Status: Thank You");
        hide();
        game = new gamewindow(this);
        game->show();
    }
}
/*

void MainWindow::on_pushButtonClose_clicked()
{
    ui->label->setText("Status: HI BITCH");
}


void MainWindow::on_pushButtonCheck_clicked()
{
    QString username = ui->lineEdit_Name->text();
    QString password = ui->lineEdit_Password->text();

    if(username == "test" && password == "test")
        QMessageBox::information(this,"Login","Correct");
    else
        QMessageBox::warning(this,"Login","Incorrect");
}

*/