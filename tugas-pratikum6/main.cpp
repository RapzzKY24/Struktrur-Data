#include <iostream>
#include "doubleList.h"

using namespace std;

int main(){
    List L;
    createList(L);

    int n, value,target;
    cout << "Masukkan jumlah data pada list: ";
    if (!(cin >> n) || n < 0) return 0;

    for (int i = 0; i < n; i++){
        cout << "Masukkan data ke-" << i+1 << ": ";
        cin >> value;
        insertLast(L, alokasi(value));
    }

    cout << "List awal: ";
    printList(L);

    int acuanVal;
    cout << "Masukkan nilai acuan: ";
    cin >> acuanVal;

   
    Node* acuan = findByValue(L, acuanVal);

   
    Node* gone = deleteAfter(acuan);
    if (gone){
        if (acuan && acuan->next == nullptr){
            
            L.last = acuan;
        }
        dealokasi(gone);
    } else {
        cout << "nilai acuan tidak ditemukan \n";
    }

    cout << "List akhir: ";
    printList(L);

    //nomor3
    cout << "Masukkan data yang ingin dicari: ";
    cin >> target;
    Node* search = findByValue(L,target);
    if(search){
        cout << "Data ditemukan";
    }else{
        cout << "Data tidak ditemukan";
    }

    
    return 0;
}
