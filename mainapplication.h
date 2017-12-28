#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H



#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WEnvironment.h>
#include <Wt/WJavaScript.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>

#include <Wt/WBootstrapTheme>


#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>


#include "Footer/maincontainer.h"
#include "intro/intropage.h"
#include "Body/bodypage.h"



#include <iostream>
#include <memory>



using namespace Wt;

#include <QtCore/qglobal.h>

///
/// \brief The MainApplication class
/// This is Web Application Server. Contruct and Manage Page. Deliver the some neccessary variabla from platform or host
class MainApplication : public WApplication
{
public:
    MainApplication(const WEnvironment& env);



    void startupPage();



    void initPage();



private:


    ///
    /// \brief p_wtTheme
    /// Bootstrap Theme
    std::shared_ptr<Wt::WBootstrapTheme> p_wtTheme;



    Intro::introPage* mIntroPage;


};

#endif // MAINAPPLICATION_H
