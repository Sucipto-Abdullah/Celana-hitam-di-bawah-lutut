#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>

typedef struct alas_kaki *sendal;
struct alas_kaki
{
    int key;
    std::string nama, warna, merek, bahan;
    int ukuran;
    sendal next = NULL;

    alas_kaki( int Key, std::string Nama, std::string Warna, std::string Merek, std::string Bahan, int Ukuran)
    {
        key = Key;
        nama = Nama;
        warna = Warna;
        merek = Merek;
        bahan = Bahan;
        ukuran = Ukuran;
    }
};

struct linkedList
{
    sendal front = NULL;
    sendal behind = NULL; 

    void insert(sendal item)
    {
        if (front == NULL){
            front = item;
            behind = item;
        }else{
            behind->next = item;
            behind = item;
        }
    }

    void display()
    {
        sendal index = front;
        while (index != NULL){
            if (index->next != NULL){
                std::cout << index->nama << " -> ";
            }else{
                std::cout << index->nama;
            }
            index = index->next;
        }
    }
};

struct hash_tabel
{
    private:
    int hash( int input )
    {
        return input % 10;
    }

    public:
    linkedList table[10];

    int length(){
        return (sizeof(table)/sizeof(table[0]));
    }

    void insertTable( sendal item ){
        int index = item->ukuran % length();

        table[index].insert(item);
    }

    void display(){
        for( int i=0; i < length(); i++){
            std::cout << i+1 << ". ";
            table[i].display();
            std::cout <<"\n";
        }
    }

    std::string* get(sendal sendal)
    {
        static std::string data[5];
        data[0] = sendal->nama;
        data[1] = sendal->merek;
        data[2] = sendal->ukuran;
        data[3] = sendal->bahan;
        data[4] = sendal->warna;

        return data;
    }
    std::string* at( int key )
    {
        sendal index = table[hash(key)].front;
        while (index->key != key){
            index = index->next;
        }

        static std::string data[6];
        data[0] = index->key;
        data[1] = index->nama;
        data[2] = index->merek;
        data[3] = index->ukuran;
        data[4] = index->bahan;
        data[5] = index->warna;
    }

};

#endif