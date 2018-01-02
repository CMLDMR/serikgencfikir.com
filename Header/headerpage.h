#ifndef HEADERPAGE_H
#define HEADERPAGE_H

#include <QtCore/qglobal.h>



#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WCssDecorationStyle.h>


#include "bootstrap.h"

using namespace Wt;



namespace Header {

    class HeaderPage : public WContainerWidget
    {
    public:
        HeaderPage();
    };

}



#endif // HEADERPAGE_H
