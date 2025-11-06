#include "stack.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Inisialisasi stack kosong
void createStack(Stack* s){
    // Set top = -1 menandakan stack kosong
    s->top = -1;
}

// Menambahkan elemen ke stack
void push(Stack* s, int x){
    // Cek stack penuh
    if(s->top >= NMAX - 1){
        cout << "Stack penuh! Tidak bisa push." << endl;
        return;
    }
    // Naikkan top untuk menunjuk ke posisi kosong berikutnya
    s->top++;
     // Masukkan data x ke posisi top
    s->data[s->top] = x;
}

// Menghapus dan return elemen teratas stack
int pop(Stack* s){
    // Cek stack kosong
    if(s->top == -1){
        cout << "Stack kosong! Tidak bisa pop." << endl;
        return -1;  
    }
    // Simpan nilai yang akan di-pop
    int nilai = s->data[s->top];
    s->top--; // Turunkan top (elemen dianggap terhapus)
    return nilai;// return nilai yang dihapus
}

void printInfo(const Stack s){
    // cek apakah stack ada elemt atau tidak
    if(s.top == -1){
        cout << "Stack kosong!" << endl;
        return;
    }
    
    cout << "[TOP] ";
    // looping untuk jelah semua isi stack
    for (int i = s.top; i >= 0; --i){
        cout << s.data[i];
        if (i > 0) cout << " ";
    }
    cout << "\n";
}

void balikStack(Stack* s){
    if(s->top <= 0){
        return;  // Stack kosong atau cuma 1 elemen
    }
    
    int temp[NMAX];
    int count = s->top + 1;
    
    // Copy ke array temporary
    for(int i = 0; i <= s->top; i++){
        temp[i] = s->data[i];
    }
    
    // Balik urutannya
    for(int i = 0; i < count; i++){
        s->data[i] = temp[count - 1 - i];
    }
}

void pushAscending(Stack *s, int x){
    if(s->top >= NMAX - 1){
        cout << "Stack penuh! Tidak bisa push." << endl;
        return;
    }
    
    // Jika stack kosong, langsung push
    if(s->top == -1){
        s->top++;
        s->data[s->top] = x;
        return;
    }
    
    // Stack sementara untuk menyimpan elemen yang lebih besar dari x
    Stack temp;
    temp.top = -1;
    
    // Pop elemen yang lebih besar dari x ke stack temporary
    while(s->top >= 0 && s->data[s->top] > x){
        temp.top++;
        temp.data[temp.top] = s->data[s->top];
        s->top--;
    }
    
    // Push x
    s->top++;
    s->data[s->top] = x;
    
    // Push kembali elemen dari temp ke stack asli
    while(temp.top >= 0){
        s->top++;
        s->data[s->top] = temp.data[temp.top];
        temp.top--;
    }
}

void getInputStream(Stack* s){
    cout << "Masukkan angka (pisahkan dengan spasi, tekan Enter untuk selesai): ";
    
    string line;
    getline(cin, line);  // Baca satu baris penuh
    
    // Jika line kosong, langsung return
    if(line.empty()){
        cout << "Tidak ada input." << endl;
        return;
    }
    
    // Parse string menjadi angka-angka
    stringstream ss(line);
    int x;
    
    while(ss >> x){
        push(s, x);
    }
}