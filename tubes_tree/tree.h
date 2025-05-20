#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <string>
// Struktur node untuk menyimpan data karyawan
struct Node {
    std::string nama;
    std::vector<Node*> anak;

    Node(const std::string& n) : nama(n) {}
};

// Class Tree untuk manajemen struktur organisasi
class Tree {
private:
    Node* root;
    Node* cari(Node* node, const std::string& nama);
    void tampil(Node* node, int level);
    void hapus(Node* node);

public:
    Tree();               // Konstruktor
    ~Tree();              // Destruktor
    void add(const std::string& atasan, const std::string& bawahan);  // Tambah anak
    void display();       // Tampilkan pohon
};
#endif