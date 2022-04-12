#pragma once
/**
 * Header file for the Matrix class.
 * 
 * @author Yossi Elias
 * @since 2022
 */



#include <iostream>
#include <vector>
namespace zich {
    class Matrix {

    private:
        std::vector<std::vector<double> > _mat;
        static void string2vector(std::string s, std::vector<double> & v, size_t & col, size_t & row);
        static void checkLegal(std::vector<double> & v, int col, int row);
        void checkLegalOper(const Matrix &c2) const;
        void checkLegalMul(const Matrix &c2) const;

    public:
        //-------------------------------------
        // Constructors:
        // -------------------------------------
        Matrix(std::vector<double> v, int row, int col);
        Matrix(Matrix& other);
        Matrix();

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
        Matrix operator+=(const Matrix &c1);
        Matrix operator-=(const Matrix &c1) ;
        Matrix operator*=(const Matrix &c1) ;

        //-------------------------------------
        // friend global binary operators
        //-------------------------------------
        friend Matrix operator-(const Matrix &c1, const Matrix &c2);

        friend Matrix operator*(Matrix &c1, const Matrix &c2);

        friend Matrix operator+(const Matrix &c1, const Matrix &c2);

        friend Matrix operator-(const Matrix &c1, double d);

        friend Matrix operator*(double d, const Matrix &c1);

        friend Matrix operator*(const Matrix &c1, double d);

        friend Matrix operator+(const Matrix &c1, double d);

        friend Matrix operator-=(Matrix &c1, double d);

        friend Matrix operator*=(Matrix &c1, double d);

        friend Matrix operator+=(Matrix &c1, double d);

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

    }; // end of class Matrix
}