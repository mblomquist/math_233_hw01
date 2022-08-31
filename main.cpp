#include <iostream>
#include <vector>

// Problem 2
void problem_2() {
    std::cout << "Hello, World!" << std::endl;
}

// Problem 3c
#define MM 3
#define NN 4
#define LL 5

// Dynamic allocation of a three-dimensional array
void problem_3c() {
// Define my_array
    auto*** my_array = new double**[MM];
    for (int i = 0; i < MM; i++){
        my_array[i] = new double*[NN];
        for (int j = 0; j < NN; j++){
            my_array[i][j] = new double[LL];
        }
    }
    double val = 0;
// Assign values to my_array
    for (int i = 0; i < MM; i++){
        for (int j = 0; j < NN; j++){
            for (int k = 0; k < LL; k++){
                my_array[i][j][k] = val;
                val++;
            }
        }
    }
// Print out my_array
    for (int i = 0; i < MM; i++){
        for (int j = 0; j < NN; j++){
            for (int k = 0; k < LL; k++){
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

std::vector<double> sampledLegendre(double a, double b, int N, int n){

    if (a < -1. || b > 1.)
        throw std::invalid_argument("the range for a & b is out of bounds");

    double dx = (b - a) / (N - 1.);

    std::vector<double> output;
    output.resize(N);

    for (int i = 0; i < N; i++){
        output[i] = Legendre(a+dx*i, n);
    }

    return output;

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
    std::vector<double> test_4c_00;
    test_4c_00.resize(5);
    test_4c_00 = sampledLegendre(-1., 1., 5, 2);
    for (int i = 0; i < 5; i++)
        std::cout << test_4c_00[i] << std::endl;
    problem_4c();

    return 0;
}
