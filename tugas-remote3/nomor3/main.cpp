#include <iostream>

using namespace std;

// prosedur untuk input nama mahasiswa
void inputNama(char **nama, int n) {
    cin.ignore(); // membersihkan buffer newline dari input sebelumnya
    for (int i = 0; i < n; i++) {
        *(nama + i) = new char[50]; // alokasi memori tiap nama
        cout << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
        cin.getline(*(nama + i), 50); // input string ke memori
    }
}

// prosedur untuk menampilkan daftar nama mahasiswa
void tampilNama(char **nama, int n) {
    cout << "\nDaftar Nama Mahasiswa:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << *(nama + i) << endl;
    }
}

// prosedur untuk menghapus memori
void hapusMemori(char **nama, int n) {
    for (int i = 0; i < n; i++) {
        delete[] *(nama + i); // hapus tiap string
    }
    delete[] nama; // hapus array pointer
}

int main(){
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    // alokasi pointer ke pointer
    char **nama = new char*[n];

    // input nama mahasiswa
    inputNama(nama, n);

    // tampilkan semua nama
    tampilNama(nama, n);

    // hapus memori
    hapusMemori(nama, n);
    return 0;
}
