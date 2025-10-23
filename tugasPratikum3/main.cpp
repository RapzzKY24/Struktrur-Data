#include <iostream>
using namespace std;

// input matriks 3x3
void inputMatriks(int Matriks2D[3][3]) {
    for(int i = 0 ; i < 3 ; i++ ){
        for(int j = 0 ; j < 3 ; j++){
            cout << "Masukkan elemen [" << i << "][" << j << "]: ";
            cin >> Matriks2D[i][j];
        }
    }
}

// cetak matriks 3x3
void printMatriks(int matriks2D[3][3]) {
    for(int i = 0 ; i < 3 ; i++){
        cout << "[ ";
        for(int j = 0 ; j < 3 ; j++){
            cout << matriks2D[i][j] << " ";
        }
        cout << "]" << endl;
    }
}


void tukarPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void tukarIsiArray(int matriksA[3][3], int matriksB[3][3], int x, int y) {
    tukarPointer(&matriksA[x][y], &matriksB[x][y]);
}

int main() {
    int matriksA[3][3];
    int matriksB[3][3];
    int x,y; 
    
    cout << "Input Matriks A" << endl;
    inputMatriks(matriksA);

    cout << "Input Matriks B" << endl;
    inputMatriks(matriksB);

    cout << "\nIsi Matriks A:" << endl;
    printMatriks(matriksA);

    cout << "\nIsi Matriks B:" << endl;
    printMatriks(matriksB);

    
    cout << "Masukkan posisi x yang ingin ditukar: " ;
    cin >> x;

    cout << "Masukkan posisi y yang ingin ditukar: ";
    cin >> y;

    cout << "\nMenukar elemen." << endl;
    tukarIsiArray(matriksA, matriksB,x,y);

    cout << "\nIsi Matriks A setelah ditukar:" << endl;
    printMatriks(matriksA);

    cout << "\nIsi Matriks B setelah ditukar:" << endl;
    printMatriks(matriksB);

    return 0;
}
