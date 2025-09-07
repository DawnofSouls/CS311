/************************************************************************
CS311 Kazumi Slott

Your name: Agustin Martinez
Your program number: 24
Hours spent: 6 hours
Describe any difficulties here: In Algo A, I couldn't find a better way to make one without doing an O(n^3) time complexity. Unsure if that's a good answer.

Experiment:                             (in milliseconds)
                                        AlgoA       AlgoB      AlgoC
------------------------------------------------------------------------
Actual Runtimes with 1000 elements    |           |           |
(Record the 3 runtimes obtained       |           |           |
when you run big-O_file.cpp)          |           |           |
------------------------------------------------------------------------
Expected Runtimes with 2000 elements  |           |           |
(Predict how long each algo would take|           |           |
before you run big-O_file.cpp)        |           |           |
------------------------------------------------------------------------
Actual Runtimes with 2000 elements    |           |           |
------------------------------------------------------------------------
Expected Runtimes with 3000 elements  |           |           |
------------------------------------------------------------------------
Actual Runtimes with 3000 elements    |           |           |
------------------------------------------------------------------------

<Question> Did the actual runtimes for 2000 and 3000 match what you expected?
Please explain.
<Your answer here>

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
