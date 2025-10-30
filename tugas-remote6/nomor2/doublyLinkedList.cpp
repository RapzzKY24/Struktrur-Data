#include "doublyLinkedList.h"
#include <iostream>
using namespace std;

void inputTransaksi(Transaksi &t) {
    cout << "Id transaksi   : ";
    cin >> t.idTransaksi;
    cout << "Jenis Transaksi(Debit / Kredit )   : ";
    cin >> t.jenis;
    cout << "Jumlah transaksi  : ";
    cin >> t.jumlah;
}

Node* findById(const List &l, const int id){
    Node* cur = l.first;
    while (cur){
        if (cur->data.idTransaksi == id) return cur;
        cur = cur->next;
    }
    return nullptr;
}

void createList(List &l){
    l.first = nullptr;
}

bool isEmpty(const List &l){
    return l.first == nullptr;
}

Node* alokasi(Transaksi t){
    Node* newNode = new Node();
    newNode->data = t;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void dealokasi(Node* p){
    delete p;
}

void insertLast(List &l,Node* p){
    if(isEmpty(l)){
        l.first = p;
        l.last = p;
    }else{
        l.last->next = p;
        p->prev = l.last;
        l.last = p;
    }
}



void deleteAfter(List &l, Node* r) {
    if (!r || !r->next) return;          
    Node* p = r->next;                   
    r->next = p->next;                   
    if (p->next) {
        p->next->prev = r;               
    } else {
        l.last = r;                      
    }

    p->prev = nullptr;                   
    p->next = nullptr;
    dealokasi(p);
}


void printList(const List &l){
    if (isEmpty(l)){
        cout << "List Kosong\n";
        return;
    }
    Node* p = l.first;
    while (p){
        cout << "Id transaksi: " << p->data.idTransaksi << endl;
        cout << "Jenis transaksi: " << p->data.jenis<< endl;
        cout << "Jumlah transaksi: " << p->data.jumlah << endl;
        if (p->next) cout << " ";
        p = p->next;
    }
    cout << "\n";
}



