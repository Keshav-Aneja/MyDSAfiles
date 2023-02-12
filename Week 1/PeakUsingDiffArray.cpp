#include<iostream>
#include<string>
#include<vector>
using namespace std;
void findpeak1(vector<int> arr, vector<int> *store)//This can also be used to find multiple peaks even when duplicate elements are available
//for multiple peaks the peaks indices can pe stored in an array instead of returning it.
{
    int diff[arr.size() - 1] = {0};
    for(int i=0; i<arr.size() - 1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            diff[i] = -1;
        }
        if(arr[i]<arr[i+1])
        {
            diff[i] = 1;
        }
    }
    // for(auto &x : diff)
    // {cout<<x<<" ";}
    for(int i = 0; i<arr.size() - 1; i++)
    {
        if(diff[i] == 1)
        {
            if(diff[i+1] == -1) { store->push_back(i+1);}
            if(diff[i+1] == 0)
            {
                int j = i + 1;
                while(diff[j]==0){j++;}
                if(diff[j]==-1){store->push_back(i+1);}
                i = j - 1;
            }
        }
    }
}
int findpeak2(vector<int> arr) 
//This code has a problem with finding multiple peaks as in case of {...7,7,7,...} for the middle 7 this will show it as a peak too
{
    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1,2,3,3,5,7,7,7,7,5,2,2,8,1,0,0};
    vector<int> store;
    findpeak1(arr,&store);
    for(auto &x : store){cout<<x<<" ";}
    return 0;
}