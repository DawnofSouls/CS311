/************************************************************************
CS311 Kazumi Slott

Your name: Agustin Martinez
Your program number: 24
Hours spent: 8 hours
Describe any difficulties here: In Algo A, I couldn't find a better way to make one without doing an O(n^3) time complexity. Unsure if that's a good answer.

Experiment:                             (in milliseconds)
                                        AlgoA       AlgoB      AlgoC
------------------------------------------------------------------------
Actual Runtimes with 1000 elements    |           |           |
(Record the 3 runtimes obtained       |  202.414  |   1.333   | 0.004
when you run big-O_file.cpp)          |           |           |
------------------------------------------------------------------------
Expected Runtimes with 2000 elements  |           |           |
(Predict how long each algo would take|  1619.32  |   5.332   | 0.008
before you run big-O_file.cpp)        |           |           |
------------------------------------------------------------------------
Actual Runtimes with 2000 elements    |  1226.19  |   3.982   | 0.008
------------------------------------------------------------------------
Expected Runtimes with 3000 elements  |  5465.178 |  11.997   | 0.011
------------------------------------------------------------------------
Actual Runtimes with 3000 elements    |  4049.25  |   8.849   | 0.01
------------------------------------------------------------------------





<Question> Did the actual runtimes for 2000 and 3000 match what you expected?
Please explain.
<I was suprised to see difference between my prediction and the actual runtime. I suppose there's a lot of varibles to this
including faster machine especially on Algo A and B. Algo C felt easy to predict because it runs at linear complexity so I can multiply 2 or 3 after dividng 
elements by 1000.>

************************************************************************/

/********************************************************************
//Make your own test client and test your functions thorougly.
//You will submit this header file only. My test client will test your functions.
********************************************************************/


//What is the runtime complexity of this algorithm? O(n^3)
//Even if you cannot get this function to work, you may guess the complexity and provide your answer above.
int algoA(const int a[], int sz)//Don't change the function headers
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
    //cout << max << endl;
    return max;

}

//What is the runtime complexity of this algorithm? O(n^2)
//Even if you cannot get this function to work, you may guess the complexity and provide your answer above..
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

    //cout << max << "\n";
    return max;
}

//What is the runtime complexity of this algorithm? O(n)
//Even if you cannot get this function to work, you may guess the complexity and provide your answer above..
int algoC(const int a[], int sz)
{
    int sum = 0;
    int max = 0;

    for (int i = 0; i<sz; i++ ){

        sum+=a[i];

        if(sum < 0){
            sum = 0;
        }

        if (max < sum){
            max = sum;
        }



    }   

    //cout << max << "\n";
    return max;
}
