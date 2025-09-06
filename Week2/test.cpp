#include <iostream>
using namespace std;

int algoA(const int a[], int sz)
{

    int max = 0;
    int sum = 0;

    for (int i = 0; i < sz; i++)
    {   
        cout << "i: " << i << endl;

        for (int j = 0; j + i < sz; j++)
        {   
            cout << "j: " << j << endl;

            int start = j;
            int end = j + i;

            for(start; start<=end; start++)
            {   
                cout << "Array["<< start << " - " << end <<"] = " <<a[start] << endl;
                
                sum+=a[start];
                cout << "Sum: " << sum << endl;
            }
            if (max < sum)
            {
                max = sum;
                cout << "------------------ NEW MAX: " << max <<" ------------------" << endl;
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
    algoA(Arry, a); //expected 16
    

    cout << "=========================  ARRY B =========================   \n";
    int b = 6;
    int ArryB[] = {2, -7, 3, 4, -2, 1};
    algoA(ArryB, b); // expected 7

}
