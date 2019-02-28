#include<bits/stdc++.h>
using namespace std;

int main()
{   /* How to get a random number?
       rand() function is used in C/C++ to generate random numbers but if we generate a sequence of random number with rand() function,
       it will create the same sequence again and again every time program runs.
       How to make it completely random every time?
       The srand() function sets the starting point for producing a series of pseudo-random integers. If srand() is not called,
       the rand() seed is set as if srand(1) were called at program start. Any other value for seed sets the generator to a different
       starting point. Time always varies so we get a random value every time.
   
    /* Case 1: When no. of vectors we need is fixed, like 2 vectors */
    cout<<"CASE 1:\n";
    srand(time(0));         // Use current time as seed for random generator, only needed once.
    int a = rand() % 32768;       // Upper limit on size, % N means max size will be N (0 to N-1)
    vector<int> vector_1(a);
    cout<<"Size of vector_1 is "<<vector_1.size()<<endl;
    
    vector<int> vector_2(rand() % 32768);
    cout<<"Size of vector_2 is "<<vector_2.size()<<endl;
    
    /* Case 2: When no. of vectors we need is also random, 
    we make an Array of Vectors and the size of both Array and Vectors is randomly generated*/
    cout<<"\nCASE 2:\n";
    int ARRAY_SIZE = rand() % 10;       // Upper limit on size, max size will be 10 (0 to 9) 
    vector<int> *ARRAY[ARRAY_SIZE];     // Array of pointers which will point to a vector.
    for(int i=0; i<ARRAY_SIZE; i++)
    {
        ARRAY[i] = new vector<int>(rand() % 32768);     // New vector dynamically created and ARRAY[i] points to it.
        cout<<"Size of vector_"<<i<<" is "<<ARRAY[i]->size()<<endl;
    }

	return 0;
}
