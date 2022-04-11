#pragma once
/**
 * Header file for the Matrix class.
 * 
 * @author Ofir Pele
 * @since 2017
 */


#include <iostream>
#include <vector>
namespace zich {
    class Matrix {

    private:
        std::vector<std::vector<double> > _mat;
        void string2vector(std::string s,  std::vector<double> & d);
        void checkLegal(std::vector<double> & v, int col, int row);
        void checkLegalOper(const Matrix &c1, const Matrix &c2) const;

    public:

        // Constructor:
        Matrix(std::vector<double> v, int row, int col);
//            checkLegal(v, col, row);
//            this->_mat.resize(row);
//            for (int i= 0 ; i< row; i++){
//                this->_mat.at(i).resize(col);
//            }
//            for (size_t r=0, i=0; r<row; r++){
//                for (size_t c = 0; c < col; ++c) {
//                    this->_mat.at(r).at(c) = v.at(i);
//                    i++;
//                }
//            }
//        };
        //-------------------------------------

        //-------------------------------------
        // getters
        //-------------------------------------
        std::vector<std::vector<double>> getMat() const {
            return this->_mat;
        }
        int getRow() const{
            return int(this->_mat.size());
        }
        int getColmn() const{
            if (this->getRow()>0) {
                return int(this->_mat.at(0).size());
            }
            else {
                return 0;
            }
        }
        //-------------------------------------

        //-------------------------------------
        //basic operators
        //-------------------------------------
        friend Matrix operator++(Matrix & c1);
        friend Matrix operator--(Matrix & c1);

        Matrix operator++(int);
        Matrix operator--(int);

        //----------------------------------
        // unary operator
        //----------------------------------


        Matrix operator-() const;

        Matrix operator+() const;
        //----------------------------------------
        // binary operators
        //----------------------------------------

//        Matrix operator+(const Matrix &other) const;

        Matrix operator+=(const Matrix &other);

        Matrix operator-=(const Matrix &other) ;

        Matrix operator*=(const Matrix &other) ;


        //-------------------------------------
        // friend global binary operators
        //-------------------------------------
        friend Matrix operator-(const Matrix &c1, const Matrix &c2);

        friend Matrix operator*(Matrix &c1, const Matrix &c2);

        friend Matrix operator+(const Matrix &c1, const Matrix &c2);

        friend Matrix operator-(double d, const Matrix &c2);

        friend Matrix operator*(double d, const Matrix &c2);

        friend Matrix operator*(const Matrix &c2, double d);

        friend Matrix operator+(const Matrix &c2, double d);

        friend Matrix operator-=(Matrix &c2, double d);

        friend Matrix operator*=(Matrix &c2, double d);
//        friend Matrix operator*=(const Matrix &c2, double d);
        //Todo: maybe add: d*=M

        friend Matrix operator+=(Matrix &c2, double d);

        friend bool operator==(const Matrix &c1, const Matrix &c2);

        friend bool operator!=(const Matrix &c1, const Matrix &c2);

        friend bool operator<(const Matrix &c1, const Matrix &c2);

        friend bool operator>(const Matrix &c1, const Matrix &c2);

        friend bool operator>=(const Matrix &c1, const Matrix &c2);

        friend bool operator<=(const Matrix &c1, const Matrix &c2);


        //----------------------------------
        // friend global IO operators
        //----------------------------------
        friend std::ostream& operator<< (std::ostream& output, const Matrix& c);
        friend std::istream& operator>> (std::istream& input , Matrix& c);
        //-------------------------------------
        void checkLegalMul(Matrix c1, const Matrix &c2);
    }; // end of class Matrix
}