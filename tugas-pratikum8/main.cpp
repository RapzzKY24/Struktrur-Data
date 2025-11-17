#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    string minuman;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
    int count;
};

void initQueue(Queue &q) {
    q.front = NULL;
    q.rear = NULL;
    q.count = 0;
}

bool isEmpty(Queue q) {
    return q.front == NULL;
}

bool isFull(Queue q) {
    return q.count >= 5;
}

void enqueue(Queue &q, string nama, string minuman) {
    if (isFull(q)) {
        cout << "\nAntrian penuh!\n";
        return;
    }

    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->minuman = minuman;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q.front = q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
    q.count++;
    cout << "\nPesanan berhasil ditambahkan!\n";
}

void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "\nBelum ada pesanan!\n";
        return;
    }

    Node* temp = q.front;
    cout << "\nPesanan novri selesai dilayani.\n";
    
    q.front = q.front->next;
    if (q.front == NULL) {
        q.rear = NULL;
    }
    delete temp;
    q.count--;
}

void display(Queue q) {
    if (isEmpty(q)) {
        cout << "\nAntrian kosong!\n";
        return;
    }

    cout << "\n=== ANTRIAN PESANAN MINUMAN ===\n";
    Node* temp = q.front;
    int i = 1;
    while (temp != NULL) {
        cout << i << ". " << temp->nama << endl;
        i++;
        temp = temp->next;
    }
}

void displayMenu() {
    cout << "\n=== ANTRIAN PESANAN MINUMAN ===\n";
    cout << "1. Tambah Pesanan\n";
    cout << "2. Layani Pesanan\n";
    cout << "3. Lihat Antrian\n";
    cout << "4. Keluar\n";
    cout << "Pilih menu: ";
}

int main() {
    Queue q;
    initQueue(q);
    
    int pilihan;
    string nama, minuman;

    do {
        displayMenu();
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Nama pelanggan: ";
                getline(cin, nama);
                cout << "Menu: ";
                getline(cin, minuman);
                enqueue(q, nama, minuman);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                display(q);
                break;

            case 4:
                cout << "\nTerima kasih!\n";
                break;

            default:
                cout << "\nPilihan tidak valid!\n";
        }

        if (pilihan != 4) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
        }

    } while (pilihan != 4);

    return 0;
}