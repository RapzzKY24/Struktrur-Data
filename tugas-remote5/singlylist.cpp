#include "singlyList.h"
#include <iostream>

// memanggil semua fungsi yang sudah di deklarisan pada file header
void CreateList(List &L) {
    L.First = nullptr;
}

Address alokasi(Infotype x) {
    Address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(Address &P) {
    delete P;
    P = nullptr;
}

void printInfo(const List &L) {
    if (!L.First) {
        std::cout << "List kosong\n";
        return;
    }
    Address p = L.First;
    while (p) {
        std::cout << p->info;
        if (p->next) std::cout << " ";
        p = p->next;
    }
    std::cout << "\n";
}

void insertFirst(List &L, Address P) {
    if (!P) return;
    P->next = L.First;
    L.First = P;
}

Address searchElement(const List &L, Infotype X) {
    Address temp = L.First;
    int posisi = 1;

    while(temp != nullptr){
        if(temp->info == X ){
            return temp;
        }
        temp = temp->next;
        posisi++;
    }
        return nullptr;
}

void Plus(List &L) {
    Address P = L.First;
    int sum = 0;
    while(P != nullptr){
        sum += P->info;
        P = P->next;
    }
    std::cout << "Total penjumalahn adalah: "<< sum << std::endl;
}
