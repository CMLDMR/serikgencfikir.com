#include "mainapplication.h"

MainApplication::MainApplication(const Wt::WEnvironment &env)
    :WApplication(env)
{

    p_wtTheme = std::make_shared<Wt::WBootstrapTheme>();
    p_wtTheme->setVersion(Wt::WBootstrapTheme::Version::v3);
    p_wtTheme.get()->setResponsive(true);
    Wt::WApplication::instance()->setTheme(p_wtTheme);
    Wt::WApplication::instance()->setTitle("Serik Genç Fikir");

    Wt::WApplication::instance()->useStyleSheet("css/maincss.css");

    Wt::WApplication::instance()->useStyleSheet("resources/themes/bootstrap/3/bootstrap-theme.min.css");

    WApplication::instance()->addMetaHeader("viewport","width=device.width, initial-scale=1.0");

    WApplication::instance()->require("script/script.js");

    root()->setContentAlignment(AlignmentFlag::Center);

    root()->addStyleClass(Bootstrap::Grid::container_fluid);

    this->initPage();
}

void MainApplication::startupPage()
{

    mIntroPage = root()->addWidget(cpp14::make_unique<Intro::introPage>());
    mIntroPage->Click.connect(this,&MainApplication::initPage);
}

void MainApplication::initPage()
{

    root()->clear();
    root()->addWidget(cpp14::make_unique<Footer::MainContainer>());
    root()->addWidget(cpp14::make_unique<Body::BodyPage>());


}
