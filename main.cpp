#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>

#include "mainapplication.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    mongocxx::instance inst{};


    return Wt::WRun(argc,argv,[](const Wt::WEnvironment &env){
        return Wt::cpp14::make_unique<MainApplication>(env);
    });


}
