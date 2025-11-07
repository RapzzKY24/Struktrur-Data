#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk menyimpan informasi buku
struct Buku {
    string judulBuku;
    string penulis;
};

// Struktur Rak sebagai Stack dengan kapasitas 12 buku
struct RakBuku {
    Buku data[12];
    int top;
    
    // Constructor
    RakBuku() {
        top = -1;
    }
};

// Fungsi untuk menambahkan buku ke dalam rak (Push)
void Push(RakBuku &S, string judul, string penulis) {
    if (S.top >= 11) {
        cout << "Stack penuh! Tidak bisa menambah buku lagi." << endl;
        return;
    }
    S.top++;
    S.data[S.top].judulBuku = judul;
    S.data[S.top].penulis = penulis;
    cout << "Buku \"" << judul << "\" berhasil ditambahkan ke rak." << endl;
}

// Fungsi untuk mengambil buku paling atas (Pop)
void Pop(RakBuku &S, string &judul, string &penulis) {
    if (S.top < 0) {
        cout << "Stack kosong! Tidak ada buku untuk diambil." << endl;
        judul = "";
        penulis = "";
        return;
    }
    judul = S.data[S.top].judulBuku;
    penulis = S.data[S.top].penulis;
    S.top--;
    cout << "Buku \"" << judul << "\" oleh " << penulis << " berhasil diambil dari rak." << endl;
}

// Fungsi untuk mengambil buku dengan judul tertentu dan menyimpan nama penulisnya
void Get(RakBuku S, string judul, string &namaPenulis) {
    if (S.top < 0) {
        cout << "Stack kosong! Judul buku yang dicari tidak ada pada stack." << endl;
        namaPenulis = "";
        return;
    }
    
    bool ditemukan = false;
    for (int i = S.top; i >= 0; i--) {
        if (S.data[i].judulBuku == judul) {
            namaPenulis = S.data[i].penulis;
            ditemukan = true;
            cout << "Buku \"" << judul << "\" ditemukan! Penulisnya: " << namaPenulis << endl;
            return;
        }
    }
    
    if (!ditemukan) {
        cout << "Buku dengan judul \"" << judul << "\" tidak ditemukan dalam rak." << endl;
        namaPenulis = "";
    }
}

// Fungsi untuk menampilkan semua buku di rak
void TampilkanRak(RakBuku S) {
    if (S.top < 0) {
        cout << "\nRak buku kosong." << endl;
        return;
    }
    
    cout << "\n=== ISI RAK BUKU ===" << endl;
    cout << "Jumlah buku: " << (S.top + 1) << "/12" << endl;
    cout << "--------------------" << endl;
    for (int i = S.top; i >= 0; i--) {
        cout << "Posisi " << (i + 1) << ": " << S.data[i].judulBuku 
             << " oleh " << S.data[i].penulis << endl;
    }
    cout << "====================" << endl;
}

int main() {
    RakBuku rak;
    string judul, penulis;
    int pilihan;
    
    cout << "========================================" << endl;
    cout << "  PROGRAM MANAJEMEN RAK BUKU (STACK)   " << endl;
    cout << "========================================" << endl;
    
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Push (Tambah buku ke rak)" << endl;
        cout << "2. Pop (Ambil buku paling atas)" << endl;
        cout << "3. Get (Cari buku berdasarkan judul)" << endl;
        cout << "4. Tampilkan semua buku di rak" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();
        
        switch(pilihan) {
            case 1:
                cout << "\nMasukkan judul buku: ";
                getline(cin, judul);
                cout << "Masukkan nama penulis: ";
                getline(cin, penulis);
                Push(rak, judul, penulis);
                break;
                
            case 2:
                Pop(rak, judul, penulis);
                break;
                
            case 3:
                cout << "\nMasukkan judul buku yang dicari: ";
                getline(cin, judul);
                Get(rak, judul, penulis);
                break;
                
            case 4:
                TampilkanRak(rak);
                break;
                
            case 5:
                cout << "\nTerima kasih telah menggunakan program!" << endl;
                break;
                
            default:
                cout << "\nPilihan tidak valid!" << endl;
        }
    } while(pilihan != 5);
    
    return 0;
}