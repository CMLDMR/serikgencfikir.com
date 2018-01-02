#include "intropage.h"

Intro::introPage::introPage()
    :WContainerWidget()
{

    this->addStyleClass("bodyClass");

    this->doJavaScript("resizeintroPage();");

    auto layout = this->setLayout(cpp14::make_unique<WVBoxLayout>());

    layout->addStretch(1);

    auto img = layout->addWidget(cpp14::make_unique<WImage>(WLink("img/intrologo.png")),0,AlignmentFlag::Center|AlignmentFlag::Middle);

    img->decorationStyle().setCursor(Cursor::PointingHand);


    img->clicked().connect([=](){

        Click.emit(NoClass());

    });


    layout->addStretch(1);

}
