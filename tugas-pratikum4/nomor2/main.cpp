#include <iostream>
#include <iomanip>
using namespace std;

//deklarasi struct alias dengan nama Mahasiswa
typedef struct {
    string name;
    int grade;
} Mahasiswa;

// Membuat alias "address" untuk pointer ke struct elmList
typedef struct elmList *address;

// membuat struktur dari node 
typedef struct elmList {
    Mahasiswa data;
    address next;
} elmList;

// membuat struct dengan nama alias
typedef struct {
    address first;
} List;

// meinisialisasi prosedur untuk membuat list
void create_list(List &L) {
    L.first = nullptr;
}

// membuat sebuah fungsi dengan tipe address yang mengembalikan sebuah alamat, untuk membuat element pada node
address new_element(Mahasiswa data) {
    address P = new elmList();
    P->data = data;
    P->next = nullptr;
    return P;
}

//membuat prosedur untuk menambahkan data di awal
void insert_first(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

//membuat prosedur untuk memprint semua isi data pada list
void print_list(List L) {
    address p = L.first;
    if (p == nullptr) {
        cout << "List kosong.\n";
        return;
    }
    while (p != nullptr) {
        cout << "Nama  : " << p->data.name << endl;
        cout << "Nilai : " << p->data.grade << endl;
        p = p->next;
    }
}

//fungsi bertipe data float , untuk mencari rata-rata
float average(List L) {
    int grade_sum = 0;
    int count = 0;
    address p = L.first;
    if (p == nullptr) {
        cout << "List kosong.\n";
        return 0.0;
    }
    while (p != nullptr) {
        grade_sum += p->data.grade;
        ++count;
        p = p->next;
    }
    // static cast untuk membuat menjadi decimal
    return static_cast<float>(grade_sum) / count;
}

//main program
int main() {
    List L;
    create_list(L);

    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Mahasiswa M;
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Masukkan nama mahasiswa: ";
        cin >> M.name;
        cout << "Masukkan nilai mahasiswa: ";
        cin >> M.grade;

        address P = new_element(M);
        insert_first(L, P);
    }

    cout << "\nDaftar mahasiswa:\n";
    print_list(L);

    float avg = average(L);
    cout << fixed << setprecision(2);
    cout << "Rata-rata nilai: " << avg << endl;

    return 0;
}
