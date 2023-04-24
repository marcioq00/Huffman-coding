#include <iostream>
#include <string>

using namespace std;

/*
    Jednokierunkowa lista. Struktura reprezentujaca elementy listy
*/
struct Node {
    Node  * left, * right, * next;
    char letter;
    int count;
};

void createNodeList (Node* & root, string word) {
    unsigned int i;
    Node * p, * q, * tmp;

    root = NULL;
    for(i = 0; i < word.length(); i++) {
        p = root;
        while( p && ( p->letter != word [ i ] ) ) {
         p = p->next;

        }
        if( !p ) {
          p = new Node;
          p->next   = root;
          p->left   = NULL;
          p->right  = NULL;
          p->letter = word[ i ];
          p->count  = 0;
          root = p;
        }
        p->count++;
    }

   // Sortowanie przez wstawianie
    p = root;
    root = NULL;
    while (p != NULL) {
        tmp = p->next;
        if (root == NULL || p->count > root->count) {
            p->next = root;
            root = p;
        } else {
            q = root;
            while (q->next != NULL && p->count <= q->next->count) {
                q = q->next;
            }
            p->next = q->next;
            q->next = p;
        }
        p = tmp;
    }

    // Wyswietlanie posortowanej listy wezlow
    p = root;
    while (p != NULL) {
        cout << p->letter << " : " << p->count << endl;
        p = p->next;
    }
}


int main()
{
    Node * root;
    string word;
    cout << "Podaj tekst do skompresowania: ";
    cin >> word;
    createNodeList(root, word);
    return 0;
}
