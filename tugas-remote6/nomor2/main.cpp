#include <iostream>
#include "doublyLinkedList.h"
using namespace std;


int main(){
    List l;
    createList(l);

    while (true) {
        cout << "\n==== MENU ====\n"
             << "1. Tambah transaksi (insertLast)\n"
             << "2. Hapus setelah ID (deleteAfter)\n"
             << "3. Print list\n"
             << "4. Exit\n"
             << "Pilih: ";

        int menu; 
        if (!(cin >> menu)) break;

        if (menu == 1) {
            cout << "\n-- Tambah transaksi (akhir) --\n";
            Transaksi t;
            inputTransaksi(t);
            insertLast(l, alokasi(t));
        }
        else if (menu == 2) {
            if (isEmpty(l)) {
                cout << "List kosong. Isi dulu.\n";
                continue;
            }
            int id;
            cout << "Hapus node SETELAH ID transaksi: ";
            cin >> id;

            Node* r = findById(l, id);
            if (!r) {
                cout << "ID target tidak ketemu.\n";
                continue;
            }
            if (!r->next) {
                cout << "Nggak ada node setelah ID itu \n";
                continue;
            }
            deleteAfter(l, r);
            cout << "node setelah " << id << " sudah dihapus.\n";
        }
        else if (menu == 3) {
            printList(l);
        }
        else if (menu == 4) {
            cout << "selesai.\n";
            break;
        }
        else {
            cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}
