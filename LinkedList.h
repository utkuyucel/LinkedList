#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList {
public:

    Node *header;
    LinkedList(void);

    void ListeyeElemanEkle(int girdi_sayisi);
    void ListeyiYazdir(void);
    void ListeninBasinaElemanEkle(int sayi_degeri);

    // Çalışma soruları | Ödevler // Çizip tasarlayarak yapmaya çalış. // Paintte vb.
    int ListeninSirasindakiEleman(int sira_no);
    void ListeninSirasinaBirelemanEkle(int sira_no, int sayi_degeri);
    bool ListedeAramaYap(int sayi_degeri);

    void ListeninSirasindakiElemaniSil(int sira_no);

    // Derste yaptık.
    void sonElemaniSil(void);
    void ListeninBasindakiElemaniSil(void);

    // listenin, n. indexindeki sayıyı getir. (fonksiyonu yaz).
};

LinkedList::LinkedList(void) {
    header = 0; // LinkedList liste1 -> Çağırıldığı an bu şekilde ortaya çıkıyor.
}

void LinkedList::ListeyeElemanEkle(int girdi_sayisi) {
    Node *yeni = new Node();
    yeni -> sayi1 = girdi_sayisi;

    if (header == 0) { // ilk elementse (Node yoksa)
        header = yeni;
    }
    else { // ilk element değilse
        Node *temp = header;

        while (temp -> sonraki != 0) {// listenin en sonuna git
            temp = temp -> sonraki;
        }

        temp->sonraki = yeni; // listenin sonuna ekle.
    }
}

void LinkedList::ListeyiYazdir(void) {
    Node *temp = header;

    if (header == 0) {
        cout << "Listede eleman bulunmamaktadir.";
    }
    else {
        while (temp != 0) {
            cout << temp->sayi1 << endl;
            temp = temp->sonraki;
        }
    }
}

void LinkedList::ListeninBasinaElemanEkle(int sayi_degeri) {
    Node *yeni = new Node();
    yeni->sayi1 = sayi_degeri;

    yeni->sonraki = header;
    header = yeni;

}

void LinkedList::sonElemaniSil(void) {

    if (header == 0) {
        cout << "Listede eleman bulunmamaktadir. Silme islemi yapilamaz.\n";
        return;
    }

    cout << "Listenin sonundaki eleman silinecektir.\n";

    if (header->sonraki == 0) {

        delete header;
        header = 0;
        return; // Aşağıdakiler çalışmayacak böylece.
    }

    Node *temp = header;
    // sonraki aslında bir adres.
    // temp -> sonraki -> sonraki = en son node'un sonraki adresi | en sondan bir öncekinde duralım ki en sonuncuyu silebilelim.
    while (temp->sonraki->sonraki != 0) {
        temp = temp->sonraki;
    }
    delete temp->sonraki;
    temp->sonraki = 0;
}

void LinkedList::ListeninBasindakiElemaniSil(void) {
    if (header == 0) {
        cout << "Listede eleman bulunmamaktadir.\n";
        return;
    }

    Node *temp = header->sonraki;
    delete header;

    header = temp;
}
int LinkedList::ListeninSirasindakiEleman(int sira_no) {
    Node *temp = header;
    int counter = 0;
    int return_value = 0;

    if (header == 0) {
        cout << "Listede eleman bulunmamaktadir.\n";
        return_value = -1;
    }

    while (temp->sonraki != 0) {
        if (counter == sira_no) {
            return_value = temp->sayi1;
            break;
        }

        counter++;
        temp = temp->sonraki;
    }

    return_value = temp->sayi1;

    if ( (temp->sonraki == 0 && counter < sira_no) || sira_no < 0) {
        return_value = -1;
    }

    return return_value;
}

bool LinkedList::ListedeAramaYap(int sayi_degeri) {
    Node *temp = header;

    if (header == 0) {
        cout << "Listede herhangi bir eleman bulunmamaktadir.";
        return false;
    }

    else {
        for (int i = 1; temp->sonraki != 0; i++) {
            if (temp->sayi1 == sayi_degeri) {
                return true;
            }
            temp = temp->sonraki;
        }
    }
    return false;
}

void LinkedList::ListeninSirasinaBirelemanEkle(int sira_no, int sayi_degeri) {
    Node *yeni = new Node();
    yeni->sayi1 = sayi_degeri;

    if (sira_no == 0) {
        yeni->sonraki = header;
        header = yeni;

    } else {
        Node *temp = header;

        for (int i = 1; temp->sonraki != 0; i++) {
            if (i == sira_no) {
                yeni->sonraki = temp->sonraki;
                temp->sonraki = yeni;
                break;
            }
            temp = temp->sonraki;
        }
    }
}

void LinkedList::ListeninSirasindakiElemaniSil(int sira_no) {
    Node *temp = header;

    if (header == 0) {
        cout << "Listede herhangi bir eleman bulunmamaktadir.";
    }

    else if (sira_no == 0) {
        ListeninBasindakiElemaniSil();
    }

    else {

        for (int i = 1; temp->sonraki != 0; i++) {
            if (i == sira_no) {
                temp-> sonraki= temp->sonraki->sonraki;
            }
            temp = temp->sonraki;
        }
    }
}


#endif // LINKEDLIST_H
