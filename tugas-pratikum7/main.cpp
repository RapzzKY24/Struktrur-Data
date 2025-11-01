#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

struct List{
    Node* first;
};

void createList(List &l){
    l.first = nullptr;
}

bool isEmpty(const List &l){
    return l.first == nullptr;
}

void pop(List &l){
    if(isEmpty(l)){
        cout << "List kosong" << endl;
        return;
    }
    Node* p = l.first;
    l.first = p->next;
    delete p;
}

void push(List &l, int value){
    Node* p = new Node;
    p->value = value;
    p->next = l.first;
    l.first = p;
}

void printStackTopDown(const List &l) {
    cout << "Isi Stack Akhir: ";
    for (Node* p = l.first; p != nullptr; p = p->next) {
        cout << p->value << " ";
    }
    cout << "\n";
}


int main(){
    List l;
    createList(l);
    int n,jumlahHapus, value;
    cout << "Masukkan jumlah data: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Masukkan data ke-" << i+1 << ": ";
        cin >> value;
        push(l, value);
    }
    cout << "Masukkan jumlah data yang ingin dihapus: ";
    cin >> jumlahHapus;
    for(int i = 0; i < jumlahHapus; i++){
        pop(l);
    }
    printStackTopDown(l);
    return 0;
}