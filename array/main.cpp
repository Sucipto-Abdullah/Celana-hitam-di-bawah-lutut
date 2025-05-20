#include <iostream>

int main()
{
    int matrix_a[2][2] = {
        {1, 2},
        {3, 4}
    };
    
    int matrix_b[2][2] = {
        {5, 6},
        {7, 8}
    };

    int result[2][2] = {{0, 0}, {0, 0}};

    for(int i=0; i<2; i++){
        std::cout << "| ";
        for(int j=0; j<2; j++){

            std::cout << matrix_a[i][j] + matrix_b[i][j] << " ";

        }
        std::cout << "|\n";
    }
}