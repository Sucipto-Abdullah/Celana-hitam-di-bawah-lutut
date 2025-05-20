#include "tree.h"
#include <iostream>

// Konstruktor: Membuat akar pohon dengan nama "CEO"
Tree::Tree() {
    root = new Node("CEO");  
}

// Destruktor: Menghapus semua node saat Tree dihancurkan
Tree::~Tree() {
    hapus(root);  
}

// Fungsi rekursif untuk menghapus node dan semua anak-anaknya
void Tree::hapus(Node* node) {
    for (size_t i = 0; i < node->anak.size(); ++i) {
        hapus(node->anak[i]);   // Hapus semua anak terlebih dahulu
    }
    delete node;   
}

// Fungsi pencarian node berdasarkan nama, mulai dari node tertentu
Node* Tree::cari(Node* node, const std::string& nama) {
    if (node->nama == nama) return node; 
    // Jika tidak cocok, cari di setiap anaknya secara rekursif
    for (size_t i = 0; i < node->anak.size(); ++i) {
        Node* hasil = cari(node->anak[i], nama);   // Rekursi ke anak
        if (hasil) return hasil;   
    }
    return 0;  
}

// Menambahkan node anak (bawahan) ke node tertentu (atasan)
void Tree::add(const std::string& atasan, const std::string& bawahan) {
    Node* nodeAtasan = cari(root, atasan);   
    if (nodeAtasan) {
        nodeAtasan->anak.push_back(new Node(bawahan));   // Tambah anak baru ke vektor anak
    } else {
        std::cout << "Atasan \"" << atasan << "\" tidak ditemukan.\n";  
    }
}

// Menampilkan isi pohon dari node tertentu, dengan indentasi sesuai level
void Tree::tampil(Node* node, int level) {
    for (int i = 0; i < level; ++i) std::cout << "  ";  // Cetak spasi sesuai level
    std::cout << "- " << node->nama << "\n";  // Tampilkan nama node

    for (size_t i = 0; i < node->anak.size(); ++i) {
        tampil(node->anak[i], level + 1);   // Tampilkan anak-anaknya dengan level lebih dalam
    }
}

// Fungsi publik untuk menampilkan seluruh pohon mulai dari akar
void Tree::display() {
    tampil(root, 0);                
}