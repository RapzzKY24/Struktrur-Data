#include "doubleList.h"
#include <iostream>

void createList(List &l){
    l.first = nullptr;
    l.last  = nullptr;
}

bool isEmpty(const List &l){
    return l.first == nullptr;
}

Node* alokasi(int value){
    Node* P = new Node;
    P->data = value;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(Node* r){
    delete r;
    // r lokal; set ke nullptr di sini nggak ngaruh ke caller
}

void insertLast(List &l, Node* p){
    if (isEmpty(l)){
        l.first = l.last = p;
    } else {
        p->prev     = l.last;
        l.last->next = p;
        l.last       = p;
    }
}

Node* findByValue(const List &l, int value){
    Node* cur = l.first;
    while (cur){
        if (cur->data == value) return cur;
        cur = cur->next;
    }
    return nullptr;
}


Node* deleteAfter(Node* R){
    if (!R || !R->next) return nullptr; 

    Node* P = R->next;      
    R->next = P->next;      
    if (P->next){
        P->next->prev = R;  
    }
    P->next = P->prev = nullptr; 
    return P;               
}

void printList(const List &l){
    if (isEmpty(l)){
        std::cout << "List Kosong\n";
        return;
    }
    Node* p = l.first;
    while (p){
        std::cout << p->data;
        if (p->next) std::cout << " ";
        p = p->next;
    }
    std::cout << "\n";
}
