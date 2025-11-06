#include <iostream>
#include <string>

using namespace std;

struct Account {
    string username;
    string password;
};

struct Node {
    Account data;
    Node* next;
    Node* prev;
};

struct List {
    Node* first;
    Node* last;
};

void createList(List &l){
    l.first = nullptr;
    l.last = nullptr;
}

void dealokasi(Node* r){
    delete r;
}

bool isEmpty(const List &l){
    return l.first == nullptr;
}

Node* createNewElm(Account data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertLast(Node* p , List &l){
    if(isEmpty(l)){
        l.first = p;
        l.last = p;
    }else{
        p->prev = l.last;
        l.last->next = p;
        l.last = p;
    }
}

Node* findAccount(string username,const List& l){
    Node* temp = l.first;
    while(temp != nullptr){
        if(temp->data.username == username){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void signUp(Account akun, List &l){
    if (l.first == nullptr) {
        insertLast(createNewElm(akun), l);
        return;
    }
    if (findAccount(akun.username, l)) {
        cout << "Account has been registered" << endl;
        return;
    }
    insertLast(createNewElm(akun),l);
}


void deleteFirst(List &l, Node* &p){
    p = l.first;
    l.first = p->next;
    l.first->prev = nullptr;
    p->next = nullptr;
}


void deleteAfter(Node* q, Node* &p){
    p = q->next;
    q->next = p->next;
    
    if(p->next != nullptr){
        p->next->prev = q;
    }
    
    p->next = nullptr;
    p->prev = nullptr;
}


void deleteLast(List &l, Node* &p){
    p = l.last;
    l.last = p->prev;
    l.last->next = nullptr;
    p->prev = nullptr;
}


void removeAccount(const string& username, List &l){   
    if(isEmpty(l)){
        cout << "List kosong." << endl;
        return;
    }
    
    Node* target = findAccount(username, l);
    
    if(target == nullptr){
        cout << "Tidak ada akun bernama " << username << " dalam list" << endl;
        return;
    }
    
    Node* p;
    
    if(target == l.first && target == l.last){
        p = l.first;
        l.first = nullptr;
        l.last = nullptr;
        delete p;
    }
    else if(target == l.first){
        deleteFirst(l, p);
        delete p;
    }
    else if(target == l.last){
        deleteLast(l, p);
        delete p;
    }
    else{
        deleteAfter(target->prev, p);
        delete p;
    }
    
    cout << "Akun " << username << " telah dihapus" << endl;
}

void printList(List &l){
    if(isEmpty(l)){
        cout << "\n--- List Akun Kosong ---" << endl;
        return;
    }

    Node* p = l.first;
    int i = 1; 
    
    cout << "\n--- Daftar Akun ---" << endl; 
    while(p != nullptr){
        cout << i << ". Username: " << p->data.username << endl;
        cout << "   Password: " << p->data.password << endl;
        p = p->next;
        i++;
    }
    cout << "-------------------" << endl; 
}



int main(){
    List l;
    createList(l);
    string targetUsername;
    
    Account a1 = {"budi", "pass123"};
    Account a2 = {"citra", "pass456"};
    Account a3 = {"dodi", "pass789"};
    Account a4 = {"erna", "pass101"};

    signUp(a1,l);
    signUp(a2,l);
    signUp(a3,l);
    signUp(a4,l);

    cout << "List Awal:";
    printList(l);

    cout << "Masukkan username yang ingin dihapus: ";
    cin >> targetUsername;
    
    removeAccount(targetUsername, l);
    cout << "List setelah dihapus" << endl;
    printList(l);

    return 0;
}