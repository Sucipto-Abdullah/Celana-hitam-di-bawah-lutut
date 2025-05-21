#include "tree.h"
#include <iostream>

// Konstruktor: Membuat node root dengan nama "Ketua OSIS"
Tree::Tree() {
    root = new Node("Ketua OSIS");
}

// Destruktor: Menghapus semua node dalam tree
Tree::~Tree() {
    hapus(root);
}

// Fungsi rekursif untuk menghapus semua anak dan node itu sendiri
void Tree::hapus(Node* node) {
    for (size_t i = 0; i < node->anak.size(); ++i) {
        hapus(node->anak[i]); // Hapus anak-anak terlebih dahulu
    }
    delete node; // Hapus node saat ini
}

// Fungsi pencarian node berdasarkan nama (rekursif, DFS)
Node* Tree::cari(Node* node, const std::string& nama) {
    if (node->nama == nama) return node; // Jika cocok, kembalikan node

    for (size_t i = 0; i < node->anak.size(); ++i) {
        Node* hasil = cari(node->anak[i], nama); // Cari di anak-anak
        if (hasil) return hasil; // Jika ditemukan, kembalikan
    }

    return NULL; // Tidak ditemukan
}

// Fungsi untuk menambahkan node bawahan ke atasan tertentu
void Tree::add(const std::string& atasan, const std::string& bawahan) {
    Node* nodeAtasan = cari(root, atasan); // Cari node atasan

    if (nodeAtasan) {
        nodeAtasan->anak.push_back(new Node(bawahan)); // Tambah anak
    } else {
        std::cout << "Atasan \"" << atasan << "\" tidak ditemukan.\n";
    }
}

// Fungsi rekursif untuk menampilkan tree dengan indentasi per level
void Tree::tampil(Node* node, int level) {
    for (int i = 0; i < level; ++i) std::cout << "  "; // Indentasi
    std::cout << "- " << node->nama << "\n"; // Tampilkan nama node

    for (size_t i = 0; i < node->anak.size(); ++i) {
        tampil(node->anak[i], level + 1); // Tampilkan anak-anak
    }
}

// Fungsi utama untuk menampilkan struktur organisasi OSIS dari root
void Tree::display() {
    tampil(root, 0);
}
