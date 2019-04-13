#include<iostream>
#include<cstring>
#include<string>
#include<time.h>
#include<list>

using namespace std;

void SelectionSort(int* p, int n)
{
    int* head = p;
}

void InputCheck(list<int> &sortList)
{
    string arg;

    cin >> arg;

    while(arg != "end")
    {
        int value = atoi(arg.c_str());
        sortList.push_back(value);
        cin >> arg;
    }
}

int main(int argc, char const *argv[])
{
    list<int> sortList;

    InputCheck(sortList);

    /* code */
    return 0;
}
