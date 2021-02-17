

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include <algorithm>

using namespace std;

int random(int bound) {
    int x = rand();
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return abs(x) % bound;
}

int compareNode(const int& e1, const int& e2) {
    return e1 - e2;
}

void displayNode(const int& e1) {
    cout << e1 << " ";
}

template<typename T>
class BST {
public:
    using COMPARE = int(*)(const T&, const T&);
    using DISPLAY = void(*)(const T&);

    struct Node {
        Node* left;
        Node* right;
        T key;
    };

private:
    Node* root;
    Node* daddy;

    Node* find(Node* parent, const T& type, COMPARE compare);
    void inOrder(Node* parent, DISPLAY display);
    void preOrder(Node* parent, DISPLAY display);
    int max_height(Node* parent);
    Node* min_key(Node* parent);
    void kill_all_nodes(Node* parent);

public:
    BST();
    void add(const T& type, COMPARE compare);
    Node* find(const T& type, COMPARE compare);
    void inOrder(DISPLAY display);
    void preOrder(DISPLAY display);
    int max_height();
    void kill_node(Node* parent);
    void kill_all_nodes();
};


int main() {

    double time_spent;
    srand(time(NULL));
    const int MAX_ORDER = 7;
    BST<int>* bst = new BST<int>();
    bst->add(9, compareNode);
    bst->add(1, compareNode);
    bst->add(5, compareNode);
    bst->add(3, compareNode);
    bst->add(7, compareNode);
    bst->add(4, compareNode);
    bst->add(8, compareNode);
    bst->add(13, compareNode);
    bst->add(10, compareNode);
    bst->add(12, compareNode);
    bst->add(11, compareNode);

    bst->preOrder(displayNode);
   
    delete bst;
}



template<typename T>
BST<T>::BST() {
    root = NULL;
    daddy = NULL;
}

template<typename T>
void BST<T>::add(const T& type, COMPARE compare) {
    Node* node = new Node;
    Node* temp;
    node->key = type;
    node->left = NULL;
    node->right = NULL;

    if (root == NULL) {
        root = node;
        return;
    }
    temp = root;
    while (1) {
        if (compare(temp->key, type) > 0) {
            if (temp->left != NULL) {
                temp = temp->left;
            }
            else {
                temp->left = node;
                break;
            }
        }
        else {
            if (temp->right != NULL) {
                temp = temp->right;
            }
            else {
                temp->right = node;
                break;
            }
        }
    }

}

template<typename T>
void BST<T>::inOrder(Node* parent, DISPLAY display) {

    if (parent != NULL) {
        inOrder(parent->left, display);
        display(parent->key);
        inOrder(parent->right, display);
    }
}

template<typename T>
void BST<T>::preOrder(Node* parent, DISPLAY display) {
    if (parent != NULL) {
        display(parent->key);
        preOrder(parent->left, display);
        preOrder(parent->right, display);
    }

    /*
    postOrder

    if (parent != NULL) {
        preOrder(parent->left, display);
        preOrder(parent->right, display);
        display(parent->key);
    }

    */
}

template<typename T>
typename BST<T>::Node* BST<T>::find(const T& type, COMPARE compare) {
    return find(root, type, compare);
}

template<typename T>
void BST<T>::inOrder(DISPLAY display) {
    inOrder(root, display);
}

template<typename T>
void BST<T>::preOrder(DISPLAY display) {
    preOrder(root, display);
}

template<typename T>
int BST<T>::max_height() {
    return max_height(root);
}

template<typename T>
int BST<T>::max_height(Node* parent) {
    int height = 0;
    if (parent->left || parent->right) {
        height = max(parent->left ? max_height(parent->left) : 0, parent->right ? max_height(parent->right) : 0) + 1;
    }
    return height;
}

template<typename T>
typename BST<T>::Node* BST<T>::find(Node* n, const T& type, COMPARE compare) {
    if (n != NULL) {
        int res = compare(n->key, type);
        if (res == 0) {
            return n;
        }
        else if (res < 0) {
            daddy = n;
            return find(n->right, type, compare);
        }
        else {
            daddy = n;
            return find(n->left, type, compare);
        }
    }
    else {
        return NULL;
    }
}

template<typename T>
typename BST<T>::Node* BST<T>::min_key(Node* parent) {
    while (parent->left != nullptr) {
        daddy = parent;
        parent = parent->left;
    }
    return parent;
}

template<typename T>
void BST<T>::kill_node(Node* parent) {
    if (parent->left == nullptr && parent->right == nullptr) {
        if (parent != root) {
            if (daddy->left == parent)
                daddy->left = nullptr;
            else if (daddy->right == parent)
                daddy->right = nullptr;
        }
        else
            root = nullptr;

        delete parent;
    }
    else if (parent->left && parent->right) {

        daddy = parent;
        Node* find_min = min_key(parent->right);
        parent->key = find_min->key;
        kill_node(find_min);
    }
    else {
        Node* child;
        if (parent->left)
            child = parent->left;
        else
            child = parent->right;

        if (parent != root) {
            if (parent == daddy->left)
                daddy->left = child;
            else
                daddy->right = child;
        }
        else
            root = child;

        delete parent;
    }
}

template<typename T>
void BST<T>::kill_all_nodes() {
    kill_all_nodes(root);
    root = NULL;
}

template<typename T>
void BST<T>::kill_all_nodes(Node* parent) {
    if (parent != NULL) {
        kill_all_nodes(parent->left);
        kill_all_nodes(parent->right);
        delete parent;
    }
}
