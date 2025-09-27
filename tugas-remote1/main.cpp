#include <iostream> // Library standar untuk input dan output
#include <string>   // Library standar untuk menggunakan tipe data string

using namespace std; // Supaya tidak perlu menulis std:: di depan fungsi

// fungsi operasi matematika sederhana mengembalikan return void karena fungsi tidak mengembalikan nilai apapun
// function memiliki 2 param yaitu angka1 dan angka 2 mempunya tipe data float(decimal)
void printCalculation(float angka1, float angka2) {
    // operasi penjumlahan
    cout << "Hasil operasi penambahan: " << angka1 + angka2 << endl;
    //operasi pengurangan
    cout << "Hasil operasi pengurangan: " << angka1 - angka2 << endl;
    //operasi perkalian
    cout << "Hasil operasi perkalian: " << angka1 * angka2 << endl;
    //kondisi jika pembagi tidak 0 maka operasi pembagian dijalankan
    if (angka2 != 0) {
        cout << "Hasil operasi pembagian: " << angka1 / angka2 << endl;
    //jika pembagi maka akan ada error bahwa pembagi tidak boleh 0
    } else {
        cout << "Error: Tidak dapat dibagi dengan 0!" << endl;
    }
}

// Array global untuk angka satuan (0–9), index 0 dikosongin biar gampang akses langsung
string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", 
                   "enam", "tujuh", "delapan", "sembilan"};

// Array global untuk angka belasan (10–19)
string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", 
                    "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};

// Fungsi angkaKeKata memiliki nilai return string dan param int yang namanya angka 
//untuk mengubah angka (0–100) menjadi kata dalam bahasa Indonesia
string angkaKeKata(int angka) {
    if (angka == 0) {
        // Jika angka 0 → kembalikan "nol"
        return "nol";
    } else if (angka >= 1 && angka <= 9) {
        // Jika angka 1–9 → ambil langsung dari array satuan
        return satuan[angka];
    } else if (angka >= 10 && angka <= 19) {
        // Jika angka 10–19 → ambil dari array belasan (indeks mulai dari 0 = sepuluh)
        return belasan[angka - 10];
    } else if (angka >= 20 && angka <= 99) {
        // Jika angka 20–99 → dipecah jadi puluhan dan satuan
        int puluh = angka / 10;  // ambil digit puluhan
        int sat = angka % 10;    // ambil digit satuan
        // Bentuk kata dasar puluhan, contoh: "dua puluh"
        string hasil = satuan[puluh] + " puluh";
        // Jika masih ada satuan (misal 25 → "dua puluh lima")
        if (sat > 0) {
            hasil += " " + satuan[sat];
        }
        return hasil;
    } else if (angka == 100) {
        // Jika angka 100 → langsung "seratus"
        return "seratus";
    }
    // Jika input di luar jangkauan (misal negatif atau >100)
    return "angka di luar jangkauan";
}


// Membuat fungsi dengan nama segitigaSamaKakiTerbalik
// Fungsi ini tidak mengembalikan nilai (void) dan menerima parameter 'angka' sebagai tinggi segitiga
void segitigaSamaKakiTerbalik(int angka) {
    // Perulangan dari baris paling atas sampai baris terbawah
    for (int i = angka; i >= 1; i--) {
        
        // Cetak spasi di depan supaya segitiga terlihat rapi di tengah
        for (int s = 0; s < angka - i; s++) {
            cout << "  ";  // tiap kali kasih 2 spasi
        }

        // Cetak angka menurun di sisi kiri segitiga
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // Cetak bintang di bagian tengah segitiga
        cout << "* ";

        // Cetak angka menaik di sisi kanan segitiga
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        // Pindah ke baris berikutnya
        cout << endl;
    }

    // Setelah selesai, cetak 1 bintang di bagian paling bawah
    for (int s = 0; s < angka; s++) cout << "  ";  // kasih spasi biar bintang ada di tengah
    cout << "*" << endl;
}

// ===================== MAIN PROGRAM =====================
int main() {
    int pilihan;
    
    do {
        // Tampilkan menu
        cout << "\n=== MENU PROGRAM ===" << endl;
        cout << "1. Kalkulator" << endl;
        cout << "2. Konversi Angka ke Kata" << endl;
        cout << "3. Segitiga Sama Kaki Terbalik" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;
        
        if (pilihan == 1) {
            // Menu Kalkulator
            float angka1, angka2;
            cout << "\n--- KALKULATOR ---" << endl;
            cout << "Masukkan angka 1: ";
            cin >> angka1;
            cout << "Masukkan angka 2: ";
            cin >> angka2;
            printCalculation(angka1, angka2);
        }
        else if (pilihan == 2) {
            // Menu Konversi Angka ke Kata
            int angka;
            cout << "\n--- KONVERSI ANGKA KE KATA ---" << endl;
            cout << "Masukkan angka (0-100): ";
            cin >> angka;
            
            if (angka < 0 || angka > 100) {
                cout << "Angka harus antara 0 sampai 100!" << endl;
            } else {
                cout << "Angka " << angka << " dalam kata: " << angkaKeKata(angka) << endl;
            }
        }
        else if (pilihan == 3) {
            // Menu Segitiga
            int angka;
            cout << "\n--- SEGITIGA SAMA KAKI TERBALIK ---" << endl;
            cout << "Masukkan tinggi segitiga: ";
            cin >> angka;
            segitigaSamaKakiTerbalik(angka); 
        }
        else if (pilihan == 4) {
            cout << "Terima kasih, program selesai." << endl;
        }
        else {
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }
        
    } while (pilihan != 4); // Ulang sampai pilih keluar
    
    return 0;
}
