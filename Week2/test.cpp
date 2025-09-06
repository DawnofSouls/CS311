#include <iostream>
using namespace std;

int algoA(const int a[], int sz)
{

    int max, sum = 0;

    for (int i = 0; i < sz; i++)
    {   
        cout << "i: " << i << endl;

        for (int j = 0; j + i < sz; j++)
        {   
            cout << "j: " << j << endl;

            int start = j;
            int end = j + i;

            for(start = 0; start<=end; start++)
            {   
                cout << "Array["<< start <<"]: " <<a[start] << endl;
                
                sum+=a[start];
                cout << "Sum: " << sum << endl;
            }
            if (max < sum)
            {
                max = sum;
            }
            sum = 0;

        }
    }
    cout << max << endl;
    return max;
};

int main()
{
    int n = 7;
    int Arry[] = {9, 1, -16, 4, 12, -8, 6};

    algoA(Arry, n);
}
