#include "tree.cpp"
#include <iostream>

int main() {
    Tree organisasi;

    // Tambah struktur organisasi
    organisasi.add("CEO", "Manager Keuangan");
    organisasi.add("Manager Keuangan", "Staff Akuntansi");

    organisasi.add("CEO", "Manager Produksi");
    organisasi.add("Manager Produksi", "Operator Mesin");

    std::cout << "Struktur Organisasi Perusahaan:\n";
    organisasi.display();

    return 0;
}
