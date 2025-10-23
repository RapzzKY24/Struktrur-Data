// menambahkan file header
#include "singlyList.h"
#include <iostream>

using namespace std;

int main(){
    // menginstance / create List
    List L;
    CreateList(L);

    // variabel untuk parameter ditiap fungsi / prosedur
    int value ,target , n;

    // input jumlah length dari List
    cout << "Masukkan jumlah data pada linked list: ";
    cin >> n;

    // input semua data ke dalam list
    for(int i = 0 ; i < n ; i++){
        cout << "Masukkan elemen ke-" << i+1 << " : " ;
        cin >> value;
        Address Node = alokasi(value);
        // menambahkan data di awal list
        insertFirst(L, Node);
    }

    // print semua data yang ada di list
    printInfo(L);

    // menginput nilai yang ingin dicari
    cout << "Masukkan value yang ingin dicari pada linked list: " ;
    cin >> target;

    // memanggil fungsi search Element untuk mencari data yang diinputkan
    Address found = searchElement(L, target);
    // address / alamat != null maka data ditemukan
    if (found != nullptr) {
         cout << found->info << " " << "ditemukan dalam list"<< endl;
    // jika null maka data tidak ditemukan
    }else {
        cout << target << " " << "tidak ditemukan dalam list" << endl;
    }

    // fungsi sum semua data di list
    Plus(L);

    return 0;
}