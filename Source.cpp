#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <fstream>
using namespace std;
class Book
{
public:
	char genre[20];
	char name[20];
	char year[10];
	char author[20];
	char about[40];
	Book Vvod();
	void Show(Book tmp);
	Book* Add(Book* mas, int& n)
	{
		mas = (Book*)realloc(mas, (n + 1) * sizeof(Book));
		mas[n] = Vvod();
		n++;
		return mas;
	}

	void Print(Book* mas, int n)
	{
		for (int i = 0; i < n; i++)
		{
			Show(mas[i]);
			cout << "\n";
		}
	}
	Book* Del(Book* mas, int& n)
	{
		char str[30];
		cout << "Vvedite name filma: ";
		gets_s(str);
		int f = 0;
		for (int i = 0; i < n; i++)
		{
			if (_stricmp(mas[i].name, str) == 0)
			{
				for (int j = i; j < n - 1; j++)
					mas[j] = mas[j + 1];
				mas = (Book*)realloc(mas, (n - 1) * sizeof(Book));
				n--;
				i--;
				f = 1;
			}
		}
		if (f == 0)
		{
			cout << "Error.\n";
		}
		else
		{
			cout << "Playlist - delete.\n";
		}
		return mas;
	}
	void Write(Book* mas)
	{
		ofstream out;
		out.open("text.txt", ios::app);
		if (out.is_open())
		{
			out << mas;
		}
		else { cout << "Error"; }
	}
};
Book Book::Vvod()
{
	Book tmp;
	cout << "Enter genre : ";
	gets_s(tmp.genre);
	cout << "Enter movie title : ";
	gets_s(tmp.name);
	cout << "Enter year : ";
	cin >> tmp.year;
	cin.ignore();
	cout << "Enter author : ";
	gets_s(tmp.author);
	cout << "Enter short description : ";
	gets_s(tmp.about);
	return tmp;

}
inline void Book::Show(Book tmp)
{
	cout << "Genre : " << tmp.genre << " \n " << "Title : " << tmp.name << "\n" << "Year : " << tmp.year<<"\nAuthor : "<<tmp.author<<"\nAbout : "<<tmp.about << endl;
}
int main()
{
	Book* baza = nullptr;
	Book x;
	int n = 0;
	char ch;
	do
	{
		
		system("cls");
		cout << "Menu.\n";
		cout << "1 - Add book.\n";
		cout << "2 - Vivod .\n";
		cout << "3 - Delete book .\n";
		cout << "4 - Examination .\n";
		cout << "Esc - Vihod.\n";
		cout << "Vash vibor: ";
		ch = _getch();
		switch (ch)
		{
		case '1':
			system("cls");
			baza = x.Add(baza, n);
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "\nSuccessful addition !";
			this_thread::sleep_for(chrono::milliseconds(2000));
			break;
		case '2':
			system("cls");
			cout << "Wait - data processing:)\n";
			this_thread::sleep_for(chrono::milliseconds(3000));
			if (n != 0)
			{
				x.Print(baza, n);
			}
			else
			{
				cout << "Baza danih pusta.\n";
			}
			system("pause");
			break;
		case '3':
			system("cls");
			if (n != 0)
			{
				baza = x.Del(baza, n);
			}
			else
			{
				cout << "Baza danih pusta.\n";
			}
			system("pause");
			break;
		case '4':
			system("cls");
			cout << "Wait - recording in progress";
			this_thread::sleep_for(chrono::seconds(30));
			x.Write(baza);
			cout << "\nSuccessfully !!!!";
			this_thread::sleep_for(chrono::seconds(2));
			system("pause");
			break;
		}
	} while (ch != 27);
	free(baza);
}
