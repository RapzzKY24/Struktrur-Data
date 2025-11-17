#include <iostream>
#include <string>

using namespace std;
// Kapasitas maksimum queue (cukup untuk contoh: A, B, C, dst.)
const int MAX = 5;


struct Queue {
    string data[MAX]; // menyimpan plat / nama mobil
    int front;        // indeks elemen paling depan
    int rear;         // indeks elemen paling belakang
    int count;        // jumlah elemen di dalam queue
};

// Inisialisasi queue supaya kosong
void initQueue(Queue &q) {
    q.front = 0;
    q.rear  = -1;
    q.count = 0;
}

// Cek apakah queue kosong
bool isEmpty(const Queue &q) {
    return q.count == 0;
}

// Cek apakah queue penuh
bool isFull(const Queue &q) {
    return q.count == MAX;
}

// ENQUEUE: masukkin mobil ke antrian
bool enqueue(Queue &q, const string &mobil) {
    if (isFull(q)) {
        return false; // gagal kalau penuh
    }
    q.rear = (q.rear + 1) % MAX; // circular queue
    q.data[q.rear] = mobil;
    q.count++;
    return true;
}

// DEQUEUE: keluarkan mobil dari antrian (yang paling depan)
bool dequeue(Queue &q, string &mobil) {
    if (isEmpty(q)) {
        return false; // gagal kalau kosong
    }
    mobil = q.data[q.front];
    q.front = (q.front + 1) % MAX;
    q.count--;
    return true;
}

// Print isi queue (urutan dari front ke rear)
void printQueue(const Queue &q, const string &namaQueue) {
    cout << namaQueue << " tersisa: ";
    if (isEmpty(q)) {
        cout << "(kosong)" << endl;
        return;
    }

    for (int i = 0; i < q.count; i++) {
        int idx = (q.front + i) % MAX;
        cout << q.data[idx];
        if (i != q.count - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    Queue Q_Masuk; // antrean mobil masuk
    Queue Q_Cuci;  // antrean area cuci (hanya 1 mobil aktif)
    initQueue(Q_Masuk);
    initQueue(Q_Cuci);

    string temp;

    //Mobil A dan Mobil B tiba, masukkan ke Q_Masuk.
    enqueue(Q_Masuk, "Mobil A");
    enqueue(Q_Masuk, "Mobil B");

    //Cek apakah Q_Cuci kosong. Jika kosong, pindahkan Mobil A dari Q_Masuk ke Q_Cuci.
    if (isEmpty(Q_Cuci)) {
        dequeue(Q_Masuk, temp);    // ambil Mobil A dari Q_Masuk
        enqueue(Q_Cuci, temp);     // pindah ke Q_Cuci
    }

    //Mobil C tiba, masukkan ke Q_Masuk.
    enqueue(Q_Masuk, "Mobil C");

    //Mobil D selesai dicuci (keluarkan dari Q_Cuci).
    dequeue(Q_Cuci, temp); // keluarkan mobil yang sedang dicuci

    //Cek lagi, apakah Q_Cuci kosong. Jika kosong, pindahkan Mobil B dari Q_Masuk ke Q_Cuci.
    if (isEmpty(Q_Cuci)) {
        dequeue(Q_Masuk, temp);    // ambil Mobil B dari Q_Masuk
        enqueue(Q_Cuci, temp);     // pindah ke Q_Cuci
    }

    //Tampilkan status akhir kedua queue
    cout << "=== STATUS AKHIR ===" << endl;
    printQueue(Q_Masuk, "Q_Masuk");
    printQueue(Q_Cuci,  "Q_Cuci");

    return 0;
}
