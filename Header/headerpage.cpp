#include "headerpage.h"



Header::HeaderPage::HeaderPage()
    :WContainerWidget()
{
    addStyleClass(Bootstrap::Grid::container_fluid);
    setMinimumSize(WLength::Auto,500);

    addStyleClass("headerid");

    addWidget(cpp14::make_unique<WText>("sdf asdf asdf asd fasd f"));
}
