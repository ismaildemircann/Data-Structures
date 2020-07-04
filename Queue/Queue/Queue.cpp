/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 3 Kas�m Ekim 2019 Pazar
* @brief Bu program bir yaz�c� senaryo uygulamas�d�r.
* Similasyonda bir yaz�c� kuyru�u olu�turuluyor ve kullan�c�dan s�rada bekleyen belge ile ilgili gerekli bilgiler al�p
* bunu bir istatistik alt men�s� alt�nda sunuyor. S�radan istedi�iniz zaman s�radaki elamman� ��kar�p s�raya yeni elaman ekleyebiliyorsunuz.
*/
#include"Queue.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<locale.h>
#include<conio.h>
using namespace std;
/**
* @param first : S�rarn�n �n�.
* @param rear : S�ran�n arkas�.
* @param p : S�radaki eleman say�s�.
* @param count1 : Sayfa say�s� 10'dan b�y�k olan belgeleri sayan saya�.
* @param count2 : Sayfa say�s� 10'dan k���k olan belgeleri sayan saya�.
* @param sum : S�radaki belgelerin toplam sayfa say�s�.
* @param renk1 : S�radaki belgelerin renkli olanlar�n� sayan saya�.
* @param renk2 : S�radaki belgelerin siyah olanlar�n� sayan saya�.
*/
Yaz�c�_Kuyru�u::Yaz�c�_Kuyru�u()
{
	first = 0;
	rear = 0;
	p = 0;
	count1 = 0;
	count2 = 0;
	sum = 0;
	renk1 = 0;
	renk2 = 0;
}
Yaz�c�_Kuyru�u::~Yaz�c�_Kuyru�u()
{
}
/**
* @brief : Bu fonksiyon s�rada toplam ka� eleman oldu�unu hesaplar ve d�nd�r�r.
* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
*/
int Yaz�c�_Kuyru�u::Say()
{
	return p - first;
}
/**
* @brief : Bu fonksiyon s�raya eleman eklemek istendi�inde yer olup olmad���n� d�nd�r�r.
* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
*/
bool Yaz�c�_Kuyru�u::S�ra_Dolumu()
{
	if (first == ((rear + 1) % (size + 1)))
	{
		return true;
	}
	return false;
}
/**
* @brief : Bu fonksiyon s�radan eleman silinmek istendi�inde bo� olup olmad���n� d�nd�r�r.
* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
*/
bool Yaz�c�_Kuyru�u::S�ra_Bo�mu()
{
	if (first == rear)
	{
		return true;
	}
	return false;
}
/**
* @brief : Bu fonksiyon s�raya eklenen belgenin sayfa say�s�n� kullan�c�dan al�r.
* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
*/
void Yaz�c�_Kuyru�u::Sayfa_Say�s�()
{
	int  sayfa_say�s� = 0;
	cout << "Yazd�rmak istedi�iniz sayfa say�s�n� giriniz: ";
	cin >> sayfa_say�s�;
	while (sayfa_say�s� < 0)
	{
		system("cls");
		cout << "Yazd�rmak istedi�iniz sayfa say�s�n� giriniz: ";
		cin >> sayfa_say�s�;
	}
	ptr[rear].sayfa_sayisi = sayfa_say�s�;
	if (sayfa_say�s� > 10)
	{
		count1++;
	}
	else
	{
		count2++;
	}
	sum += sayfa_say�s�;
}
/**
* @brief : Bu fonksiyon s�raya eklenen belgenin rengini kullan�c�dan al�r.
* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
*/
void Yaz�c�_Kuyru�u::Renk()
{
	cout << "Belge renkli mi olsun siyah beyaz m�? (Renkli) / (Siyah) ";
	cin >> ptr[rear].renk;
	while (ptr[rear].renk != "renkli"  && ptr[rear].renk != "siyah")
	{
		system("cls");
		cout << "Belge renkli mi olsun siyah beyaz m�? (renkli) / (siyah) ";
		cin >> ptr[rear].renk;
	}
	if (ptr[rear].renk == "renkli")
	{
		renk1++;
	}
	else
	{
		renk2++;
	}
}
/**
* @brief : Bu fonksiyon kullan�c�dan ald��� bilgileri bir yap�da tutar ve s�ran�n sonuna ekler
* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
*/
void Yaz�c�_Kuyru�u::Ekle()
{
	if (S�ra_Dolumu())
	{
		cout << "Yaz�c�da bo� yer yok" << endl;
	}
	else
	{
		int say� = 0;
		cout << "Yazd�rmak istedi�iniz belge numaras�n� giriniz: ";
		cin >> say�;
		ptr[rear].say� = say�;
		Sayfa_Say�s�();
		Renk();
		rear++;
		p++;
	}
}
/**
* @brief : Bu fonksiyon s�radaki eleman�n sayfa say�s�n�n ka��n�n 10'dan b�y�k ka��n�n 10'dan k���k oldu�unu,
* s�radaki belgelerin toplam sayfa say�s�n�, ortalama sayfa say�s�n�, renkli belge say�s�n� ve siyah beyaz belge say�s�n� yazd�r�r. 
* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
*/
void Yaz�c�_Kuyru�u::�statistik()
{
	cout << "Sayfa say�s� 10'dan b�y�k olan belge say�s�: " << count1 << endl;
	cout << "Sayfa say�s� 10 ve 10'dan k���k olan belge say�s�: " << count2 << endl << endl;
	cout << "Toplam sayfa say�s�: " << sum << endl;
	if (Say() == 0)
	{
		cout << "Ortalama sayfa say�s�: 0" << endl << endl;
	}
	else
	{
		cout << "Ortalama sayfa say�s�: " << sum / Say() << endl << endl;
	}
	cout << "Renkli belge say�s�: " << renk1 << endl;
	cout << "Siyah Beyaz belge say�s�: " << renk2 << endl << endl;
}
/**
* @brief : Bu fonksiyon s�radaki elemanlar� eklenme s�ras�na g�re listeler.
* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
*/
void Yaz�c�_Kuyru�u::Listele()const
{
	int counter = 1;
	for (int i = first; i < p; i++)
	{
		cout << counter << ".belge: " << ptr[i].say� << "------Sayfa Say�s�: " << ptr[i].sayfa_sayisi << "------Rengi: " << ptr[i].renk << endl;
		counter++;
	}
}
/**
* @brief : Bu fonksiyon s�raya eklenme s�ras�na g�re eklenen ilk eleman� siler.
* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
*/
void Yaz�c�_Kuyru�u::Sil()
{
	if (S�ra_Bo�mu())
	{
		cout << "Yaz�c�da bekleyen belge yok" << endl;
	}
	else
	{
		cout << "Silinen belge : " << ptr[first].say� << " Sayfa Say�s� : " << ptr[first].sayfa_sayisi << " Rengi: "<< ptr[first].renk << endl;
		sum -= ptr[first].sayfa_sayisi;
		if (ptr[first].sayfa_sayisi > 10)
		{
			count1--;
		}
		else
		{
			count2--;
		}
		if (ptr[first].renk == "renkli")
		{
			renk1--;
		}
		else
		{
			renk2--;
		}
		ptr[first].say� = 0;
		first++;
	}

}
/**
* @brief : Bu fonksiyon s�radan silinen elemanlar�n kaplad��� yeri elemanlar� kayd�rarak gereksiz alan kullan�m�n� azalt�r.
* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
*/
void Yaz�c�_Kuyru�u::Toparla() 
{
	if (first == 0)
		return ;
	for (int i = 0; i < size; i++)
	{
		ptr[i].say� = ptr[i + 1].say�;
		ptr[i].sayfa_sayisi = ptr[i + 1].sayfa_sayisi;
	}
	rear -= first;
	first = 0;
	p--;
}
/**
* @brief : Bu fonksiyon menuyu acar ve istenen fonkisiyona yonlendirir.
* @see main() : Fonksiyonun hangi amacla cagr�ld�g�n� inceleyiniz.
*/
void Menu()
{
	Yaz�c�_Kuyru�u N;
	char choose;
	do
	{
		system("cls");
		cout << "\n\n\n\t---------ANA MEN�---------\n\n";
		cout << "\n\t [E] - Ekle";
		cout << "\n\t [�] - �statistikler";
		cout << "\n\t [S] - Sil";
		cout << "\n\t [B] - Boyu";
		cout << "\n\t [L] - Listele";
		cout << "\n\t [C] - ��k��";
		cout << "\t\n\n\n��lemi Se�iniz: ";

		choose = _getch();
		system("cls");
		if (choose == 'E' || choose == 'e')
		{
			N.Ekle();
			system("pause");
		}

		if (choose == '�' || choose == 'i')
		{
			N.�statistik();
			system("pause");
		}

		if (choose == 'S' || choose == 's')
		{
			N.Sil();
			N.Toparla();
			system("pause");
		}
		if (choose == 'B' || choose == 'b')
		{
			cout << "Yaz�c�da bekleyen belge say�s� --> " << N.Say() << endl;
			system("pause");
		}
		if (choose == 'L' || choose == 'l')
		{
			N.Listele();
			system("pause");
		}
		if (choose == 'C' || choose == 'c')
		{
			exit(0);
		}
	} while (choose != 'C' || choose != 'c');
}