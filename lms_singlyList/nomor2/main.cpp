#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

struct List {
    Node* first;
};

void createList(List &l){
    l.first = nullptr;
}

Node* newElm(int x){
    Node* p = new Node;
    p->value = x;
    p->next = nullptr;
    return p;
}

void insertLast(List &l, Node* p){
    if(l.first == nullptr){
        l.first = p;
    }else{
        Node* temp = l.first;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = p;
    }
}   

Node* findNode(Node* head, int x){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->value == x){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

bool isLastNode(Node* node){
    return node != nullptr && node->next == nullptr;
}

void deleteFirst(List &l){
    if(l.first == nullptr) return;
    Node* temp = l.first;
    l.first = l.first->next;
    delete temp;
}

void deleteLast(List &l){
    if(l.first == nullptr) return;
    if(l.first->next == nullptr){
        delete l.first;
        l.first = nullptr;
        return;
    }
    Node* temp = l.first;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void deleteAfter(Node* prev){
    if(prev == nullptr || prev->next == nullptr) return;
    Node* temp = prev->next;
    prev->next = temp->next;
    delete temp;
}

void deleteElm(List &l, int x){
    Node* target = findNode(l.first, x);
    
    if(target == nullptr){
        cout << "Tidak ada elemen bernilai " << x << " dalam list" << endl;
        return;
    }
    
    if(l.first == target){
        deleteFirst(l);
        cout << "Elemen " << x << " di awal list telah dihapus" << endl;
        return;
    }
    
    if(isLastNode(target)){
        deleteLast(l);
        cout << "Elemen " << x << " di akhir list telah dihapus" << endl;
        return;
    }
    
    if(target->next != nullptr){
        int deletedValue = target->next->value;
        deleteAfter(target);
        cout << "Elemen " << deletedValue << " setelah elemen " << x << " telah dihapus" << endl;
    }
}

void printList(List &l){
    Node* p = l.first;
    while(p != nullptr){
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    List l;
    createList(l);
    Node* p;
    p = newElm(15);
    insertLast(l, p);

    p = newElm(30);
    insertLast(l, p);

    p = newElm(40);
    insertLast(l, p);

    p = newElm(50);
    insertLast(l, p);

    cout << "List awal: ";
    printList(l);
    
    int x;
    cout << "\nMasukkan elemen X untuk dihapus: ";
    cin >> x;
    deleteElm(l, x);
    cout << "List setelah dihapus: ";
    printList(l);
    
    return 0;
}
