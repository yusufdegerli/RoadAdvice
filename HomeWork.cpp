/*
    İSİM SOYİSİM:
    OKUL:
    ÖĞRENCİ NO:
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string.h>

void ft_err(std::string message) // message değişkenine verilen yazıyı hata mesajı olarak yazdırırız.
{
    std::cout << message << std::endl;
}

void tavsiye(std::string tavsiye) // İstenilen tavsiyeye göre çıktı yazdırılır.
{
    std::cout << "Tavsiye edilen: "<< tavsiye << " ile gitmeniz." << std::endl;
}

void sorgu(long yas, float mesafe, long arkSayisi)
{
    std::string havaDurumu[] = {"Açik", "Bulutlu", "Yağmurlu", "Karli", "Firtina"}; // Verilmiş hava durumları bir string dizisinde tutulur.
    int hava = rand() % 5; // rastgele bir sayı elde edilir. Hava durumu için.
    int ruzgarHizi = rand() % 5; // rastgele bir sayı elde edilir. Rüzgar hızı için.
    bool bisikletYolu = rand() % 2; // rastgele bir değer elde edilir (True - False). Bisiklet yolu için.

    std::cout << "Hava durumu: " << havaDurumu[hava] << std::endl; // Edinilen hava değeri ile, hava durumu yazdırılır.
    std::cout << "Rüzgar hizi: " << ruzgarHizi << std::endl; // Edinilen rüzgar hızı değeri ile, rüzgar hızı yazdırılır.

    if(bisikletYolu == true) // Bisiklet yolunun varlığı kontrol edilir.
        std::cout << "Bisiklet yolu: Var\n";
    else
        std::cout << "Bisiklet yolu: Yok\n";

    if (yas < 10 || mesafe > 1.5) // Yaş 10'dan küçükse veya mesafe 1.5'den fazla ise, tavsiye edilen araba ile gitmektir.
        tavsiye("araba");
    else if (yas >= 10 && mesafe < 1.0) // Yas 10'dan buyukse ve eşitse ve mesafe 1.0'dan küçükmü durumunu kontrol eder
    {
        if ((hava >= 2 && hava <= 4) || (hava == 0 && ruzgarHizi > 3)) // (Eğer hava durumu "Yağmurlu", "Karli", "Firtina" veya hava "Açik") ve (ruzgar hızı 3'den büyükse) araba ile gildilmesi tavsiye edilir.
            tavsiye("araba");
        else
            tavsiye("yürüyerek"); // Yukarıdaki koşullar sağlanmazsa yürüyerek gidilmesi tavsiye edilir.
    }
    else if (yas >= 10 && mesafe >= 1.0 && mesafe <= 1.5) // (Eğer yaş 10'a eşit veya büyükse) ve (mesafe 1.0'dan büyük ve eşitse) ve (mesafe 1.5'den küçükmü) durumunu kontrol eder.
    {
        if (arkSayisi > 0 && bisikletYolu) // Arkadaş sayisi 0'dan büyükse ve bisiklet yolu varsa kontrolu yapılır
        {
            if ((hava >= 2 && hava <= 4) || (hava == 0 && ruzgarHizi > 3)) // Yukarıdaki tüm koşullar ve hava "Yağmurlu", "Karli" ve "Firtina" ise veya hava "Açık" ve ruzgar hızı 3'den büyükse araba ile gidilmesi tavsiye edilir.
                tavsiye("araba");
            else
                tavsiye("bisiklet"); // yukarıdaki koşullar sağlanmazsa bisiklet tavsiyesi verilir.
        }
        else // ark sayısı 0'ise ve bisiklet yolu yoksa
        {
            if ((hava >= 2 && hava <= 4) || (hava == 0 && ruzgarHizi > 3)) // Yukarıdaki koşullarla birlikte hava "Yağmurlu", "Karli" ve "Firtina" ise veya hava "Açık" ve ruzgar hızı 3'den büyükse araba ile gidilmesi tavsiye edilir
                tavsiye("araba");
            else
                tavsiye("yürüyerek");
        }
    }
}


void cycle()
{
    std::string input;
    long yas;
    float mesafe;
    long ark_sayisi;

    while(1)
    {
        yas:
        std::cout<<"Lütfen yaş girin: ";
        std::getline(std::cin, input); // girdiyi almamızı sağlar.
        yas = atol(input.c_str()); // Yaş'ın sayısal verisini alırız.
        if(!(yas >= 6 && yas <= 35) && !std::cin.eof()) // İstenilen yaş sorgusu yapılır.
        {
            ft_err("Lütfen belirtilen yaş araligi giriniz (6-35):");
            goto yas; // İstenilen durumlar karşılanmadığı zaman 'yas:' satırına geri döner.
        }
        mesafe:
        std::cout<<"Lütfen Mesafe girin: ";
        std::getline(std::cin, input);
        mesafe = atof(input.c_str()); // Mesafe'nin ondalık değerini alırız.
        if(!(mesafe >= 0.1 && mesafe <= 20.0) && !std::cin.eof()) // İstenilen mesafe sorgusu yapılır. eof() - End Of File, değer girildiğini kontrol eder.
        {
            ft_err("Lütfen belirtilen mesafe araligi giriniz (0.1-20):");
            goto mesafe; // İstenilen durumlar karşılanmadığı zaman 'mesafe:' satırına geri döner.
        }
        ark:
        std::cout<<"Lütfen arkadas sayisini girin: ";
        std::getline(std::cin, input);
        ark_sayisi = atol(input.c_str()); // Arkadaş Sayısı'nın sayısal değerini alırız.
        if(!(ark_sayisi >= 0 && ark_sayisi <= 10) && !std::cin.eof())
        {
            ft_err("Lütfen belirtilen arkadaş araligi giriniz (0-10):");
            goto ark;// İstenilen durumlar karşılanmadığı zaman 'ark:' satırına geri döner.
        }
        break; // Döngüyü durdurur.
    }
    sorgu(yas, mesafe, ark_sayisi); // Elde ettiğimiz değerleri, sorgu fonksiyonuna atılır.
}


int main()
{
    srand(time(0));
    cycle();
    return 0;   
}