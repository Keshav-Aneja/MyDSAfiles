#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int arr[] = {6,7,8,9,11,12,15,16,17,18,19};
    int l,h,n;
    l = arr[0];
    n = sizeof(arr)/4;
    h = arr[n-1];

    int diff = l - 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]-i!=diff)
        {
            while(diff<arr[i]-i)
            {
                cout<<i+diff<<" ";
                diff++;
            }
        }
    }
    return 0;
}