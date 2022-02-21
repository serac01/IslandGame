#include <cmath>
#include "ilha.h"

using namespace std;

/************************************* Preparação da Ilha *************************************/
int Ilha::diaSimulacao=0;

Ilha::Ilha(int lin, int col): linha(lin), coluna(col) { criaIlha(); }

Ilha::~Ilha() { destroiIlha(); }

void Ilha::criaIlha() {
    int pos, cont_zonas[6]={0,0,0,0,0,0};

    arrayZonas = new Zona**[linha];
    for (int i = 0; i < linha; i++)
        arrayZonas[i] = new Zona*[coluna];

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            do
                pos = rand() % 6;
            while (cont_zonas[pos]==1 && (cont_zonas[0]==0 || cont_zonas[1]==0 || cont_zonas[3]==0 || cont_zonas[4]==0 || cont_zonas[5]==0));
            cont_zonas[pos]=1;

            //"Deserto", "Pastagem", "Floresta", "Montanha","Pantano", "ZonaX"
            if(pos==0)
                arrayZonas[i][j]=new Deserto;
            else if(pos==1)
                arrayZonas[i][j]=new Pastagem;
            else if(pos==2)
                arrayZonas[i][j]=new Floresta;
            else if(pos==3)
                arrayZonas[i][j]=new Montanha;
            else if(pos==4)
                arrayZonas[i][j]=new Pantano;
            else if(pos==5)
                arrayZonas[i][j]=new Praia;
        }
    }
}

void Ilha::resizeIlha(int l, int c) {
    destroiIlha();
    linha=l, coluna=c;
    arrayZonas[0][0]->setContador();
    criaIlha();
}

void Ilha::destroiIlha() {
    for(int i=0;i<linha;i++)
        for(int j=0;j<coluna;j++)
            delete arrayZonas[i][j];

    for(int i=0;i<linha;i++)
        delete [] arrayZonas[i];
    delete [] arrayZonas;
}

int &Ilha::getLinha() { return linha; }

int &Ilha::getColuna() { return coluna; }

/************************************* Funções para serem executadas com comandos *************************************/
/********************** Edificios **********************/
int Ilha::preparaEdificio(string nome, int lin, int col){
    float nVigas=0,nVigasSobra=0;
    int i,j,flagEncontreiSerr=0;

    if(!(nome=="minaf" || nome=="minac" || nome=="central" || nome=="bat" || nome=="fund" || nome=="serr"))
        return 0;   //Parametros de entrada errados

    //Vai buscar as vigas
    for(i=0; i<linha; i++)
        for(j=0; j<coluna; j++)
            if(arrayZonas[i][j]->getNomeEdificio() == "serr"){
                flagEncontreiSerr=1;
                nVigasSobra=nVigas=nVigas+arrayZonas[i][j]->getArmazemEd();
                if(nVigas>=10)
                    break;
            }

    if(nVigas>10){
        nVigasSobra=10;
        arrayZonas[i][j]->setArmazemEd(nVigas-10);
    }

    arrayZonas[lin-1][col-1]->constroiEdificio(nome, &dinheiroDisponivel, &nVigasSobra);

    if(flagEncontreiSerr)
        arrayZonas[i][j]->setArmazemEd(nVigasSobra);

    return 1;
}

int Ilha::ligaEdificio(int lin, int col) { return arrayZonas[lin-1][col-1]->ligaEdificio(); }

int Ilha::desligaEdificio(int lin, int col) { return arrayZonas[lin-1][col-1]->desligaEdificio(); }

int Ilha::upgradeEdificio(int lin, int col) { return arrayZonas[lin-1][col-1]->upEdificio(&dinheiroDisponivel); }

int Ilha::vendeEdificio(int lin, int col){
    if(arrayZonas[lin-1][col-1]->temEdificio()==0)
        return 0;

    dinheiroDisponivel = dinheiroDisponivel + arrayZonas[lin-1][col-1]->getPrecoEdificio(arrayZonas[lin-1][col-1]->getNomeEdificio());
    return 1;
}

/********************** Recursos **********************/
int Ilha::vendeRecurso(string nome, float quantidade){
    float ferro=0, barraAco=0, carvao=0, madeira=0, viga=0, eletricidade=0;

    //Receber os recursos
    for(int i=0; i<linha; i++)
        for(int j=0; j<coluna; j++){
            if(arrayZonas[i][j]->getNome() == "Floresta")
                madeira=madeira + arrayZonas[i][j]->getMadeiraArmazenada();
            else if(arrayZonas[i][j]->getNome() == "Montanha")
                ferro=ferro+arrayZonas[i][j]->getFerroArmazenada();
            if(arrayZonas[i][j]->getNomeEdificio() == "minaf")
                ferro=ferro+arrayZonas[i][j]->getArmazemEd();
            else if(arrayZonas[i][j]->getNomeEdificio() == "minac")
                carvao=carvao+arrayZonas[i][j]->getArmazemEd();
            else if(arrayZonas[i][j]->getNomeEdificio() == "central")
                carvao=carvao+arrayZonas[i][j]->getArmazemEd();
            else if(arrayZonas[i][j]->getNomeEdificio() == "bat")
                eletricidade=eletricidade+arrayZonas[i][j]->getArmazemEd();
            else if(arrayZonas[i][j]->getNomeEdificio() == "fund")
                barraAco=barraAco+arrayZonas[i][j]->getArmazemEd();
            else if(arrayZonas[i][j]->getNomeEdificio() == "serr")
                viga=viga+arrayZonas[i][j]->getArmazemEd();
        }

    if("ferro" == nome){
        if(ferro < quantidade)
            return 0;
        for(int i=0; i<linha; i++)
            for(int j=0; j<coluna; j++)
                if(arrayZonas[i][j]->getNomeEdificio() == "minaf")
                    arrayZonas[i][j]->setArmazemEd(-quantidade);
    }
    else if("aco" == nome){
        if(barraAco < quantidade)
            return 0;
        for(int i=0; i<linha; i++)
            for(int j=0; j<coluna; j++)
                if(arrayZonas[i][j]->getNomeEdificio() == "fund")
                    arrayZonas[i][j]->setArmazemEd(-quantidade);
    }
    else if("carvao" == nome){
        if(carvao < quantidade)
            return 0;
        for(int i=0; i<linha; i++)
            for(int j=0; j<coluna; j++)
                if(arrayZonas[i][j]->getNomeEdificio() == "minac")
                    arrayZonas[i][j]->setArmazemEd(-quantidade);
    }
    else if("mad" == nome){
        if(madeira < quantidade)
            return 0;
        for(int i=0; i<linha; i++)
            for(int j=0; j<coluna; j++)
                if(arrayZonas[i][j]->getNome() == "Floresta")
                    arrayZonas[i][j]->setMadeiraArmazenada(-quantidade);
    }
    else if("viga" == nome){
        if(viga < quantidade)
            return 0;
        for(int i=0; i<linha; i++)
            for(int j=0; j<coluna; j++)
                if(arrayZonas[i][j]->getNomeEdificio() == "serr")
                    arrayZonas[i][j]->setArmazemEd(-quantidade);
    }
    else if("eletr" == nome){
        if(eletricidade < quantidade)
            return 0;
        for(int i=0; i<linha; i++)
            for(int j=0; j<coluna; j++)
                if(arrayZonas[i][j]->getNomeEdificio() == "bat")
                    arrayZonas[i][j]->setArmazemEd(-quantidade);
    }
}

/********************** Trabalhadores **********************/
int Ilha::contrataTrabalhador(string nome) {
    int nPastagens=0,pasN=1;

    //Contar o numero de pastagens
    for(int i=0; i<linha; i++)
        for(int j=0; j<coluna; j++)
            if(arrayZonas[i][j]->getNome() == "Pastagem")
                nPastagens++;

    if(nPastagens==0) //Se não houver pastagens
        return 0;

    nPastagens = (rand()%nPastagens)+1; //Sorteia um dos pastos

    for(int i=0; i<linha; i++)
        for(int j=0; j<coluna; j++)
            if(arrayZonas[i][j]->getNome() == "Pastagem"){   //Se a zona for do tipo Pastagem
                if(pasN++ == nPastagens){                    //Confirma se é o numero do pasto certo se nao incrementa
                    if(nome=="oper"){
                        if(dinheiroDisponivel>=15){
                            trabalhadores.push_back(new Trabalhador("Operario",to_string(trabalhadores.size()+1)+"."+ to_string(diaSimulacao),i,j,configPrecoTrab[0],0.05));
                            dinheiroDisponivel=dinheiroDisponivel-configPrecoTrab[0];
                            return 1;
                        }
                        return 0;
                    } else if(nome=="len"){
                        if(dinheiroDisponivel>=20){
                            trabalhadores.push_back(new Trabalhador("Lenhador",to_string(trabalhadores.size()+1)+"."+ to_string(diaSimulacao),i,j,configPrecoTrab[1],0));
                            dinheiroDisponivel=dinheiroDisponivel-configPrecoTrab[1];
                            return 1;
                        }
                        return 0;
                    } else if(nome=="miner"){
                        if(dinheiroDisponivel>=10){
                            trabalhadores.push_back(new Trabalhador("Mineiro",to_string(trabalhadores.size()+1)+"."+ to_string(diaSimulacao),i,j,configPrecoTrab[2],0.1));
                            dinheiroDisponivel=dinheiroDisponivel-configPrecoTrab[2];
                            return 1;
                        }
                        return 0;
                    }
                }
            }
}

int Ilha::moveTrabalhador(string id, int lin, int col) {
    auto pos=trabalhadores.begin();
    int tam=0;

    if(trabalhadores.empty())
        return 0; //Se não existirem trabalhadores contratados

    //Vai a procura do ID
    while(trabalhadores.end()!=pos){
        if((*pos)->getID() != id)
            pos++, tam++;
        else
            break;
    }

    if(tam == trabalhadores.size()) //Se nao existir o trabalhador com o ID que foi recebido termina
        return 0;

    //Move-o para outra zona
    (*pos)->setLinha(lin-1);
    (*pos)->setColuna(col-1);

    return 1;
}

int Ilha::getNumTrabalhadoresZona(int lin, int col, string nome) {
    auto pos=trabalhadores.begin();
    int contador=0;

    while(pos != trabalhadores.end()) {
        if(nome=="undefined"){
            if((*pos)->getLinha()==lin && (*pos)->getColuna()==col)
                contador++;
        }
        else{
            if((*pos)->getLinha()==lin && (*pos)->getColuna()==col && (*pos)->getNome()==nome)
                contador++;
        }
        pos++;
    }
    return contador;
}

string Ilha::getNomeTrabalhadoresZona(int lin, int col) {
    auto pos=trabalhadores.begin();
    int contador=0;
    string nome="    ";

    while(pos != trabalhadores.end()) {
        if((*pos)->getLinha()==lin && (*pos)->getColuna()==col && contador<4){
            nome[contador]=(*pos)->getNome()[0];
            contador++;
        }
        pos++;
    }
    return nome;
}

/********************** Ler Ficheiros **********************/
int Ilha::leConfig(string nomeF){
    int numPalavras,nLinha=0;
    vector<string> words, cTrab;
    string linhaFicheiro;

    //Abrir o ficheiro
    ifstream nameFileout;
    nameFileout.open(nomeF);

    while(getline(nameFileout, linhaFicheiro)){
        nLinha++,numPalavras=0;
        words.clear();
        istringstream iss(linhaFicheiro);
        copy(std::istream_iterator<string>(iss), std::istream_iterator<string>(), std::back_inserter(words));

        for (const auto &str : words)
            numPalavras++;

        if(numPalavras==0){
            nameFileout.close();
            return 0;
        }

        for(int i=0; i<linha; i++)
            for(int j=0; j<coluna; j++)
                arrayZonas[i][j]->setPrecoEdificio(words);

        for(auto pos=words.begin(); pos!=words.end(); pos++){
            if(*pos == "oper"){
                pos++;
                configPrecoTrab[0]= stof(*pos);
            }
            else if(*pos == "len"){
                pos++;
                configPrecoTrab[1]= stof(*pos);
            }
            else if(*pos == "miner"){
                pos++;
                configPrecoTrab[2]= stof(*pos);
            }
            else
                pos++;
        }
    }

    //Fechar o ficheiro
    nameFileout.close();
}

/********************** Acontecimentos do dia **********************/
void Ilha::amanhecer(){
    diaSimulacao++;
    vector<string> words;

    for(int i=0; i<linha; i++)
        for(int j=0; j<coluna; j++){
            arrayZonas[i][j]->maisMadeira(diaSimulacao, arrayZonas[i][j]->temEdificio());

            //Zonas que produzem recursos
            if(arrayZonas[i][j]->getNome() == "Floresta" && diaSimulacao%4!=0)
                arrayZonas[i][j]->produzZona(getNumTrabalhadoresZona(i, j, "Lenhador"));
            else if(arrayZonas[i][j]->getNome() == "Montanha")
                arrayZonas[i][j]->produzZona(getNumTrabalhadoresZona(i, j));

            //Desabar
            if(arrayZonas[i][j]->desaba(diaSimulacao)){
                for(auto pos = trabalhadores.begin(); pos != trabalhadores.end(); pos++)
                    if((*pos)->getLinha()==i && (*pos)->getColuna()==j)
                        pos = trabalhadores.erase(pos);
            }
        }
}

void Ilha::anoitecer(){
    vector<string> zonaAdj, edificioAdj, ondeEsta;
    int oper=0, len=0, miner=0, flagFunciona=0;
    float existeMadeira=0;

    for(int i=0; i<linha; i++)
        for(int j=0; j<coluna; j++){
            if(arrayZonas[i][j]->temEdificio() && arrayZonas[i][j]->estadoEdificio()){ //Se tiver edificio e estiver a funcionar vai acontecer as mudanças da noite
                //conta o número de trabalhadores de cada tipo em cada zona
                for(auto pos = trabalhadores.begin(); pos != trabalhadores.end(); pos++)
                    if((*pos)->getNome()=="Mineiro")
                        miner++;
                    else if((*pos)->getNome()=="Lenhador")
                        len++;
                    else if((*pos)->getNome()=="Operario")
                        oper++;

                zonaAdj=getZonasAdj(i,j);
                edificioAdj=getEdificioAdj(i,j);

                //So recebe recursos na minaf e minac se tiver pelo menos um mineiro
                if(miner>0 && (arrayZonas[i][j]->getNomeEdificio() == "minaf" || arrayZonas[i][j]->getNomeEdificio() == "minac"))
                    if(arrayZonas[i][j]->getNome() == "Deserto")
                        arrayZonas[i][j]->setArmazemEdReduz(2);
                    else if(arrayZonas[i][j]->getNome() == "Montanha")
                        arrayZonas[i][j]->setArmazemEdDobra(2);
                    else
                        arrayZonas[i][j]->setArmazemEd(2);

                if(oper>0 && arrayZonas[i][j]->getNomeEdificio() == "central"){
                    for(auto pos=zonaAdj.begin(); pos!=zonaAdj.end(); pos++){
                        ondeEsta=dividePalavras(*pos);
                        if(ondeEsta[0] == "Floresta")
                            if(arrayZonas[stoi(ondeEsta[1])][stoi(ondeEsta[2])]->getMadeiraArmazenada() > 0){
                                arrayZonas[stoi(ondeEsta[1])][stoi(ondeEsta[2])]->setMadeiraArmazenada(-1);
                                existeMadeira++;
                            }
                    }
                    if(existeMadeira>0)
                        arrayZonas[i][j]->setArmazemEd(1);
                }

                //Para funcionar precisa de um operario de uma minaf e de uma minac ou ce (por causa do carvao)
                if(oper>0 && arrayZonas[i][j]->getNomeEdificio() == "fund"){
                    for(auto pos=edificioAdj.begin(); pos!=edificioAdj.end(); pos++){
                        ondeEsta=dividePalavras(*pos);
                        if(ondeEsta[0] == "minaf" && arrayZonas[stoi(ondeEsta[1])][stoi(ondeEsta[2])]->getArmazemEd() > 1.5)
                            flagFunciona++;
                        if((ondeEsta[0] == "minac" || ondeEsta[0] == "central") && arrayZonas[stoi(ondeEsta[1])][stoi(ondeEsta[2])]->getArmazemEd() > 0.5)
                            flagFunciona++;
                    }
                    if(flagFunciona>1){
                        for(auto pos=edificioAdj.begin(); pos!=edificioAdj.end(); pos++){
                            ondeEsta=dividePalavras(*pos);
                            if(ondeEsta[0] == "minaf" && arrayZonas[stoi(ondeEsta[1])][stoi(ondeEsta[2])]->getArmazemEd() > 1.5)
                                arrayZonas[stoi(ondeEsta[1])][stoi(ondeEsta[2])]->setArmazemEd(-1.5);
                            if((ondeEsta[0] == "minac" || ondeEsta[0] == "central") && arrayZonas[stoi(ondeEsta[1])][stoi(ondeEsta[2])]->getArmazemEd() > 0.5)
                                arrayZonas[stoi(ondeEsta[1])][stoi(ondeEsta[2])]->setArmazemEd(-0.5);
                        }
                        arrayZonas[i][j]->setArmazemEd(1);
                    }
                }


                if(oper>0 && arrayZonas[i][j]->getNomeEdificio() == "serr"){
                    for(auto pos=zonaAdj.begin(); pos!=zonaAdj.end(); pos++){
                        ondeEsta=dividePalavras(*pos);
                        if(ondeEsta[0] == "Floresta")
                            if(arrayZonas[stoi(ondeEsta[1])][stoi(ondeEsta[2])]->getMadeiraArmazenada() >= 2){
                                arrayZonas[stoi(ondeEsta[1])][stoi(ondeEsta[2])]->setMadeiraArmazenada(-2);
                                arrayZonas[i][j]->setArmazemEd(4);
                                break;
                            }
                    }
                }
            }
        }

    //Para a funcao que tem que ter edificios adjacentes anteriormente criados
    for(int i=0; i<linha; i++)
        for(int j=0; j<coluna; j++){
            if(arrayZonas[i][j]->temEdificio() && arrayZonas[i][j]->estadoEdificio()){ //Se tiver edificio e estiver a funcionar vai acontecer as mudanças da noite

                if(existeMadeira>0 && arrayZonas[i][j]->getNomeEdificio() == "bat") { //Se a central produziu carvão
                    for(auto pos=edificioAdj.begin(); pos!=edificioAdj.end(); pos++) {
                        ondeEsta=dividePalavras(*pos);
                        if(ondeEsta[0] == "central"){
                            cout << "produz eletrecidade" << endl;
                            arrayZonas[i][j]->setArmazemEd(existeMadeira);
                        }
                    }
                }
            }
            if(arrayZonas[i][j]->temEdificio() && (arrayZonas[i][j]->getNomeEdificio() == "minaf" || arrayZonas[i][j]->getNomeEdificio() == "minac"))
                if(((float)rand())/RAND_MAX <= arrayZonas[i][j]->getPD())
                    arrayZonas[i][j]->apagaEdificio();
        }

    //Realizar a probabilidade de um trabalhador se despedir
    for(auto pos=trabalhadores.begin(); pos != trabalhadores.end(); ){
        float prob = ((float)rand())/RAND_MAX; // gera um numero entre 0.0 e 1.0
        if( prob <= (*pos)->getProbabilidadeDespedir() && arrayZonas[(*pos)->getLinha()][(*pos)->getColuna()]->getNome() !="Montanha" && arrayZonas[(*pos)->getLinha()][(*pos)->getColuna()]->getNome() !="Pastagem"  && arrayZonas[(*pos)->getLinha()][(*pos)->getColuna()]->getNome() !="Praia") {
            pos = trabalhadores.erase(pos);
        }
        else if(arrayZonas[(*pos)->getLinha()][(*pos)->getColuna()]->getNome() == "Montanha"){
            if(prob <= ((*pos)->getProbabilidadeDespedir() + 0.05)){
                pos = trabalhadores.erase(pos);
            }
        }
        else
            pos++;
    }
}

/********************** Informações da ilha **********************/
string Ilha::informacaoIlha(){
    string texto;
    int lenhador=0, mineiro=0, operario=0;
    float ferro=0, barraAco=0, carvao=0, madeira=0, viga=0, eletricidade=0,riqueza=0;

    //Vai a procura do ID
    for(auto pos=trabalhadores.begin(); trabalhadores.end()!=pos; pos++)
        if((*pos)->getNome() == "Mineiro")
            mineiro++;
        else if((*pos)->getNome() == "Lenhador")
            lenhador++;
        else if((*pos)->getNome() == "Operario")
            operario++;

    for(int i=0; i<linha; i++)
        for(int j=0; j<coluna; j++){
            if(arrayZonas[i][j]->getNome() == "Floresta")
                madeira=madeira+arrayZonas[i][j]->getMadeiraArmazenada();
            else if(arrayZonas[i][j]->getNome() == "Montanha")
                ferro=ferro+arrayZonas[i][j]->getFerroArmazenada();

            if(arrayZonas[i][j]->getNomeEdificio() == "minaf")
                ferro=ferro+arrayZonas[i][j]->getArmazemEd();
            else if(arrayZonas[i][j]->getNomeEdificio() == "minac")
                carvao=carvao+arrayZonas[i][j]->getArmazemEd();
            else if(arrayZonas[i][j]->getNomeEdificio() == "central")
                carvao=carvao+arrayZonas[i][j]->getArmazemEd();
            else if(arrayZonas[i][j]->getNomeEdificio() == "bat")
                eletricidade=eletricidade+arrayZonas[i][j]->getArmazemEd();
            else if(arrayZonas[i][j]->getNomeEdificio() == "fund")
                barraAco=barraAco+arrayZonas[i][j]->getArmazemEd();
            else if(arrayZonas[i][j]->getNomeEdificio() == "serr")
                viga=viga+arrayZonas[i][j]->getArmazemEd();
        }

    texto = "\tDia "+ to_string(diaSimulacao) + "\n" +
            "Riqueza Acumulada: " + to_string(dinheiroDisponivel + riqueza ) + "\n\n" +
            "Lista de Recursos: " + "\n" +
            "   Ferro: " + to_string(ferro) + "\n" +
            "   Barra Aço: " + to_string(barraAco) + "\n" +
            "   Carvão: " + to_string(carvao) + "\n" +
            "   Madeira: " + to_string(madeira) + "\n" +
            "   Viga Madeira: " + to_string(viga) + "\n" +
            "   Eletricidade: " + to_string(eletricidade) + "\n" +
            "Lista de Trabalhadores: " + to_string(trabalhadores.size()) + "\n" +
            "   Lenhadores: " + to_string(lenhador) + "\n" +
            "   Mineiros: " + to_string(mineiro) + "\n" +
            "   Operarios: " + to_string(operario) + "\n";

    return texto;
}

string Ilha::list(){
    string texto;
    int nEdificios=0;

    for(int i=0; i<linha; i++)
        for(int j=0; j<coluna; j++)
            if(arrayZonas[i][j]->temEdificio())
                nEdificios++;

    texto = "Edificios: " + to_string(nEdificios) + "\n";

    return texto;
}

string Ilha::listZona(int lin, int col){
    string texto, edificios;
    int trab;

    if(arrayZonas[lin-1][col-1]->temEdificio())
        edificios=arrayZonas[lin-1][col-1]->getNomeEdificio();

    trab = getNumTrabalhadoresZona(lin-1,col-1);

    texto = "\n\n\tZona " + to_string(lin) + " " + to_string(col) + "\n" +
            "Edificio: " + edificios + "\n"
            "Trabalhadores: " + to_string(trab) + "\n";

    return texto;
}

/********************** Funções para debug **********************/
void Ilha::debcash(float cash){ dinheiroDisponivel=dinheiroDisponivel+cash; }

void Ilha::debed(string tipo, int lin, int col){ arrayZonas[lin-1][col-1]->constroiEdificioGratis(tipo); }

void Ilha::debkill(string id){
    for (auto i = trabalhadores.begin(); i != trabalhadores.end(); ++i)
        if ((*i)->getID() == id) {
            trabalhadores.erase(i);
            i--;
        }
}

/********************** Suplementares **********************/
string Ilha::getAbrZona(int lin, int col){ return arrayZonas[lin][col]->getAbreviaturas(); }

string Ilha::getEdificioZona(int lin, int col) { return arrayZonas[lin][col]->getNomeEdificio(); }

vector<string> Ilha::dividePalavras(string frase){
    vector<string> words;
    istringstream iss(frase);
    copy(std::istream_iterator<string>(iss), std::istream_iterator<string>(), std::back_inserter(words));

    return words;
}

vector<string> Ilha::getZonasAdj(int i, int j){
    vector<string> zonaAdj;
    if(i==0 && j==0){
        zonaAdj.push_back(arrayZonas[i][j+1]->getNome() + " " + to_string(i) + " " + to_string(j+1));
        zonaAdj.push_back(arrayZonas[i+1][j]->getNome() + " " + to_string(i+1) + " " + to_string(j));
    } else if(i==0 && j==(coluna-1)){
        zonaAdj.push_back(arrayZonas[i+1][j]->getNome() + " " + to_string(i+1) + " " + to_string(j));
        zonaAdj.push_back(arrayZonas[i][j-1]->getNome() + " " + to_string(i) + " " + to_string(j-1));
    } else if(i==(linha-1) && j==(coluna-1)){
        zonaAdj.push_back(arrayZonas[i-1][j]->getNome() + " " + to_string(i-1) + " " + to_string(j));
        zonaAdj.push_back(arrayZonas[i][j-1]->getNome() + " " + to_string(i) + " " + to_string(j-1));
    } else if(i==(linha-1) && j==0){
        zonaAdj.push_back(arrayZonas[i-1][j]->getNome() + " " + to_string(i-1) + " " + to_string(j));
        zonaAdj.push_back(arrayZonas[i][j+1]->getNome() + " " + to_string(i) + " " + to_string(j+1));
    } else if(i==0){
        zonaAdj.push_back(arrayZonas[i][j-1]->getNome() + " " + to_string(i) + " " + to_string(j-1));
        zonaAdj.push_back(arrayZonas[i][j+1]->getNome() + " " + to_string(i) + " " + to_string(j+1));
        zonaAdj.push_back(arrayZonas[i+1][j]->getNome() + " " + to_string(i+1) + " " + to_string(j));
    } else if(i==linha-1){
        zonaAdj.push_back(arrayZonas[i][j-1]->getNome() + " " + to_string(i) + " " + to_string(j-1));
        zonaAdj.push_back(arrayZonas[i][j+1]->getNome() + " " + to_string(i) + " " + to_string(j+1));
        zonaAdj.push_back(arrayZonas[i-1][j]->getNome() + " " + to_string(i-1) + " " + to_string(j));
    } else if(j==0){
        zonaAdj.push_back(arrayZonas[i][j+1]->getNome() + " " + to_string(i) + " " + to_string(j+1));
        zonaAdj.push_back(arrayZonas[i-1][j]->getNome() + " " + to_string(i-1) + " " + to_string(j));
        zonaAdj.push_back(arrayZonas[i+1][j]->getNome() + " " + to_string(i+1) + " " + to_string(j));
    } else if(i==coluna-1){
        zonaAdj.push_back(arrayZonas[i][j-1]->getNome() + " " + to_string(i) + " " + to_string(j-1));
        zonaAdj.push_back(arrayZonas[i-1][j]->getNome() + " " + to_string(i-1) + " " + to_string(j));
        zonaAdj.push_back(arrayZonas[i+1][j]->getNome() + " " + to_string(i+1) + " " + to_string(j));
    } else{
        zonaAdj.push_back(arrayZonas[i][j-1]->getNome() + " " + to_string(i) + " " + to_string(j-1));
        zonaAdj.push_back(arrayZonas[i][j+1]->getNome() + " " + to_string(i) + " " + to_string(j+1));
        zonaAdj.push_back(arrayZonas[i-1][j]->getNome() + " " + to_string(i-1) + " " + to_string(j));
        zonaAdj.push_back(arrayZonas[i+1][j]->getNome() + " " + to_string(i+1) + " " + to_string(j));
    }
    return zonaAdj;
}

vector<string> Ilha::getEdificioAdj(int i, int j){
    vector<string> edificioAdj;
    if(i==0 && j==0){
        edificioAdj.push_back(arrayZonas[i][j+1]->getNomeEdificio() + " " + to_string(i) + " " + to_string(j+1));
        edificioAdj.push_back(arrayZonas[i+1][j]->getNomeEdificio() + " " + to_string(i+1) + " " + to_string(j));
    } else if(i==0 && j==(coluna-1)){
        edificioAdj.push_back(arrayZonas[i+1][j]->getNomeEdificio() + " " + to_string(i+1) + " " + to_string(j));
        edificioAdj.push_back(arrayZonas[i][j-1]->getNomeEdificio() + " " + to_string(i) + " " + to_string(j-1));
    } else if(i==(linha-1) && j==(coluna-1)){
        edificioAdj.push_back(arrayZonas[i-1][j]->getNomeEdificio() + " " + to_string(i-1) + " " + to_string(j));
        edificioAdj.push_back(arrayZonas[i][j-1]->getNomeEdificio() + " " + to_string(i) + " " + to_string(j-1));
    } else if(i==(linha-1) && j==0){
        edificioAdj.push_back(arrayZonas[i-1][j]->getNomeEdificio() + " " + to_string(i-1) + " " + to_string(j));
        edificioAdj.push_back(arrayZonas[i][j+1]->getNomeEdificio() + " " + to_string(i) + " " + to_string(j+1));
    } else if(i==0){
        edificioAdj.push_back(arrayZonas[i][j-1]->getNomeEdificio() + " " + to_string(i) + " " + to_string(j-1));
        edificioAdj.push_back(arrayZonas[i][j+1]->getNomeEdificio() + " " + to_string(i) + " " + to_string(j+1));
        edificioAdj.push_back(arrayZonas[i+1][j]->getNomeEdificio() + " " + to_string(i+1) + " " + to_string(j));
    } else if(i==linha-1){
        edificioAdj.push_back(arrayZonas[i][j-1]->getNomeEdificio() + " " + to_string(i) + " " + to_string(j-1));
        edificioAdj.push_back(arrayZonas[i][j+1]->getNomeEdificio() + " " + to_string(i) + " " + to_string(j+1));
        edificioAdj.push_back(arrayZonas[i-1][j]->getNomeEdificio() + " " + to_string(i-1) + " " + to_string(j));
    } else if(j==0){
        edificioAdj.push_back(arrayZonas[i][j+1]->getNomeEdificio() + " " + to_string(i) + " " + to_string(j+1));
        edificioAdj.push_back(arrayZonas[i-1][j]->getNomeEdificio() + " " + to_string(i-1) + " " + to_string(j));
        edificioAdj.push_back(arrayZonas[i+1][j]->getNomeEdificio() + " " + to_string(i+1) + " " + to_string(j));
    } else if(i==coluna-1){
        edificioAdj.push_back(arrayZonas[i][j-1]->getNomeEdificio() + " " + to_string(i) + " " + to_string(j-1));
        edificioAdj.push_back(arrayZonas[i-1][j]->getNomeEdificio() + " " + to_string(i-1) + " " + to_string(j));
        edificioAdj.push_back(arrayZonas[i+1][j]->getNomeEdificio() + " " + to_string(i+1) + " " + to_string(j));
    } else{
        edificioAdj.push_back(arrayZonas[i][j-1]->getNomeEdificio() + " " + to_string(i) + " " + to_string(j-1));
        edificioAdj.push_back(arrayZonas[i][j+1]->getNomeEdificio() + " " + to_string(i) + " " + to_string(j+1));
        edificioAdj.push_back(arrayZonas[i-1][j]->getNomeEdificio() + " " + to_string(i-1) + " " + to_string(j));
        edificioAdj.push_back(arrayZonas[i+1][j]->getNomeEdificio() + " " + to_string(i+1) + " " + to_string(j));
    }
    return edificioAdj;
}
