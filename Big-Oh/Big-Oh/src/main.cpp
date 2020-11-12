/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 1 Ekim 2019 Salı
* @brief The program is a simulation of listing the scores.
* and statistics of a given assignment in a class and changing an incorrectly entered grade if necessary.
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<locale.h>
#include<conio.h>
#include<time.h>
using namespace std;
typedef struct Student
{
	string name;
	int id;
	int graade;
}Student;
/**
* @brief : This function opens the menu and leads to the desired function.
* @see main() : Review what function is called.
*/
void Menu(Student *p, int n);
/**
* @brief : This function takes a random number from the computer and prints a random name in the string.
* @param *p : Is the student object created in the structure.
* @param n : Total number of students in the classroom.
* @see main() : Review what function is called.
*/
void getdata_name(struct Student *p, int n)
{
	string alphabets = { "abcdefghijklmnopqrstuvwxyz" };
	for (int i = 0; i < n; i++)
	{
		int k = rand() % 4 + 5;
		for (int j = 0; j < k; j++)
		{
			p->name += alphabets[rand() % 26];
		}
		p++;
	}
}
/**
* @brief : This function takes a random number from the computer and prints a random id number in the list.
* Then assigns the number of all the elements in the list by increasing the number.
* And it takes a random number from the computer and prints a random note in the list.
* @param *p : Is the student object created in the structure.
* @param n : Total number of students in the classroom.
* @see main() : Review what function is called.
*/
void getdata_id_graade(struct Student *p, int n)
{
	int counter = rand() % 9 + 1;
	counter = counter * 12345 + rand() % 99;
	for (int i = 0; i < n; i++)
	{
		p->graade = rand() % 100;
		p->id = counter;
		counter++;
		p++;
	}
}
/**
* @brief : This function writes the values ​​in the structure with a pointer.
* @param *p : Is the student object created in the structure.
* @param n : Total number of students in the classroom.
* @see main() : Review what function is called.
*/
void printdata(struct Student *p, int n)
{
	int i;
	cout << endl << endl;
	cout << left << setw(30) << "Öğrenci Numarası";
	cout << left << setw(30) << "Öğrenci İsmi";
	cout << left << setw(30) << "Öğrenci Notu";
	cout << endl;
	cout << left << setw(30) << "-------------";
	cout << left << setw(30) << "-------------";
	cout << left << setw(30) << "-------------";
	cout << endl;

	for (i = 0; i < n; i++)
	{
		cout << left << setw(30) << p->id;
		cout << left << setw(30) << p->name;
		cout << left << setw(30) << p->graade;
		cout << endl;
		p++;
	}
}
/**
* @brief : This function sorts the data in the list.
* @param *p : Is the student object created in the structure.
* @param n : Total number of students in the classroom.
* @see main() : Review what function is called.
*/
void Sort(struct Student *p, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (p[j].graade < p[j + 1].graade)
			{
				swap(p[j], p[j + 1]);
			}
		}
	}
}
/**
* @brief : This function finds and prints the smallest and largest values ​​in the list. It also finds the average of the numbers in the list.
* @param *p : Is the student object created in the structure.
* @param n : Total number of students in the classroom.
* @see main() : Review what function is called.
*/
void Min_Max_Ort(struct Student *p, int n)
{
	int sum = 0;
	int min = p[0].graade;
	int max = p[0].graade;
	for (int i = 0; i < n; i++)
	{
		if (min >= p[i].graade)
		{
			min = p[i].graade;
		}
		if (max <= p[i].graade)
		{
			max = p[i].graade;
		}
		sum += p[i].graade;
	}
	for (int i = 0; i < n; i++)
	{
		if (min == p[i].graade)
		{
			cout << "Minimum: " << min << " (No: " << p[i].id << "  İsim: " << p[i].name << ")" << endl;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (max == p[i].graade)
		{
			cout << "Maksimum: " << max << " (No: " << p[i].id << "  İsim: " << p[i].name << ")" << endl;
		}
	}
	float avg = (float)sum / n;
	cout << "Ortalma: " << avg << endl;
	cout << "İstatistik menüsüne dönmek için herangi bir tuşa basınız." << endl;
	system("pause");
}
/**
* @brief : This function displays the student information in a selected row.
* @param *p : Is the student object created in the structure.
* @param n : Total number of students in the classroom.
* @see main() : Review what function is called.
*/
void K_Big(struct Student *p, int n)
{
	Sort(p, n);
	int k, temp = 0;
	while (true)
	{
		cout << "K'nın değerini girin: ";
		cin >> k;
		bool Attention;
		Attention = cin.fail();
		if (Attention)
		{
			cout << "Hatalı giriş yaptınız programı yeniden başlatınız." << endl;
			system("pause");
			exit(0);
		}
		if (0 < k && k <= n)
		{
			temp = p[k - 1].graade;
			for (int i = 0; i < n; i++)
			{
				if (temp == p[i].graade)
				{
					cout << i + 1 << ". kişinin notu: " << p[i].graade << " (No: " << p[i].id << "  İsim: " << p[i].name << ")" << endl;
				}
			}
			cout << "İstatistik menüsüne dönmek için herangi bir tuşa basınız." << endl;
			system("pause");
			break;
		}
		else
		{
			cout << "Sınıf mevcudundan farklı sayı girdiniz lütfen tekrar deneyin." << endl;
		}
	}
}
/**
* @brief : This function opens the statistics menu.
* @param *p : Is the student object created in the structure.
* @param n : Total number of students in the classroom.
* @see main() : Review what function is called.
*/
void statistics(Student *p, int n)
{
	char choose;
	do
	{
		system("cls");
		cout << "\n\t [M] - Min-Max-Ort";
		cout << "\n\t [K] - K. En Buyuk";
		cout << "\n\t [A] - Ana menu";
		cout << "\n\t [Q] - Cikis";
		cout << "\t\n\n\nIslemi Seciniz: ";
		choose = _getch();
		system("cls");
		if (choose == 'M' || choose == 'm')
		{
			Min_Max_Ort(p, n);
		}
		if (choose == 'K' || choose == 'k')
		{
			K_Big(p, n);
		}
		if (choose == 'A' || choose == 'a')
		{
			Menu(p, n);
		}
		if (choose == 'Q' || choose == 'q')
		{
			exit(0);
		}
	} while (choose != 'Q' || choose != 'q');
}
/**
* @brief : This function changes the grade of the selected student.
* @param *p : Is the student object created in the structure.
* @param n : Total number of students in the classroom.
* @see main() : Review what function is called.
*/
void change(Student *p, int n)
{
	system("cls");
	cout << "--- Not Değiştirme ---" << endl << endl;
	printdata(p, n);
	cout << "Ogrencinin, " << endl;
	cout << "Numarasını giriniz: ";
	int No = 0, graadee = 0;
	cin >> No;
	bool Attention;
	Attention = cin.fail();
	if (Attention)
	{
		cout << "Hatalı giriş yaptınız programı yeniden başlatınız." << endl;
		system("pause");
		exit(0);
	}
	int i = 0;
	while (i < n)
	{
		if (No == p[i].id)
		{
			cout << "Öğrenci Bilgileri" << " Grade: " << p[i].graade << " No: " << p[i].id << "  İsim: " << p[i].name << ")" << endl;
			cout << "Yeni notu giriniz." << endl;
			cin >> graadee;
			p[i].graade = graadee;
			break;
		}
		i++;
	}
	cout << "Ana menüye yönlendiriliyorsunuz bir tuşa basın..." << endl;
	system("pause");
}
/**
* @brief : This function takes the number of students from the user.
* And it sends the entered value to the corresponding functions.
* @see main() : Review what function is called.
*/
void Size()
{
	try
	{
		int n;
		cout << "Toplam ögrenci sayısını giriniz." << endl;
		cin >> n;
		struct Student* p = new struct Student[n];
		if (p)
		{
			getdata_name(p, n);
			getdata_id_graade(p, n);
			Menu(p, n);
		}
		else
		{
			cout << "Bellek Yetersiz!" << endl;
			exit(0);
		}
	}
	catch (const std::exception&)
	{
		cout << "Hatali giris yaptiniz" << endl;
		Size();
	}
}
int main()
{
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));
	Size();
	system("pause");
}
void Menu(Student *p, int n)
{
	char choose;
	do
	{
		system("cls");
		cout << "\n\n\n\t---------ANA MENÜ---------\n\n";
		cout << "\n\t [D] - Değiştir";
		cout << "\n\t [I] - İstatistik";
		cout << "\n\t [L] - Listeleme";
		cout << "\n\t [Q] - Çıkış";
		cout << "\t\n\n\nİşlemi Seçiniz: ";

		choose = _getch();
		system("cls");
		if (choose == 'D' || choose == 'd')
		{
			change(p, n);
		}
		if (choose == 'i' || choose == 'I')
		{
			statistics(p, n);
		}
		if (choose == 'L' || choose == 'l')
		{
			printdata(p, n);
			cout << "Ana menüye dönmek için bir tuşa basınız..." << endl;
			system("pause");
		}
		if (choose == 'Q' || choose == 'q')
		{
			exit(0);
		}
	} while (choose != 'Q' || choose != 'q');
}
