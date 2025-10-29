#include <iostream>
using namespace std;
#include "doublyLinkedList.h"
#include <string>

void createList(List &l){
    l.first = nullptr;
    l.last = nullptr;
}

bool isEmpty(const List &l){
    return l.first == nullptr;
}

Node* alokasi(Product p){
    Node* newNode = new Node();
    newNode->data = p;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void dealokasi(Node* r){
    delete r;
}

void insertFirst(List &l,Node* p){
    if(isEmpty(l)){
        l.first = p;
        l.last = p;
    }else{
        p->next = l.first;
        l.first->prev = p;
        l.first = p;
    }
}

void insertLast(List &l,Node*p){
    if(isEmpty(l)){
        l.first = p;
        l.last = p;
    }else{
        l.last->next = p;
        p->prev = l.last;
        l.last = p;
    }
}

void insertAfter(List &l, Node* r, Node* p){
    if (!p) return;
    if (isEmpty(l)) { l.first = l.last = p; return; }
    if (!r) { 
        insertFirst(l, p);
        return;
    }
    p->prev = r;
    p->next = r->next;
    if (r->next) r->next->prev = p; 
    else l.last = p;               
    r->next = p;
}

Node* findByKode(const List &l, const std::string& kode){
    for (Node* cur = l.first; cur; cur = cur->next)
        if (cur->data.kodeProduk == kode) return cur;
    return nullptr;
}

void printList(const List &l){
    if (isEmpty(l)){ cout << "List Kosong\n"; return; }
    for (Node* p = l.first; p; p = p->next){
        cout << p->data.namaProduk << "\n"
             << p->data.kodeProduk << "\n"
             << p->data.harga      << "\n";
        if (p->next) cout << "----\n";
    }
}

void inputProduct(Product &p) {
    cout << "Nama produk   : ";
    cin >> p.namaProduk;
    cout << "Kode produk   : ";
    cin >> p.kodeProduk;
    cout << "Harga produk  : ";
    cin >> p.harga;
}
