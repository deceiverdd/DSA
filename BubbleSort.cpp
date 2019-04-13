#include<iostream>
#include<cstring>
#include<string>
#include<time.h>
#include<vector>

using namespace std;

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

bool BubbleA(vector<int> &array, int lo, int hi)
{
    bool isSorted = true;

    while(++lo < hi)
    {
        if(array[lo - 1] > array[lo])
        {
            swap(array[lo - 1],array[lo]);
            isSorted = false;
        }
    }

    return isSorted;
}

void BubbleSort_A(vector<int> &array, int lo, int hi)
{
    while(!BubbleA(array,lo,hi--));
}

//Version B 在A的基础上改进，防止特殊情况
int BubbleB(vector<int> &array, int lo, int hi)
{
    //先把标志位移到最左边
    int last = lo;

    while(++lo < hi)
    {
        if(array[lo - 1] > array[lo])
        {
            swap(array[lo - 1], array[lo]);
            //如果发生交换，则把标志位移到发生交换的位置，此时标志位右边的序列都已经有序
            last = lo;
        }
    }

    return last;
}

void  BubbleSort_B(vector<int> &array, int lo, int hi)
{
    while(lo < (hi = BubbleB(array, lo, hi)));
}

int main(int argc, char const *argv[])
{
    vector<int> array;

    InputCheck(array);

    BubbleSort_B(array, 0, array.size());

    for(int i = 0; i < array.size(); i++)
    {
        cout << array[i];
    }

    /* code */
    return 0;
}
