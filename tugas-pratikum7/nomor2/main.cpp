#include <iostream>
#include <string>
using namespace std;

struct Node {
    int value;
    Node* next;
};

struct List {
    Node* first;
};

void createList(List &l) { l.first = nullptr; }

bool isEmpty(const List &l) { return l.first == nullptr; }

void push(List &l, int value) {
    Node* p = new Node();
    p->value = value;        
    p->next  = l.first;
    l.first  = p;
}


bool pop(List &l) {
    if (isEmpty(l)) return false;
    Node* p = l.first;
    l.first = p->next;
    delete p;
    return true;
}

void printStackTopDown(const List &l) {
    cout << "Isi Stack Akhir: ";
    for (Node* p = l.first; p != nullptr; p = p->next) {
        cout << p->value << " ";
    }
    cout << "\n";
}

int main() {
    List st;
    createList(st);

    int n;
    cin >> n;                

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;          
        if (cmd == "push") {
            int x;
            cin >> x;        
            push(st, x);
        } else if (cmd == "pop") {
            pop(st);         
        } 
    }

    printStackTopDown(st);

}
