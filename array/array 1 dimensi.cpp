#include <iostream>
using namespace std;

int main() {
    // Membuat array 1 dimensi dengan tipe data int
    int array_1d[10] ;
    int ukuran = 5;  // Ukuran array secara eksplisit
	int angka = 0;
    int jumlah = 0;
    
    // mencetak hasil yang akan di jumlah beb
    for (int i = 0; i < 5; i++){
    	cout << "masukan angka " <<1<< " = ";
    	cin >> array_1d[i];
    	angka+=array_1d[i];
	}

    // Menghitung jumlah elemen dalam array
    for (int i = 0; i < ukuran; i++) {
        jumlah += array_1d[i];
    }

    // Menghitung rata-rata elemen dalam array
    double rata_rata = (double)jumlah / ukuran;

    // Menampilkan hasil
    cout << "Array 1D: ";
    for (int i = 0; i < ukuran; i++) {
        cout << array_1d[i] << " ";
    }
    cout << endl;

    cout << "Jumlah elemen: " << jumlah << endl;
    cout << "Rata-rata elemen: " << rata_rata << endl;

    return 0;
}

