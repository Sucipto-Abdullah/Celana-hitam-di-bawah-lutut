#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 15; //Menentukan kapasitas maksimal dari antrian

struct DataPenumpang {
    string nama_penumpang;
    string kelas_penerbangan;
    string tujuan_penerbangan;
    int umur;
    int tarif;
};

struct Queue {
    int front, rear;
    DataPenumpang data[MAX];
};

void createQueue(Queue &Q);
bool isFull(Queue Q);
bool isEmpty(Queue Q);
void enqueue(Queue &Q, DataPenumpang d);
void dequeue(Queue &Q, DataPenumpang &d);
void display(Queue Q);

#endif
