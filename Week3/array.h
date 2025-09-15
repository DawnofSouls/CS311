/***********************************
Template prepared by Kazumi Slott
CS311

array class

Complete destructor, destroy(), copy constructor,
operator=(), copy() 
Replace the ?????s

Your name:  Agustin Martinez
Your programmer number: 24
Hours spent?: 12 hours
Any difficulties?: Dont remember this concept. Had to do a little review.
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
  void destroy();
  void copy(const array<T>& source);

 public:
  array(int sz);
  array();
  ~array();
  array operator+(const array<T>& other);
  array(const array<T>& source);
  array<T>& operator=(const array<T>& rhs);
  

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
  destroy(); //call destroy()
}


//private function
template <class T>
void array<T>::destroy()
{
  if (ar != NULL) {        
    delete [] ar;         
    ar = NULL;            
}
}



template <class T>
array<T>::array(const array<T>&  source)
: ar(NULL),
  size(source.size)  //Copy constructor
{
  copy(source); 

}



//private function
template <class T>
void array<T>::copy(const array<T>& source)
{
  if (source.ar != NULL && source.size > 0) {   
    ar = new T[size];                           
    for (int i = 0; i < size; ++i)
      ar[i] = source.ar[i];                     
  } else {
    ar = NULL;                                  
  }
}



//should this be public or private?
//the return type is array<T>& so we can do (a=b)=c;  What (a=b) returns needs to get changed by c.
template <class T>
array<T>& array<T>::operator=(const array<T>& rhs)
{
  if (this == &rhs) return *this;  // self-assign guard

  if (size == rhs.size) {
    // same size: deep-copy elements
    if (ar == NULL && rhs.ar != NULL && size > 0)
      ar = new T[size];

    if (ar != NULL && rhs.ar != NULL) {
      for (int i = 0; i < size; ++i) ar[i] = rhs.ar[i];
    } else if (rhs.ar == NULL) {
      // rhs has no array; mirror that state
      destroy();
    }

    return *this;
  }

  this->~array();                 
  ::new (this) array<T>(rhs);     
  return *this;
}





