#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

int length( int matrix[] )
{
    int ukuran_total = sizeof(matrix);
    int ukuran_baris = sizeof(matrix[0]);
    int ukuran_kolom = sizeof(matrix[0][0]);

    static int result[2];
    result[0] = ukuran_total/ukuran_baris;
    result[1] = ukuran_baris/ukuran_kolom;

    return result[0];
}

bool same_column_row( int matrix_1[], int matrix_2[] )
{
    if( length(matrix_1) == length(matrix_2) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

int* add( int matrix_1[], int matrix_2[] )
{   
    if( same_column_row(matrix_1, matrix_2) ){
        int result[sizeof(matrix_1)/sizeof(matrix_1[0])]
        return 1;
    }else{
        return 0;
    }
}

int *subtract( int matrix_1[], int matrix_2[] )
{

}

int *multiply( int matrix_1[], int matrix_2[] )
{

}

#endif