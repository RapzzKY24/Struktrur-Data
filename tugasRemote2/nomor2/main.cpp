#include <iostream>

using namespace std;

void inputDataProduk(int arr[],int n=5){
    for(int i = 0 ; i < n ; i++){
        cout << "Masukkan data produk ke-" << i+1 << ": " ;
        cin >> arr[i];
    }
}

void printDataProduk(int arr[], int n=5) {
    cout << "Menampilkan seluruh data produk: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl; 
}

int jumlahProduk(int arr[],int n=5){
    int jumlahProduk = 0;
    for(int i = 0 ; i < n ; i++){
        jumlahProduk += arr[i];
    }
    return jumlahProduk;
}

int produkMaksimum(int arr[],int n=5){
    int maxIdx = 0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > arr[maxIdx]){
            maxIdx = i;
        }
    }
    return maxIdx; 
}

int produkMinimum(int arr[],int n=5){
    int minIdx = 0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] < arr[minIdx]){
            minIdx = i;
        }
    }
    return minIdx;
}

int main(){
    int arr[5];
    //inputdata
    inputDataProduk(arr,5);
    //printData
    printDataProduk(arr,5);
    //jumlahproduk
    int jumlahProd = jumlahProduk(arr,5);
    cout << "Jumlah produk yang tersedia adalah: "<< jumlahProd << endl;
    // maksimum
    int idxMax = produkMaksimum(arr, 5);
    cout << "Tertinggi = produk ke-" << idxMax+1 << " (" << arr[idxMax] << ")" << endl;
    // minimum
    int idxMin = produkMinimum(arr, 5);
    cout << "Terendah = produk ke-" << idxMin+1 << " (" << arr[idxMin] << ")" << endl;
    return 0;
}