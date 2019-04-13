#include<iostream>
#include<cstring>
#include<string>
#include<time.h>
#include<vector>

using namespace std;

//use include<string> recursive solute LCS(longest common subsequence)
string UseStringRecursionLCS(string strA, string strB)
{
    int m = strA.size();
    int n = strB.size();

    //recursive base
    if(strA.size() < 1 || strB.size() < 1)
    {
        return "";
    }
    
    string subStrA = strA.substr(0,m-1);
    string subStrB = strB.substr(0,n-1);

    //decrease-and-conquer
    if(strA[m - 1] == strB[n - 1])
    {
        string temp = UseStringRecursionLCS(subStrA,subStrB);
        return temp + strA[m-1];
    }
    //devide-and-conquer
    else
    {
        string leftRecursion = UseStringRecursionLCS(strA,subStrB);
        string rightRecursion = UseStringRecursionLCS(subStrA,strB);

        return leftRecursion.size() >= rightRecursion.size() ? leftRecursion : rightRecursion;
    }    
}

//use vector recursive solute LCS
vector<char> UseVectorRecursionLCS(vector<char> vectorA, vector<char> vectorB)
{
    int lengthA = vectorA.size();
    int lengthB = vectorB.size();

    if(lengthA < 1 || lengthB < 1)
    {
        vector<char> result;
        return result;
    }

    vector<char> subVectorA = vectorA;
    vector<char> subVectorB = vectorB;

    subVectorA.pop_back();
    subVectorB.pop_back();

    if(vectorA[lengthA-1] == vectorB[lengthB-1])
    {
        vector<char> result = UseVectorRecursionLCS(subVectorA,subVectorB);
        result.push_back(vectorA[lengthA-1]);

        return result;
    }
    else
    {
        vector<char> leftResult = UseVectorRecursionLCS(vectorA,subVectorB);
        vector<char> rightResult = UseVectorRecursionLCS(subVectorA,vectorB);

        return leftResult.size() >= rightResult.size() ? leftResult : rightResult;
    }
}

//recursive solute Fibonacci Sequence
int RecursionFib(int n)
{
    if(n == 0)
    {
        return 0;
    }

    if(n == 1)
    {
        return 1;
    }

    return RecursionFib(n-1) + RecursionFib(n-2);
}

void FibCompute()
{
    int fibNum;
    
    cout << "please input the fib index:" << endl;
    cin >> fibNum;

    clock_t start,finish;
    double totaltime;
    start=clock();

    long fibNumResult = RecursionFib(fibNum);

    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;

    cout << "the fib array index:" << fibNum << endl << "value:" << fibNumResult << endl << "time cost:" << totaltime << endl;
}

void UseStringLCScompute()
{
    std::string parameterA;
    std::string parameterB;

    cout << "please input string A:" <<endl;
    cin >> parameterA;
    cout << "please input string B:" << endl;
    cin >> parameterB;

    string LCSresult = UseStringRecursionLCS(parameterA,parameterB);

    cout << "the length of result:" << LCSresult.size() << endl;

    cout << LCSresult << endl;
}

void UseVectorLCSCompute()
{
    std::string parameterA;
    std::string parameterB;

    cout << "please input string A:" <<endl;
    cin >> parameterA;
    cout << "please input string B:" << endl;
    cin >> parameterB;

    vector<char> vectorA;
    vector<char> vectorB;

    for(int i = 0; i < parameterA.size(); i++)
    {
        vectorA.push_back(parameterA[i]);
    }

    for(int i = 0; i < parameterB.size(); i++)
    {
        vectorB.push_back(parameterB[i]);
    }

    vector<char> resultVector;

    resultVector = UseVectorRecursionLCS(vectorA,vectorB);

    cout << "the length of result:" << resultVector.size() << endl;

    for(int i = 0; i < resultVector.size(); i++)
    {
        cout << resultVector[i];
    }
}

int main(int argc, char const *argv[])
{
    //FibCompute();

    //UseStringLCScompute();

    //UseVectorLCSCompute();

    return 0;
}
