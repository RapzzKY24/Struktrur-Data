#include <iostream>
#include <string>
using namespace std;

struct Pasien{
    string nama;
    string klinik;
    int usia;
};

typedef Pasien infotype;

struct Elem;             
typedef Elem* adr;        

struct Elem{
    infotype info;
    adr next;
    adr prev;
};

struct Queue{
    adr head;
    adr tail;
};

void createQueue(Queue* q){
    q->head = nullptr;
    q->tail = nullptr;
}

adr createElement(infotype data){
    adr p = new Elem;
    p->info = data;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

void enqueue(Queue &q, adr p){
    if(q.head == nullptr && q.tail == nullptr){
        q.head = p;
        q.tail = p;
    }else{
        q.tail->next = p;
        p->prev = q.tail;
        q.tail = p;
    }
}

void dequeue(Queue &q, adr &p){
    if(q.head == nullptr && q.tail == nullptr){
        p = nullptr;
    }else if(q.head == q.tail){
        p = q.head;
        q.head = nullptr;
        q.tail = nullptr;
        p->next = nullptr;
        p->prev = nullptr;
    }else{
        p = q.head;
        q.head = q.head->next;
        q.head->prev = nullptr;
        p->next = nullptr;
        p->prev = nullptr;  
    }
}

void pindahTestCovid(Queue &QReg, Queue &QCovid) {
    adr P;
    int i;

    if (QCovid.head != nullptr) {
        cout << "Pemindahan belum bisa dilakukan. Queue Test Covid masih berisi pasien." << endl;
    } else {
        i = 1;
        while (i <= 3 && QReg.head != nullptr) {
            dequeue(QReg, P);
            if (P != nullptr) {
                enqueue(QCovid, P);
                cout << "Pasien " << P->info.nama << " dipindahkan ke Queue Test Covid" << endl;
            }
            i++;
        }
        if (i <= 3) {
            cout << "Pemindahan selesai. Hanya " << (i-1) << " pasien yang dipindahkan (Queue Registrasi tidak cukup)." << endl;
        } else {
            cout << "Pemindahan 3 pasien berhasil dilakukan." << endl;
        }
    }
}

void printQueue(const string &label, const Queue &q){
    cout << "--- " << label << " ---" << endl;
    adr p = q.head;
    int i = 1;
    if(!p){
        cout << "(kosong)" << endl;
    }
    while(p){
        cout << i++ << ". " << p->info.nama
             << " | Klinik: " << p->info.klinik
             << " | Usia: " << p->info.usia << endl;
        p = p->next;
    }
    cout << endl;
}

int main(){
    Queue QReg, QCovid;
    createQueue(&QReg);
    createQueue(&QCovid);

    
    enqueue(QReg, createElement({"Alice", "Umum", 24}));
    enqueue(QReg, createElement({"Budi", "Gigi", 31}));
    enqueue(QReg, createElement({"Citra", "Anak", 12}));
    enqueue(QReg, createElement({"Doni", "Umum", 45}));
    enqueue(QReg, createElement({"Eka", "Kandungan", 29}));

    printQueue("Queue Registrasi (awal)", QReg);
    printQueue("Queue Test Covid (awal)", QCovid);

    cout << "== Pindah 3 pasien ke Queue Test Covid ==" << endl;
    pindahTestCovid(QReg, QCovid);
    cout << endl;

    printQueue("Queue Registrasi (setelah pindah)", QReg);
    printQueue("Queue Test Covid (setelah pindah)", QCovid);

    cout << "== Proses 1 pasien di Queue Test Covid (dequeue) ==" << endl;
    adr served = nullptr;
    dequeue(QCovid, served);
    if(served){
        cout << "Dilayani: " << served->info.nama << " (hapus node dari memori)" << endl;
        delete served; 
    }else{
        cout << "Queue Test Covid kosong." << endl;
    }
    cout << endl;

    printQueue("Queue Test Covid (setelah 1x dequeue)", QCovid);

    return 0;
}
