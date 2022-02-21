#include "gamewindow.h"
#include "ui_GameWindow.h"
#include <string>
#include <iostream>

using namespace std;

GameWindow::GameWindow(Ilha& il, QWidget *parent) : ilh(&il), QDialog(parent), ui(new Ui::gamewindow){
    int i,j,k;

    ui->setupUi(this);

    //Conectar o botao para que ele execute uma função quando for clicado
    QObject::connect(ui->pbComando, &QPushButton::clicked, this, &GameWindow::pbComando_clicked);

    //Prencher o vetor com as labels
    labels << ui->lbCell00; labels << ui->lbCell01; labels << ui->lbCell02; labels << ui->lbCell03; labels << ui->lbCell04;
    labels << ui->lbCell05; labels << ui->lbCell06; labels << ui->lbCell07; labels << ui->lbCell08; labels << ui->lbCell09;
    labels << ui->lbCell010; labels << ui->lbCell011; labels << ui->lbCell012; labels << ui->lbCell013; labels << ui->lbCell014; labels << ui->lbCell015;
    labels << ui->lbCell10; labels << ui->lbCell11; labels << ui->lbCell12; labels << ui->lbCell13; labels << ui->lbCell14;
    labels << ui->lbCell15; labels << ui->lbCell16; labels << ui->lbCell17; labels << ui->lbCell18; labels << ui->lbCell19;
    labels << ui->lbCell110; labels << ui->lbCell111; labels << ui->lbCell112; labels << ui->lbCell113; labels << ui->lbCell114; labels << ui->lbCell115;
    labels << ui->lbCell20; labels << ui->lbCell21; labels << ui->lbCell22; labels << ui->lbCell23; labels << ui->lbCell24;
    labels << ui->lbCell25; labels << ui->lbCell26; labels << ui->lbCell27; labels << ui->lbCell28; labels << ui->lbCell29;
    labels << ui->lbCell210; labels << ui->lbCell211; labels << ui->lbCell212; labels << ui->lbCell213; labels << ui->lbCell214; labels << ui->lbCell215;
    labels << ui->lbCell30; labels << ui->lbCell31; labels << ui->lbCell32; labels << ui->lbCell33; labels << ui->lbCell34;
    labels << ui->lbCell35; labels << ui->lbCell36; labels << ui->lbCell37; labels << ui->lbCell38; labels << ui->lbCell39;
    labels << ui->lbCell310; labels << ui->lbCell311; labels << ui->lbCell312; labels << ui->lbCell313; labels << ui->lbCell314; labels << ui->lbCell315;
    labels << ui->lbCell40; labels << ui->lbCell41; labels << ui->lbCell42; labels << ui->lbCell43; labels << ui->lbCell44;
    labels << ui->lbCell45; labels << ui->lbCell46; labels << ui->lbCell47; labels << ui->lbCell48; labels << ui->lbCell49;
    labels << ui->lbCell410; labels << ui->lbCell411; labels << ui->lbCell412; labels << ui->lbCell413; labels << ui->lbCell414; labels << ui->lbCell415;
    labels << ui->lbCell50; labels << ui->lbCell51; labels << ui->lbCell52; labels << ui->lbCell53; labels << ui->lbCell54;
    labels << ui->lbCell55; labels << ui->lbCell56; labels << ui->lbCell57; labels << ui->lbCell58; labels << ui->lbCell59;
    labels << ui->lbCell510; labels << ui->lbCell511; labels << ui->lbCell512; labels << ui->lbCell513; labels << ui->lbCell514; labels << ui->lbCell515;
    labels << ui->lbCell60; labels << ui->lbCell61; labels << ui->lbCell62; labels << ui->lbCell63; labels << ui->lbCell64;
    labels << ui->lbCell65; labels << ui->lbCell66; labels << ui->lbCell67; labels << ui->lbCell68; labels << ui->lbCell69;
    labels << ui->lbCell610; labels << ui->lbCell611; labels << ui->lbCell612; labels << ui->lbCell613; labels << ui->lbCell614; labels << ui->lbCell615;
    labels << ui->lbCell70; labels << ui->lbCell71; labels << ui->lbCell72; labels << ui->lbCell73; labels << ui->lbCell74;
    labels << ui->lbCell75; labels << ui->lbCell76; labels << ui->lbCell77; labels << ui->lbCell78; labels << ui->lbCell79;
    labels << ui->lbCell710; labels << ui->lbCell711; labels << ui->lbCell712; labels << ui->lbCell713; labels << ui->lbCell714; labels << ui->lbCell715;

    //Defenir a cor da label a vermelho
    ui->lbError->setStyleSheet("QLabel { color : red; }");

    //Imprimir as abreviatura daz zonas
    for (i = 0; i < ilh->getLinha(); i++){
        k=16*i;
        for (j = 0; j < ilh->getColuna(); j++, k++)
            //Converter uma string numa qstring e compara-la com o texto que esta ecrito na label da ui
            if(QString::fromStdString(to_string(i)+to_string(j)) == labels.at(k)->text())
                labels.at(k)->setFrameShape(QFrame::Box);
    }

    //"Apagar" as labels que estão a mais
    for (i = 0, k = 0; i < 8; i++)
        for (j = 0; j < 16; j++,k++)
            //Se as labels não tiverem nome de zona desaparecem
            if("pnt\n \n \n " != labels.at(k)->text().toStdString() && "dsr\n \n \n " != labels.at(k)->text().toStdString()  && "pas\n \n \n " != labels.at(k)->text().toStdString()  && "flr\n \n \n " != labels.at(k)->text().toStdString() && "znX\n \n \n " != labels.at(k)->text().toStdString()&& "mnt\n \n \n " != labels.at(k)->text().toStdString())
                //Nao fazem resize
                labels.at(k)->setText("");
                //Faz resize
                //labels.at(k)->setVisible(false);
    ilh->amanhecer();
    ui->lbInformacao->setText(QString::fromStdString(ilh->informacaoIlha()));
    listar();
}

GameWindow::~GameWindow(){ delete ui; }

//Quando o botao for clicado:
void GameWindow::pbComando_clicked(){
    ui->lbError->setText("");
    pedirComandos(ui->leComando->text().toStdString());
    ui->leComando->clear();
}

//Tratar os dados recebidos
int GameWindow::pedirComandos(string text) {
    int numPalavras=0,op;
    vector<string> words;
    string comandoNome,linhaFicheiro;

    istringstream iss(text);

    //Percorrer o texto com o iterator e separa-lo, este método só pode dividir strings por espaços (delimitador default
    //do istream_iterator), e copia as strings extraídas para o vector, usando o algoritmo std::copy.
    copy(std::istream_iterator<string>(iss), std::istream_iterator<string>(), std::back_inserter(words));

    //contar o numero de palavras
    for (const auto &str : words)
        numPalavras++;

    //se nao foi introduzido texto (o empty falha nos espaços em branco)
    if(numPalavras==0){
        ui->lbError->setText("Intruduza texto");
        return 0;
    }

    //Percorre os comandos todos e confirma se existe algum igual ao ue o utilizador introduziu
    for (op = 0; op < comandos.size(); op++)
        if (comandos[op].getNome() == words[0])
            break;

    //Caso o comando escrito nao existe no vector
    if (op == comandos.size()) {
        ui->lbError->setText("Comando Desconhecido");
        return 0;
    }

    //Se o comando for o exec
    if(words[0]=="exec")
        if (words.size() != 2)
            ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
        else
            return leFicheiro(words[1]);
    else
        return executaComando(words, op);
}

//Se o comando for o 'exec', le os comandos dos ficheiros
int GameWindow::leFicheiro(string nomeF){
    int numPalavras,op,nLinha=0;
    vector<string> words;
    string comandoNome,linhaFicheiro;

    //Abrir o ficheiro
    ifstream nameFileout;
    nameFileout.open(nomeF);

    while(getline(nameFileout, linhaFicheiro)){
        nLinha++,numPalavras=0;//Inicialização das variaveis a cada comando
        words.clear(); //Limpar o comando que foi escrito anteriormente

        istringstream iss(linhaFicheiro);

        //Percorrer o texto com o iterator e separa-lo, este método só pode dividir strings por espaços (delimitador default
        //do istream_iterator), e copia as strings extraídas para o vector, usando o algoritmo std::copy.
        copy(std::istream_iterator<string>(iss), std::istream_iterator<string>(), std::back_inserter(words));

        //contar o numero de palavras
        for (const auto &str : words)
            numPalavras++;

        //se nao foi introduzido texto (o empty falha nos espaços em branco)
        if(numPalavras==0){
            ui->lbError->setText("Nenhum comando foi detetado na linha " + QString::fromStdString(to_string(nLinha)) + " <" + QString::fromStdString(nomeF) + ">");
            nameFileout.close();
            return 0;
        }

        //Percorre os comandos todos e confirma se existe algum igual ao que o utilizador introduziu
        for (op = 0; op < comandos.size(); op++)
            if (comandos[op].getNome() == words[0])
                break;

        //Caso o comando escrito nao existe no vetor
        if (op == comandos.size()) {
            ui->lbError->setText("Comando Desconhecido");
            return 0;
        }

        if(executaComando(words,op)==0) {
            return 0;
        }
    }

    //Fechar o ficheiro
    nameFileout.close();
}

int GameWindow::executaComando(vector<string> words, int op){
    ui->lbInformacao->setText(QString::fromStdString(ilh->informacaoIlha()));
    switch (op) {
        case 1: { //cons      <tipo> <linha> <coluna>
            if ((words.size() != 4) || !((words[1]=="minaf" || words[1]=="minac" || words[1]=="central" || words[1]=="bat" || words[1]=="fund" || words[1]=="serr") && (stoi(words[2])>0 && stoi(words[2])<=ilh->getLinha()) && (stoi(words[3])>0 && stoi(words[3])<=ilh->getColuna()))) {
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()) + "\tTipo: minaf | minac | central | bat | fund | edx");
                break;
            }
            ilh->preparaEdificio(words[1], stoi(words[2]), stoi(words[3]));
            listar();
            break;
        }

        case 2: { //liga      <linha> <coluna>
            if ((words.size() != 3) || !((stoi(words[1])>0 && stoi(words[1])<=ilh->getLinha()) && (stoi(words[2])>0 && stoi(words[2])<=ilh->getColuna()))) {
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                break;
            }
            ilh->ligaEdificio(stoi(words[1]), stoi(words[2]));
            break;
        }

        case 3: { //des       <linha> <coluna>
            if (words.size() != 3 || !((stoi(words[1])>0 && stoi(words[1])<=ilh->getLinha()) && (stoi(words[2])>0 && stoi(words[2])<=ilh->getColuna()))) {
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                break;
            }
            ilh->desligaEdificio(stoi(words[1]), stoi(words[2]));
            break;
        }

        case 4: { //move      <id> <linha> <coluna>
            if (words.size() != 4 || !((stoi(words[2])>0 && stoi(words[2])<=ilh->getLinha()) && (stoi(words[3])>0 && stoi(words[3])<=ilh->getColuna()))) {
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                return 0;
            }
            ilh->moveTrabalhador(words[1], stoi(words[2]), stoi(words[3]));
            listar();
            break;
        }

        case 5: { //vende     <tipo> <quanto>
            //Fazer o redericionamento para o segundo comando vende
            if (words.size() != 3 || !(words[1]=="ferro" || words[1]=="aco" || words[1]=="carvao" || words[1]=="mad" || words[1]=="viga" || words[1]=="eletr")) {
                executaComando(words, 8);
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                break;
            }
            ilh->vendeRecurso(words[1], stof(words[2]));
            break;
        }

        case 6: { //cont      <tipo>
            if ((words.size() != 2) || !((words[1]=="oper" || words[1]=="len" || words[1]=="miner"))) {
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                return 0;
            }
            ilh->contrataTrabalhador(words[1]);
            listar();
            break;
        }

        case 7: { //list      <linha> <coluna>
            if (words.size() == 1) {
                ui->lbInformacao->setText(QString::fromStdString(ilh->informacaoIlha()+ilh->list()));
                break;
            } else if (words.size() == 3 && (stoi(words[1])>0 && stoi(words[1])<=ilh->getLinha()) && (stoi(words[2])>0 && stoi(words[2])<=ilh->getColuna())) {
                ui->lbInformacao->setText(QString::fromStdString(ilh->informacaoIlha()+ilh->listZona(stoi(words[1]),stoi(words[2]))));
                break;
            } else {
                if (words.size() != 3 || !((stoi(words[1])>0 && stoi(words[1])<=ilh->getLinha()) && (stoi(words[2])>0 && stoi(words[2])<=ilh->getColuna()))) {
                    ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                    break;
                }
            }
        }

        case 8: { //vende     <linha> <coluna>
            if (words.size() != 3 || !((stoi(words[1])>0 && stoi(words[1])<=ilh->getLinha()) && (stoi(words[2])>0 && stoi(words[2])<=ilh->getColuna()))) {
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                break;
            }
            ilh->vendeEdificio(stoi(words[1]), stoi(words[2]));
            listar();
            break;
        }

        case 9: { //next
            if (words.size() != 1) {
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                break;
            }
            ilh->anoitecer();
            ilh->amanhecer();
            ui->lbInformacao->setText(QString::fromStdString(ilh->informacaoIlha()));
            listar();
            break;
        }

        case 10: { //save      <nome>
            if (words.size() != 2) {
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                break;
            }
            for (auto it = saves.begin(); it != saves.end(); it++)
                if ((*it)->getNome() == words[1])
                    ui->lbError->setText("Ja existe esse nome");
            saves.push_back(new Save(*ilh, words[1]));
            break;
        }

        case 11: { //load      <nome>
            if (words.size() != 2) {
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                break;
            }

            /*for (auto it = saves.begin(); it != saves.end(); it++)
                if ((*it)->getNome() == words[1])
                        *ilh = (*it)->getIlha();*/
            listar();
            break;
        }

        case 12: { //apaga     <nome>
            if (words.size() != 2) {
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                break;
            }
            /*for (auto it = saves.begin(); it != saves.end(); it++)
                if ((*it)->getNome() == words[1]) {
                    delete (*it);
                    saves.erase(it);
                }*/
            listar();
            break;
        }

        case 13: { //config    <ficheiro>
            if (words.size() != 2) {
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                break;
            }
            ilh->leConfig(words[1]);
            listar();
            break;
        }

        case 14: { //debcash   <valor>
            if (words.size() != 2) {
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                break;
            }
            ilh->debcash(stoi(words[1]));
            listar();
            break;
        }

        case 15: { //debed     <tipo> <linha> <coluna>
            if (words.size() != 4) {
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                break;
            }
            ilh->debed(words[1], stoi(words[2]), stoi(words[3]));
            listar();
            break;
        }

        case 16: { //debkill   <id>
            if (words.size() != 2) {
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                break;
            }
            ilh->debkill(words[1]);
            listar();
            break;
        }

        case 17: { //upgrade      <linha> <coluna>
            if ((words.size() != 3) || !((stoi(words[1])>0 && stoi(words[1])<=ilh->getLinha()) && (stoi(words[2])>0 && stoi(words[2])<=ilh->getColuna()))) {
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                break;
            }
            ilh->upgradeEdificio(stoi(words[1]), stoi(words[2]));
            listar();
            break;
        }

        case 18: { //termina
            if (words.size() != 1) {
                ui->lbError->setText("Instruções: " + QString::fromStdString(comandos[op].getNome()) + " " + QString::fromStdString(comandos[op].getArgs()));
                break;
            }
            QCoreApplication::quit();
        }

        default: {
            ui->lbError->setText("Comando não reconhecido");
            return 0;
        }
    }

    return 1; //Se tudo correu bem ate aqui
}

void GameWindow::listar() {
    for (int k, i = 0; i < ilh->getLinha(); i++){
        k=16*i;//Avancar a para a proxima linha das labels
        for (int j = 0; j < ilh->getColuna(); j++,  k++) {
            labels.at(k)->setText(QString::fromStdString(ilh->getAbrZona(i,j) + "\n"
                                                         + ilh->getEdificioZona(i,j) + "\n"
                                                         + ilh->getNomeTrabalhadoresZona(i,j) + "\n"
                                                         + to_string(ilh->getNumTrabalhadoresZona(i,j)) ));
        }
    }
}