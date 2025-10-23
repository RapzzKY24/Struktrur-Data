#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <cstddef>

//membuat sebuah type untuk infotype dengan tipe data integer
typedef int Infotype;

// membuat inisiasi dari sebuah struct dengan nama elmList
struct ElmList;

// membuat sebuah type untuk menyimpan address dari sebuah value
typedef ElmList* Address;

// menambah field pada struct elmList yang berisi data(int) , value(address)  
struct ElmList {
    Infotype info;
    Address next;
};

// membuat struct list yang berisi address pertama pada list
struct List {
    Address First;
};

// prosedur untuk membuat list dengan parameter struct List
void CreateList(List &L);

//fungsi bertipe address (pointer) untuk memambahkan sebuah data pada singlyList menerima sebuah data (value) bertipe integer
Address alokasi(Infotype x);

//prosedur untuk mengahapus semua data pada singly list(clearList) menerima paramater pointer dari struct address
void dealokasi(Address &P);

// prosedur untuk print semua data pada list dengan paremter List of pointer yang konstan 
void printInfo(const List &L);

// prosedur untuk menambahkan data di awal list menerima parameter struct List dan Address 
void insertFirst(List &L, Address P);

// fungsi bertipe address untuk mencari sebuah data pada list mempunyai paramter List dan Infotype(value / target)
Address searchElement(const List &L, Infotype X);

// prosedur menjumlahkan semua data yang ada pada List menerima param List
void Plus(List &L);

#endif 
