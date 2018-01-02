#ifndef PROJEKEYS_H
#define PROJEKEYS_H


#include <iostream>

namespace ProjeKeys {


    static std::string DB{"SERIKGENCFIKIR"};

    namespace Proje {
    static std::string Collection{"Proje"};
    static std::string ProjeAdi{"Proje Adı"};
    static std::string ProjeKategori{"Proje Kategori"};
    static std::string Ad{"Ad"};
    static std::string Soyad{"Soyad"};
    static std::string TCNO{"TCNO"};
    static std::string Okul{"Okul"};
    static std::string Sinif{"Sınıf"};
    static std::string Tel{"Tel"};
    static std::string Mail{"Mail"};
    static std::string Adres{"Adres"};
    static std::string NeredenDuydunuz{"NerenDuydunuz"};
    static std::string Uyeler{"Üyeler"};
    namespace Uye {
        static std::string TCNO{"TCNO"};
        static std::string AdSoyad{"AdSoyad"};
        static std::string Okul{"Okul"};
        static std::string Sinif{"Sınıf"};
        static std::string Tel{"Tel"};
        static std::string Mail{"Mail"};
        static std::string Adres{"Adres"};
    }
    }
    static std::string ProjeFile{"ProjeFile"};
    static std::string Vesikalik{"Vesikalik"};
    static std::string OgrenciKimlik{"ÖgrenciKimlik"};
}

#endif // PROJEKEYS_H
