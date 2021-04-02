#ifndef NODE_H
#define NODE_H

class Node {
public:
    int sayi1;

    Node *sonraki; // Kendinden sonraki adres

    Node(void); // Constructor / __init__ // return zorunluluğu yok o yüzden önüne herhangi bir tür yazmak zorunda değiliz.
    // Construcor fonksiyonu class ismiyle aynı olmalı.
    // otomatik olarka çalışıyor.

};

Node::Node(void) {
    sayi1 = 0;
    sonraki = 0;
}

#endif // NODE_H