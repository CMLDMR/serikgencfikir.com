#ifndef BODYPAGE_H
#define BODYPAGE_H

#include <QtCore/qglobal.h>

#include <Wt/WContainerWidget.h>
#include <Wt/WImage.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WSignal.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WGridLayout.h>
#include <Wt/WText.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WAnchor.h>
#include <Wt/WLink.h>
#include <Wt/WLineEdit.h>
#include <Wt/WComboBox.h>
#include <Wt/WTextArea.h>
#include <Wt/WLineF.h>
#include <Wt/WFileUpload.h>
#include <Wt/WPushButton.h>
#include <Wt/WTable.h>
#include <Wt/WTableCell.h>

#include <Wt/WStandardItem.h>
#include <Wt/WStandardItemModel.h>
#include <Wt/WTableView.h>
#include <Wt/WModelIndex.h>
#include <Wt/WEvent.h>
#include <Wt/WCheckBox.h>
#include <Wt/Http/Client.h>
#include <Wt/WProgressBar.h>
#include <Wt/WIntValidator.h>
#include <Wt/WMessageBox.h>




#include <QFile>
#include <QXmlStreamWriter>
#include <QByteArray>
#include <QFileInfo>


#include <random>


#include <bsoncxx/builder/basic/array.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/exception/exception.hpp>
#include <bsoncxx/types/value.hpp>
#include <bsoncxx/types.hpp>

#include <mongocxx/database.hpp>
#include <mongocxx/collection.hpp>
#include <mongocxx/exception/exception.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/stdx/make_unique.hpp>
#include <mongocxx/gridfs/bucket.hpp>


#include "bootstrap.h"
#include "projekeys.h"

using bsoncxx::builder::basic::document;
using bsoncxx::builder::basic::array;
using bsoncxx::builder::basic::kvp;

using namespace Wt;

namespace Body {


    class BodyPage : public WContainerWidget
    {
    public:
        BodyPage(mongocxx::database* _db);

        void initStart();

        void ClickGencFikir();
        void ClickOduller();
        void ClickYarismaKosullari();
        void OrnekTaslak();
        void Basvuru();

        WContainerWidget* mMainContainer;

        mongocxx::database* db;
    };

    class GencFikir : public WContainerWidget
    {
    public:
        GencFikir();
    };

    class Oduller : public WContainerWidget
    {
    public:
        Oduller();
    };


    class YarisKosullari : public WContainerWidget
    {
    public:
        YarisKosullari();
    };


    class OrnekTaslak : public WContainerWidget
    {
    public:
        OrnekTaslak();
    };


    namespace Basvuru {
        class Basvuru : public WContainerWidget
        {
        public:
            Basvuru(mongocxx::database* _db);
            void LoadForm();
            void addUploadPanel();
            void loadLoginScreen();


            int currentRow;
            WTableView* mTable;
            std::shared_ptr<WStandardItemModel> mTableModel;


            WLineEdit* mProjeAdi;
            WComboBox* mProjeCat;

            WLineEdit* mTCNO;
            bool tcnoKontrol(std::string tcno);
            bool mtcnoExist;
            WLineEdit* mAd;
            WLineEdit* mSoyad;
            WComboBox* mOkul;
            WLineEdit* mSinif;
            WLineEdit* mTel;
            bool telnoKontrol(std::string tcno);
            bool telnoExist;
            WLineEdit* mEposta;
            WTextArea* mAdres;
            WLineEdit* mNeredenDuyma;

            WLineEdit* mTCNOuye;
            bool UyeTCNOKontrol(std::string tcno);
            WLineEdit* mAdsoyaduye;
            WComboBox* mOkuluye;
            WLineEdit* mSinifuye;
            WLineEdit* mTeluye;
            WLineEdit* mEpostauye;
            WLineEdit* mAdresuye;

            WPushButton* mKaydet;

            void setToVerification();

            std::string verificationCode;


            WProgressBar* ProjeUploadbar;
            WFileUpload* ProjeUpload;
            WFileUpload* VesikalikUpload;
            WFileUpload* KimlikUpload;

            std::string ProjeFileFullPath, ProjeFileName;
            std::string VesikalikFullPath, VesikalikFileName;
            std::string KimlikFileFullPath, KimlikFileName;


            bool ProjeUploaded,VesikalilUploaded,KimlikUploaded;




            WLineEdit* mDogrulamaAlani;
            WPushButton* mDogrulaButton;

            WCheckBox* mAcceptVerication;

            bool CanApplyProject;

            void SaveProject();

            void MessageBox( std::string mTitle , std::string mesaj );

            mongocxx::database* db;
        };


        class LoginWidget : public WContainerWidget
        {
        public:
            LoginWidget();

            void Signup();

        private:
            WContainerWidget* mMainContainer;
            WPushButton* mUyeol;
            WContainerWidget* verifiCationCodecontainer;

        };
    }





}



#endif // BODYPAGE_H
