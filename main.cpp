#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int choice = 6;
class Klient
{
public:
	string name, surname, email;
	int phone;
	void wczytaj()
	{
		cout << "podaj imie" << endl;
		cin >> name;
		cout << "podaj nazwisko" << endl;
		cin >> surname;
		cout << "podaj email" << endl;
		cin >> email;
		cout << "podaj telefon" << endl;
		cin >> phone;

	}
	Klient();
	Klient(string m, string n, string e, int p)
	{
		m = name;
		n = surname;
		e = email;
		p = phone;
	}

};

class Rezerwacja : public Klient
{

	int nr_ref;
	int reservation;
	int arrival;
	string type;
	string uwagi;
public:


	void Type()
	{

		cout << "a,b,c,d,e,f" << endl;
		switch (choice)
		{
		case 1:
			type = 290;
			cout << type;
			break;
		case 2:
			type = 330;
			cout << type;
			break;
		case 3:
			type = 410;
			cout << type;
			break;
		case 4:
			type = 450;
			cout << type;
			break;
		case 5:
			type = 510;
			cout << type;
			break;
		case 6:
			type = 520;
			cout << type;
			break;

		}

	}

	void Stworz()
	{
		Klient::wczytaj();
		cout << nr_ref << endl;
		cout << "ilosæ pobytu" << endl;
		cin >> reservation;
		cout << "arrival" << endl;
		cin >> arrival;
		cout << "wybierz typ" << endl;
		Rezerwacja::Type();
		cout << "uwagi" << endl;
		cin >> uwagi;
	}
	Rezerwacja();
	Rezerwacja(int f, int h, int b, string jp, string jg, string qw, string we, string er, int t)
		:Klient(qw, we, er, t)
	{
		f = nr_ref;
		h = reservation;
		b = arrival;
		jp = type;
		jg = uwagi;
	}


};

int main()
{
	Rezerwacja d1;
	d1.Stworz();

}