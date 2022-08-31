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

void problem_4c(){

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

double dot(std::vector<double> x, std::vector<double> y){

    if (x.size() != y.size())
        throw std::invalid_argument("expected x and y to be the same size");

    double sum = 0.;

    for (int i = 0; i < x.size(); i++)
        sum += x[i] * y[i];

    return sum;
}

void problem_4e(){

    std::vector<double> x, y;

    x.resize(5);
    y.resize(5);

    x = sampledLegendre(-1., 1., 5, 2);
    y = sampledLegendre(-1., 1., 5, 4);

    double test_4e_01 = dot(x,y);

    x.resize(10);
    y.resize(10);

    x = sampledLegendre(-1., 1., 10, 2);
    y = sampledLegendre(-1., 1., 10, 4);

    double test_4e_02 = dot(x,y);

    x.resize(15);
    y.resize(15);

    x = sampledLegendre(-1., 1., 15, 2);
    y = sampledLegendre(-1., 1., 15, 4);

    double test_4e_03 = dot(x,y);

    std::cout << test_4e_01 << std::endl;
    std::cout << test_4e_02 << std::endl;
    std::cout << test_4e_03 << std::endl;
}

void problem_4b(){

    double test_4b_00, test_4b_01, test_4b_02, test_4b_03, test_4b_04, test_4b_05;

    test_4b_00 = Legendre(0.5, 0);
    test_4b_01 = Legendre(0.5, 1);
    test_4b_02 = Legendre(0.5, 2);
    test_4b_03 = Legendre(0.5, 3);
    test_4b_04 = Legendre(0.5, 4);
    test_4b_05 = Legendre(0.5, 5);

    if (test_4b_00 == 1.){
        std::cout << "Test 0 passed." << std::endl;
    } else {
        std::cout << "Test 0 failed." << std::endl;
    }

    if (test_4b_01 == 0.5){
        std::cout << "Test 1 passed." << std::endl;
    } else {
        std::cout << "Test 1 failed." << std::endl;
    }
    if (test_4b_02 == -0.125){
        std::cout << "Test 2 passed." << std::endl;
    } else {
        std::cout << "Test 2 failed." << std::endl;
    }

    if (test_4b_03 == -0.4375){
        std::cout << "Test 3 passed." << std::endl;
    } else {
        std::cout << "Test 3 failed." << std::endl;
    }

    if (test_4b_04 == (-37./128.)){
        std::cout << "Test 4 passed." << std::endl;
    } else {
        std::cout << "Test 4 failed." << std::endl;
    }

    if (test_4b_05 == (23./256.)){
        std::cout << "Test 5 passed." << std::endl;
    } else {
        std::cout << "Test 5 failed." << std::endl;
    }
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
    problem_4b();
    std::cout << std::endl;

    // Problem 4c solution.
    std::cout << "Problem 4c solution:" << std::endl;
    std::vector<double> test_4c_00;
    test_4c_00.resize(5);
    test_4c_00 = sampledLegendre(-1., 1., 5, 2);
    for (int i = 0; i < 5; i++)
        std::cout << test_4c_00[i] << std::endl;
    problem_4c();
    std::cout << std::endl;

    //Problem 4e solution.
    std::cout << "Problem 4e solution:" << std::endl;
    problem_4e();

    return 0;
}
