
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;

#include "Matrix.hpp"
namespace zich{

    void Matrix::checkLegal(vector<double> & v, int col, int row){
        if (col * row != v.size()) {
            throw invalid_argument("size error");
        }
        if (col < 0){
            throw invalid_argument("size error");
        }
        if (row < 0) {
            throw invalid_argument("size error");
        }
    }

//constructor:
    Matrix::Matrix(std::vector<double> v, int row, int col) {
        checkLegal(v, col, row);
        this->_mat.resize(size_t(row));
        for (size_t i= 0 ; i< row; i++){
            this->_mat.at(i).resize(size_t(col));
        }
        for (size_t r=0, i=0; r<row; r++){
            for (size_t c = 0; c < col; ++c) {
                this->_mat.at(r).at(c) = v.at(i);
                i++;
            }
        }
    }

//----------------------------------------
// basic operators
//----------------------------------------

    Matrix operator++(Matrix &c1){
        return c1+=1;
    }

    Matrix operator--(Matrix &c1){
        return c1-=1;
    }

    Matrix Matrix::operator++(int) {
        for (size_t r= 0 ; r < this->getRow(); r++) {
            for (size_t c = 0; c < this->getColmn(); c++) {
                this->_mat.at(r).at(c) += 1;
            }
        }
        return *this;
    }

    Matrix Matrix::operator--(int) {
        for (size_t r= 0 ; r < this->getRow(); r++) {
            for (size_t c = 0; c < this->getColmn(); c++) {
                this->_mat.at(r).at(c) -= 1;
            }
        }
        return *this;
    }

//----------------------------------------
// unary operators
//----------------------------------------

    Matrix Matrix::operator+() const {
        vector<double> v;
        for (size_t r= 0 ; r < this->getRow(); r++) {
            for (size_t c = 0; c < this->getColmn(); c++) {
                v.push_back(this->_mat.at(r).at(c));
            }
        }
        return Matrix(v, this->getRow(),this->getColmn());
    }

    Matrix Matrix::operator-() const {
        vector<double> v;
        for (size_t r= 0 ; r < this->getRow(); r++) {
            for (size_t c = 0; c < this->getColmn(); c++) {
                v.push_back(-1*(this->_mat.at(r).at(c)));
            }
        }
        return Matrix(v, this->getRow(),this->getColmn());
    }

//----------------------------------------
// binary operators
//----------------------------------------

    Matrix Matrix::operator+=(const Matrix &c1) {
        checkLegalOper(*this, c1);
        for (size_t r= 0 ; r < c1.getRow(); r++) {
            for (size_t c = 0; c < c1.getColmn(); c++) {
                this->_mat.at(r).at(c) += c1._mat.at(r).at(c);
            }
        }
        return *this;
    }
    Matrix Matrix::operator-=(const Matrix &c1) {
        checkLegalOper(*this, c1);
        for (size_t r= 0 ; r < c1.getRow(); r++) {
            for (size_t c = 0; c < c1.getColmn(); c++) {
                this->_mat.at(r).at(c) -= c1._mat.at(r).at(c);
            }
        }
        return *this;
    }
    Matrix Matrix::operator*=(const Matrix &c1) {
        checkLegalMul(*this, c1);
        //resize new matrix:
        vector<vector<double>> temp;
        temp.resize(size_t(this->getRow()));
        for (size_t i= 0 ; i< this->getRow(); i++){
            temp.at(i).resize(size_t(c1.getColmn()));
        }

        for(size_t r = 0; r < this->getRow(); ++r){
            for(size_t i = 0; i < c1.getColmn(); ++i){
                for(size_t c = 0; c < this->getColmn(); ++c){
                    temp.at(r).at(i) += this->_mat.at(r).at(c) * c1._mat.at(c).at(i);
                }
            }
        }
        //init this matrix size:
        this->_mat.clear();
        this->_mat.resize(temp.size());
        for (size_t i= 0 ; i< this->getRow(); i++){
            this->_mat.at(i).resize(size_t(c1.getColmn()));
        }
        //set this matrix to new one:
        for (size_t r=0, i=0; r< this->getRow(); r++){
            for (size_t c = 0; c < this->getColmn(); ++c) {
                this->_mat.at(r).at(c) = temp.at(r).at(c);
            }
        }
        return *this;
    }

//----------------------------------------
// friend global binary operators
//----------------------------------------

    Matrix operator-(const Matrix& c1, const Matrix& c2) {
        c1.checkLegalOper(c1, c2);
        vector<double> v;
        for (size_t r= 0 ; r < c1.getRow(); r++) {
            for (size_t c = 0; c < c1.getColmn(); c++) {
                v.push_back(c1._mat.at(r).at(c) - c2._mat.at(r).at(c));
            }
        }
        return Matrix(v, c1.getRow(),c1.getColmn());
    }

    Matrix operator*(Matrix &c1, const Matrix &c2) {
        c1.checkLegalMul(c1, c2);
        //resize new matrix:
        vector<vector<double>> temp;
        temp.resize(size_t(c1.getRow()));
        for (size_t i= 0 ; i< c1.getRow(); i++){
            temp.at(i).resize(size_t(c2.getColmn()));
        }

        for(size_t r = 0; r < c1.getRow(); ++r){
            for(size_t i = 0; i < c2.getColmn(); ++i){
                for(size_t c = 0; c < c1.getColmn(); ++c){
                    temp.at(r).at(i) += c1._mat.at(r).at(c) * c2._mat.at(c).at(i);
                }
            }
        }
        vector<double> tempVector;
        tempVector.push_back(-1);
        Matrix ans(tempVector, 1, 1);
        //init new matrix size:
        ans._mat.clear();
        ans._mat.resize(temp.size());
        for (size_t i= 0 ; i< ans.getRow(); i++){
            ans._mat.at(i).resize(size_t(c2.getColmn()));
        }
        //set new matrix:
        for (size_t r=0, i=0; r< ans.getRow(); r++){
            for (size_t c = 0; c < ans.getColmn(); ++c) {
                ans._mat.at(r).at(c) = temp.at(r).at(c);
            }
        }
        return ans;


//        c1.checkLegalOper(c1, c2);
//        vector<double> v;
//        for (size_t r= 0 ; r < c1.getRow(); r++) {
//            for (size_t c = 0; c < c1.getColmn(); c++) {
//                v.push_back(c1._mat.at(r).at(c) * c2._mat.at(r).at(c));
//            }
//        }
//        return Matrix(v, c1.getRow(),c1.getColmn());
    }

    Matrix operator+(const Matrix &c1, const Matrix &c2){
        c1.checkLegalOper(c1, c2);
        vector<double> v;
        for (size_t r= 0 ; r < c1.getRow(); r++) {
            for (size_t c = 0; c < c1.getColmn(); c++) {
                v.push_back(c1._mat.at(r).at(c) + c2._mat.at(r).at(c));
            }
        }
        return Matrix(v, c1.getRow(),c1.getColmn());
    }

//    Matrix operator-(double d, const Matrix &c1){
//        vector<double> v;
//        for (size_t r= 0 ; r < c1.getRow(); r++) {
//            for (size_t c = 0; c < c1.getColmn(); c++) {
//                v.push_back(d - c1._mat.at(r).at(c));
//            }
//        }
//        return Matrix(v, c1.getRow(),c1.getColmn());
//    }

    Matrix operator*(double d, const Matrix &c1){
        vector<double> v;
        for (size_t r= 0 ; r < c1.getRow(); r++) {
            for (size_t c = 0; c < c1.getColmn(); c++) {
                v.push_back(c1._mat.at(r).at(c) * d);
            }
        }
        return Matrix(v, c1.getRow(),c1.getColmn());
    }

    Matrix operator*(const Matrix &c1, double d){
        vector<double> v;
        for (size_t r= 0 ; r < c1.getRow(); r++) {
            for (size_t c = 0; c < c1.getColmn(); c++) {
                v.push_back(c1._mat.at(r).at(c) * d);
            }
        }
        return Matrix(v, c1.getRow(),c1.getColmn());
    }

//                    Todo:
//    Matrix operator+(double d, const Matrix &c2){
//        vector<double> a = {0,1};
//        return Matrix(a, 1,1);
//    }

    Matrix operator-=(Matrix &c1, double d){
        for (size_t r= 0 ; r < c1.getRow(); r++) {
            for (size_t c = 0; c < c1.getColmn(); c++) {
                c1._mat.at(r).at(c) = c1._mat.at(r).at(c) - d;
            }
        }
        return c1;
    }

    Matrix operator*=(Matrix &c1, double d){
        for (size_t r= 0 ; r < c1.getRow(); r++) {
            for (size_t c = 0; c < c1.getColmn(); c++) {
                c1._mat.at(r).at(c) = c1._mat.at(r).at(c) * d;
            }
        }
        return c1;
    }

    Matrix operator+=(Matrix &c1, double d){
        for (size_t r= 0 ; r < c1.getRow(); r++) {
            for (size_t c = 0; c < c1.getColmn(); c++) {
                c1._mat.at(r).at(c) = c1._mat.at(r).at(c) + d;
            }
        }
        return c1;
    }

    bool operator==(const Matrix& c1, const Matrix& c2) {
        c1.checkLegalOper(c1, c2);
        for (size_t r= 0 ; r < c1.getRow(); r++) {
            for (size_t c = 0; c < c1.getColmn(); c++) {
                if (c1._mat.at(r).at(c) != c2._mat.at(r).at(c)){
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix& c1, const Matrix& c2) {
        return !(c1 == c2);
    }

    bool operator<(const Matrix& c1, const Matrix& c2) {
        c1.checkLegalOper(c1, c2);
        double sum1, sum2;
        for (size_t r= 0 ; r < c1.getRow(); r++) {
            for (size_t c = 0; c < c1.getColmn(); c++) {
                sum1 += c1._mat.at(r).at(c);
                sum2 += c2._mat.at(r).at(c);
            }
        }
        if (sum1<sum2){
            return true;
        }
        return false;
    }

    bool operator>(const Matrix& c1, const Matrix& c2) {
        c1.checkLegalOper(c1, c2);
        double sum1, sum2;
        for (size_t r= 0 ; r < c1.getRow(); r++) {
            for (size_t c = 0; c < c1.getColmn(); c++) {
                sum1 += c1._mat.at(r).at(c);
                sum2 += c2._mat.at(r).at(c);
            }
        }
        if (sum1>sum2){
            return true;
        }
        return false;
    }

    bool operator>=(const Matrix& c1, const Matrix& c2) {
        c1.checkLegalOper(c1, c2);
        return c1==c2 || c1>c2;
    }

    bool operator<=(const Matrix& c1, const Matrix& c2) {
        c1.checkLegalOper(c1, c2);
        return c1==c2 || c1<c2;
    }





//----------------------------------------
// friend global IO operators
//----------------------------------------

    ostream& operator<< (ostream& output, const Matrix& c) {
        for (size_t r= 0 ; r < c.getRow(); r++){
            output << "[";
            for (size_t cl= 0 ; cl< c.getColmn(); cl++){
                if (cl != c.getColmn()-1) {
                    output << c._mat.at(r).at(cl) << +" ";
                }
                else{
                    output << c._mat.at(r).at(cl) << +"]";
                    if (r!= c.getRow()-1){
                        output<<endl;
                    }
                }
            }
        }
        return output;
    }

    void string2vector(string s,  vector<double> & v, size_t & col, size_t & row){
        row = size_t(count(s.begin(),s.end(),'['));
        string tempNum = "";
        double tempD;
        for (size_t i = 0; i < s.size(); i++) {
            switch (s.at(i)) {
                case '[':
                    break;
                case ']':
                    if (tempNum.size() > 0){
                        tempD = stod(tempNum);
                        tempNum = "";
                        v.push_back(tempD);
                    }
                    if (i!=(s.size()-1) && s.at(i+1) != ','){
                        throw invalid_argument("string not OK");
                    }
                    break;
                case ' ':
                    if (tempNum.size() > 0){
                        tempD = stod(tempNum);
                        tempNum = "";
                        v.push_back(tempD);
                    }
                    break;
                case ',':
                    if (i!=(s.size()-1) && s.at(i+1) != ' '){
                        throw invalid_argument("string not OK");
                    }
                    break;
                default:
                    tempNum += s.at(i);
            }
        }
        col = v.size()/row;
    }

    istream& operator>> (istream& input, Matrix& c) {
        string s;
        std::getline (input,s);
        vector<double> v;
        size_t col, row;
        string2vector(s, v, col , row);
        c.checkLegal(v, col, row);
        c._mat.resize(row);
        for (size_t i= 0 ; i< row; i++){
            c._mat.at(i).resize(col);
        }
        for (size_t r=0, i=0; r<row; r++){
            for (size_t cl = 0; cl < col; ++cl) {
                c._mat.at(r).at(cl) = v.at(i);
                i++;
            }
        }
        return input;
    }



    static istream& getAndCheckNextCharIs(istream& input, char expectedChar) {
        char actualChar;
        input >> actualChar;
        if (!input) {return input;}

        if (actualChar!=expectedChar) {
            // failbit is for format error
            input.setstate(ios::failbit);
        }
        return input;
    }


    void Matrix::checkLegalOper(const Matrix &c1, const Matrix &c2) const {
        if (c1.getRow() != c2.getRow()){
            throw invalid_argument("size error");
        }
        if (c1.getColmn() != c2.getColmn()){
            throw invalid_argument("size error");
        }
    }

    void Matrix::checkLegalMul(Matrix c1, const Matrix &c2) {
        if (c1.getColmn() != c2.getRow()){
            throw invalid_argument("size error");
        }
    }


}



















