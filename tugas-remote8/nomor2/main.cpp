#include <iostream>
using namespace std;

// Maksimal jumlah elemen queue (6 pasien)
const int MAX = 6;

struct Queue {
    int data[MAX];  // array untuk menyimpan nomor antrian
    int front;      // indeks elemen paling depan (HEAD)
    int rear;       // indeks elemen paling belakang (TAIL)
    int count;      // jumlah elemen saat ini di dalam queue
};

// Inisialisasi queue supaya kosong
void initQueue(Queue &q) {
    q.front = 0;
    q.rear  = -1;
    q.count = 0;
}

// Cek apakah queue penuh
bool isFull(const Queue &q) {
    return q.count == MAX;
}

// Cek apakah queue kosong
bool isEmpty(const Queue &q) {
    return q.count == 0;
}

// Operasi ENQUEUE: masukkin nomor ke antrian
bool enqueue(Queue &q, int nomor) {
    if (isFull(q)) {
        return false;          // gagal kalau penuh
    }
    q.rear = (q.rear + 1) % MAX; // circular queue
    q.data[q.rear] = nomor;
    q.count++;
    return true;
}

// Operasi DEQUEUE: keluarkan nomor dari antrian (yang di HEAD)
bool dequeue(Queue &q, int &nomor) {
    if (isEmpty(q)) {
        return false;          // gagal kalau kosong
    }
    nomor = q.data[q.front];   // ambil nomor di front
    q.front = (q.front + 1) % MAX;
    q.count--;
    return true;
}

// AmbilNomor: generate nomor 1..6 dan masukkin ke queue
void AmbilNomor(Queue &Q) {
    cout << "=== Pemberian Nomor Antrian ===" << endl;
    for (int i = 1; i <= MAX; i++) {
        if (enqueue(Q, i)) {
            cout << "Pasien mendapat nomor antrian: " << i << endl;
        } else {
            cout << "Antrian penuh, nomor " << i << " tidak bisa diberikan." << endl;
        }
    }
    cout << endl;
}

// PanggilPasien: panggil dan keluarkan 2 pasien pertama dari antrian
void PanggilPasien(Queue &Q) {
    cout << "=== Pemanggilan Pasien ===" << endl;
    int nomor;

    for (int i = 1; i <= 2; i++) {   // panggil 2 pasien
        if (dequeue(Q, nomor)) {
            cout << "Pasien yang dipanggil ke-" << i
                 << " dengan nomor antrian: " << nomor << endl;
        } else {
            cout << "Tidak ada lagi pasien dalam antrian." << endl;
            break;
        }
    }
    cout << endl;
}

// CekAntrian: tampilkan nomor di HEAD dan TAIL setelah 2 pasien dipanggil
void CekAntrian(Queue Q) {
    // Parameter Q dibuat BY VALUE (salinan),
    // jadi isi queue asli di main tidak berubah.

    cout << "=== Cek Status Antrian ===" << endl;

    if (isEmpty(Q)) {
        cout << "Antrian kosong." << endl;
        return;
    }

    // Nomor di HEAD (paling depan)
    int headNumber = Q.data[Q.front];

    // Nomor di TAIL (paling belakang)
    int tailIndex = Q.rear;
    int tailNumber = Q.data[tailIndex];

    cout << "Nomor antrian di HEAD (paling depan): " << headNumber << endl;
    cout << "Nomor antrian di TAIL (paling belakang): " << tailNumber << endl;
    cout << endl;
}


int main() {
    Queue antrian;
    initQueue(antrian);

    //Pemberian nomor 1..6 ke 6 pasien
    AmbilNomor(antrian);

    //Panggil 2 pasien pertama
    PanggilPasien(antrian);

    //Cek nomor di HEAD dan TAIL setelah 2 pasien dipanggil
    CekAntrian(antrian);

    return 0;
}
