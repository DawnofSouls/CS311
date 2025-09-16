/***********************************
Kazumi Slott
CS311
9-12-2025

A test client to test the array class
************************************/
#include <istream>
using namespace std;
#include "array.h"

void func()
{
  array<char> c(2);
  cout << "\nc is at " << &c << endl;
  cout << "filling c, char array with 2 slots" << endl;
  cin >> c;
  cout << "c = " << c << endl;
} //c (object that contains ar and size) is destroyed here
  //Without a destructor, the dynamic array that was pointed to by c.ar would be left in the heap memory but we wouldn't be able to access it.

int main()
{
  char ch; //used for cin.get()
  
  array<int> a(5);
  cout << endl << "a is at " << &a << endl;
  
  cout << "filling a, int array with 5 slots" << endl;
  cin >> a;
  cout << "a = " << a << endl;

  cout << "ENTER";
  cin.ignore(); //clear the input stream
  cin.get(ch); //wait for the user to enter to hit enter
  
  array<double> b; //using the defaul constructor. No array is created.
  cout << endl << "b is at " << &b << endl;

  cout << "ENTER";
  cin.get(ch); //wait for the user to enter to hit enter
  
  func();  

  cout << "ENTER";
  cin.ignore(); //clear the input stream
  cin.get(ch); //wait for the user to enter to hit enter

  array<int> d(5);
  cout << "\nd is at " << &d << endl;
  cout << "filling d, int array with 5 slots" << endl;
  cin >> d;
  
  cout << "ENTER";
  cin.ignore(); //clear the input stream
  cin.get(ch); //wait for the user to enter to hit enter    
  
  array<int> e(4);
  cout << "\ne is at " << &e << endl;
  cout << "filling e, int array with 4 slots" << endl;
  cin >> e;

  cout << "ENTER";
  cin.ignore(); //clear the input stream                                                        
  cin.get(ch); //wait for the user to enter to hit enter
  
  array<int> y;
  try
    {
      cout << "\ntrying to do x = a + d, the sizes are the same" << endl;
      array<int> x = a + d;
      cout << "x is at " << &x << endl;
      cout << "x = " << x << endl;

      cout << "ENTER";
      cin.get(ch); //wait for the user to enter to hit enter
      
      cout << "\ntrying to do y = a + e, the sizes are different" << endl;
      y = a + e; //throws an exception because the sizes of a and e are different. jumps to catch
      cout << y << endl; //this line won't be executed
    }
  catch(array<int>::incomparable)
    {
      cout << "y is at " << &y << endl;
      cout << "The sizes of the arrays have to be the same" << endl;
    }

  cout << "ENTER";
  cin.get(ch); //wait for the user to enter to hit enter

  cout << "\ntesting the copy constructor. creating a new object, f from e" << endl;
  array<int> f(e); //f will point to a new array containing the same elements as e
  cout << "f is at " << &f << endl;        
  cout << "The new object has " << f << endl;

  cout << "ENTER";
  cin.get(ch); //wait for the user to enter to hit enter
  
  cout << "\ntesting operator=(). d = e" << endl;
  d = e;
  cout << "d is at " << &d << endl;        
  cout << "d = " << d << endl;

  cout << "ENTER";
  cin.get(ch); //wait for the user to enter to hit enter
  
  cout << "\nEnding the prog" << endl;
  cout << "ENTER";
  cin.get(ch); //wait for the user to enter to hit enter
  cout << endl;
  
  return 0;
}

