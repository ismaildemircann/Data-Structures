/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 3 Kasým Ekim 2019 Pazar
* @brief Bu program bir yazýcý senaryo uygulamasýdýr.
* Similasyonda bir yazýcý kuyruðu oluþturuluyor ve kullanýcýdan sýrada bekleyen belge ile ilgili gerekli bilgiler alýp
* bunu bir istatistik alt menüsü altýnda sunuyor. Sýradan istediðiniz zaman sýradaki elammaný çýkarýp sýraya yeni elaman ekleyebiliyorsunuz.
*/
#include"Queue.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<locale.h>
#include<conio.h>
using namespace std;
/**
* @param first : Sýrarnýn önü.
* @param rear : Sýranýn arkasý.
* @param p : Sýradaki eleman sayýsý.
* @param count1 : Sayfa sayýsý 10'dan büyük olan belgeleri sayan sayaç.
* @param count2 : Sayfa sayýsý 10'dan küçük olan belgeleri sayan sayaç.
* @param sum : Sýradaki belgelerin toplam sayfa sayýsý.
* @param renk1 : Sýradaki belgelerin renkli olanlarýný sayan sayaç.
* @param renk2 : Sýradaki belgelerin siyah olanlarýný sayan sayaç.
*/
Yazýcý_Kuyruðu::Yazýcý_Kuyruðu()
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
Yazýcý_Kuyruðu::~Yazýcý_Kuyruðu()
{
}
/**
* @brief : Bu fonksiyon sýrada toplam kaç eleman olduðunu hesaplar ve döndürür.
* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
*/
int Yazýcý_Kuyruðu::Say()
{
	return p - first;
}
/**
* @brief : Bu fonksiyon sýraya eleman eklemek istendiðinde yer olup olmadýðýný döndürür.
* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
*/
bool Yazýcý_Kuyruðu::Sýra_Dolumu()
{
	if (first == ((rear + 1) % (size + 1)))
	{
		return true;
	}
	return false;
}
/**
* @brief : Bu fonksiyon sýradan eleman silinmek istendiðinde boþ olup olmadýðýný döndürür.
* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
*/
bool Yazýcý_Kuyruðu::Sýra_Boþmu()
{
	if (first == rear)
	{
		return true;
	}
	return false;
}
/**
* @brief : Bu fonksiyon sýraya eklenen belgenin sayfa sayýsýný kullanýcýdan alýr.
* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
*/
void Yazýcý_Kuyruðu::Sayfa_Sayýsý()
{
	int  sayfa_sayýsý = 0;
	cout << "Yazdýrmak istediðiniz sayfa sayýsýný giriniz: ";
	cin >> sayfa_sayýsý;
	while (sayfa_sayýsý < 0)
	{
		system("cls");
		cout << "Yazdýrmak istediðiniz sayfa sayýsýný giriniz: ";
		cin >> sayfa_sayýsý;
	}
	ptr[rear].sayfa_sayisi = sayfa_sayýsý;
	if (sayfa_sayýsý > 10)
	{
		count1++;
	}
	else
	{
		count2++;
	}
	sum += sayfa_sayýsý;
}
/**
* @brief : Bu fonksiyon sýraya eklenen belgenin rengini kullanýcýdan alýr.
* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
*/
void Yazýcý_Kuyruðu::Renk()
{
	cout << "Belge renkli mi olsun siyah beyaz mý? (Renkli) / (Siyah) ";
	cin >> ptr[rear].renk;
	while (ptr[rear].renk != "renkli"  && ptr[rear].renk != "siyah")
	{
		system("cls");
		cout << "Belge renkli mi olsun siyah beyaz mý? (renkli) / (siyah) ";
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
* @brief : Bu fonksiyon kullanýcýdan aldýðý bilgileri bir yapýda tutar ve sýranýn sonuna ekler
* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
*/
void Yazýcý_Kuyruðu::Ekle()
{
	if (Sýra_Dolumu())
	{
		cout << "Yazýcýda boþ yer yok" << endl;
	}
	else
	{
		int sayý = 0;
		cout << "Yazdýrmak istediðiniz belge numarasýný giriniz: ";
		cin >> sayý;
		ptr[rear].sayý = sayý;
		Sayfa_Sayýsý();
		Renk();
		rear++;
		p++;
	}
}
/**
* @brief : Bu fonksiyon sýradaki elemanýn sayfa sayýsýnýn kaçýnýn 10'dan büyük kaçýnýn 10'dan küçük olduðunu,
* sýradaki belgelerin toplam sayfa sayýsýný, ortalama sayfa sayýsýný, renkli belge sayýsýný ve siyah beyaz belge sayýsýný yazdýrýr. 
* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
*/
void Yazýcý_Kuyruðu::Ýstatistik()
{
	cout << "Sayfa sayýsý 10'dan büyük olan belge sayýsý: " << count1 << endl;
	cout << "Sayfa sayýsý 10 ve 10'dan küçük olan belge sayýsý: " << count2 << endl << endl;
	cout << "Toplam sayfa sayýsý: " << sum << endl;
	if (Say() == 0)
	{
		cout << "Ortalama sayfa sayýsý: 0" << endl << endl;
	}
	else
	{
		cout << "Ortalama sayfa sayýsý: " << sum / Say() << endl << endl;
	}
	cout << "Renkli belge sayýsý: " << renk1 << endl;
	cout << "Siyah Beyaz belge sayýsý: " << renk2 << endl << endl;
}
/**
* @brief : Bu fonksiyon sýradaki elemanlarý eklenme sýrasýna göre listeler.
* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
*/
void Yazýcý_Kuyruðu::Listele()const
{
	int counter = 1;
	for (int i = first; i < p; i++)
	{
		cout << counter << ".belge: " << ptr[i].sayý << "------Sayfa Sayýsý: " << ptr[i].sayfa_sayisi << "------Rengi: " << ptr[i].renk << endl;
		counter++;
	}
}
/**
* @brief : Bu fonksiyon sýraya eklenme sýrasýna göre eklenen ilk elemaný siler.
* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
*/
void Yazýcý_Kuyruðu::Sil()
{
	if (Sýra_Boþmu())
	{
		cout << "Yazýcýda bekleyen belge yok" << endl;
	}
	else
	{
		cout << "Silinen belge : " << ptr[first].sayý << " Sayfa Sayýsý : " << ptr[first].sayfa_sayisi << " Rengi: "<< ptr[first].renk << endl;
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
		ptr[first].sayý = 0;
		first++;
	}

}
/**
* @brief : Bu fonksiyon sýradan silinen elemanlarýn kapladýðý yeri elemanlarý kaydýrarak gereksiz alan kullanýmýný azaltýr.
* @see main() : Fonksiyonun hangi amacla cagrildýigini inceleyiniz.
*/
void Yazýcý_Kuyruðu::Toparla() 
{
	if (first == 0)
		return ;
	for (int i = 0; i < size; i++)
	{
		ptr[i].sayý = ptr[i + 1].sayý;
		ptr[i].sayfa_sayisi = ptr[i + 1].sayfa_sayisi;
	}
	rear -= first;
	first = 0;
	p--;
}
/**
* @brief : Bu fonksiyon menuyu acar ve istenen fonkisiyona yonlendirir.
* @see main() : Fonksiyonun hangi amacla cagrýldýgýný inceleyiniz.
*/
void Menu()
{
	Yazýcý_Kuyruðu N;
	char choose;
	do
	{
		system("cls");
		cout << "\n\n\n\t---------ANA MENÜ---------\n\n";
		cout << "\n\t [E] - Ekle";
		cout << "\n\t [Ý] - Ýstatistikler";
		cout << "\n\t [S] - Sil";
		cout << "\n\t [B] - Boyu";
		cout << "\n\t [L] - Listele";
		cout << "\n\t [C] - Çýkýþ";
		cout << "\t\n\n\nÝþlemi Seçiniz: ";

		choose = _getch();
		system("cls");
		if (choose == 'E' || choose == 'e')
		{
			N.Ekle();
			system("pause");
		}

		if (choose == 'Ý' || choose == 'i')
		{
			N.Ýstatistik();
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
			cout << "Yazýcýda bekleyen belge sayýsý --> " << N.Say() << endl;
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