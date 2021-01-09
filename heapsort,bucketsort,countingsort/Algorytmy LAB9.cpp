#include <iostream>
#include "BinaryHeapS.h"
#include "SortingFunctions.h"
#include <algorithm>
#include <time.h>
#include <stdlib.h>

using namespace std;

int random(int bound) {
    int x = rand();
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return abs(x) % bound;
}

int main_ints()
{
    srand(time(NULL));
    double time_spent;
    const int MAX_ORDER = 7;
    const int m = (int)pow(10,7);
    //int m;

    for (int o = 1; o <= MAX_ORDER; o++)
    {
        const int n = (int)pow(10, o);

        int* array1 = new int[n];

        for (int i = 0; i < n; i++) {
            int rand_val = ((rand() << 15) + rand()) % m;
            array1[i] = rand_val;
        }

        if (n <= 100)
            for (int i = 0; i < n; i++) {
                cout << array1[i] << " ";
            }
        else
            for (int i = 0; i < 100; i++) {
                cout << array1[i] << " ";
            }

        cout << "\n";

        // skrotowy wypis tablicy do posortowania ( np . pewna liczba poczatkowych elementow )
        int* array2 = new int[n];
        int* array3 = new int[n];
        memcpy(array2, array1, n * sizeof(int)); // pierwsza kopia
        memcpy(array3, array1, n * sizeof(int)); // druga kopia

        clock_t t1 = clock();
        countingSort(array1, n, m);
        clock_t t2 = clock();

        cout << "After counting sort: " << "\n";

        if (n <= 100) {
            for (int i = 0; i < n; i++) {
                cout << "Key" << " " << "#" << array1[i] << " " << i << " ";
            }
        }
        else {
            for (int i = 0; i < 100; i++) {
                cout << "Key" << " " << "#" << array1[i] << " " << i << " ";
            }
        }

        cout << "\n";

        time_spent = (double)(t2 - t1) / CLOCKS_PER_SEC;
        cout << "Time spent: " << time_spent;
        cout << "\n";

        t1 = clock();
        BinaryHeap<int> *bh = new BinaryHeap<int>(array2, n, compareNode, true);
        bh->heapSort(compareNode);
        t2 = clock();

        cout << "After heap sort: " << "\n";

        bh->disp(displayNode);

        time_spent = (double)(t2 - t1) / CLOCKS_PER_SEC;
        cout << "Time spent: " << time_spent;
        cout << "\n";
        
    }
    return 0;
}
int main_some_objects() {
    const int MAX_ORDER = 7; // maksymalny rzad wielkosci sortowanych danych
    const double m_double = (double)pow(2, 30); // mianownik przy ustalaniu losowej liczby

    for (int o = 1; o <= MAX_ORDER; o++)
    {
        const int n = (int)pow(10, o);
    }
    return 0;
}

int main()
{
    main_ints();
}

