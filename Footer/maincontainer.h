#ifndef MAINCONTAINER_H
#define MAINCONTAINER_H

#include <QtCore/qglobal.h>

#include "bootstrap.h"
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WToolBar.h>
#include <Wt/WPushButton.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WGridLayout.h>
#include <Wt/WSignal.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WAnchor.h>




using namespace Wt;



namespace Footer {


    class MainContainer : public WContainerWidget
    {
    public:
        MainContainer();

        WToolBar* mToolBar;

        Signal<NoClass> AnaSayfa;
        Signal<NoClass> serikGencFikir;
        Signal<NoClass> Oduller;
        Signal<NoClass> YarismaKosullari;
        Signal<NoClass> OrnekTaslak;
        Signal<NoClass> Basvuru;
    };


}




#endif // MAINCONTAINER_H
