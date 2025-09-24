/**********************************
Template prepared by Kazumi Slott
CS311

matrix class

Complete operator>>(),operator<<(), operator*(), destructor, destroy(),  
copy constructor, copy() and operator=()

For examples of matrix multiplication
https://matrix.reshish.com/multCalculation.php 

Your name: Agustin Martinez
Your programmer number: 24
Hours spent?: 4
Any difficulties?: Had to review the concepts once again
***********************************/
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

//This forward declaration of Matrix class is necessary because the following operator>> and << are using Matrix as a parameter
template <class T>
class Matrix;

//This forward declaration of operator>> is necessary Since operator<< is a template function.
template<class T>
ifstream& operator>>(ifstream& o, Matrix<T>& m);

//This forward declaration of operator<< is necessary Since operator<< is a template function.
template <class T>
ostream& operator<<(ostream& o, const Matrix<T> & m);

//Template class so we can have a matrix of any data types, int or double
template <class T>
class Matrix
{
  //friend functions so they can access the private members 
  friend ostream& operator<< <T>(ostream& o, const Matrix<T> & m);
  friend ifstream& operator>> <T>(ifstream& o, Matrix<T>& m);

private: 
  T** m; //2 dimensional dynamic array
  int R; //number of rows. R and C cannot be const because they change when we do m1 = m2
  int C; //number of columns
  void destroy();
  void copy(const Matrix<T>& source);

public: 
  Matrix(int R, int C);
  Matrix();
  ~Matrix();
  Matrix operator*(const Matrix& other);// matrix multiplication
  Matrix(const Matrix<T>& source);
  Matrix<T>& operator=(const Matrix<T>& rhs);

  
  class size_error{};//exception class 
};

//default constructor
template<class T>
Matrix<T>::Matrix()
{
  R = C = 0;
  m = NULL;
}

//constructor to create a matrix, row x col 
template<class T>
Matrix<T>::Matrix(int row, int col)
{
  R = row;
  C = col; 
  if(row <= 0 || col <= 0)
    {
      m = NULL;
      return;
    }

  //m = new T[R][C]; //this doesn't compile
  m = new T*[R]; //create a single dimensional array of pointers of the T type
  for (int i=0; i<R; i++) //create a single dimensional array for each slot of m
    m[i] = new T[C];

  //initialize each element to 0
  for(int rw = 0; rw < R; rw++)
    for(int cl = 0; cl < C; cl++)
	m[rw][cl] = 0;
}

//fill a matrix using an input file
template<class T>
ifstream& operator>>(ifstream& fin, Matrix<T>& mrx)
{
  for (int r = 0; r < mrx.R; ++r){
    for (int c = 0; c < mrx.C; ++c){

      fin >> mrx.m[r][c];
    }
  }
  return fin;
}

/*output the matrix to screen in the following format. Allocate 10 spaces for each value.
         1          1          1
         2          2          2
         3          3          3
         4          4          4 
*/
template<class T>
ostream& operator<<(ostream& o, const Matrix<T>& mrx)
{
  for (int r = 0; r < mrx.R; ++r)
  {
    for (int c = 0; c < mrx.C; ++c)
      o << setw(10) << mrx.m[r][c];
    o << endl; // end each row
  }
   return o;
  
}

//matrix multiplication
template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other)
{
  if (this->C != other.R)
    throw size_error();  // incomparable sizes

  Matrix<T> result(this->R, other.C);

  for (int i = 0; i < this->R; ++i)
    for (int j = 0; j < other.C; ++j)
    {
      T sum = T(); // zero of T
      for (int k = 0; k < this->C; ++k)
        sum += this->m[i][k] * other.m[k][j];
      result.m[i][j] = sum;
    }

  return result;
}

//destructor
template<class T>
Matrix<T>::~Matrix()
{
    destroy();
}


template<class T>
void Matrix<T>::destroy()
{
  if (m != NULL)
  {
    // delete each row first
    for (int r = 0; r < R; ++r)
      delete [] m[r];

    // delete the row pointer array
    delete [] m;

    // reset members
    m = NULL;
    R = 0;
    C = 0;
  }
}



template <class T>
Matrix<T>::Matrix(const Matrix<T>& source)
{

  m = NULL;
  R = source.R;
  C = source.C;
  copy(source);
}



template <class T>
void Matrix<T>::copy(const Matrix<T>& source)
{
  if (source.m == NULL || R <= 0 || C <= 0) {
    m = NULL;
    return;
  }

  m = new T*[R];
  for (int r = 0; r < R; ++r) {
    m[r] = new T[C];
    for (int c = 0; c < C; ++c)
      m[r][c] = source.m[r][c];
  }
}



template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
{

  if (this != &rhs) {
    destroy();        
    R = rhs.R;        
    C = rhs.C;
    copy(rhs);        
  }
  return *this;
}

#endif // end the definition here  
