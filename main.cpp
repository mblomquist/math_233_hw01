#include <iostream>

// Problem 2
void problem_2() {
    std::cout << "Hello, World!" << std::endl;
}

// Problem 3c
#define M 3
#define N 4
#define L 5

// Dynamic allocation of a three-dimensional array
void problem_3c() {
// Define my_array
    double*** my_array = new double**[M];
    for (int i = 0; i < M; i++){
        my_array[i] = new double*[N];
        for (int j = 0; j < N; j++){
            my_array[i][j] = new double[L];
        }
    }
    double val = 0;
// Assign values to my_array
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < L; k++){
                my_array[i][j][k] = val;
                val++;
            }
        }
    }
// Print out my_array
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < L; k++){
                std::cout << my_array[i][j][k] << " ";
            }
            std::cout << "\n";
        }
        std::cout << std::endl;
    }
}

// Problem 4b solution
void problem_4b(){

}

void problem_4c(){

}
int main() {

    // Problem 2 solution.
    std::cout << "Problem 2 solution:" << std::endl;
    problem_2();
    std::cout << std::endl;

    // Problem 3c solution.
    std::cout << "Problem 3c solution:" << std::endl;
    problem_3c();
    std::cout << std::endl;

    // Problem 4b solution.
    std::cout << "Problem 4b solution:" << std::endl;
    problem_4b();
    std::cout << std::endl;

    // Problem 4c solution.
    std::cout << "Problem 4c solution:" << std::endl;
    problem_4c();
    std::cout << std::endl;
    return 0;
}
