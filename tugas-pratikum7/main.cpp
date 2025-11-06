#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

struct Stack{
    Node* top;
};

void createList(Stack &s){
    s.top = nullptr;
}

bool isEmpty(const Stack &s){
    return s.top == nullptr;
}

void pop(Stack &s){
    if(isEmpty(s)){
        cout << "Stack kosong" << endl;
        return;
    }
    Node* p = s.top;
    s.top = p->next;
    delete p;
}

void push(Stack &s, int value){
    Node* p = new Node;
    p->value = value;
    p->next = s.top;
    s.top = p;
}

void printStackTopDown(const Stack &s) {
    cout << "Isi Stack Akhir: ";
    for (Node* p = s.top; p != nullptr; p = p->next) {
        cout << p->value << " ";
    }
    cout << "\n";
}


int main(){
    Stack s;
    createList(s);
    int n,jumlahHapus, value;
    cout << "Masukkan jumlah data: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Masukkan data ke-" << i+1 << ": ";
        cin >> value;
        push(s, value);
    }
    cout << "Masukkan jumlah data yang ingin dihapus: ";
    cin >> jumlahHapus;
    for(int i = 0; i < jumlahHapus; i++){
        pop(s);
    }
    printStackTopDown(s);
    return 0;
}