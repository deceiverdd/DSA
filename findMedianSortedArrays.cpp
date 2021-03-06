#include <iostream>
#include <cstring>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int i, j = 0;
    vector<int> q;

    int totalLength = nums1.size() + nums2.size();
    int mid = totalLength / 2;

    while (i < nums1.size() || j < nums2.size())
    {
        if (i >= nums1.size())
        {
            q.push_back(nums2[j]);
            j++;
            continue;
        }

        if (j >= nums2.size())
        {
            q.push_back(nums1[i]);
            i++;
            continue;
        }

        if (nums1[i] <= nums2[j])
        {
            q.push_back(nums1[i]);
            i++;
        }
        else
        {
            q.push_back(nums2[j]);
            j++;
        }

        if (i + j - 1 == mid)
        {
            if (totalLength % 2 != 0)
            {
                return q.back();
            }
            else
            {
                return (q.at(q.size() - 1) + q.at(q.size() - 2))/2.0;
            }
        }
    }

    return 0.0;
}

double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) 
{
            int i,j = 0;
    vector<int> q; 

    while(i < nums1.size() || j < nums2.size())
    {
        if(i >= nums1.size())
        {
            q.push_back(nums2[j]);
            j++;
            continue;
        }
        
        if(j >= nums2.size())
        {
            q.push_back(nums1[i]);
            i++;
            continue;
        }
        

        if(nums1[i] <= nums2[j])
        {
            q.push_back(nums1[i]);
            i++;
        }
        else
        {
            q.push_back(nums2[j]);
            j++;
        }
    }
    
    int r = q.size()/2;

    if(q.size()%2 == 0)
    {
        return (q[r] + q[r-1])/2.0;
    }
    else
    {
        return q[r];
    }
}

int main(int argc, char const *argv[])
{
    vector<int> a = {2};

    vector<int> b;

    //double result = findMedianSortedArrays(a, b);

    //cout << result << endl;

    cout << b.size() << endl;

    return 0;
}