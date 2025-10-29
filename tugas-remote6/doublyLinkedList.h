#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <string>

struct Product {
    std::string namaProduk;
    std::string kodeProduk;
    int harga;
};

struct Node{
    Product data;
    Node* next;
    Node* prev;
};

struct List{
    Node* first;
    Node* last;
};

void createList(List &l);
bool isEmpty(const List &l);
Node* alokasi(Product p);
void dealokasi(Node* r);
void insertFirst(List &l,Node* p);
void insertLast(List &l,Node*p);
void printList(const List &l);
Node* findByKode(const List &l, const std::string& kode);
void insertAfter(List &l, Node* r, Node* p);
void inputProduct(Product &p);

#endif