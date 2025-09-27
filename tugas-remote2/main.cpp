#include <iostream>

using namespace std;

void inputDataMahasiswa(int arr[],int n){
    for(int i = 0 ; i < n ; i++){
        cout << "Masukkan data nilai mahasiswa ke-" << i+1 << ":" ;
        cin >> arr[i];
    }
}

int main(){
    int n ;
    int arr[n] ;
    cout << "Masukkan jumlah mahasiswa";
    cin >> n;
    inputDataMahasiswa(arr,n);
    return 0;
}