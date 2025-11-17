#include <iostream>
#include <string>

using namespace std;
// Maksimal jumlah elemen queue
const int MAX = 5;

struct Queue {
    string data[MAX]; // array untuk menyimpan nama siswa
    int front;        // indeks elemen paling depan (yang akan keluar duluan)
    int rear;         // indeks elemen paling belakang (yang baru masuk)
    int count;        // jumlah elemen saat ini di dalam queue
};

// Inisialisasi queue supaya kosong
void initQueue(Queue &q) {
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}

// Cek apakah queue sudah penuh
bool isFull(const Queue &q) {
    return q.count == MAX;
}

// Cek apakah queue kosong
bool isEmpty(const Queue &q) {
    return q.count == 0;
}

// Operasi ENQUEUE: masukkin nama ke antrian
bool enqueue(Queue &q, const string &nama) {
    if (isFull(q)) {
        // kalau penuh, gagal masukkin
        return false;
    }
    // pakai rumus circular queue: (rear + 1) mod MAX
    q.rear = (q.rear + 1) % MAX;
    q.data[q.rear] = nama;
    q.count++;
    return true;
}

// Operasi DEQUEUE: keluarkan nama dari antrian (yang paling depan)
bool dequeue(Queue &q, string &nama) {
    if (isEmpty(q)) {
        // kalau kosong, ga ada yang bisa dikeluarin
        return false;
    }
    // ambil nama di posisi front
    nama = q.data[q.front];
    // geser front ke elemen berikutnya (circular)
    q.front = (q.front + 1) % MAX;
    q.count--;
    return true;
}

// Menampilkan sisa antrian setelah beberapa siswa dilayani
void printSisaAntrian(const Queue &q) {
    if (isEmpty(q)) {
        cout << "Tidak ada siswa yang tersisa dalam antrian." << endl;
        return;
    }

    cout << "Siswa yang masih dalam antrian: ";

    // loop dari front sebanyak count elemen (circular)
    for (int i = 0; i < q.count; i++) {
        int index = (q.front + i) % MAX;
        cout << q.data[index];
        if (i != q.count - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    Queue q;
    initQueue(q);

    // Input 5 nama siswa sesuai urutan kedatangan
    cout << "Masukkan 5 nama siswa sesuai urutan kedatangan:" << endl;
    for (int i = 0; i < MAX; i++) {
        string nama;
        getline(cin, nama);

        // masukkan ke queue
        if (!enqueue(q, nama)) {
            cout << "Antrian penuh, tidak bisa menambahkan: " << nama << endl;
        }
    }

    // Simulasi kasir melayani 3 siswa pertama
    string served1, served2, served3;

    if (dequeue(q, served1)) {
        cout << "Siswa yang dilayani pertama: " << served1 << endl;
    }

    if (dequeue(q, served2)) {
        cout << "Siswa yang dilayani kedua: " << served2 << endl;
    }

    if (dequeue(q, served3)) {
        cout << "Siswa yang dilayani ketiga: " << served3 << endl;
    }

    // Tampilkan siswa yang masih ada di antrian
    printSisaAntrian(q);

    return 0;
}
