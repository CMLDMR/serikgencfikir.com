#include "maincontainer.h"


Footer::MainContainer::MainContainer()
    :WContainerWidget()
{

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
        }
        mToolBar = sLayout->addWidget(cpp14::make_unique<WToolBar>(),0,AlignmentFlag::Middle);
        mToolBar->addStyleClass(Bootstrap::Grid::Large::col_lg_8+"mToolbarMenu");


        {
            auto btn = cpp14::make_unique<WPushButton>("Serik Genç Fikir");
            btn->addStyleClass("footerBtn");
            mToolBar->addButton(std::move(btn));
        }
        {
            auto btn = cpp14::make_unique<WPushButton>("Ödüller");
            btn->addStyleClass("footerBtn");
            mToolBar->addButton(std::move(btn));
        }
        {
            auto btn = cpp14::make_unique<WPushButton>("Yarışma Şartnamesi");
            btn->addStyleClass("footerBtn");
            mToolBar->addButton(std::move(btn));
        }
        {
            auto btn = cpp14::make_unique<WPushButton>("Örnek Taslak");
            btn->addStyleClass("footerBtn");
            mToolBar->addButton(std::move(btn));
        }
        mToolBar->addSeparator();
        {
            auto btn = cpp14::make_unique<WPushButton>("Başvuru");
            btn->addStyleClass("footerBtn");
            mToolBar->addButton(std::move(btn));
        }


        {
            auto img = sLayout->addWidget(cpp14::make_unique<WImage>(WLink("img/facebook.png")),0,AlignmentFlag::Middle);
            img->addStyleClass(Bootstrap::Grid::Large::col_lg_1+"socialFooterbtn");
        }

        {
            auto img = sLayout->addWidget(cpp14::make_unique<WImage>(WLink("img/tweeter.png")),0,AlignmentFlag::Middle);
            img->addStyleClass(Bootstrap::Grid::Large::col_lg_1+"socialFooterbtn");
        }

        {
            auto img = sLayout->addWidget(cpp14::make_unique<WImage>(WLink("img/ins.png")),0,AlignmentFlag::Middle);
            img->addStyleClass(Bootstrap::Grid::Large::col_lg_1+"socialFooterbtn");
        }
    }









}
