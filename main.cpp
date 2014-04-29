#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include "FenPrincipale.h"

int main(int argc, char*argv[])
{
    QApplication app(argc, argv);

    FenPrincipale fenetre;

    fenetre.show();

    return app.exec();
}
