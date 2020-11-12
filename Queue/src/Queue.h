/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 3 Kasým 2019 Pazar
* @brief Bu program bir yazýcý senaryo uygulamasýdýr.
* Similasyonda bir yazýcý kuyruðu oluþturuluyor ve kullanýcýdan sýrada bekleyen belge ile ilgili gerekli bilgiler alýp
* bunu bir istatistik alt menüsü altýnda sunuyor. Sýradan istediðiniz zaman sýradaki elammaný çýkarýp sýraya yeni elaman ekleyebiliyorsunuz.
*/
#pragma once
#include<string>
using namespace std;
/**
* @brief Bu sýnýf bir yazýcý kuyruðudur.
* @param first : Sýrarnýn önü.
* @param rear : Sýranýn arkasý.
* @param p : Sýradaki eleman sayýsý.
* @param count1 : Sayfa sayýsý 10'dan büyük olan belgeleri sayan sayaç.
* @param count2 : Sayfa sayýsý 10'dan küçük olan belgeleri sayan sayaç.
* @param sum : Sýradaki belgelerin toplam sayfa sayýsý.
* @param renk1 : Sýradaki belgelerin renkli olanlarýný sayan sayaç.
* @param renk2 : Sýradaki belgelerin siyah olanlarýný sayan sayaç.
* @param size : Sýranýn boyutu.
*/
class Yazýcý_Kuyruðu
{
private:
	int first;
	int rear;
	int size = 50;
	int p;
	int count1;
	int count2;
	int sum;
	int renk1;
	int renk2;
	struct Yazýcý
	{
		int sayý;
		string renk;
		int sayfa_sayisi;
	};
	Yazýcý* ptr = new Yazýcý[size];
public:
	Yazýcý_Kuyruðu();
	~Yazýcý_Kuyruðu();
	/**
	* @brief : Bu fonksiyon sýrada toplam kaç eleman olduðunu hesaplar ve döndürür.
	* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
	*/
	int Say();
	/**
	* @brief : Bu fonksiyon sýraya eleman eklemek istendiðinde yer olup olmadýðýný döndürür.
	* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
	*/
	bool Sýra_Dolumu();
	/**
	* @brief : Bu fonksiyon sýradan eleman silinmek istendiðinde boþ olup olmadýðýný döndürür.
	* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
	*/
	bool Sýra_Boþmu();
	/**
	* @brief : Bu fonksiyon sýraya eklenen belgenin sayfa sayýsýný kullanýcýdan alýr.
	* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
	*/
	void Sayfa_Sayýsý();
	/**
	* @brief : Bu fonksiyon sýraya eklenen belgenin rengini kullanýcýdan alýr.
	* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
	*/
	void Renk();
	/**
	* @brief : Bu fonksiyon kullanýcýdan aldýðý bilgileri bir yapýda tutar ve sýranýn sonuna ekler
	* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
	*/
	void Ekle();
	/**
	* @brief : Bu fonksiyon sýradaki elemanýn sayfa sayýsýnýn kaçýnýn 10'dan büyük kaçýnýn 10'dan küçük olduðunu,
	* sýradaki belgelerin toplam sayfa sayýsýný, ortalama sayfa sayýsýný, renkli belge sayýsýný ve siyah beyaz belge sayýsýný yazdýrýr.
	* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
	*/
	void Ýstatistik();
	/**
	* @brief : Bu fonksiyon sýradaki elemanlarý eklenme sýrasýna göre listeler.
	* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
	*/
	void Listele()const;
	/**
	* @brief : Bu fonksiyon sýraya eklenme sýrasýna göre eklenen ilk elemaný siler.
	* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
	*/
	void Sil();
	/**
	* @brief : Bu fonksiyon sýradan silinen elemanlarýn kapladýðý yeri elemanlarý kaydýrarak gereksiz alan kullanýmýný azaltýr.
	* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
	*/
	void Toparla();
};
/*
* @brief : Bu fonksiyon menuyu acar ve istenen fonkisiyona yonlendirir.
* @see main() : Fonksiyonun hangi amacla cagrýldýgýný inceleyiniz.
*/
void Menu();