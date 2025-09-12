/***********************************
Template prepared by Kazumi Slott
CS311

array class

Complete destructor, destroy(), copy constructor,
operator=(), copy() 
Replace the ?????s

Your name:  Agustin Martinez
Your programmer number: 24
Hours spent?:
Any difficulties?: 
***********************************/
#include <iostream>
using namespace std;

//forward declaration
template <class T>
class array;

//prototype
template <class T>
istream& operator>>(istream& in, array<T>& a);

//prototype
template <class T>
ostream& operator<<(ostream& out, const array<T>& a);

template <class T>
class array
{
  friend ostream& operator<< <T>(ostream& out, const array<T>& a);
  friend istream& operator>> <T>(istream& in, array<T>& a);
 private: 
  T* ar;
  const int size;
 public:
  array(int sz);
  array();
  ~array();
  array operator+(const array<T>& other);

  class incomparable{};
};

template <class T>
array<T>::array(int sz) : size(sz)
{
  if(sz >= 1)
    ar = new T[sz];
  else
    ar = NULL;
}

template <class T>
array<T>::array() : size(0)
{
  ar = NULL;
}

template <class T>
istream& operator>>(istream& in, array<T>& a)
{
  for(int i = 0; i < a.size; i++)
    {
      cout << "Enter a value: ";
      in >> a.ar[i];
    }
  return in;
}

template <class T>
ostream& operator<<(ostream& out, const array<T>& a)
{
  for(int i = 0; i < a.size; i++)
      out << a.ar[i] << " ";

  return out;
}

template <class T>
array<T> array<T>::operator+(const array<T>& other)
{
  if(this->size != other.size)
    throw incomparable();

  array<T> a(this->size);
  for(int i = 0; i < this->size; i++)
    a.ar[i] = this->ar[i] + other.ar[i];

  return a;
}

template <class T>
array<T>::~array()
{
  //????? //call destroy()
}

/*
//private function
template <class T>
void array<T>::destroy()
{
  //if(????) //if an array exists
    //????? //delete the entire array

  //Don't forget to put the prototype of this function in the class definition
}
*/

/*
//should this be private or public?
template <class T>
array<T>::array(const array<T>&  source)  //Copy constructor
{
  //?????? //set ar and size of the new objet to NULL and 0
  //?????? //call copy()

  //Don't forget to put the prototype of this function in the class definition
}
*/

/*
//private function
template <class T>
void array<T>::copy(const array<T>& source)
{
  //if(??????) //make a new array for "this" only if source has an array                          
    {
      //?????? //create a new array for this object
      //?????? //the size of this object should be the same as that of source
      //??????//copy each value from source and this object
    }

    //Don't forget to put the prototype of this function in the class definition
}
*/

/*
//should this be public or private?
//the return type is array<T>& so we can do (a=b)=c;  What (a=b) returns needs to get changed by c.
template <class T>
array<T>& array<T>::operator=(const array<T>& rhs)
{
  //if(??????)//proceed only if the objects on the left and right hand sides of = are different.                     
    {
      //??????? //destroy the existing array "this" is pointing                                     
      //??????? //call copy()
    }
  //no need to have else. If the objects on the left and right are the same (a = a), you don't need to do anything. If you procceded to the above section when a = a, the right side object(a) gets destroyed!!!
  
  //return ?????; //return this object (not the pointer)

  //Don't forget to put the prototype of this function in the class definition
}
*/




