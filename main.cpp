
#include <time.h>
#include "Interface/mainwindow.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[]){
    srand(time(NULL));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}