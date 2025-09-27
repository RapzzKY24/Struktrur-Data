#include <iostream>
#include <vector>
using namespace std;

void inputDataMatrik(vector<vector<int>>& arr,int baris,int kolom){
    for(int i= 0 ; i < baris ; i++){
        for(int j = 0 ; j < kolom ; j++){
             cout << "Masukkan elemen [" << i << "][" << j << "]: ";
             cin >> arr[i][j];
        }
    }
}

void printMatriks(vector<vector<int>>& arr, int baris, int kolom) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < baris; i++) {
        cout << "[ ";
        for (int j = 0; j < kolom; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "]" << endl;
    }
}


int main(){
     int baris, kolom;
    cout << "Masukkan jumlah baris: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom: ";
    cin >> kolom;

    vector<vector<int>> arr(baris, vector<int>(kolom));
    
    inputDataMatrik(arr, baris, kolom);
    printMatriks(arr, baris, kolom);

    return 0;
}