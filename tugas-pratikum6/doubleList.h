#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <cstddef>

struct Node{
    int data;
    Node* next;
    Node* prev;
};

struct List{
    Node* first;
    Node* last;
};

void createList(List &l);
bool isEmpty(const List &l);
Node* alokasi(int value);
void dealokasi(Node* r);
void insertLast(List &l, Node* p);
Node* findByValue(const List &l, int value);
Node* deleteAfter(Node* r);

void printList(const List &l);

#endif
