/******************************************
Template prepared by Kazumi Slott
CS311

Description of this program: ???????????????????

Your name: Agustin Martinez
Your programmer number: 24
Number of hours you spent: 2
Any difficulties?: None
*******************************************/
//What do you need to include? HINT: What are you using in main()?
//include your matrix.h

#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
  
  
  //Your matrices need to be of the same data type.  When you do multiplication, the data types of the 2 matrices need to be the same.
  Matrix<double> houseFunc(4, 3);
  Matrix<double> houseInfo(4, 4);
  //Create 2 input files yourself. You need to name them house_info.in and house_func.in, otherwise my auto-grader will not run your program.

  //Check matrixClient.cpp to see an example
  //create fin
  //open the first file (which file should be the first? You need to figure it out.)
  //load the data into the first matrix
  //close fin
  ifstream fin;
  //fin.open("house_inf.in");
  fin.open("house_info.in");
  //cout << "Loading House Info" << endl;
  fin >> houseInfo;
  fin.close();
  //cout << houseInfo << endl;

  //open the second file
  //load the data into the second matrix
  //close fin

  fin.open("house_func.in");
  //cout << "Loading House Func" << endl;
  fin >> houseFunc;
  fin.close();
  //cout << houseFunc << endl;

  //?????
  //use try and catch
  //In catch, show the following message.
  //cout << "SIZE ERROR" << endl;
  try {
    Matrix<double> houseResult = houseInfo * houseFunc;
    cout << houseResult << endl;
  } catch (Matrix<double>::size_error){
    cout << "SIZE ERROR" << endl;
  }

  


  
  return 0;
}
