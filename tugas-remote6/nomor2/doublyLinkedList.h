#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST
#include <string>

using eJenis = std::string;

const eJenis jenisOptions[2] = {"kredit","debit"};

struct Transaksi {
    int idTransaksi;
    eJenis jenis;
    int jumlah;
};

struct Node{
    Transaksi data;
    Node* next;
    Node* prev;
};

struct List{
    Node* first;
    Node* last;
};

void inputTransaksi(Transaksi &t);
void createList(List &l);
bool isEmpty(const List &l);
Node* alokasi(Transaksi t);
void dealokasi(Node* p);
void insertLast(List &l,Node* p);
void deleteAfter(List &l, Node* r);
void printList(const List &l);
Node* findById(const List &l, const int id);


#endif