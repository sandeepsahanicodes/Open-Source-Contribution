#include<iostream>
#include<vector>
using namespace std;


int MaxSumSubArr(vector<int> A) {
    bool f = true;

    int rr= INT_MIN;

    for(auto x : A) {

       if(x > 0) f = false;
       if(x > rr)rr =  x;

    }

    if(f) return rr;
        int MaxSumFromPrevIndexTOLeft = 0;

        int finalAnswer = 0;
        int temporary = 0;

        int arraySize = A.size();

        for(int i=0; i<arraySize; i++)
 {
      temporary = MaxSumFromPrevIndexTOLeft + A[i];
 }
 
 
 return 0;
 }