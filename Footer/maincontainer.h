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




using namespace Wt;



namespace Footer {


    class MainContainer : public WContainerWidget
    {
    public:
        MainContainer();

        WToolBar* mToolBar;
    };


}




#endif // MAINCONTAINER_H
