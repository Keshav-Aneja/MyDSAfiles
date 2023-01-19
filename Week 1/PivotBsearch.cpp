#include<iostream>
#include<string>
#include<vector>
using namespace std;
//this will not work for duplicate values
int pivot(vector<int> arr) {
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        // 4 cases over here
        if (mid < end && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        if (mid > start && arr[mid] < arr[mid - 1]) {
            return mid-1;
        }
        if (arr[mid] <= arr[start]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

//For duplicates

int DuplicatePivot(vector<int> arr) {
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        // 4 cases over here
        if (mid < end && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        if (mid > start && arr[mid] < arr[mid - 1]) {
            return mid-1;
        }
        if(arr[mid] == arr[start] && arr[mid == arr[end]])
        {
            if(arr[start] > arr[start+1])
            {
                return start;
            }
            start++;
            if(arr[end]<arr[end-1])
            {
                return end - 1;
            }
            end--;
        }
        if(arr[start]<arr[mid] || (arr[mid]==arr[start] && arr[end]<arr[mid]))
        {
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}


int main()
{

    vector<int> arr = {4,5,6,7,8,0,1,2};
    vector<int> arr2 = {2,9,2,2,2};
    cout<<pivot(arr);
    cout<<endl<<DuplicatePivot(arr2);
    return 0;
}