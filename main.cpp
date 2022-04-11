#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Matrix.hpp"
using namespace zich;

int main() {
    vector<double> v = {1,2,3,4};
    Matrix m(v, 2,2);
//    std::cin >> m;
    std::cout << m << std::endl;

    vector<double> v1 = {-1,-2,-3,-4};
    Matrix m1(v1, 2,2);
//    std::cin >> m1;
    std::cout << m1 << std::endl;


//    if (m1==m)
//    m*=m1;
    std::cout << m*m1 << std::endl;
    return 0;
}
