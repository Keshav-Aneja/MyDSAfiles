#include<iostream>
#include<string>
#include<vector>
using namespace std;
int findpeak(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid;
    while(start<end)
    {
        mid = start + (end-start)/2;
        if(arr[mid]>arr[mid+1])
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}
int Bsearch(vector<int> arr, int start, int end, int target)
{
    int mid;
    while(start<=end)
    {
        mid = start + (end-start)/2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid]<target)
        {
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}
int AgnosticBsearch(vector<int> arr, int start, int end, int target)
{
    int mid;
    while(start<end)
    {
        mid = start + (end-start)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]<target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {2,4,5,7,8,4,3,2,0};
    int target = 3;
    // cout<<findpeak(arr);
    int a = Bsearch(arr,0,findpeak(arr),target);
    if(a==-1)
    {
        cout<<AgnosticBsearch(arr,findpeak(arr),arr.size()-1,target);
    }
    else{
        return a;
    }
    

    return 0;
}