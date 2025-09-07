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

int main()
{   
    cout << "=========================  ARRY A =========================   \n";
    int a = 7;
    int Arry[] = {9, 1, -16, 4, 12, -8, 6};
    cout << "Expected: 16\n";
    algoA(Arry, a); //expected 16
    

    cout << "=========================  ARRY B =========================   \n";
    int b = 6;
    int ArryB[] = {2, -7, 3, 4, -2, 1};
    cout << "Expected: 7\n";
    algoA(ArryB, b); // expected 7

    cout << "=========================  ARRY C =========================   \n";
    int c = 6;
    int ArryC[] = {-2, -1, 4, 3, -2, 5};
    cout << "Expected: 10\n";
    algoA(ArryC, c); // expected 10

    cout << "=========================  ARRY D =========================   \n";
    int d = 4;
    int ArryD[] = {-4, -2, -7, -1};
    cout << "Expected: 0\n";
    algoA(ArryD, d); // expected 0

    cout << "=========================  ARRY E =========================   \n";
    int e = 7;
    int ArryE[] = {3, -1, 2, -5, 3, -1, 2};
    cout << "Expected: 4\n";
    algoA(ArryE, e); // expected 4

    cout << "=========================  ARRY F =========================   \n";
    int f = 4;
    int ArryF[] = {1, 2, 3, 4};
    cout << "Expected: 10\n";
    algoA(ArryF, f); // expected 10

    cout << "=========================  ARRY G =========================   \n";
    int g = 4;
    int ArryG[] = {-100, 50, -100, 49};
    cout << "Expected: 50\n";
    algoA(ArryG, g); // expected 50

    cout << "=========================  ARRY H =========================   \n";
    int h = 6;
    int ArryH[] = {-4, 2, -1, 2, -1, 3};
    cout << "Expected: 5\n";
    algoA(ArryH, h); // expected 5

    cout << "=========================  ARRY I =========================   \n";
    int i = 12;
    int ArryI[] = {7, -5, 3, 4, -2, -1, 6, -8, 5, -3, 2, 1};
    cout << "Expected: 12\n";
    algoA(ArryI, i); // expected 12

}


