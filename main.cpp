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
    auto*** my_array = new double**[M];
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
double Legendre(double x, int n){

    if (n < 0 || n > 5)
        throw std::invalid_argument("expected 0 <= n <= 5");

    switch (n){
        case 0 : return 1.;
        case 1 : return x;
        case 2 : return 0.5 * (3.*x*x - 1.);
        case 3 : return 0.5 * (5.*x*x*x - 3.*x);
        case 4 : return (1./8.) * (35.*x*x*x*x - 30.*x*x + 3.);
        case 5 : return (1./8.) * (63.*x*x*x*x*x - 70.*x*x*x + 15.*x);
        default : return 0.;
    }
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
    double test_4b_00, test_4b_01, test_4b_02, test_4b_03, test_4b_04, test_4b_05;

    std::cout << "Problem 4b solution:" << std::endl;
    test_4b_00 = Legendre(0.5, 0);
    test_4b_01 = Legendre(-0.4, 1);
    test_4b_02 = Legendre(0.3, 2);
    test_4b_03 = Legendre(-0.6, 3);
    test_4b_04 = Legendre(0.7, 4);
    test_4b_05 = Legendre(-0.8, 5);

    std::cout << test_4b_00 << std::endl;
    std::cout << test_4b_01 << std::endl;
    std::cout << test_4b_02 << std::endl;
    std::cout << test_4b_03 << std::endl;
    std::cout << test_4b_04 << std::endl;
    std::cout << test_4b_05 << std::endl;

    // Problem 4c solution.
    std::cout << "Problem 4c solution:" << std::endl;
    problem_4c();
    std::cout << std::endl;
    return 0;
}
