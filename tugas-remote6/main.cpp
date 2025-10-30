#include <iostream>
#include "doublyLinkedList.h"
using namespace std;
#include <string>

int main(){
    List l;
    createList(l);

    while (true){
        cout << "\n==== MENU ====\n"
             << "1. Insert First\n"
             << "2. Insert Last\n"
             << "3. Insert After\n"
             << "4. Print List\n"
             << "5. Exit\n"
             << "Pilih: ";
        int m; if(!(cin >> m)) break;

        if (m == 1){
            Product p; 
            inputProduct(p);
            insertFirst(l, alokasi(p));
        } else if (m == 2){
            Product p; 
            inputProduct(p);
            insertLast(l, alokasi(p));
        } else if (m == 3){
            if (isEmpty(l)){ 
                cout << "List kosong.\n"; 
                continue; 
            }
            std::string target; 
            cout << "Sisip setelah kode: "; 
            cin >> target;
            Node* r = findByKode(l, target);
            if (!r){ 
                cout << "Kode target gak ketemu.\n"; 
                continue; 
            }
            Product p; inputProduct(p);
            insertAfter(l, r, alokasi(p));
        } else if (m == 4){
            printList(l);
        } else if (m == 5){
            cout << "Bye.\n"; break;
        } else {
            cout << "Pilihan gak valid.\n";
        }
    }
    return 0;
}
