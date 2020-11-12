/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 3 Kas�m 2019 Pazar
* @brief Bu program bir yaz�c� senaryo uygulamas�d�r.
* Similasyonda bir yaz�c� kuyru�u olu�turuluyor ve kullan�c�dan s�rada bekleyen belge ile ilgili gerekli bilgiler al�p
* bunu bir istatistik alt men�s� alt�nda sunuyor. S�radan istedi�iniz zaman s�radaki elamman� ��kar�p s�raya yeni elaman ekleyebiliyorsunuz.
*/
#pragma once
#include<string>
using namespace std;
/**
* @brief Bu s�n�f bir yaz�c� kuyru�udur.
* @param first : S�rarn�n �n�.
* @param rear : S�ran�n arkas�.
* @param p : S�radaki eleman say�s�.
* @param count1 : Sayfa say�s� 10'dan b�y�k olan belgeleri sayan saya�.
* @param count2 : Sayfa say�s� 10'dan k���k olan belgeleri sayan saya�.
* @param sum : S�radaki belgelerin toplam sayfa say�s�.
* @param renk1 : S�radaki belgelerin renkli olanlar�n� sayan saya�.
* @param renk2 : S�radaki belgelerin siyah olanlar�n� sayan saya�.
* @param size : S�ran�n boyutu.
*/
class Yaz�c�_Kuyru�u
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
	struct Yaz�c�
	{
		int say�;
		string renk;
		int sayfa_sayisi;
	};
	Yaz�c�* ptr = new Yaz�c�[size];
public:
	Yaz�c�_Kuyru�u();
	~Yaz�c�_Kuyru�u();
	/**
	* @brief : Bu fonksiyon s�rada toplam ka� eleman oldu�unu hesaplar ve d�nd�r�r.
	* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
	*/
	int Say();
	/**
	* @brief : Bu fonksiyon s�raya eleman eklemek istendi�inde yer olup olmad���n� d�nd�r�r.
	* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
	*/
	bool S�ra_Dolumu();
	/**
	* @brief : Bu fonksiyon s�radan eleman silinmek istendi�inde bo� olup olmad���n� d�nd�r�r.
	* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
	*/
	bool S�ra_Bo�mu();
	/**
	* @brief : Bu fonksiyon s�raya eklenen belgenin sayfa say�s�n� kullan�c�dan al�r.
	* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
	*/
	void Sayfa_Say�s�();
	/**
	* @brief : Bu fonksiyon s�raya eklenen belgenin rengini kullan�c�dan al�r.
	* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
	*/
	void Renk();
	/**
	* @brief : Bu fonksiyon kullan�c�dan ald��� bilgileri bir yap�da tutar ve s�ran�n sonuna ekler
	* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
	*/
	void Ekle();
	/**
	* @brief : Bu fonksiyon s�radaki eleman�n sayfa say�s�n�n ka��n�n 10'dan b�y�k ka��n�n 10'dan k���k oldu�unu,
	* s�radaki belgelerin toplam sayfa say�s�n�, ortalama sayfa say�s�n�, renkli belge say�s�n� ve siyah beyaz belge say�s�n� yazd�r�r.
	* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
	*/
	void �statistik();
	/**
	* @brief : Bu fonksiyon s�radaki elemanlar� eklenme s�ras�na g�re listeler.
	* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
	*/
	void Listele()const;
	/**
	* @brief : Bu fonksiyon s�raya eklenme s�ras�na g�re eklenen ilk eleman� siler.
	* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
	*/
	void Sil();
	/**
	* @brief : Bu fonksiyon s�radan silinen elemanlar�n kaplad��� yeri elemanlar� kayd�rarak gereksiz alan kullan�m�n� azalt�r.
	* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
	*/
	void Toparla();
};
/*
* @brief : Bu fonksiyon menuyu acar ve istenen fonkisiyona yonlendirir.
* @see main() : Fonksiyonun hangi amacla cagr�ld�g�n� inceleyiniz.
*/
void Menu();