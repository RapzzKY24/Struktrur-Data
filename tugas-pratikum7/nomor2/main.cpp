#include <iostream>
#include <string>
using namespace std;

struct Node {
    int value;
    Node* next;
};

struct Stack {
    Node* top;
};

void createList(Stack &s) { 
    s.top = nullptr; 
}

bool isEmpty(const Stack &s) { 
    return s.top == nullptr; 
}

void push(Stack &s, int value) {
    Node* p = new Node();
    p->value = value;        
    p->next  = s.top;
    s.top  = p;
}


bool pop(Stack &s) {
    if (isEmpty(s)) return false;
    Node* p = s.top;
    s.top = p->next;
    delete p;
    return true;
}

void printStackTopDown(const Stack &s) {
    cout << "Isi Stack Akhir: ";
    for (Node* p = s.top; p != nullptr; p = p->next) {
        cout << p->value << " ";
    }
    cout << "\n";
}

int main() {
    Stack s;
    createList(s);

    int n;
    cin >> n;                

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;          
        if (cmd == "push") {
            int x;
            cin >> x;        
            push(s, x);
        } else if (cmd == "pop") {
            pop(s);         
        } 
    }

    printStackTopDown(s);

}
