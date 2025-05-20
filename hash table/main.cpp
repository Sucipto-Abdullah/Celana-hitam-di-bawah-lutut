#include "hash_table.h"

int main()
{
    sendal sendal_1 = new alas_kaki( 23, "sendal Swallow", "Hijau", "Swallow", "Karet", 42);
    sendal sendal_2 = new alas_kaki( 41, "Carefill", "Coklat", "Carefill", "Kulit", 43);
    sendal sendal_3 = new alas_kaki(43, "Sendal Swallow", "Biru", "Swallow", "Kulit", 42);

    hash_tabel sendal;

    sendal.insertTable(sendal_1);
    sendal.insertTable(sendal_2);
    sendal.insertTable(sendal_3);

    sendal.display();
}