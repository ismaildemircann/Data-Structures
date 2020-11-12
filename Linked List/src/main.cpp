/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 20 Ekim 2019 Pazar
* @brief Bu program ilgili veri
* yapis�i fonksiyonlarin�in test uygulamasi niteligindedir. Pointer tabanli listenin
* verisi tam sayilardan olusmaktadir. Program menu uzerine kuruludur. 
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<locale.h>
#include<conio.h>
using namespace std;
typedef struct Element {
	int value;
	Element * next;
}node;
/**
* @brief : Bu fonksiyon menuyu acar ve istenen fonkisiyona yonlendirir.
* @see main() : Fonksiyonun hangi amacla cagr�ld�g�n� inceleyiniz.
*/
void Menu();
/**
* @brief : Bu fonksiyon listeyi bastan sona tarayarak toplam eleman sayisini hesaplar ve dondurur.
* @param h : Listenin baslang�c elemeni.
* @see main() : Fonksiyonun hangi amacla cagrild�igini inceleyiniz.
*/
int Say(node * h)
{
	node * iter = h;
	int counter = 0;
	while (iter->next != NULL)
	{
		iter = iter->next;
		counter++;
	}
	return counter;
}
/**
* @brief : Bu fonksiyon kullanicidan istenen sayiyi varsayilan olarak listenin sonuna ekler.
* @param h : Listenin baslang�c elemen�.
* @see main() : Fonksiyonun hangi amacla cagrildigini inceleyiniz.
*/
void Ekle(node * h)
{
	int k;
	cout << "Eklemek istedi�iniz say�y� giriniz." << endl;
	cin >> k;
	while (h->next != NULL)
	{
		h = h->next;
	}
	h->next = (node *)malloc(sizeof(node));
	h->next->value = k;
	h->next->next = NULL;
}
/**
* @brief : Bu fonksiyon kullanicidan istenen sayiyi, benzer sekilde kullanicidan istenen pozisyon
* degerine gore listenin uygun kismina yerlestirir.
* @param h : Listenin baslang�c elemeni.
* @see main() : Fonksiyonun hangi amacla cagrildigini inceleyiniz.
*/
void Araya_Ekle(node * h)
{
	node * iter = h;
	int k, n, counter;
	cout << "Eklemek istedi�iniz say�n�n pozisyon de�erini giriniz: ";
	cin >> n;
	counter = Say(h);
	if (n > 0 && n < counter)
	{
		cout << "Eklemek istedi�ihiz say�y� giriniz: ";
		cin >> k;
		for (int i = 1; i < n; i++)
		{
			iter = iter->next;
		}
		node * temp = (node *)malloc(sizeof(node));
		temp->next = iter->next;
		iter->next = temp;
		temp->value = k;
	}
	else
	{
		system("cls");
		Araya_Ekle(h);
	}
}
/**
* @brief : Bu fonksiyon kullanicidan istenen sayiyi liste icinde tarar; varsa listeden siler, listede
* yoksa kullaniciyi bilgilendirir. Birden fazla olmasi durumunda tumunu silip koku geri dondurur.
* @param h : Listenin baslang�c elemeni.
* @param k : Silinmek istenen deger.
* @see main() : Fonksiyonun hangi amacla cagrildigini inceleyiniz.
*/
node * Sil(node * h, int k)
{
	int counter = 0;
	node * iter = h;
	node * temp;
	if (h->value == k)
	{
		temp = h;
		h = h->next;
		free(temp);
		return h;
	}
	while (iter->next != NULL)
	{
		if (iter->next->value == k)
		{
			counter++;
		}
		iter = iter->next;
	}
	iter = h;
	for (int i = 0; i < counter; i++)
	{
		while (iter->next != NULL && iter->next->value != k)
		{
			iter = iter->next;
		}
		if (iter->next == NULL)
		{
			cout << "Arada��n�z say� bulunamad�." << endl;
			return h;
		}
		temp = iter->next;
		iter->next = iter->next->next;
		free(temp);
	}
	return h;
}
/**
* @brief : Bu fonksiyon belirli bir noktadan itibaren coklu siler. Kullanicidan istenen say� degeri, ve
* kullanicidan istenen pozisyon degerine gore silme islemi gerceklestirir.
* @param h : Listenin baslang�c elemeni.
* @param n : Listede silinmek istenen baslang�c konumu.
* @param a : Silinmek istenilen eleman sayisi.
* @see main() : Fonksiyonun hangi amacla cagrildigini inceleyiniz.
*/
void B_Sil(node * h, int n, int a)
{
	node * iter = h;
	node * temp;
	for (int i = 1; i < n; i++)
	{
		iter = iter->next;
	}
	for (int i = 0; i < a; i++)
	{
		temp = iter->next;
		iter->next = iter->next->next;
		free(temp);
	}
}
/**
* @brief : Bu fonksiyon listeyi kullanicinin girdigi bag numarasindan ikiye boler ve iki alt liste de
* ekranda ayri ayri gosterir. Daha sonra kullanic�nin hangi parcay� ana liste
* olarak kullanmak istedigine gore diger listeyi siler.
* @param h : Listenin ba�lang�� elemen�.
* @see main() : Fonksiyonun hangi amacla cagrildigini inceleyiniz.
*/
void B�l(node * h)
{
	int counter = 0;
	node * iter = h->next;
	int a, k;
	cout << "B�lmek istedi�iniz ba�� giriniz: ";
	cin >> a;
	counter = Say(h);
	if (a >= 0 && a < counter)
	{
		cout << "1.liste" << endl;
		node * temp1 = h;
		for (int i = 1; i <= a; i++)
		{
			cout << iter->value << " ";
			iter = iter->next;
		}
		node * temp2 = iter;
		cout << endl << "2.liste" << endl;
		for (int i = a + 1; i <= counter; i++)
		{
			cout << iter->value << " ";
			iter = iter->next;
		}
		cout << endl << "Hangi liste ile devam etmek ist�yorssun(1-2): ";
		cin >> k;
		if (k == 1 || k == 2)
		{
			if (k == 1)
			{
				h = temp1;
				B_Sil(h, a + 1, counter - a);
			}
			if (k == 2)
			{
				B_Sil(h, 0, a);
				h->next = temp2;
				h = NULL;
			}
		}
		else
		{
			system("cls");
			B�l(h);
		}
	}
	else
	{
		system("cls");
		B�l(h);
	}
}
/**
* @brief : Bu fonksiyon listenin elemanlarini eklenme sirasina gore ekranda listeler.
* @param h : Listenin baslang�c elemeni.
* @see main() : Fonksiyonun hangi amacla cagrildigini inceleyiniz.
*/
void Listele(node * h)
{
	while (h != NULL)
	{
		cout << h->value << " ";
		h = h->next;
	}
}
int main()
{
	setlocale(LC_ALL, "Turkish");
	Menu();
	system("pause");
}
void Menu()
{
	node *head = NULL;
	head = (node *)malloc(sizeof(node));
	head->next = NULL;
	head->value = 0;
	char choose;
	do
	{
		system("cls");
		cout << "\n\n\n\t---------ANA MEN�---------\n\n";
		cout << "\n\t [E] - Ekle";
		cout << "\n\t [A] - Araya Ekle";
		cout << "\n\t [S] - Sil";
		cout << "\n\t [D] - Belirtilen Noktadan Sonra �oklu Sil";
		cout << "\n\t [B] - B�l";
		cout << "\n\t [L] - Listele";
		cout << "\n\t [F] - Say";
		cout << "\n\t [C] - ��k��";
		cout << "\t\n\n\n��lemi Se�iniz: ";

		choose = _getch();
		system("cls");
		if (choose == 'E' || choose == 'e')
		{
			Ekle(head);
			system("pause");
		}
		if (choose == 'A' || choose == 'a')
		{
			Araya_Ekle(head);
			system("pause");
		}
		if (choose == 'S' || choose == 's')
		{
			int k;
			cout << "Silmek istedi�ihiz say�y� giriniz: ";
			cin >> k;
			head = Sil(head, k);
			system("pause");
		}
		if (choose == 'D' || choose == 'd')
		{
			int counter = 0, n, a;
			cout << "Silmek istedi�iniz say�n�n pozisyon de�erini giriniz: ";
			cin >> n;
			counter = Say(head);
			if (n > counter || n < 0)
			{
				system("cls");
				cout << "Girdi�iniz pozizyonda bir de�er yok. Bir tu�a bas�p men�ye d�n�p tekrar giriniz..." << endl;
				system("pause");
			}
			else
			{
				cout << "Ka� adet silmek istiyorsunuz: ";
				cin >> a;
				if (a > counter - n + 1 || a < 0)
				{
					system("cls");
					cout << "Liste boyutunu a�t�n�z. Bir tu�a bas�p men�ye d�n�p tekrar giriniz..." << endl;
					system("pause");
				}
				else
				{
					B_Sil(head, n, a);
					system("pause");
				}
			}
		}
		if (choose == 'B' || choose == 'b')
		{
			B�l(head);
			system("pause");
		}
		if (choose == 'F' || choose == 'f')
		{
			cout << "Listedeki eleman say�s�: " << Say(head) << endl;
			system("pause");
		}
		if (choose == 'L' || choose == 'l')
		{
			Listele(head->next);
			system("pause");
		}
		if (choose == 'C' || choose == 'c')
		{
			exit(0);
		}
	} while (choose != 'C' || choose != 'c');
}
