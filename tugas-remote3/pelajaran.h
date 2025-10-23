#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

// Tipe data
struct Pelajaran {
    string namaMapel;
    string kodeMapel;
};

// Deklarasi fungsi & prosedur
Pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(Pelajaran pel);

#endif
