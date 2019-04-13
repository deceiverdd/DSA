#include<iostream>
#include<cstring>
#include<string>
#include<time.h>
#include<vector>
#include<algorithm>

using namespace std;

//Version A : find value in range [lo,hi)
int BinSearchA(const vector<int> &orderedArray, const int &value, int lo, int hi)
{  
    if(lo < 0 || hi > orderedArray.size())
        return -1;

    while(lo < hi)
    {
        int mid = (lo + hi) >> 1;

        if(value < orderedArray[mid])   hi = mid;
        else if(orderedArray[mid] < value)  lo = mid + 1;
        else    return mid;
    }

    return -1;
}

//Recursion Fib
int RecursionFib(int n)
{
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else return RecursionFib(n-1) + RecursionFib(n-2);
}

//Reverse Fib
int ReverseFib(int fibNum)
{
    for(int i = 0; i < 20; i++)
    {
        if(fibNum == RecursionFib(i) - 1)
        {
            return RecursionFib(i - 1) - 1;
        }
    }

    return -1;
}

//Version Fib : 
int FibBinSearch(const vector<int> &orderedArray, const int &value, int lo, int hi)
{
    if(lo < 0 || hi > orderedArray.size())
        return -1;   

    while(lo < hi)
    {
        int breakPoint = ReverseFib(hi - lo);

        if(breakPoint == -1) 
        {
            cout << "Format Error" << endl;
        }

        if(value < orderedArray[breakPoint])   hi = breakPoint;
        else if(orderedArray[breakPoint] < value)  lo = breakPoint + 1;
        else    return breakPoint;
    }

    return -1;
}

//Version B
int BinSearchB(const vector<int> &orderedArray, const int &value, int lo, int hi)
{
    if(lo < 0 || hi > orderedArray.size())
        return -1;

    //有效查找区间缩短至1时，才会终止算法
    while(hi - lo > 1)
    {
        int mid = (lo + hi) >> 1;

        value < orderedArray[mid] ? hi = mid : lo = mid;
    }
    //出口时hi = lo + 1,查找区间只剩一个元素orderedArray[lo]

    //返回命中元素的秩，或者返回-1
    return orderedArray[lo] == value ? lo : -1;
}

//Version C
//该版本严格遵守语义：返回不大于value的最后一个元素
int BinSearchC(const vector<int> &orderedArray, const int &value, int lo, int hi)
{
    if(lo < 0 || hi > orderedArray.size())
        return -1;

    //不变性:orderedArray[0, lo) <= value < orderedArray[hi, n)
    while(lo < hi)
    {
        int mid = (lo + hi) >> 1;

        value < orderedArray[mid] ? hi = mid : lo = mid + 1;
    }    
    //出口时，orderedArray[lo = hi]为大于value的最小元素

    //故lo-1为不大于value的元素的最大秩
    return --lo;
}

//input check ordered
bool OrderedSequenceCheck(vector<int> &orderedArray)
{
    string arg;

    cin >> arg;

    while(arg != "end")
    {
        int value = atoi(arg.c_str());
        orderedArray.push_back(value);
        cin >> arg;
    }

    for(int i = 0; i < orderedArray.size(); i++)
    {
        cout << orderedArray[i]<<endl;
    } 

    return is_sorted(orderedArray.begin(),orderedArray.end()) ? true : false;
}

int main(int argc, char const *argv[])
{
    vector<int> orderedArray;

    if(!OrderedSequenceCheck(orderedArray))
    {
        cout << "this sequence is not ascending sequence" << endl;
        return 0;
    }
    else
    {
        cout << "this sequence is ascending sequence" << endl;
    }

    int lo = 0;
    int hi = orderedArray.size();

    int resultIndex = -1;
    int value = -1;

    cout << "please input the value to search" << endl;
    cin >> value;

    //resultIndex = BinSearchA(orderedArray, value, lo, hi);

    //resultIndex = FibBinSearch(orderedArray, value, lo, hi);

    //resultIndex = BinSearchB(orderedArray, value, lo, hi);

    resultIndex = BinSearchC(orderedArray, value, lo, hi);

    cout << resultIndex << endl;

    return 0;
}
