#include <iostream>
#include "pelajaran.h"
using namespace std;

Pelajaran create_pelajaran(string namapel, string kodepel) {
    return {namapel, kodepel};
}

void tampil_pelajaran(Pelajaran pel) {
    cout << "Nama Mapel : " << pel.namaMapel << "\n";
    cout << "Kode Mapel : " << pel.kodeMapel << "\n";
}
