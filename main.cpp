#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Matrix.hpp"
using namespace zich;

int main() {
    int k=1;
    int random = rand() % 1000;
//    for (double i = 0; i < 500; i++)
//    {
    double i=0;
    vector<double> vec1 = {i*random,i*random,i*random,i*random,i*random,i*random,i*random,i*random,i*random};
    Matrix matrix(vec1, 3, 3);

    vector<double> v = {i*random,i*random,i*random,i*random,i*random,i*random,i*random,i*random,i*random};
    Matrix matrix_v(v, 3, 3);

    vector<double> vec = {i*random+k,i*random+k,i*random+k,i*random+k,i*random+k,i*random+k,i*random+k,i*random+k,i*random+k};
    Matrix mat(vec, 3, 3);

    vector<double> vec1_minus = {-i*random,-i*random,-i*random,-i*random,-i*random,-i*random,-i*random,-i*random,-i*random};
    Matrix matrix_minus(vec1_minus, 3, 3);

    vector<double> vec_sub = {i*random-k,i*random,i*random,i*random,i*random-k,i*random,i*random,i*random,i*random-k};
    Matrix matrix_sub(vec_sub, 3, 3);

    vector<double> vec_ = {i*random-k,i*random-k,i*random-k,i*random-k,i*random-k,i*random-k,i*random-k,i*random-k,i*random-k};
    Matrix matrix_(vec_, 3, 3);
    cout<<matrix<<endl;
    cout<<matrix++<<endl;
    cout<<matrix<<endl;
//    cout<<matrix_v<<endl;

    if(((matrix++) == matrix_v))
        cout<<"Good"<<endl;
//        CHECK(((matrix--) == mat));
//        CHECK(((++matrix) == mat));
//        ++matrix;
//        CHECK(((--matrix) == mat));
//    }
    return 0;
}
