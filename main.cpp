#include <iostream>
#include <LinkedList.h>
#include <Node.h>

using namespace std;

int main()
{
    LinkedList liste;


    liste.ListeyeElemanEkle(1);
    liste.ListeyeElemanEkle(2);
    liste.ListeyeElemanEkle(3);
    liste.ListeyeElemanEkle(4);
    liste.ListeyeElemanEkle(5);
    liste.ListeyiYazdir();

    int a = liste.ListeninSirasindakiEleman(0);
    int b = liste.ListeninSirasindakiEleman(2);

    cout << "Eleman: " << a << "\n" << "Son Eleman: " << b << "\n";
    return 0;
}