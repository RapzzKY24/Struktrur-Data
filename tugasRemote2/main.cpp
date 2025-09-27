#include <iostream>

using namespace std;

void inputDataMahasiswa(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        while (true) { 
            cout << "Masukkan data nilai mahasiswa ke-" << i + 1 << ": ";
            cin >> arr[i];

            if (arr[i] >= 0 && arr[i] <= 100) {
                break; 
            } else {
                cout << "Nilai tidak valid! Harus 0 - 100." << endl;
            }
        }
    }
}

float rataRataMhs(int arr[],int n){
    int jumlahNilai = 0;
    for(int i = 0 ; i < n ; i++){
        jumlahNilai += arr[i];
    }
    return jumlahNilai / n;
}

int nilaiMaksimum(int arr[],int n){
    int max = arr[0];
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max; 
}

int nilaiMinimum(int arr[],int n){
    int min = arr[0];
    for(int i = 0 ; i < n ; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

int main(){
    int n ;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    int arr[n] ;
    //func input nilai
    inputDataMahasiswa(arr,n);
    //func rata"
    float rataRata = rataRataMhs(arr,n);
    cout << "Rata rata nilai mahasiswa: " << rataRata << endl ;
    //nilai maksimum
    int maxNilai = nilaiMaksimum(arr,n);
    cout << "Nilai maksimum: " << maxNilai << endl;
    //nilai minimum
    int minNilai = nilaiMinimum(arr,n);
    cout << "Nilai minimum: " << minNilai << endl;
    return 0;
}