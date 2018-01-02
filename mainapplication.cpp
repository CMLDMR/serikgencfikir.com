#include "mainapplication.h"

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/types/value.hpp>
#include <bsoncxx/types.hpp>
#include <bsoncxx/exception/exception.hpp>

#include <mongocxx/collection.hpp>
#include <mongocxx/result/insert_one.hpp>

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

    try {
        mClient = new mongocxx::client(mongocxx::uri(administratorObj));
        db = mClient->database(ProjeKeys::DB);
    } catch (mongocxx::exception &e) {
        std::cout << e.what() << std::endl;
        return;
    }
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

    auto footer = root()->addWidget(cpp14::make_unique<Footer::MainContainer>());

    auto body = root()->addWidget(cpp14::make_unique<Body::BodyPage>(&db));

    footer->AnaSayfa.connect(this,&MainApplication::initPage);

    footer->serikGencFikir.connect(body,&Body::BodyPage::ClickGencFikir);

    footer->YarismaKosullari.connect(body,&Body::BodyPage::ClickYarismaKosullari);

    footer->OrnekTaslak.connect(body,&Body::BodyPage::OrnekTaslak);

    footer->Basvuru.connect(body,&Body::BodyPage::Basvuru);

    footer->Oduller.connect(body,&Body::BodyPage::ClickOduller);


}
