#include <iostream>

using namespace std;

//prosedur input nilai mahasiswa
void inputNilai(float *nilai, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Masukkan nilai mahasiswa ke-" << i + 1 << ": ";
        cin >> *(nilai + i);  
    }
}


// function hitung Rata rata
float hitungRataRata(float *nilai, int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += *(nilai + i); 
    }
    return total / n;
}

int main(){
    int m;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> m;

    float nilai[m];          
    float *ptr = nilai;      

   
    inputNilai(ptr, m);

   
    float rata = hitungRataRata(ptr, m);

   
    cout << "\nRata-rata nilai mahasiswa: " << rata << endl;

    return 0;
}
