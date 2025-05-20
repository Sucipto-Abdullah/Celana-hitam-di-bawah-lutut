#include <iostream>
using namespace std;

int main() {
    // Membuat array 2 dimensi dengan tipe data int
    int array_2d[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
	
	
    int jumlah = 0;
    int baris = 3;
    int kolom = 3;
    int total_elemen = baris * kolom;

    // Menghitung jumlah elemen dalam array
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            jumlah += array_2d[i][j];
        }
    }

    // Menghitung rata-rata elemen dalam array
    double rata_rata = (double)jumlah / total_elemen;

    // Menampilkan hasil
    cout << "Array 2D:" << endl;
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << array_2d[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Jumlah elemen: " << jumlah << endl;
    cout << "Rata-rata elemen: " << rata_rata << endl;

    return 0;
}


