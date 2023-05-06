#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
    Jednokierunkowa lista. Struktura reprezentujaca elementy listy
*/
struct Node {
    Node  * left, * right, * next;
    char letter;
    int count;
};

void createNodeList ( Node * & root, string s )
{
  unsigned int i, x;
  char cx;
  Node * p;
  bool t;

  root = NULL;
  for( i = 0; i < s.length( ); i++ )
  {
    p = root;
    while( p && ( p->letter != s [ i ] ) ) p = p->next;
    if( !p )
    {
      p = new Node;
      p->next  = root;
      p->left  = NULL;
      p->right = NULL;
      p->letter    = s [ i ];
      p->count = 0;
      root     = p;
    }
    p->count++;
  }
  do
  {
    t = true;
    p = root;
    while( p->next )
    {
      if( p->count > p->next->count )
      {
        cx = p->letter;
        p->letter = p->next->letter;
        p->next->letter = cx;
        x = p->count;
        p->count = p->next->count;
        p->next->count = x;
        t = false;
      }
      p = p->next;
    }
  } while( !t );
}



void createHuffmanTree ( Node * & root )
{
  Node *p, *r, *v1, *v2;

  while( true )
  {
    v1 = root;
    v2 = v1->next;

    if( !v2 ) break;

    root = v2->next;

    p = new Node;
    p->left = v1;
    p->right = v2;
    p->count = v1->count + v2->count;



    if( !root || ( p->count <= root->count ) )
    {
      p->next = root;
      root = p;
      continue;
    }

    r = root;

    while( r->next && ( p->count > r->next->count ) ) r = r->next;

    p->next = r->next;
    r->next = p;
  }
}




int main()
{
    Node * root;
    string word;
    cout << "Podaj tekst do skompresowania: ";
    cin >> word;
    root = NULL;
    createNodeList (root, word);
    createHuffmanTree (root);
    return 0;
}
