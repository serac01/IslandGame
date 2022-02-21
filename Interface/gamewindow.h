#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <vector>
#include <fstream>
#include <QDialog>
#include <QTableWidget>
#include <QLabel>
#include <map>

#include "../Ilha/ilha.h"
#include "../Comandos/comandos.h"
#include "../Save/save.h"


namespace Ui {
class gamewindow;
}

class GameWindow : public QDialog{
    Ilha* ilh;
    std::vector<Save*> saves;
    Ui::gamewindow *ui;
    QList<QLabel *> labels;
    std::vector<Comando> comandos = { {"exec", "<nomeFicheiro>"},
                                      {"cons", "<tipo> <linha> <coluna>"},
                                      {"liga", "<linha> <coluna>"},
                                      {"des", "<linha> <coluna>"},
                                      {"move", "<id> <linha> <coluna>"},
                                      {"vende", "<tipo> <quanto>"},
                                      {"cont", "<tipo>"},
                                      {"list", "<linha> <coluna>"},
                                      {"vende", "<linha> <coluna>"},
                                      {"next", ""},
                                      {"save", "<nome>"},
                                      {"load", "<nome>"},
                                      {"apaga", "<nome>"},
                                      {"config",  "<ficheiro>"},
                                      {"debcash", "<valor>"},
                                      {"debed", "<tipo> <linha> <coluna>"},
                                      {"debkill", "<id>"},
                                      {"upgrade", "<linha> <coluna>"},
                                      {"termina", ""} };

    Q_OBJECT

public:
    GameWindow(Ilha& ilh, QWidget *parent = nullptr);

    ~GameWindow();

    int pedirComandos(std::string text);
    void listar();
    int executaComando(std::vector<std::string> words, int op);
    int leFicheiro(std::string nomeF);

private slots:
    void pbComando_clicked();
};

#endif
