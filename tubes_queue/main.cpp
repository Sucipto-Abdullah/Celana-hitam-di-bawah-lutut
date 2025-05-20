#include "queue.cpp"
#include <iostream>
using namespace std;

int main() {
    Queue antrianBisnis, antrianEkonomi;
    createQueue(antrianBisnis);
    createQueue(antrianEkonomi);

    DataPenumpang daftarPenumpang[] = {
        {"Salsa", "Bisnis", "Jepang", 33, 20000000},
        {"Raka", "Ekonomi", "Lombok", 27, 1300000},
        {"Tiara", "Bisnis", "Bali", 41, 5800000},
        {"Yadi", "Ekonomi", "Malaysia", 24, 1563000},
        {"Linka", "Bisnis", "Korea Selatan", 36, 21000000}
    };

    for (int i = 0; i < 5; i++) {
        if (daftarPenumpang[i].tarif >= 2000000) {
            enqueue(antrianBisnis, daftarPenumpang[i]);
        } else {
            enqueue(antrianEkonomi, daftarPenumpang[i]);
        }
    }

    cout << "=== Daftar Penumpang Kelas Bisnis ===\n";
    display(antrianBisnis);

    cout << "\n=== Daftar Penumpang Kelas Ekonomi ===\n";
    display(antrianEkonomi);

    DataPenumpang sedangDiproses;
    cout << "\n>> Memproses penumpang dari antrian bisnis...\n";
    dequeue(antrianBisnis, sedangDiproses);
    cout << "Penumpang: " << sedangDiproses.nama_penumpang << "\n";
    cout << "Kelas: " << sedangDiproses.kelas_penerbangan << "\n";
    cout << "Tujuan: " << sedangDiproses.tujuan_penerbangan << "\n";

    cout << "\n=== Sisa Antrian Bisnis ===\n";
    display(antrianBisnis);
    cout << "\n=== Sisa Antrian Ekonomi ===\n";
    display(antrianEkonomi);

    return 0;
}
