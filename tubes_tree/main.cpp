#include "tree.cpp"
#include <iostream>

int main() {
    Tree osis;

    // Struktur utama OSIS
    osis.add("Ketua OSIS", "Wakil Ketua");
    osis.add("Ketua OSIS", "Sekretaris");
    osis.add("Ketua OSIS", "Bendahara");
    osis.add("Ketua OSIS", "SekBid Keagamaan");
    osis.add("Ketua OSIS", "SekBid Kominfo");
    osis.add("Ketua OSIS", "SekBid Bela Negara");

    // Anak-anak dari SekBid
    osis.add("SekBid Keagamaan", "Ketua SekBid Keagamaan");
    osis.add("SekBid Keagamaan", "Anggota SekBid Keagamaan");

    osis.add("SekBid Kominfo", "Ketua SekBid Kominfo");
    osis.add("SekBid Kominfo", "Anggota SekBid Kominfo");
    
    osis.add("SekBid Bela Negara", "Ketua SekBid Bela Negara");
    osis.add("SekBid Bela Negara", "Anggota SekBid Bela Negara");

    std::cout << "Struktur Organisasi OSIS:\n";
    osis.display();

    return 0;
}
