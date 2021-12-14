#include "mundo.h"

using namespace std;

int &Mundo::getLinha(){ return linha; }

int &Mundo::getColuna(){ return coluna; }

void Mundo::criaTabela(){
    arrayZonas = new Zona*[linha];

    for (int i = 0; i < linha; i++) {
        arrayZonas[i] = new Zona[coluna];
    }

    prencheTabela();
}

void Mundo::prencheTabela(){
    int pos, cont_zonas[6]={0,0,0,0,0,0};;
    const char *nomeZonas[6] = { "Deserto", "Pastagem","Floresta", "Montanha", "Pantano", "Zona-X" },
                *abrZonas[6] = { "dsr", "pas","flr", "mnt", "pnt", "znZ" };

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            do{ //Este ciclo garante que existe pelo menos uma zona de cada
                //Enquanto o número gerado aleatoriamente corresponder a uma zona já inicializada e existirem zonas por inicializar
                //Vão sendo gerados novos números aleatórios
                pos = rand() % 6;
            } while (cont_zonas[pos]==1 && (cont_zonas[0]==0 || cont_zonas[1]==0 || cont_zonas[3]==0 || cont_zonas[4]==0 || cont_zonas[5]==0));

            cont_zonas[pos]=1;
            arrayZonas[i][j].setNome(nomeZonas[pos]);
            arrayZonas[i][j].setAbreviaturas(abrZonas[pos]);
        }
    }
}

void Mundo::mostraTabela(){
    char myStr[]="    ";
    cout << "\n\n\n" << endl;

    for(int x=0;x<((coluna*5)+1);x++)
        cout << "*";

    for (int i = 0; i < linha; i++) {
        cout <<  "\n*";

        //Nome da Zona
        for (int j = 0; j < coluna; j++)
            cout << arrayZonas[i][j].getAbreviaturas() << " *";

        //Edificios
        cout <<  "\n*";
        for (int j = 0; j < coluna; j++)
            cout << arrayZonas[i][j].getEdificio() << " " << "*";

        //Trabalhadores
        cout <<  "\n*";
        for (int j = 0; j < coluna; j++) {
            arrayZonas[i][j].concatTrabalhadores(myStr,i,j);
            cout << myStr << "*";
        }

        //Conta Trabalhadores
        cout <<  "\n*";
        for (int j = 0; j < coluna; j++)
            cout << arrayZonas[i][j].contaTrabalhadores(i,j) << "   " << "*";

        cout << endl;
        for(int x=0;x<((coluna*5)+1);x++)
            cout << "*";
    }
    cout << "\n\n\n" << endl;
}

int Mundo::prencheZonaTrabalhador(string nome){
    Trabalhador x;
    x.setnome(nome);

    for (int i = 0; i < linha; i++)
        for (int j = 0; j < coluna; j++)
            if(arrayZonas[i][j].setTrabalhador(x,i,j))
                return 1;

    return 0;
}

int Mundo::prencheZonaEdificio(string nome, string abr, int linha, int coluna){
    if(arrayZonas[linha][coluna].getEdificio() != "   ") {
        cout << "\tNesta zona ja tem o edificio " << arrayZonas[linha][coluna].getEdificio() << endl;
        return 0;
    }
    else{
        arrayZonas[linha][coluna].setEdificio(nome,abr,linha,coluna);
        return 1;
    }
}

void Mundo::descTabela(int i, int j){
    cout << "\tEsta zona e de " << arrayZonas[i][j].getNome() << " (" << arrayZonas[i][j].getAbreviaturas() << ") " << endl;
    if(arrayZonas[i][j].getEdificio() != "")
        cout << "\tTem o edificio " << arrayZonas[i][j].getEdificio() << endl;
    else
        cout << "\tNao tem edificio; " << arrayZonas[i][j].getEdificio() << endl;
    cout << "\tTem " << arrayZonas[i][j].contaTrabalhadores(i,j) << " trabalhadores" << endl;
}

void Mundo::descTabelaCompleta(){
    cout << "\tEsta e uma ilha " << getLinha() << " por " << getColuna() << endl;
}