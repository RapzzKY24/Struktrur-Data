#include <iostream>

using namespace std;

struct Node {
    int number;
    Node *next;
};

void create_list(Node *&head) {
    head = nullptr;
}

Node *create_node(int value) {
    Node *node = new Node;
    node->number = value;
    node->next = nullptr;
    return node;
}

void insert_first(Node *&head, int value) {
    Node *node = create_node(value);
    node->next = head;
    head = node;
}

void insert_last(Node *&head, int value) {
    Node *node = create_node(value);
    if (head == nullptr) {
        head = node;
        return;
    }

    Node *tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = node;
}

void print_list(Node *head) {
    if (head == nullptr) {
        cout << "List kosong.\n";
        return;
    }

    cout << "Isi list: ";
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->number;
        if (curr->next != nullptr) {
            cout << " -> ";
        }
        curr = curr->next;
    }
    cout << endl;
}

void clear_list(Node *&head) {
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node *head;
    create_list(head);

    bool running = true;
    while (running) {
        cout << "\n=== MENU LIST ANGKA ===\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Out\n";
        cout << "Pilih opsi: ";

        int pilihan;
        if (!(cin >> pilihan)) {
            cout << "Input tidak valid. Program dihentikan.\n";
            break;
        }

        switch (pilihan) {
            case 1: {
                cout << "Masukkan angka yang ingin ditambahkan di awal: ";
                int value;
                if (cin >> value) {
                    insert_first(head, value);
                    print_list(head);
                } else {
                    cout << "Angka tidak valid.\n";
                    running = false;
                }
                break;
            }
            case 2: {
                cout << "Masukkan angka yang ingin ditambahkan di akhir: ";
                int value;
                if (cin >> value) {
                    insert_last(head, value);
                    print_list(head);
                } else {
                    cout << "Angka tidak valid.\n";
                    running = false;
                }
                break;
            }
            case 3:
                cout << "Keluar dari program.\n";
                running = false;
                break;
            default:
                cout << "Pilihan tidak tersedia. Silakan pilih menu 1-3.\n";
                break;
        }
    }

    clear_list(head);
    return 0;
}
