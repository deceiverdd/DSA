#include<iostream>
#include<cstring>
#include<string>
#include<time.h>
#include<vector>

using namespace std;

void Merge(vector<int> &array, int lo, int mid, int hi)
{
    int lb = mid - lo;
    int lc = hi - mid;

    int *A = &array[lo];
    int *B = new int[lb];
    int *C = &array[mid];

    for(int i = 0; i < lb; i++)
    { 
        B[i] = A[i];
    }
    
    for(int i = 0, j = 0, k = 0; (j < lb || k < lc);)
    {
        //归并算法是稳定的
        if((j < lb) && (k >= lc || (B[j] <= C[k]))) A[i++] = B[j++];
        if((k < lc) && (j >= lb || (C[k] < B[j]))) A[i++] = C[k++];
    }  

    delete []B;  
}

void MergeSort(vector<int> &array, const int lo,const int hi)
{
    if(hi - lo < 2) return;

    int mid = (lo + hi) >> 1;

    MergeSort(array, lo, mid);
    MergeSort(array, mid, hi);

    Merge(array, lo, mid, hi);
}

void InputCheck(vector<int> &array)
{
    string arg;

    cin >> arg;

    while(arg != "end")
    {
        int value = atoi(arg.c_str());
        array.push_back(value);
        cin >> arg;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> array;

    InputCheck(array);

    MergeSort(array, 0, array.size());
    
    for(int i = 0; i < array.size(); i++)
    {
        cout << array[i] << endl;
    }
    
    return 0;
}
