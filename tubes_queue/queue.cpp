#include "queue.h"

void createQueue(Queue &Q) {  //Menginisialisasi antrian kosong
    Q.front = Q.rear = -1; 
}

bool isFull(Queue Q) {  //Mengecek apakah antrian sudah penuh
    return Q.rear == MAX - 1; 
}

bool isEmpty(Queue Q) { //Mengecek apakah antrian kosong
    return Q.front == -1;
}

void enqueue(Queue &Q, DataPenumpang d) {
    if (isFull(Q)) {
        cout << "Antrian penuh!\n";
        return;
    }
    if (isEmpty(Q)) {
        Q.front = Q.rear = 0;
    } else {
        Q.rear++;
    }
    Q.data[Q.rear] = d;
}

void dequeue(Queue &Q, DataPenumpang &d) {
    if (isEmpty(Q)) {
        cout << "Antrian kosong!\n";
        return;
    }
    d = Q.data[Q.front];
    for (int i = Q.front; i < Q.rear; i++) {
        Q.data[i] = Q.data[i + 1];
    }
    Q.rear--;
    if (Q.rear < Q.front)
        Q.front = Q.rear = -1;
}

void display(Queue Q) {
    if (isEmpty(Q)) {
        cout << "[Kosong]\n";
        return;
    }
   for (int i = Q.front; i <= Q.rear; i++) {
        cout << "- " << Q.data[i].nama_penumpang
             << " (Usia: " << Q.data[i].umur
             << ", Kelas: " << Q.data[i].kelas_penerbangan
			 << ", Tujuan: " << Q.data[i].tujuan_penerbangan
             << ", Tiket: Rp " << Q.data[i].tarif << ")\n";
    }
}
