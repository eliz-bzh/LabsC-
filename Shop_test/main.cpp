#include "genderwindow.h"
#include <QApplication>
#include "goodswindow.h"
#include "dresskindwindow.h"
#include "unitwindow.h"
#include "authorization.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataBase db;
    db.insertIntoTables();
    /*Genderwindow gw;
    gw.show();
    CategoryWindow cw;
    cw.show();
    DressKindWindow dkw;
    dkw.show();
    GoodsWindow gow;
    gow.show();
    Unitwindow uw;
    uw.show();*/
    Authorization auw;
    auw.show();

    return a.exec();
}
