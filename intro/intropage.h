#ifndef INTROPAGE_H
#define INTROPAGE_H

#include <QtCore/qglobal.h>

#include <Wt/WContainerWidget.h>
#include <Wt/WImage.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WSignal.h>
#include <Wt/WCssDecorationStyle.h>


using namespace Wt;



namespace Intro {

    class introPage : public WContainerWidget
    {
    public:
        introPage();

        Signal<NoClass> Click;
    };

}





#endif // INTROPAGE_H
