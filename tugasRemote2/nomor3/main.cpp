#include <iostream>
using namespace std;

#include <vector>
void inputDataMatriks(vector<vector<int>>& arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Masukkan elemen [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

void printMatriks(const vector<vector<int>>& arr, int n) {
    cout << "Matriks:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "[ ";
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

int main() {
    int n;
    cout << "Masukkan ukuran matriks persegi (n x n): ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    inputDataMatriks(arr, n);
    printMatriks(arr, n);

    return 0;
}
