#include <iostream>
using namespace std;

// inisialiasi sebuah prosedur bernama filterGenap yang menerima 2 parameter array dan n(jumlah elemen aray) bertipe integer
void filterGenapArray(int arr[], int n) {
    // berikan looping untuk memasukkan nilai pada array sesuai jumlah n
    for (int i = 0; i < n; i++) {
        cout << "Masukkan elemen bilangan ke-" << i << ": ";
        cin >> arr[i];
    }
    cout << "Bilangan genap pada array tersebut adalah: " ;
    // berikan looping untuk membongkar semua isi pada array
    for (int i = 0; i < n; i++) {
        // jika isi array berupa bil genap maka print bilangan tersebut
        if (arr[i] % 2 == 0) {
            // cetak bilangan genap pada array
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void nilaiMaksimumMinimumMhs(int arr[],int n){
     // berikan looping untuk memasukkan nilai pada array sesuai jumlah n
    for (int i = 0; i < n; i++) {
        cout << "Masukkan jumlah nilai mahasiswa ke-" << i << ": ";
        cin >> arr[i];
    }
    // anggap nilai max dan min nilai pertama di array
    int max = arr[0];
    int min = arr[0];

    // bongkar isi array
    for(int i = 0 ; i < n; i++){
        // jika isi di array[i] lebih besar maka ubah nilai max
        if(arr[i] > max){
            max = arr[i];
            // cetak nilai max
            cout << "Nilai maksimum: " << max << endl;
        }
    } 

    //bongkar isi array
     for(int i = 0 ; i < n; i++){
        // jika isi di array[i] lebih kecil maka ubah nilai min
        if(arr[i] < min){
            min = arr[i];
            // cetak nilai min
            cout << "Nilai minimum: " << min << endl;
        }
    } 

}

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    int arr[n]; 
   
    nilaiMaksimumMinimumMhs(arr, n);

    return 0;
}
