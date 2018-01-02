#include "maincontainer.h"


Footer::MainContainer::MainContainer()
    :WContainerWidget()
{

    setId("headerid");
    setContentAlignment(AlignmentFlag::Center|AlignmentFlag::Middle);
    addStyleClass(Bootstrap::Grid::container_fluid+"footerWidget");

    auto container = addWidget(cpp14::make_unique<WContainerWidget>());

    container->addStyleClass(Bootstrap::Grid::row+"foorterContainer");
    container->setContentAlignment(AlignmentFlag::Center|AlignmentFlag::Middle );




    {
        auto layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());
        layout->setSpacing(0);


        auto sContainer = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);
        auto sLayout = sContainer->setLayout(cpp14::make_unique<WHBoxLayout>());

        {
            auto img = sLayout->addWidget(cpp14::make_unique<WImage>(WLink("img/logo.png")));
            img->addStyleClass(Bootstrap::Grid::Large::col_lg_1+"logo");
            img->decorationStyle().setCursor(Cursor::PointingHand);
            img->clicked().connect([=](){
                AnaSayfa.emit(NoClass());
            });
        }
        mToolBar = sLayout->addWidget(cpp14::make_unique<WToolBar>(),0,AlignmentFlag::Middle);
        mToolBar->addStyleClass(Bootstrap::Grid::Large::col_lg_8+"mToolbarMenu");


        {
            auto btn = cpp14::make_unique<WPushButton>("Serik Genç Fikir");
            btn->addStyleClass("footerBtn");
            btn->clicked().connect([=]{
                serikGencFikir.emit(NoClass());
            });

            mToolBar->addButton(std::move(btn));

        }
        {
            auto btn = cpp14::make_unique<WPushButton>("Ödüller");
            btn->addStyleClass("footerBtn");
            btn->clicked().connect([=]{
                Oduller.emit(NoClass());
            });
            mToolBar->addButton(std::move(btn));
        }
        {
            auto btn = cpp14::make_unique<WPushButton>("Yarışma Şartnamesi");
            btn->addStyleClass("footerBtn");
            btn->clicked().connect([=]{
                YarismaKosullari.emit(NoClass());
            });
            mToolBar->addButton(std::move(btn));
        }
        {
            auto btn = cpp14::make_unique<WPushButton>("Örnek Proje Formatı");
            btn->addStyleClass("footerBtn");
            btn->clicked().connect([=]{
                OrnekTaslak.emit(NoClass());
            });
            mToolBar->addButton(std::move(btn));
        }
        mToolBar->addSeparator();
        {
            auto btn = cpp14::make_unique<WPushButton>("Başvuru");
            btn->addStyleClass("footerBtn");
            btn->clicked().connect([=]{
                Basvuru.emit(NoClass());
            });
            mToolBar->addButton(std::move(btn));
        }


        {
            Wt::WLink link = Wt::WLink("https://www.facebook.com/serikgen%C3%A7fikir-1538376216269716/");
            link.setTarget(Wt::LinkTarget::NewWindow);

            auto anchor = sLayout->addWidget(Wt::cpp14::make_unique<Wt::WAnchor>(link),0,AlignmentFlag::Middle);
            anchor->addWidget(Wt::cpp14::make_unique<Wt::WImage>(Wt::WLink("img/facebook.png")));
        }


        {
            Wt::WLink link = Wt::WLink("https://twitter.com/serikgencfikir");
            link.setTarget(Wt::LinkTarget::NewWindow);

            auto anchor = sLayout->addWidget(Wt::cpp14::make_unique<Wt::WAnchor>(link),0,AlignmentFlag::Middle);
            anchor->addWidget(Wt::cpp14::make_unique<Wt::WImage>(Wt::WLink("img/tweeter.png")));
//            anchor->setMaximumSize(50,50);
        }

        {
            Wt::WLink link = Wt::WLink("https://www.instagram.com/serikgencfikir/");
            link.setTarget(Wt::LinkTarget::NewWindow);

            auto anchor = sLayout->addWidget(Wt::cpp14::make_unique<Wt::WAnchor>(link),0,AlignmentFlag::Middle);
            anchor->addWidget(Wt::cpp14::make_unique<Wt::WImage>(Wt::WLink("img/ins.png")));
        }


    }









}
