#include<iostream>
#include<string>
#include<vector>
using namespace std;
int ceiling(vector<int> arr)
{
        int l = 0;
    int target = 15;
    int h = arr.size() - 1;
    while(l <= h)
    {
        int mid = l + (h - l)/2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return l;
}
int main()
{
    vector<int> arr = {2,4,5,9,14,16,18};
    cout<<ceiling(arr);
    return 0;
}