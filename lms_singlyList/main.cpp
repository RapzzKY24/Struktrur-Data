#include <iostream>
using namespace std;

struct Node {
    float data;
    Node* next;
};

struct List{
    Node* first;
};

void createList(List &l){
    l.first = nullptr;
}

void newElm(float X){
    Node* elm = new Node;
    elm->data = X;
    elm->next = nullptr;
}

void insertAscending(List &l, Node* elm){
    if(l.first == nullptr || elm->data < l.first->data){
        elm->next = l.first;
        l.first = elm;
        return;
    }
    
    
    Node* P = l.first;
    while(P->next != nullptr && P->next->data < elm->data){
        P = P->next;
    }
    elm->next = P->next;
    P->next = elm;
}

void printList(List &l){
    Node* P = l.first;
    while(P != nullptr){
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}

int main(){
    List l;
    createList(l);
    Node* elm;
    
    
    newElm(25.1);
    insertAscending(l, elm);
    
    newElm(12.5);
    insertAscending(l, elm);
    
    newElm(20.9);
    insertAscending(l, elm);
    
    newElm(10.5);
    insertAscending(l, elm);
    
    printList(l);
    return 0;
}