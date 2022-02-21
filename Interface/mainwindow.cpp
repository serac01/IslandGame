#include <QMessageBox>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    ui->label->setText("<img src=\"../Interface/logo.png\" width=\"200\" height=\"79\">");
}

MainWindow::~MainWindow() { delete ui; }

//Quando o botao "Enviar Dados" for clicado
void MainWindow::on_pushButtonEnviarDados_clicked(){
    int col = ui->lineEditNColunas->text().toInt(), lin = ui->lineEditNLinhas->text().toInt();
    if((lin < 3 || lin > 8) || (col < 3 || col > 16))
        ui->labelStatus->setText("Dados Errados! Tente outra vez");
    else {
        hide();
        ilh.resizeIlha(lin,col);
        game = new GameWindow(ilh, this);
        game->show();
    }
}