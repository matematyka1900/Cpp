#include <iostream>
#include <vector>
#include <fstream>
#include <atlbase.h>

#define SIZE 70
using namespace std;

char A = '[';
char B = ']';
char F = '~'; ////negacja
char V = 'V';	//// alternatywa
char K = '^';	///koniunkcja
char I = '>';	///implikacja
string R = "<=>"; ///równoważność
char p = 'p';
char q = 'q';
char r = 'r';
char a = '(';
char b = ')';

int j;
//char PQ = a + p + K + q + b;
//char PQ1 = a + p + V + q + b;
//char PQ2 = N + a + p + V + q + b;
//char PQ3 = a + N + p + V + q + b;
//char PQ4 = a + p + V + N + q + b;
//char PQ5 = a + p + K + N + q + b;
//char PQ6 = q + I + r;
//char PQ7 = a + q + V + r + b;
//char PR = a + p + K + r + b;
//char PQ8 = a + p + I + q + b;
//char PQ9 = a + q + V + r + b;



//void generuj1(string d)
//{
//	int tablica[10][10];
//	if (d.find(K) != string::npos)
//	{
//		
//		for (int i = 0; i < d.length(); i++)
//		{
//			if (d[i] == p && d[i + 2] == q)
//			{
//				
//				for (int i = 0; i < 8; i++)
//					if ((tablica[i][0] && tablica[i][1]) == true)
//						tablica[i][3] = true;
//
//					else
//						tablica[i][3] = false;
//
//			}
//		}
//			/*if (d[i + 1] == p)
//			{
//				j = 6;
//				for (int i = 0; i < 8; i++)
//					if (tablica[i][0] && tablica[i][5] == true)
//						tablica[i][j] = true;
//					else
//						tablica[i][j] = false;
//				j++;
//				
//			}
//
//		*/
//	}
//}
//
//




void generuj(int* tablica[], string s, ofstream& outputFile)
{
	ifstream file("dane.txt");
	int myArray[8];
	if (file.is_open())
	{
		

		for (int i = 0; i < 8; ++i)
		{
			file >> myArray[i];
		}
	}
	//ifstream file1("data.txt");
	//int myArray1[8];
	//if (file1.is_open())
	//{


	//	for (int i = 0; i < 8; ++i)
	//	{
	//		file1 >> myArray1[i];
	//	}
	//}
	bool czy = true;
	int i, j;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			tablica[i][j] = czy;
		}
	}
	j = 0;
	for (int i = 4; i < 8; i++)
		tablica[i][j] = false;
	tablica[2][1] = false;
	tablica[3][1] = false;
	tablica[6][1] = false;
	tablica[7][1] = false;
	tablica[1][2] = false;
	tablica[3][2] = false;
	tablica[5][2] = false;
	tablica[7][2] = false;
	//if (s.find(V) != string::npos)
	//{
	//	
	//	for (int i = 0; i < s.length(); i++)
	//	{
	//		if (s[i] == p && s[i + 2] == q)
	//		{

	//			for (int i = 0; i < 8; i++)
	//				if ((tablica[i][0] || tablica[i][1]) == true)
	//					tablica[i][3] = true;

	//				else
	//					tablica[i][3] = false;

	//		}
	//	}

	//	

	//	

	//
	//}
	if (s.find(r) != string::npos)
	{
		
		for (int i = 0; i < 8; i++)
			if (tablica[i][2] == false && myArray[i]==true)
				tablica[i][4] = false;
			else
				tablica[i][4] = true;

		

	}
	if (s.find('V') != string::npos)
	{

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == p && s[i + 2] == q)
			{

				for (int i = 0; i < 8; i++)
					if ((tablica[i][0] || tablica[i][1]) == true)
						tablica[i][3] = true;

					else
						tablica[i][3] = false;

			}
			/*if (s[i] == q && s[i + 2] == r)
			{

				for (int i = 0; i < 8; i++)
					if ((tablica[i][1] || tablica[i][2]) == true)
						tablica[i][6] = true;

					else
						tablica[i][6] = false;

			}*/
		}





	}
	if (s.find('^') != string::npos)
	{

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == p && s[i + 2] == q)
			{
				
				for (int i = 0; i < 8; i++)
					if ((tablica[i][0] && tablica[i][1]) == true)
						tablica[i][3] = true;

					else
						tablica[i][3] = false;
				
			}
		}





	}
	if (s.find("q>r") != string::npos)
	{

		for (int i = 0; i < s.length(); i++)
		{
			
		
				
					if (tablica[i][1] == true && tablica[i][2] == false)
						tablica[i][6] = false;

					else
						tablica[i][6] = true;
			
			
		}

	}

	if (s.find('~') != string::npos)
	{


		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == p)
			{
				
				for (int i = 0; i < 8; i++)
					if (tablica[i][0] == true)
						tablica[i][5] = false;

					else
						tablica[i][5] = true;
				
			}
		}






	}
	if (s.find("~p")  != string::npos && s.find("q>r") != string::npos)
	{


		for (int i = 0; i < s.length(); i++)
		{
		
			

				for (int i = 0; i < 8; i++)
					if (tablica[i][5] == true && tablica[i][6] == false)
						tablica[i][7] = false;

					else
						tablica[i][7] = true;

			
		}






	}
	if (s.find("p^(") != string::npos)
	{


		for (int i = 0; i < s.length(); i++)
		{

			for (int i = 0; i < 8; i++)
				if (tablica[i][0] == true )
					tablica[i][5] = true;

				else
					tablica[i][5] = false;


			for (int i = 0; i < 8; i++)
				if (tablica[i][5] == true && tablica[i][6] == true)
					tablica[i][7] = true;

				else
					tablica[i][7] = false;


		}






	}
	/*if (s.find("p>(") != string::npos)
	{


		for (int i = 0; i < s.length(); i++)
		{

			for (int i = 0; i < 8; i++)
				if (tablica[i][0] == true)
					tablica[i][5] = true;

				else
					tablica[i][5] = false;


			for (int i = 0; i < 8; i++)
				if (tablica[i][5] == true && tablica[i][6] == false)
					tablica[i][7] = false;

				else
					tablica[i][7] = true;


		}







	}*/
	if (s.find("q)") != string::npos)
	{

		for (int i = 0; i < 8; i++)
			if (tablica[i][0]== true && tablica[i][1] == false)
				tablica[i][4] = false;

			else
				tablica[i][4] = true;


	}
	for (int i = 0; i < 8; i++)
	{
		if (tablica[i][4] == true && tablica[i][7] == false)
		{
			tablica[i][8] = false;
		}
		else
		{
			tablica[i][8] = true;
		}


	}
	//for (int i = 0; i < s.length(); i++)
	//{
	//	if (s[i] == '^')
	//	{
	//		if (s[i - 1] == p && s[i + 1] == q)
	//		{
	//			j = 3;

	//			for (int i = 0; i < 8; i++)
	//				if ((tablica[i][0] && tablica[i][1]) == true)
	//					tablica[i][3] = true;

	//				else
	//					tablica[i][3] = false;
	//			j++;
	//		}
	//		


	//	}
	//	else if (s[i] == '>')
	//	{
	//		if (s[i + 1] == r)
	//		{
	//			j;
	//			for (int i = 0; i < 8; i++)
	//				if (tablica[i][3]==true && tablica[i][2] == false)
	//					tablica[i][j] = false;
	//				else
	//					tablica[i][j] = true;
	//			j++;
	//		}
	//		/*if (s[i - 1] == p && s[i + 1] == q)
	//		{
	//			j = 3;
	//			for (int i = 0; i < 8; i++)
	//				if (tablica[i][0] == true && tablica[i][1] == false)
	//					tablica[i][j] = false;
	//				else
	//					tablica[i][j] = true;
	//			j++;
	//		}
	//		if (s[i + 1] == r)
	//		{
	//			j;

	//			for (int i = 0; i < 8; i++)
	//				if (tablica[i][3] == true && tablica[i][2] == false)
	//					tablica[i][j] = false;
	//				else
	//					tablica[i][j] = true;
	//			j++;
	//		}
	//		if (s[i - 1] == q && s[i + 1] == r && s[i + 2] == b && s[i + 3] == K && s[i + 4] == p)
	//		{
	//			j;
	//			for (int i = 0; i < 8; i++)
	//				if (tablica[i][0] == false || tablica[i][0] == true && tablica[i][1] == true && tablica[i][2] == false)
	//					tablica[i][j] = false;

	//				else
	//					tablica[i][j] = true;
	//			j++;
	//			break;


	//		}
	//		if (s[i - 1] == q && s[i + 1] == r)
	//		{
	//			j;
	//			for (int i = 0; i < 8; i++)
	//				if (tablica[i][1] == true && tablica[i][2] == false)
	//					tablica[i][j] = false;

	//				else
	//					tablica[i][j] = true;
	//			j++;
	//			break;


	//		}*/
	//	}
	//	else if (s[i] == 'V')
	//	{
	//		j = 3;
	//		for (int i = 0; i < 8; i++)
	//			if ((tablica[i][0] || tablica[i][1]) == true)
	//				tablica[i][j] = true;
	//			else
	//				tablica[i][j] = false;
	//		j++;
	//	}
	//	else if (s[i] == '~')
	//	{

	//		if (s[i + 1] == 'p')
	//		{

	//			for (int i = 0; i < 8; i++)
	//			{
	//				j;
	//				if (tablica[i][0] == true)
	//				{
	//					tablica[i][j] = false;
	//				}
	//				else
	//				{
	//					tablica[i][j] = true;
	//				}
	//				j++;
	//			}

	//		}
	//	}

	//	/*else if (nazwa[i - 2] == '~' && nazwa[i - 1] == 'p' && nazwa[i + 1] == a)
	//	{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		if (tablica[i][5] == true && tablica[i][6] == false)
	//		{
	//			j = 7;
	//			tablica[i][j] = false;
	//		}
	//		else
	//		{
	//			j = 7;
	//			tablica[i][j] = true;
	//		}

	//	}

	//	}*/


	//}
	
	
		
		outputFile << tablica[0][3] << endl;
		outputFile << tablica[1][3] << endl;
		outputFile << tablica[2][3] << endl;
		outputFile << tablica[3][3] << endl;
		outputFile << tablica[4][3] << endl;
		outputFile << tablica[5][3] << endl;
		outputFile << tablica[6][3] << endl;
		outputFile << tablica[7][3] << endl;
		outputFile << tablica[8][3] << endl;

		
	
}



void wyswietl(int** tablica)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << tablica[i][j] << "\t";
		}
		printf("\n");
	}
	
}





int main()
{
	int n = 10, h;
	int** tab;
	tab = new int* [n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = new int[n];
	}
	string x;
	string f;
	string temp1;
	string N;
	string s;
	cin >> s;
	string temp;
	
	if (s.front() == '[')
	{
		size_t drugi = s.find(']');
		s.erase(s.begin(), s.begin() + 1);
		cout << s << endl;
		s.erase(s.begin() + drugi - 1, s.end());
		cout << s << endl;
		size_t trzeci = s.find('(');
		size_t czwarty = s.find(')');
		s.erase(s.begin(), s.begin() + 1);
		cout << s << endl;
			N= s;
		s.erase(s.begin() + czwarty - 1, s.end());
		cout << s << endl;
		N.erase(N.begin(), N.end() - czwarty+2);
		cout << N << endl;
		
		

	}
	ofstream outputFile;
	outputFile.open("dane.txt");
	generuj(tab, s, outputFile);
	wyswietl(tab);
	cout << endl;
	generuj(tab, N, outputFile);
	wyswietl(tab);
	outputFile.close();
	cin >> x;
	if (x.front() == '[')
	{
		size_t drugi = x.find(']');
		x.erase(x.begin(), x.begin() + 1);
		cout << x << endl;
		x.erase(x.begin() + drugi - 1, x.end());
		cout << x << endl;
		size_t trzeci = x.find('(');
		size_t czwarty = x.find(')');
		x.erase(x.begin(), x.begin());
		cout << x << endl;
		f = x;
		x.erase(x.begin() + czwarty , x.end());
		cout << x << endl; 
		f.erase(f.begin() + czwarty , f.end());
		cout << f << endl;



	}
	generuj(tab, x, outputFile);
	wyswietl(tab);
	cout << endl;
	/*generuj(tab, f, outputFile);
	wyswietl(tab);*/
	
}

