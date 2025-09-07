#include <iostream>
using namespace std;


int algoA(const int a[], int sz)
{

    int max = 0;
    int sum = 0;

    for (int i = 0; i < sz; i++)
    {   
        //cout << "i: " << i << endl;

        for (int j = 0; j + i < sz; j++)
        {   
            //cout << "j: " << j << endl;

            //int start = j;
            int end = j + i;

            for(int start = j; start<=end; start++)
            {   
                //cout << "Array["<< start << " - " << end <<"] = " <<a[start] << endl;
                
                sum+=a[start];
                //cout << "Sum: " << sum << endl;
            }
            if (max < sum)
            {
                max = sum;
                //cout << "------------------ NEW MAX: " << max <<" ------------------" << endl;
            }
            sum = 0;

        }
    }
    cout << max << endl;
    return max;
};

int algoB(const int a[], int sz)
{

    int max = 0;
    int sum = 0;

    for (int i = 0; i < sz; i++)
    {

        for (int j = i; j < sz; j++)
        {

            sum += a[j];

            if (sum > max)
            {
                max = sum;
            }
        }

        sum = 0;
    }

    cout << max << "\n";
    return max;
}

int main()
{   
    /*
    cout << "=========================  ARRY A (ALGO A) =========================   \n";
    int a = 7;
    int Arry[] = {9, 1, -16, 4, 12, -8, 6};
    cout << "Expected: 16\n";
    algoA(Arry, a); //expected 16
    

    cout << "=========================  ARRY B (ALGO A) =========================   \n";
    int b = 6;
    int ArryB[] = {2, -7, 3, 4, -2, 1};
    cout << "Expected: 7\n";
    algoA(ArryB, b); // expected 7

    cout << "=========================  ARRY C (ALGO A) =========================   \n";
    int c = 6;
    int ArryC[] = {-2, -1, 4, 3, -2, 5};
    cout << "Expected: 10\n";
    algoA(ArryC, c); // expected 10

    cout << "=========================  ARRY D (ALGO A) =========================   \n";
    int d = 4;
    int ArryD[] = {-4, -2, -7, -1};
    cout << "Expected: 0\n";
    algoA(ArryD, d); // expected 0

    cout << "=========================  ARRY E (ALGO A) =========================   \n";
    int e = 7;
    int ArryE[] = {3, -1, 2, -5, 3, -1, 2};
    cout << "Expected: 4\n";
    algoA(ArryE, e); // expected 4

    cout << "=========================  ARRY F (ALGO A) =========================   \n";
    int f = 4;
    int ArryF[] = {1, 2, 3, 4};
    cout << "Expected: 10\n";
    algoA(ArryF, f); // expected 10

    cout << "=========================  ARRY G (ALGO A) =========================   \n";
    int g = 4;
    int ArryG[] = {-100, 50, -100, 49};
    cout << "Expected: 50\n";
    algoA(ArryG, g); // expected 50

    cout << "=========================  ARRY H (ALGO A) =========================   \n";
    int h = 6;
    int ArryH[] = {-4, 2, -1, 2, -1, 3};
    cout << "Expected: 5\n";
    algoA(ArryH, h); // expected 5

    cout << "=========================  ARRY I (ALGO A) =========================   \n";
    int i = 12;
    int ArryI[] = {7, -5, 3, 4, -2, -1, 6, -8, 5, -3, 2, 1};
    cout << "Expected: 12\n";
    algoA(ArryI, i); // expected 12

    */

    cout << "=========================  ARRY J (ALGO B) =========================   \n";
    int j = 7;
    int ArryJ[] = {9,1,-16,4,12,-8,6};
    cout << "Expected: 16\n";
    algoB(ArryJ, j); //expected 16

    cout << "=========================  ARRY K (ALGO B) =========================   \n";
    int k = 10;
    int ArryK[] = {12, -5, 7, -2, 3, -10, 8, 9, -4, 6};
    cout << "Expected: 24\n";
    algoB(ArryK, k);

    cout << "=========================  ARRY L (ALGO B) =========================   \n";
    int l = 13;
    int ArryL[] = {-3, 4, -1, 2, 1, -5, 4, -2, 6, -1, 2, -3, 4};
    cout << "Expected: 11\n";
    algoB(ArryL, l);

    cout << "=========================  ARRY M (ALGO B) =========================   \n";
    int m = 13;
    int ArryM[] = {0, 0, 0, 0, 0, 0, 1, -1, 2, -2, 3, -3, 4};
    cout << "Expected: 4\n";
    algoB(ArryM, m);

    cout << "=========================  ARRY N (ALGO B) =========================   \n";
    int n = 8;
    int ArryN[] = {-2, -1, -3, -4, -1, -2, -1, -5};
    cout << "Expected: 0\n";
    algoB(ArryN, n);

    cout << "=========================  ARRY O (ALGO B) =========================   \n";
    int o = 12;
    int ArryO[] = {5, -7, 8, 3, -2, 4, -10, 6, 7, -3, 2, 1};
    cout << "Expected: 16\n";
    algoB(ArryO, o);

    cout << "=========================  ARRY P (ALGO B) =========================   \n";
    int p = 8;
    int ArryP[] = {1, -2, 3, 10, -4, 7, 2, -5};
    cout << "Expected: 18\n";
    algoB(ArryP, p);


}


