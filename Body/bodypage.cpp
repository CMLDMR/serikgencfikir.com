#include "bodypage.h"



Body::BodyPage::BodyPage(mongocxx::database *_db)
    :WContainerWidget(),
      db(_db)
{

    setContentAlignment(AlignmentFlag::Center);

    {
        auto backContainer = addWidget(cpp14::make_unique<WContainerWidget>());

        backContainer->addStyleClass("bodyClass");

        backContainer->doJavaScript("resizeintroPage();");
    }

    mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mMainContainer->setContentAlignment(AlignmentFlag::Center);

    this->initStart();

}

void Body::BodyPage::initStart()
{
    {
        auto container = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setId("Bodyid");
        container->addStyleClass("interfaceimg");
        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
        layout->addStretch(1);
        layout->addWidget(cpp14::make_unique<WImage>(WLink("img/intrologo.png")),0,AlignmentFlag::Center);
        layout->addStretch(1);
    }

    {
        auto container = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setContentAlignment(AlignmentFlag::Center);
        container->addStyleClass("bodycontent");
        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());

        layout->addWidget(cpp14::make_unique<WImage>(WLink("img/project.png")),0,AlignmentFlag::Center);
        layout->addWidget(cpp14::make_unique<WText>("Son Başvuru Tarihi: 23 Şubat 2018"),0,AlignmentFlag::Center)->addStyleClass("SonBasvuru");


        {
            auto labContainer = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);
            auto logoLayout = labContainer->setLayout(cpp14::make_unique<WHBoxLayout>());
            logoLayout->addWidget(cpp14::make_unique<WImage>(WLink("img/logo.png")),0,AlignmentFlag::Left)->setMaximumSize(50,50);
            logoLayout->addWidget(cpp14::make_unique<WImage>(WLink("img/logomilli.png")),0,AlignmentFlag::Center)->setMaximumSize(50,50);
            logoLayout->addWidget(cpp14::make_unique<WImage>(WLink("img/logoserik.png")),0,AlignmentFlag::Right)->setMaximumSize(50,50);
        }


        layout->addWidget(cpp14::make_unique<WText>("Bu Proje Yarışması Serik Belediyesi ve Serik İlçe Milli Eğitim Müdürlüğü"
                                                    " Tarafından Ortaklaşa Yürütülmektedir."))->addStyleClass("SubText");

        layout->addSpacing(50);

        layout->addWidget(cpp14::make_unique<WText>("Bu Web Sayfa Serik Belediyesi Bilgi İşlem Müdürlüğü Tarafından Açık Kaynak Kodlu"
                                                    " Olarak Geliştirilmektedir."))->addStyleClass("SubText1");

        layout->addWidget(cpp14::make_unique<WText>("Copyright © 2017"))->addStyleClass("SubText1");


        {
            auto container = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);
            auto _layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());

            _layout->addWidget(cpp14::make_unique<WText>(" Powered By : "));
            {
                Wt::WLink link = Wt::WLink("http://www.webtoolkit.eu/");
                link.setTarget(Wt::LinkTarget::NewWindow);

                std::unique_ptr<Wt::WAnchor> anchor =
                        Wt::cpp14::make_unique<Wt::WAnchor>(link,
                                        "Wt");
                _layout->addWidget(std::move(anchor));
            }

            {
                Wt::WLink link = Wt::WLink("https://www.qt.io/");
                link.setTarget(Wt::LinkTarget::NewWindow);

                std::unique_ptr<Wt::WAnchor> anchor =
                        Wt::cpp14::make_unique<Wt::WAnchor>(link,
                                        "Qt");
                _layout->addWidget(std::move(anchor));
            }

            _layout->addWidget(cpp14::make_unique<WText>(" & "));

            {
                Wt::WLink link = Wt::WLink("https://github.com/CMLDMR/serikgencfikir.com");
                link.setTarget(Wt::LinkTarget::NewWindow);

                std::unique_ptr<Wt::WAnchor> anchor =
                        Wt::cpp14::make_unique<Wt::WAnchor>(link,
                                        "gitHub");
                _layout->addWidget(std::move(anchor));
            }
        }


    }
}


void Body::BodyPage::ClickGencFikir()
{
    mMainContainer->clear();

    mMainContainer->addWidget(cpp14::make_unique<GencFikir>());




}

void Body::BodyPage::ClickOduller()
{
    mMainContainer->clear();

    mMainContainer->addWidget(cpp14::make_unique<Oduller>());


}

void Body::BodyPage::ClickYarismaKosullari()
{
    mMainContainer->clear();

    mMainContainer->addWidget(cpp14::make_unique<YarisKosullari>());
}

void Body::BodyPage::OrnekTaslak()
{
    mMainContainer->clear();

    mMainContainer->addWidget(cpp14::make_unique<Body::OrnekTaslak>());
}

void Body::BodyPage::Basvuru()
{
    mMainContainer->clear();

    mMainContainer->addWidget(cpp14::make_unique<Body::Basvuru::Basvuru>(db));
}

Body::GencFikir::GencFikir()
    :WContainerWidget()
{
    addStyleClass("gencFikirStyle");
    setId("gencFikir");
    setContentAlignment(AlignmentFlag::Center);

    doJavaScript("resizegencFikirPage();");
    auto layout = setLayout(cpp14::make_unique<WVBoxLayout>());


    {
        auto text = layout->addWidget(cpp14::make_unique<WText>("<h2>“SERİK GENÇ FİKİR 2018” Yarışması Nedir?</h2>"));
        auto text2 = layout->addWidget(cpp14::make_unique<WText>("<span>Lise öğrenimi gören, 10. ve 11. sınıf öğrencilerinin katılabileceği <b>sosyal sorumluluk proje fikirleri</b> yarışmasıdır</span>"));
    }


    // Projenin Kategorisi
    {
        auto text = layout->addWidget(cpp14::make_unique<WText>("<h2>Amaç</h2>"
                                                                "<span>Yarışmanın amacı; lise öğrencilerinin sosyal sorumluluk konusunda bilinçlenmelerini, düşünmelerini ve harekete geçmelerini sağlamak, sosyal sorumluluk konusundaki vizyonlarını genişletip öğrencileri motive ederek başarıyı ödüllendirmektir</span>"));
    }


    {
        auto container = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);


        auto _layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());

        _layout->addWidget(cpp14::make_unique<WImage>(WLink("img/icons/1 (1).jpeg")))->setMaximumSize(100,100);
        _layout->addWidget(cpp14::make_unique<WImage>(WLink("img/icons/1 (2).jpeg")))->setMaximumSize(100,100);
        _layout->addWidget(cpp14::make_unique<WImage>(WLink("img/icons/1 (3).jpeg")))->setMaximumSize(100,100);
        _layout->addWidget(cpp14::make_unique<WImage>(WLink("img/icons/1 (4).jpeg")))->setMaximumSize(100,100);
        _layout->addWidget(cpp14::make_unique<WImage>(WLink("img/icons/1 (5).jpeg")))->setMaximumSize(100,100);
    }

    layout->addStretch(1);

}

Body::YarisKosullari::YarisKosullari()
{
    addStyleClass("gencFikirStyle");
    setId("gencFikir");
    setContentAlignment(AlignmentFlag::Center);

    doJavaScript("resizegencFikirPage();");

    auto layout = setLayout(cpp14::make_unique<WVBoxLayout>());

    {
        QFile file("docroot/document/doc.html");
        if( file.open(QIODevice::ReadOnly) )
        {
            QByteArray ar = file.readAll();
            file.close();
            auto text = layout->addWidget(cpp14::make_unique<WText>(ar.toStdString().c_str()));
            text->setTextFormat(TextFormat::UnsafeXHTML);
        }
    }
}

Body::OrnekTaslak::OrnekTaslak()
{

    addStyleClass("gencFikirStyle");
    setId("gencFikir");
    setContentAlignment(AlignmentFlag::Center);

    doJavaScript("resizegencFikirPage();");
    auto layout = setLayout(cpp14::make_unique<WVBoxLayout>());


    {
        auto text = layout->addWidget(cpp14::make_unique<WText>("<h2>Serik Genç Fikir 2018</h2>"));
        auto text2 = layout->addWidget(cpp14::make_unique<WText>("<h3>Proje Formatı*</h3>"));
    }


    // Projenin Kategorisi
    {
        auto text = layout->addWidget(cpp14::make_unique<WText>("<b>Proje Kategorisi</b>"
                                                                "<span>Çevre / Eğitim / Kültür – Sanat / Sağlık ve Spor / Toplumsal</span>"));
    }



    // Proje Adı
    {
        auto text = layout->addWidget(cpp14::make_unique<WText>("<b>Proje Adı</b>"
                                                                "<span>(Projenin bundan sonra anılacağı isim/başlık / Maksimum 5 kelimeden oluşmalıdır.)</span>"));
    }

    // Projenin Amacı
    {
        auto text = layout->addWidget(cpp14::make_unique<WText>("<b>Proje Kategorisi</b>"
                                                                "<span>(Proje hangi konuda, hangi alanda ve hangi amaca hizmet ediyor?)</span>"));
    }

    // Projenin Hedef Kitlesi
    {
        auto text = layout->addWidget(cpp14::make_unique<WText>("<b>Projenin Hedef Kitlesi</b>"
                                                                "<span>(Projenin hayata geçirilmesi durumunda fayda sağlaması düşünülen kişi veya topluluk belirtilmelidir.)</span>"));
    }

    // Proje Süresi
    {
        auto text = layout->addWidget(cpp14::make_unique<WText>("<b>Proje Süresi</b>"
                                                                "<span>( Projenin hayata geçirilmesi durumunda ne kadarlık bir zamanda tamamlanacağını belirtir. Gün / hafta / ay veya yıl bazında belirtilmelidir.)</span>"));
    }
    // Projenin Yaratacağı Fayda
    {
        auto text = layout->addWidget(cpp14::make_unique<WText>("<b>Projenin Yaratacağı Fayda</b>"
                                                                "<span>( Projenin gerçekleştirilmesi durumunda ilgili tanımlanmış olan hedef kitleye veya topluma yaratması planlanan etki / katkı belirtilmelidir.)</span>"));
    }

    // Varsa İşbirliği Yapılacak Kurumlar, STK’lar
    {
        auto text = layout->addWidget(cpp14::make_unique<WText>("<b>Varsa İşbirliği Yapılacak Kurumlar, STK’lar</b>"
                                                                "<span>( Projenin gerçekleştirilebilmesi aşamasında destek alınması gereken kurum ya da sivil toplum kuruluşu var ise isimleri belirtilmelidir.) </span>"));
    }

    // Uygulama Adımları
    {
        auto text = layout->addWidget(cpp14::make_unique<WText>("<b>Uygulama Adımları</b>"
                                                                "<span>( Projenin hayata geçirilebilmesi için gerekli iş akışı anlatılmalıdır. Aşamalı olarak projenin hayata geçirilişi aktarılmalıdır.)</span>"));
    }

    // Proje Bütçesi
    {
        auto text = layout->addWidget(cpp14::make_unique<WText>("<b>Proje Bütçesi</b>"
                                                                "<span>( Projenin hayata geçirilebilmesi için gerekli iş akışı anlatılmalıdır. Aşamalı olarak projenin hayata geçirilişi aktarılmalıdır.)</span>"));
    }

    // Proje Özeti
    {
        auto text = layout->addWidget(cpp14::make_unique<WText>("<b>Proje Özeti</b>"
                                                                "<span>(max 250 kelime ile projenin amacı ve nasıl hayata geçirileceği aktarılmalıdır.)</span>"));
    }




    layout->addStretch(1);
    {
        auto container = layout->addWidget(cpp14::make_unique<WContainerWidget>());
        auto _layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());
        _layout->addStretch(1);
        auto button = _layout->addWidget(cpp14::make_unique<WPushButton>("Taslak indir"));
        _layout->addStretch(1);
        button->setLink(WLink("document/2018-proje-formati.doc"));
    }

    layout->addStretch(1);

    {
        auto text = layout->addWidget(cpp14::make_unique<WText>("<b>*PROJE FORMATI</b>"
                                                                "<span> Yukarıdaki formata uygun hazırlanan projeler, yarışma şartnamesinde de belirtildiği üzere max. 2000 kelime olmalıdır.</span>"));
    }

    layout->addStretch(1);
}

Body::Basvuru::Basvuru::Basvuru(mongocxx::database *_db)
    :WContainerWidget(),
      db(_db)
{
    addStyleClass("gencFikirStyle");
    setId("gencFikir");
    setContentAlignment(AlignmentFlag::Center);

    doJavaScript("resizegencFikirPage();");




    this->LoadForm();

    this->addUploadPanel();

}

void Body::Basvuru::Basvuru::LoadForm()
{
    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());

        auto layout = container->setLayout(cpp14::make_unique<WGridLayout>());

        int row = 0;

        {
            layout->addWidget(cpp14::make_unique<WText>("<h3>Proje Başvuru Formu</h3>"),row++,0,0,2,AlignmentFlag::Center);
        }
        {
            layout->addWidget(cpp14::make_unique<WText>("Proje Adı"),row,0,AlignmentFlag::Left);
            mProjeAdi = layout->addWidget(cpp14::make_unique<WLineEdit>(),row++,1,AlignmentFlag::Left);
            mProjeAdi->setPlaceholderText("Proje Adı Giriniz");
        }

        {
            layout->addWidget(cpp14::make_unique<WText>("Proje Kategorisi"),row,0,AlignmentFlag::Left);
            mProjeCat = layout->addWidget(cpp14::make_unique<WComboBox>(),row++,1,AlignmentFlag::Left);
            mProjeCat->addItem(WString("Çevre"));
            mProjeCat->addItem(WString("Kültür/Sanat"));
            mProjeCat->addItem(WString("Sağlık/Spor"));
            mProjeCat->addItem(WString("Eğitim"));
            mProjeCat->addItem(WString("Toplumsal"));
        }

        {
            {
                auto container = layout->addWidget(cpp14::make_unique<WContainerWidget>(),row++,0,0,2,AlignmentFlag::Justify);
                auto _layaout = container->setLayout(cpp14::make_unique<WHBoxLayout>());
                _layaout->addWidget(cpp14::make_unique<WText>("Adınız"));
                mAd = _layaout->addWidget(cpp14::make_unique<WLineEdit>());
                mAd->setPlaceholderText("Lütfen Adınızı Giriniz");
                _layaout->addWidget(cpp14::make_unique<WText>("Soyadınız"));
                mSoyad = _layaout->addWidget(cpp14::make_unique<WLineEdit>());
                mSoyad->setPlaceholderText("Lütfen Soyadınızı Giriniz");

            }
        }

        {
            layout->addWidget(cpp14::make_unique<WText>("TCNO"),row,0,AlignmentFlag::Left);
            mTCNO = layout->addWidget(cpp14::make_unique<WLineEdit>(),row++,1,AlignmentFlag::Left);
            mTCNO->setPlaceholderText("TC Kimlik Numarasını Giriniz");
        }

        {
            layout->addWidget(cpp14::make_unique<WText>("Okul"),row,0,AlignmentFlag::Left);
            mOkul = layout->addWidget(cpp14::make_unique<WComboBox>(),row++,1,AlignmentFlag::Left);
            mOkul->addItem("Atatürk Anadolu Lisesi");
            mOkul->addItem("Çandır Çok Programlı Anadolu Lisesi");
            mOkul->addItem("Gebiz Şehit Andıllah Kara Anadolu Lisesi");
            mOkul->addItem("Mesleki Eğitim Merkezi");
            mOkul->addItem("Serik Anadolu İmam-Hatip Lisesi");
            mOkul->addItem("Serik Anadolu Lisesi");
            mOkul->addItem("Serik Hasan Güçlü Mesleki ve Teknik Anadolu Lisesi");
            mOkul->addItem("Serik İbn-i Sina Mesleki ve Teknik Anadolu Lisesi");
            mOkul->addItem("Serik IMKB Mesleki ve Teknik Anadolu Lisesi");
            mOkul->addItem("Serik Kız Anadolu İmam-Hatip Lisesi");
            mOkul->addItem("Serik Mesleki ve Teknik Anadolu Lisesi");
            mOkul->addItem("Serik Orhan Gazi Mesleki ve Teknik Anadolu Lisesi");
            mOkul->addItem("Yunus Emre Anadolu Lisesi");
            mOkul->addItem("Özel Akdeniz Yükseliş Anadolu Lisesi");
            mOkul->addItem("Özel Cenap Düzgün Başarı Temel Lisesi");
            mOkul->addItem("Özel Serik Akdeniz Temel Lisesi");
            mOkul->addItem("Özel Serik Çözüm Temel Lisesi");
        }

        {
            layout->addWidget(cpp14::make_unique<WText>("Sınıf"),row,0,AlignmentFlag::Left);
            mSinif = layout->addWidget(cpp14::make_unique<WLineEdit>(),row++,1,AlignmentFlag::Left);
            mSinif->setPlaceholderText("Sınıfınızı Giriniz");
        }

        {
            layout->addWidget(cpp14::make_unique<WText>("TEL"),row,0,AlignmentFlag::Left);
            mTel = layout->addWidget(cpp14::make_unique<WLineEdit>(),row++,1,AlignmentFlag::Left);
            mTel->setPlaceholderText("Cep Telefonu Numaranızı Giriniz");
            mTel->changed().connect([=](){
                this->telnoKontrol(mTel->text().toUTF8());
            });
        }

        {
            layout->addWidget(cpp14::make_unique<WText>("Mail"),row,0,AlignmentFlag::Left);
            mEposta = layout->addWidget(cpp14::make_unique<WLineEdit>(),row++,1,AlignmentFlag::Left);
            mEposta->setPlaceholderText("E-Posta Adresinizi Giriniz");
        }

        {
            layout->addWidget(cpp14::make_unique<WText>("Adresiniz"),row,0,AlignmentFlag::Left);
            mAdres = layout->addWidget(cpp14::make_unique<WTextArea>(),row++,1,AlignmentFlag::Left);

        }

        {
            layout->addWidget(cpp14::make_unique<WText>("Yarışmayı Nereden Duydunuz?"),row,0,AlignmentFlag::Left);
            mNeredenDuyma = layout->addWidget(cpp14::make_unique<WLineEdit>(),row++,1,AlignmentFlag::Left);
            mNeredenDuyma->setPlaceholderText("Yarışmayı İlk Nerede Duyduğunuzu/Öğrendiğinizi Yazınız");
        }
    }

    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());

        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());

        layout->addWidget(cpp14::make_unique<WText>("Üye Ekle (En Fazla 2 Üye Seçebilirsiniz!)"),0,AlignmentFlag::Center);

        mTable = layout->addWidget(cpp14::make_unique<WTableView>());
        mTable->addStyleClass("tableText");
        mTableModel = std::make_shared<WStandardItemModel>( 0 , 7 );

        mTable->setModel((mTableModel));


        mTable->setAlternatingRowColors(true);
        mTable->setRowHeight(28);
        mTable->setHeaderHeight(28);
        mTable->setSelectionMode(SelectionMode::Single);
        mTable->setEditTriggers(EditTrigger::None);
        int _row = 0;
        mTableModel->setHeaderData(_row++,"#TCKN");
        mTableModel->setHeaderData(_row++,"AdSoyad");
        mTableModel->setHeaderData(_row++,"Okul");
        mTableModel->setHeaderData(_row++,"Sınıf");
        mTableModel->setHeaderData(_row++,"Tel");
        mTableModel->setHeaderData(_row++,"eposta");
        mTableModel->setHeaderData(_row++,"Adres");


        mTable->doubleClicked().connect([&](WModelIndex index,WMouseEvent e){
            if( currentRow )
            {
                currentRow--;
                mTableModel->removeRow(index.row());
            }
        });



        auto _container = layout->addWidget(cpp14::make_unique<WContainerWidget>());

        auto _layout = _container->setLayout(cpp14::make_unique<WHBoxLayout>());

        mTCNOuye = _layout->addWidget(cpp14::make_unique<WLineEdit>());    mTCNOuye->setPlaceholderText("TCKN");
        mAdsoyaduye = _layout->addWidget(cpp14::make_unique<WLineEdit>()); mAdsoyaduye->setPlaceholderText("AdSoyad");
        {
            {
                mOkuluye = _layout->addWidget(cpp14::make_unique<WComboBox>());
                mOkuluye->addItem("Atatürk Anadolu Lisesi");
                mOkuluye->addItem("Çandır Çok Programlı Anadolu Lisesi");
                mOkuluye->addItem("Gebiz Şehit Andıllah Kara Anadolu Lisesi");
                mOkuluye->addItem("Mesleki Eğitim Merkezi");
                mOkuluye->addItem("Serik Anadolu İmam-Hatip Lisesi");
                mOkuluye->addItem("Serik Anadolu Lisesi");
                mOkuluye->addItem("Serik Hasan Güçlü Mesleki ve Teknik Anadolu Lisesi");
                mOkuluye->addItem("Serik İbn-i Sina Mesleki ve Teknik Anadolu Lisesi");
                mOkuluye->addItem("Serik IMKB Mesleki ve Teknik Anadolu Lisesi");
                mOkuluye->addItem("Serik Kız Anadolu İmam-Hatip Lisesi");
                mOkuluye->addItem("Serik Mesleki ve Teknik Anadolu Lisesi");
                mOkuluye->addItem("Serik Orhan Gazi Mesleki ve Teknik Anadolu Lisesi");
                mOkuluye->addItem("Yunus Emre Anadolu Lisesi");
                mOkuluye->addItem("Özel Akdeniz Yükseliş Anadolu Lisesi");
                mOkuluye->addItem("Özel Cenap Düzgün Başarı Temel Lisesi");
                mOkuluye->addItem("Özel Serik Akdeniz Temel Lisesi");
                mOkuluye->addItem("Özel Serik Çözüm Temel Lisesi");
            }
        }
        mSinifuye = _layout->addWidget(cpp14::make_unique<WLineEdit>());   mSinifuye->setPlaceholderText("Sınıf");
        mTeluye = _layout->addWidget(cpp14::make_unique<WLineEdit>());     mTeluye->setPlaceholderText("Tel");
        mEpostauye = _layout->addWidget(cpp14::make_unique<WLineEdit>());  mEpostauye->setPlaceholderText("eposta");
        mAdresuye = _layout->addWidget(cpp14::make_unique<WLineEdit>());   mAdresuye->setPlaceholderText("Adres");

        auto ekle = layout->addWidget(cpp14::make_unique<WPushButton>("Ekle"));
        currentRow = 0;
        ekle->clicked().connect([&](){

            if( currentRow < 2 )
            {
                int col = 0 ;

                {
                    auto item = std::make_unique<WStandardItem>();
                    item->setText(mTCNOuye->text());
                    mTableModel->setItem(currentRow,col++,std::move(item));
                }
                {
                    auto item = std::make_unique<WStandardItem>();
                    item->setText(mAdsoyaduye->text());
                    mTableModel->setItem(currentRow,col++,std::move(item));
                }
                {
                    auto item = std::make_unique<WStandardItem>();
                    item->setText(mOkuluye->currentText());
                    mTableModel->setItem(currentRow,col++,std::move(item));
                }
                {
                    auto item = std::make_unique<WStandardItem>();
                    item->setText(mSinifuye->text());
                    mTableModel->setItem(currentRow,col++,std::move(item));
                }
                {
                    auto item = std::make_unique<WStandardItem>();
                    item->setText(mTeluye->text());
                    mTableModel->setItem(currentRow,col++,std::move(item));
                }
                {
                    auto item = std::make_unique<WStandardItem>();
                    item->setText(mEpostauye->text());
                    mTableModel->setItem(currentRow,col++,std::move(item));
                }
                {
                    auto item = std::make_unique<WStandardItem>();
                    item->setText(mAdresuye->text());
                    mTableModel->setItem(currentRow,col++,std::move(item));
                }
                currentRow++;
            }
        });


    }

}

void Body::Basvuru::Basvuru::addUploadPanel()
{

    auto container = addWidget(cpp14::make_unique<WContainerWidget>());

    auto layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());


    ProjeUploaded = false;
    VesikalilUploaded= false;
    KimlikUploaded = false;
    {
        auto _container = layout->addWidget(cpp14::make_unique<WContainerWidget>());
        auto _layout = _container->setLayout(cpp14::make_unique<WVBoxLayout>());
        _layout->addWidget(cpp14::make_unique<WText>("Proje Dosyası (Max:500KB)"));
        ProjeUpload = _layout->addWidget(cpp14::make_unique<WFileUpload>());

        ProjeUpload->setFileTextSize(500);

        ProjeUploadbar = _layout->addWidget(cpp14::make_unique<WProgressBar>());
        ProjeUpload->setProgressBar(ProjeUploadbar);

        ProjeUpload->changed().connect([=]{
            if( ProjeUpload->canUpload() )
            {
                ProjeUpload->upload();
                ProjeUpload->setHidden(false);
            }

        });

        ProjeUpload->uploaded().connect([=]{
            std::cout << "FILE UPLOADED" << std::endl;
            ProjeFileFullPath = ProjeUpload->spoolFileName();
            ProjeFileName = ProjeUpload->clientFileName().toUTF8();
            ProjeUploaded = true;
        });

        ProjeUpload->fileTooLarge().connect([=]{
            std::cout << "FILE Too Large" << std::endl;
        });
    }

    {
        auto _container = layout->addWidget(cpp14::make_unique<WContainerWidget>());
        auto _layout = _container->setLayout(cpp14::make_unique<WVBoxLayout>());
        _layout->addWidget(cpp14::make_unique<WText>("Öğrenci Fotoğrafı/Vesikalık (Max:500KB)"));
        VesikalikUpload = _layout->addWidget(cpp14::make_unique<WFileUpload>());
        auto bar = _layout->addWidget(cpp14::make_unique<WProgressBar>());
        VesikalikUpload->setProgressBar(bar);

        VesikalikUpload->setFileTextSize(500);

        VesikalikUpload->changed().connect([=]{
            if( VesikalikUpload->canUpload() )
            {
                VesikalikUpload->upload();
                VesikalikUpload->setHidden(false);
            }
        });

        VesikalikUpload->uploaded().connect([=]{
            VesikalikFullPath = VesikalikUpload->spoolFileName();
            VesikalikFileName = VesikalikUpload->clientFileName().toUTF8();
            VesikalilUploaded = true;
        });

        VesikalikUpload->fileTooLarge().connect([=]{
            std::cout << "FILE Too Large" << std::endl;
        });
    }

    {
        auto _container = layout->addWidget(cpp14::make_unique<WContainerWidget>());
        auto _layout = _container->setLayout(cpp14::make_unique<WVBoxLayout>());
        _layout->addWidget(cpp14::make_unique<WText>("Öğrenci Kimliği/Belgesi (Max:500KB)"));
        KimlikUpload = _layout->addWidget(cpp14::make_unique<WFileUpload>());
        KimlikUpload->setFilters("*.jpg");
        auto bar = _layout->addWidget(cpp14::make_unique<WProgressBar>());
        KimlikUpload->setProgressBar(bar);

        KimlikUpload->setFileTextSize(500);

        KimlikUpload->changed().connect([=]{
            if( KimlikUpload->canUpload() )
            {
                KimlikUpload->upload();
                KimlikUpload->setHidden(false);
            }
        });

        KimlikUpload->uploaded().connect([=]{
            KimlikFileFullPath = KimlikUpload->spoolFileName();
            KimlikFileName = KimlikUpload->clientFileName().toUTF8();
            KimlikUploaded = true;
        });

        KimlikUpload->fileTooLarge().connect([=]{
            std::cout << "FILE Too Large" << std::endl;
        });
    }

    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        auto _layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());
        mAcceptVerication = _layout->addWidget(cpp14::make_unique<WCheckBox>(),0,AlignmentFlag::Left);
        mAcceptVerication->setMargin(WLength::Auto,AllSides);
        _layout->addWidget(cpp14::make_unique<WText>("Tarafımca Verdiğim Bilgilerin "
                                                     "Yukarda Vermiş Olduğum Bilgilerin Yarışma Şartnamesine Uygunluğunu,"
                                                     " Doğruluğunu ve Hatalı Olması Durumunda Doğacak Yükümlülüğü Kabul Ediyorum."),0,AlignmentFlag::Left)->setMaximumSize(1000,WLength::Auto);
        _layout->addStretch(1);
    }

    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        auto _layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());
        mKaydet = _layout->addWidget(cpp14::make_unique<WPushButton>("Kaydet"));
        mKaydet->clicked().connect(this,&Basvuru::setToVerification);
    }

    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        auto _layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());
        mDogrulamaAlani = _layout->addWidget(cpp14::make_unique<WLineEdit>());
        mDogrulamaAlani->setPlaceholderText("Cep Telefonuna Gelen Kodu Giriniz");
        mDogrulamaAlani->setValidator(std::make_shared<WIntValidator>(1000,9999));
        mDogrulamaAlani->textInput().connect([=](){
            if( mDogrulamaAlani->text().toUTF8().size() != 4 )
            {
//                mDogrulaButton->setEnabled(false);

            }else{
//                mDogrulaButton->setEnabled(true);
                this->SaveProject();
            }
        });
//        mDogrulaButton = _layout->addWidget(cpp14::make_unique<WPushButton>("Doğrula"));
//        mDogrulaButton->setEnabled(false);
//        mDogrulaButton->clicked().connect(this,&Basvuru::Basvuru::SaveProject);
    }

}

void Body::Basvuru::Basvuru::loadLoginScreen()
{

    auto layout = setLayout(cpp14::make_unique<WVBoxLayout>());
    auto container = layout->addWidget(cpp14::make_unique<LoginWidget>(),0,AlignmentFlag::Center|AlignmentFlag::Middle);

}

bool Body::Basvuru::Basvuru::tcnoKontrol(std::string tcno)
{
    mtcnoExist = false;
    auto filter = document{};
    try {
        filter.append(kvp(ProjeKeys::Proje::TCNO,bsoncxx::types::b_utf8{tcno.c_str()}));
        auto col = db->collection(ProjeKeys::Proje::Collection);
        try {
            int exist = col.count(filter.view());
            if( exist )
            {
                mtcnoExist = true;
            }
        } catch (mongocxx::exception &e) {
            std::cout << "mongocxx count error: " << e.what() << std::endl;
        }
    } catch (bsoncxx::exception &e) {
        std::cout << "bsoncxx error: " << e.what() << std::endl;
    }
    return mtcnoExist;
}

bool Body::Basvuru::Basvuru::telnoKontrol(std::string tcno)
{
    telnoExist = false;
    auto filter = document{};
    try {
        filter.append(kvp(ProjeKeys::Proje::Tel,bsoncxx::types::b_utf8{tcno.c_str()}));
        auto col = db->collection(ProjeKeys::Proje::Collection);
        try {
            int exist = col.count(filter.view());
            if( exist )
            {
                telnoExist = true;
            }
        } catch (mongocxx::exception &e) {
            std::cout << "mongocxx count error: " << e.what() << std::endl;
        }
    } catch (bsoncxx::exception &e) {
        std::cout << "bsoncxx error: " << e.what() << std::endl;
    }
    return  telnoExist;
}

bool Body::Basvuru::Basvuru::UyeTCNOKontrol(std::string tcno)
{
    bool bexist = false;
    auto filter = document{};
    try {
        filter.append(kvp(ProjeKeys::Proje::TCNO,bsoncxx::types::b_utf8{tcno.c_str()}));
        auto col = db->collection(ProjeKeys::Proje::Collection);
        try {
            int exist = col.count(filter.view());
            if( exist )
            {
                bexist = true;
            }
        } catch (mongocxx::exception &e) {
            std::cout << "mongocxx count error: " << e.what() << std::endl;
        }
    } catch (bsoncxx::exception &e) {
        std::cout << "bsoncxx error: " << e.what() << std::endl;
    }

    return bexist;
}

void Body::Basvuru::Basvuru::setToVerification()
{

//    if( this->telnoKontrol( mTel->text().toUTF8() ) )
//    {
//        this->MessageBox("HATA","Bu Telefon Numarası ile Daha Önceden Kayıt Yapılmış");
//        return;
//    }

//    if( this->tcnoKontrol(mTCNO->text().toUTF8()) )
//    {
//        this->MessageBox("HATA","Bu TCNO ile Daha Önceden Kayıt Yapılmış");
//        return;
//    }

    if( !mAcceptVerication->isChecked() ){
        this->MessageBox("Uyarı","Girdiğiniz Bilgileri Doğru Beyan Ettiğinizi Kabul Etmediniz!");
        return;
    }

    if( !ProjeUploaded )
    {
        this->MessageBox("HATA","Proje Dosyası Girmediniz!");
        return;
    }

    if( !VesikalilUploaded )
    {
        this->MessageBox("HATA","Fotoğrafınızı Girmediniz!");
        return;
    }

    if( !KimlikUploaded )
    {
        this->MessageBox("HATA","Öğrenci Kimliğinizi Girmediniz!");
        return;
    }

    std::uniform_int_distribution<int> d(1000, 9999);
    std::random_device rd1;
    verificationCode = std::to_string(d(rd1));

    QByteArray ar;

    ar.clear();

    QXmlStreamWriter stream(&ar);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();

    stream.writeStartElement("MainmsgBody");

    stream.writeTextElement("Command", "0");
    stream.writeTextElement("PlatformID", "1");
    stream.writeTextElement("ChannelCode", "474");
    stream.writeTextElement("UserName", "serikbel");
    stream.writeTextElement("PassWord", "nisan2012");
    stream.writeTextElement("Mesgbody", QString("Doğrulama Kodu: ") + verificationCode.c_str() + QString(" .Bu İsteği Siz Bulunmadıysanız Dikkate Almayınız"));
    stream.writeTextElement("Numbers", mTel->text().toUTF8().c_str());
    stream.writeTextElement("Type", "1");
    stream.writeTextElement("Concat", "1");
    stream.writeTextElement("Originator", "SERiK BLD");

    stream.writeEndElement();

    stream.writeEndDocument();

    auto httpclient = addChild(std::make_unique<Http::Client>());

    Http::Message msg;
    msg.setHeader("Content-Type","application/json");

    msg.addBodyText(ar.toStdString());

    httpclient->setSslCertificateVerificationEnabled(false);

    httpclient->done().connect([=](AsioWrapper::error_code code, Http::Message message){
        std::cout << "HTTP DONE: " << code.message().c_str() << message.body().c_str() << std::endl;
    });

    httpclient->post("http://processor.smsorigin.com/xml/process.aspx",msg);

    mKaydet->setEnabled(false);

}

void Body::Basvuru::Basvuru::SaveProject()
{

    if( mDogrulamaAlani->text().toUTF8() != verificationCode )
    {
        this->MessageBox("HATA","Doğrulama Kodunu Hatalı Girdiniz");
        mDogrulamaAlani->setText("");
        return;
    }



    auto doc = document{};

    try {
        doc.append(kvp(ProjeKeys::Proje::ProjeAdi,bsoncxx::types::b_utf8{mProjeAdi->text().toUTF8().c_str()}));
        doc.append(kvp(ProjeKeys::Proje::ProjeKategori,bsoncxx::types::b_utf8{mProjeCat->currentText().toUTF8().c_str()}));
        doc.append(kvp(ProjeKeys::Proje::TCNO,bsoncxx::types::b_utf8{mTCNO->text().toUTF8().c_str()}));
        doc.append(kvp(ProjeKeys::Proje::Ad,bsoncxx::types::b_utf8{mAd->text().toUTF8().c_str()}));
        doc.append(kvp(ProjeKeys::Proje::Soyad,bsoncxx::types::b_utf8{mSoyad->text().toUTF8().c_str()}));
        doc.append(kvp(ProjeKeys::Proje::Okul,bsoncxx::types::b_utf8{mOkul->currentText().toUTF8().c_str()}));
        doc.append(kvp(ProjeKeys::Proje::Sinif,bsoncxx::types::b_utf8{mSinif->text().toUTF8().c_str()}));
        doc.append(kvp(ProjeKeys::Proje::Tel,bsoncxx::types::b_utf8{mTel->text().toUTF8().c_str()}));
        doc.append(kvp(ProjeKeys::Proje::Mail,bsoncxx::types::b_utf8{mEposta->text().toUTF8().c_str()}));
        doc.append(kvp(ProjeKeys::Proje::Adres,bsoncxx::types::b_utf8{mAdres->text().toUTF8().c_str()}));
        doc.append(kvp(ProjeKeys::Proje::NeredenDuydunuz,bsoncxx::types::b_utf8{mNeredenDuyma->text().toUTF8().c_str()}));

        std::cout << "ROW COUNT: " << mTableModel.get()->rowCount() << std::endl;
        auto ar = array{};
        for( int i = 0 ; i < mTableModel.get()->rowCount() ; i++ ){
            auto subDoc = document{};
            try {
                int col = 0;
                subDoc.append(kvp(ProjeKeys::Proje::Uye::TCNO,mTableModel->item(i,col++)->text().toUTF8().c_str()));
                subDoc.append(kvp(ProjeKeys::Proje::Uye::AdSoyad,mTableModel->item(i,col++)->text().toUTF8().c_str()));
                subDoc.append(kvp(ProjeKeys::Proje::Uye::Okul,mTableModel->item(i,col++)->text().toUTF8().c_str()));
                subDoc.append(kvp(ProjeKeys::Proje::Uye::Sinif,mTableModel->item(i,col++)->text().toUTF8().c_str()));
                subDoc.append(kvp(ProjeKeys::Proje::Uye::Tel,mTableModel->item(i,col++)->text().toUTF8().c_str()));
                subDoc.append(kvp(ProjeKeys::Proje::Uye::Mail,mTableModel->item(i,col++)->text().toUTF8().c_str()));
                ar.append(bsoncxx::types::b_document{subDoc});
            } catch (bsoncxx::exception &e) {
                std::cout << "Subdoc error: " << e.what() << std::endl;
            }
        }


        auto bucket = db->gridfs_bucket();
        {
            auto uploader = bucket.open_upload_stream(ProjeFileName);
            QByteArray ar;
            QFile file( ProjeFileFullPath.c_str() );
            if( file.open(QIODevice::ReadOnly) )
            {
                ar = file.readAll();
                file.close();
            }
            uploader.write((std::uint8_t*)ar.data(),ar.size());
            auto result = uploader.close();
            doc.append(kvp(ProjeKeys::ProjeFile,result.id()));
        }

        {
            auto uploader = bucket.open_upload_stream(VesikalikFileName);
            QByteArray ar;
            QFile file( VesikalikFullPath.c_str() );
            if( file.open(QIODevice::ReadOnly) )
            {
                ar = file.readAll();
                file.close();
            }
            uploader.write((std::uint8_t*)ar.data(),ar.size());
            auto result = uploader.close();
            doc.append(kvp(ProjeKeys::Vesikalik,result.id()));
        }

        {
            auto uploader = bucket.open_upload_stream(KimlikFileName);
            QByteArray ar;
            QFile file( KimlikFileFullPath.c_str() );
            if( file.open(QIODevice::ReadOnly) )
            {
                ar = file.readAll();
                file.close();
            }
            uploader.write((std::uint8_t*)ar.data(),ar.size());
            auto result = uploader.close();
            doc.append(kvp(ProjeKeys::OgrenciKimlik,result.id()));
        }




        doc.append(kvp(ProjeKeys::Proje::Uyeler,bsoncxx::types::b_array{ar}));

        auto col = db->collection(ProjeKeys::Proje::Collection);

        try {
            mongocxx::stdx::optional<mongocxx::result::insert_one> res = col.insert_one(doc.view());

            if( res.get().result().inserted_count() )
            {
                this->MessageBox("Bilgi","<b>Tebrikler!</b><p>Projenizi Başarı ile Kayıt Ettiniz</p>");
            }
        } catch (mongocxx::exception &e) {
            std::cout << "mongocxx insert one error: " << e.what() << std::endl;
        }




    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR bsoncxx: "<<e.what() << std::endl;
    }


}

void Body::Basvuru::Basvuru::MessageBox(std::string mTitle, std::string mesaj)
{
    auto messageBox = addChild(
                Wt::cpp14::make_unique<Wt::WMessageBox>
                (mTitle,
                 Wt::WString(mesaj),
                 Wt::Icon::Information, Wt::StandardButton::Ok));

        messageBox->buttonClicked().connect([=] {
            removeChild(messageBox);
        });

        messageBox->show();
}

Body::Basvuru::LoginWidget::LoginWidget()
    :WContainerWidget()
{

    mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mMainContainer->setContentAlignment(AlignmentFlag::Center);

    auto layout = mMainContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

    layout->addStretch(1);
    layout->addWidget(cpp14::make_unique<WText>("Başvuruda Bulunmak için Önce Üye Olmanız Gerekmektedir."));
    layout->addWidget(cpp14::make_unique<WText>("Üyeliğiniz Var ise Giriş Yapıp Proje Başvurusunda Bulunabilirsiniz"));
    layout->addStretch(1);

    {
        auto _container = layout->addWidget(cpp14::make_unique<WContainerWidget>());
        auto _layout = _container->setLayout(cpp14::make_unique<WGridLayout>());
        _layout->addWidget(cpp14::make_unique<WText>("Kullanıcı Adı"),0,0,AlignmentFlag::Right);
        _layout->addWidget(cpp14::make_unique<WText>("Şifre"),1,0,AlignmentFlag::Right);

        auto username = _layout->addWidget(cpp14::make_unique<WLineEdit>("Kullanıcı Adı"),0,1,AlignmentFlag::Left);
        auto pasword = _layout->addWidget(cpp14::make_unique<WLineEdit>("Şifre"),1,1,AlignmentFlag::Left);
        pasword->setPlaceholderText("Şifrenizi Giriniz");
        username->setPlaceholderText("Kullanıcı Adınızı Giriniz");
        pasword->setEchoMode(EchoMode::Password);

        _layout->addWidget(cpp14::make_unique<WPushButton>("Giriş"),2,1,AlignmentFlag::Center);
        _layout->addWidget(cpp14::make_unique<WPushButton>("Unuttum"),3,1,AlignmentFlag::Center);
        mUyeol = _layout->addWidget(cpp14::make_unique<WPushButton>("Üye Ol"),4,1,AlignmentFlag::Center);
        mUyeol->clicked().connect(this,&LoginWidget::Signup);

    }

    layout->addStretch(1);

}

void Body::Basvuru::LoginWidget::Signup()
{
    mMainContainer->clear();

    auto layout = mMainContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

    layout->addStretch(1);

    auto container = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Justify);
    container->setMinimumSize(550,WLength::Auto);

    auto glayout = container->setLayout(cpp14::make_unique<WGridLayout>());
    int row = 0;
    {
        {
            auto _container = glayout->addWidget(cpp14::make_unique<WContainerWidget>(),row,0,AlignmentFlag::Justify|AlignmentFlag::Middle);
            _container->addWidget(cpp14::make_unique<WText>("TCNO"));
        }
        {
            auto _container = glayout->addWidget(cpp14::make_unique<WContainerWidget>(),row++,1,AlignmentFlag::Justify|AlignmentFlag::Middle);
            _container->addWidget(cpp14::make_unique<WLineEdit>())->setPlaceholderText("TC Kimlik Numaranızı Giriniz");
        }
    }
    {
        {
            auto _container = glayout->addWidget(cpp14::make_unique<WContainerWidget>(),row,0,AlignmentFlag::Justify|AlignmentFlag::Middle);
            _container->addWidget(cpp14::make_unique<WText>("Adınız"));
        }
        {
            auto _container = glayout->addWidget(cpp14::make_unique<WContainerWidget>(),row++,1,AlignmentFlag::Justify|AlignmentFlag::Middle);
            _container->addWidget(cpp14::make_unique<WLineEdit>())->setPlaceholderText("Adınızı Giriniz");
        }
    }
    {
        {
            auto _container = glayout->addWidget(cpp14::make_unique<WContainerWidget>(),row,0,AlignmentFlag::Justify|AlignmentFlag::Middle);
            _container->addWidget(cpp14::make_unique<WText>("SoyAdınız"));
        }
        {
            auto _container = glayout->addWidget(cpp14::make_unique<WContainerWidget>(),row++,1,AlignmentFlag::Justify|AlignmentFlag::Middle);
            _container->addWidget(cpp14::make_unique<WLineEdit>())->setPlaceholderText("Soy Adınızı Giriniz");
        }
    }
    {
        {
            auto _container = glayout->addWidget(cpp14::make_unique<WContainerWidget>(),row,0,AlignmentFlag::Justify|AlignmentFlag::Middle);
            _container->addWidget(cpp14::make_unique<WText>("Telefon"));
        }
        {
            auto _container = glayout->addWidget(cpp14::make_unique<WContainerWidget>(),row++,1,AlignmentFlag::Justify|AlignmentFlag::Middle);
            _container->addWidget(cpp14::make_unique<WLineEdit>())->setPlaceholderText("Telefon(Cep) Numaranızı Giriniz");
        }
    }
    {
        {
            auto _container = glayout->addWidget(cpp14::make_unique<WContainerWidget>(),row,0,AlignmentFlag::Justify|AlignmentFlag::Middle);
            _container->addWidget(cpp14::make_unique<WText>("Okul"));
        }
        {
            auto _container = glayout->addWidget(cpp14::make_unique<WContainerWidget>(),row++,1,AlignmentFlag::Justify|AlignmentFlag::Middle);
            _container->addWidget(cpp14::make_unique<WLineEdit>())->setPlaceholderText("Okulunuzun Adını Giriniz");
        }
    }
    {
        {
            auto _container = glayout->addWidget(cpp14::make_unique<WContainerWidget>(),row,0,AlignmentFlag::Justify|AlignmentFlag::Middle);
            _container->addWidget(cpp14::make_unique<WText>("Sınıf"));
        }
        {
            auto _container = glayout->addWidget(cpp14::make_unique<WContainerWidget>(),row++,1,AlignmentFlag::Justify|AlignmentFlag::Middle);
            _container->addWidget(cpp14::make_unique<WLineEdit>())->setPlaceholderText("Sınıfınızı Giriniz");
        }
    }


    auto signupbtn = layout->addWidget(cpp14::make_unique<WPushButton>("Üye Ol"));

    verifiCationCodecontainer = layout->addWidget(cpp14::make_unique<WContainerWidget>());

    signupbtn->clicked().connect([&](){
        verifiCationCodecontainer->clear();
        auto _layout = verifiCationCodecontainer->setLayout(cpp14::make_unique<WVBoxLayout>());
        {
            auto _container = _layout->addWidget(cpp14::make_unique<WContainerWidget>());
            auto s_layout = _container->setLayout(cpp14::make_unique<WHBoxLayout>());
            s_layout->addWidget(cpp14::make_unique<WText>("Doğrulama Kodu"));
            s_layout->addWidget(cpp14::make_unique<WLineEdit>())->setPlaceholderText("Doğrulama Kodunu Giriniz");
        }
        _layout->addWidget(cpp14::make_unique<WPushButton>("Doğrula"));

    });

    layout->addStretch(1);


}

Body::Oduller::Oduller()
    :WContainerWidget()
{
    addStyleClass("gencFikirStyle");
    setId("gencFikir");
    setContentAlignment(AlignmentFlag::Center);

    doJavaScript("resizegencFikirPage();");
    auto layout = setLayout(cpp14::make_unique<WVBoxLayout>());

    layout->addWidget(cpp14::make_unique<WText>("<h2>Ödüller</h2>"));
    layout->addStretch(1);
    layout->addWidget(cpp14::make_unique<WText>("<h3>Büyük Ödül : 1 Adet Dizüstü Bilgisayar</h3>"));
    layout->addWidget(cpp14::make_unique<WText>("<h4>Sosyal Medya Ödülü : 1 Adet Dizüstü Bilgisayar</h4>"));
    layout->addWidget(cpp14::make_unique<WText>("<h4>Kategori Birincilik Ödülü(Her Kategoride) : 1 Adet Tablet</h4>"));
    layout->addWidget(cpp14::make_unique<WText>("<h4>Kategori İkincilik Ödülü(Her Kategoride) : 1 Adet Cep Telefonu</h4>"));
    layout->addWidget(cpp14::make_unique<WText>("<h4>Kategori Üçüncülük Ödülü(Her Kategoride) : 1 Adet Fotoğraf Makinası</h4>"));
    layout->addStretch(1);

}
