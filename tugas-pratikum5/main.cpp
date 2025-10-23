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

void search_list(Node* head,int value){
    Node* temp = head;
    int position = 1;
    bool found = false;

    while(temp != nullptr){
        if(temp->data == value){
            cout << "Data ditemukan pada node ke-" << position << endl;
            found = true;
            return;
        }
        temp = temp->next;
        position++;
    }
    if(!found){
        cout << "Data tidak ada dalam list" << endl; 
    }
}

//jika perlu print
void print_list(Node *head){
    Node* temp = head;
    while(temp){
        cout << temp->data << endl;
        temp = temp->next;
    }
}


int main(){
    Node* head = nullptr;
    int val,key,n;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    cout << "Input data: ";
    for(int i=0 ; i < n ; i++){
        cin >> val;
        insert_first(head,val);
    }
    
    cout << "Masukkan data yang ingin dicari: ";
    cin >> key;
    search_list(head,key);

    return 0;
}