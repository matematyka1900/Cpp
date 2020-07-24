// Potegowanie_modularne.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
int phi(unsigned int n)
{
    unsigned int result = 1;
    for (int i = 2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}

int main()
{
    int wybor = 0;

    do
    {
        cout << "Wybierz:\n 1.Potegowanie\n 0.Wyjscie\n";
        cin >> wybor;
        int A, B, n;
        cout << "Podaj podstawe potegi: ";
        cin >> A;
        cout << endl;
        cout << "Podaj wykladnik potegi: ";
        cin >> B;
        cout << endl;
        cout << "Podaj mod: ";
        cin >> n;
        cout << endl;

        if (gcd(A, n) == 1)
        {
            cout << "Zgodne z zalozeniem Eulera";
        }
        else
        {
            cout << "Niezgodne z zalozeniem Eurela";
            return 0;
        }

        cout << endl;
        int x = phi(n);

        cout << x << endl;
        int d = B % x;

        cout << d << endl;

        long long int wynik = pow(A, d);

        cout << wynik;


        cout << "wynik:" << wynik % n << endl;
    } while (wybor != 0);
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
