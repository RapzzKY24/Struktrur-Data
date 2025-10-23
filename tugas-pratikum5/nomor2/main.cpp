#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

void insert_first(Node*& head,int value){
    Node* newNode = new Node(value);
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

bool update(Node* head,int oldValue,int newValue){
    Node* temp = head;
    while (temp != nullptr)
    {
        if(temp->data == oldValue){
            temp->data = newValue;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void print_list(Node *head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){

    Node* head = nullptr;
    int oldValue,newValue,n,val;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    cout << "Input data: ";
    for(int i = 0 ; i < n ;i++){
        cin >> val;
        insert_first(head,val);
    }

    cout << "Masukkan data yang ingin diganti: ";
    cin >> oldValue;

    cout << "Masukkan nilai baru: ";
    cin >> newValue;

    if (update(head, oldValue, newValue)) {
        print_list(head);
    } else {
        cout << "Data tidak ditemukan" << endl;
    }


    return 0;
}