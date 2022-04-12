#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Matrix.hpp"
using namespace zich;


int main()
{
    Matrix m1;
    Matrix m2;

    cout << "Enter numbers for first matrix: ";
    cin >> m1;
    cout << "The matrix is: " <<endl;
    cout << m1 <<endl<<endl;
    cout << "Enter numbers for second matrix: " <<endl;
    cin >> m2;
    cout << "The matrix is: " <<endl;
    cout << m2 <<endl<<endl;

    cout << "m1+m1=" <<endl;
    cout << m1+m2 <<endl<<endl;

    cout << "m1-m1=" <<endl;
    cout << m1-m1 <<endl<<endl;

    cout << "m1*m1=" <<endl;
    cout << m1*m1 <<endl<<endl;

    cout << "After (m1-=87) m1=" <<endl;
    m1-=87;
    cout << m1 <<endl<<endl;

    cout << "-m2=" <<endl;
    cout << -m2 <<endl<<endl;



    return 0;
}