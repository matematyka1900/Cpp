#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

using namespace std;


struct Client {
    int key;
};

void displayClient(const Client* &e1) {
    cout << "Key" << " " << "#" << e1->key << " ";
}
void displayNode(const int &e1) {
    cout << "Key" << " " << "#" << e1 << " ";
}
int compareClient(const Client*& e1, const Client*& e2) {
    return e1->key - e2->key;
}

int compareNode(const int& e1,const int& e2) {
    return e1 - e2;
}

char compareChar(const char& e1, const char& e2) {
    return e1 - e2;
}
void displayChar(const char& e1) {
    cout << "Key" << " " << "#" << e1 << " ";
}

double compareDouble(const double& e1, const double& e2) {
    return e1 - e2;
}
void displayDouble(const double& e1) {
    cout << "Key" << " " << "#" << e1 << " ";
}



template <typename T>
class BinaryHeap {

    using COMPARE = int(*)(const T&,const T&);
    using DISPLAY = void(*)(const T&);


    T* tab = nullptr;
    bool ok;
    int tab_size = 0;


    int p(int child);
    int l(int parent);
    int r(int parent);

    void moveUp(int idx,int size,COMPARE compare);
    void moveDown(int idx,int n,COMPARE compare);
public:

    BinaryHeap(int* &arr, int n,COMPARE compare,bool bottomUp);
    void disp(DISPLAY display);
    void heapSort(COMPARE compare);
};



template<typename T>
inline BinaryHeap<T>::BinaryHeap(int* &arr, int n, COMPARE compare, bool bottomUp)
{
    tab = arr;
    tab_size = n;
    ok = bottomUp;
}


template<typename T>
void BinaryHeap<T>::disp(DISPLAY display)
{
    if (tab == NULL)
    {
        cout << "Pusty kontener ";
    }

    if (tab_size <= 100) {
        for (int i = 0; i < tab_size; i++) {
            display(tab[i]);
            cout << i << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 0; i < 100; i++) {
            display(tab[i]);
            cout << i << " ";
        }
        cout << "\n";
    }
}

template<typename T>
void BinaryHeap<T>::heapSort(COMPARE compare)
{

    if (!ok)
    {
        for (int i = tab_size / 2 - 1; i >= 0; i--)
            moveDown(i, tab_size, compare);

        for (int i = tab_size - 1; i > 0; i--) {
            swap(tab[0], tab[i]);

            moveDown(0, i, compare);
        }
    } 
    else {
        for (int i = 1; i < tab_size; i++)
            moveUp(i, tab_size, compare);

        for (int i = tab_size - 1; i > 0; i--) {
            swap(tab[0], tab[i]);

            moveDown(0, i, compare);
        }
    }
}


template<typename T>
void BinaryHeap<T>::moveDown(int idx, int size, COMPARE compare)
{
    int temp = idx;
    int left_child = l(idx);
    int right_child = r(idx);

    if (left_child < size && (compare(tab[idx], tab[left_child]) < 0))
        temp = left_child;

    if (right_child < size && (compare(tab[temp], tab[right_child]) < 0))
        temp = right_child;

    if (temp != idx) {
        swap(tab[idx], tab[temp]);

        moveDown(temp, size, compare);
    }
}


template<typename T>
int BinaryHeap<T>::p(int child)
{
    int p = (child - 1) / 2;
    return p;
}

template<typename T>
int BinaryHeap<T>::l(int parent)
{
    int l = 2 * parent + 1;
    return l;
}

template<typename T>
int BinaryHeap<T>::r(int parent)
{
    int r = 2 * parent + 2;
    return r;
}

template<typename T>
void BinaryHeap<T>::moveUp(int idx, int size, COMPARE compare)
{
    if (idx == 0)
        return;

    if ((compare(tab[idx], tab[p(idx)]) > 0)) {
        swap(tab[idx], tab[p(idx)]);
        moveUp(p(idx),size,compare);
    }
}


#endif