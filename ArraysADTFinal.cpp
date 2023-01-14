// The following code includes the various functions that can be called on an Array like:
// Display()
// Append()
// Insert()
// Delete()
// Bsearch() -- Binary Search
// RBsearch() -- Recursive Binary searchen
// Lsearch1 -- Optimised Linear search
// Lsearch2 -- Optimised Linear search
// get(index)
// set(index,val)
// Max()
// Min()

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

struct array{
 
    int A[20];
    int size;
    int length;

    int RBsearch(int l, int h, int key)
    {
       int mid = floor((l+h)/2);
       if(l<=h)
       {
            if(A[mid]==key)
            {
                return mid;
            }
            else if (A[mid]>key)
            {
                return RBsearch(l,mid-1,key);
            }
            else
            {
                return RBsearch(mid+1,h,key);
            }
       }
    return -1;
    }
};
void display(struct array *arr)
{
    cout<<"The Elements of the Array are: ";
    for(int i=0; i<arr->length; i++)
    {
        cout<<arr->A[i]<<" ";
    }
    cout<<endl;
}
void append(struct array *arr, int z)
{
    arr->A[arr->length] = z;
    arr->length++;
}
void insert(struct array *arr, int index, int z)
{
    for(int i=arr->length; i>index; i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[index] = z;
    arr->length++;
}
void Delete(struct array *arr, int index)
{   
    for(int i=index; i<=arr->length-2;i++)
    {
        arr->A[i] = arr->A[i+1]; 
    }
    arr->length--;
}
int Lsearch1(struct array *arr, int key)
{   
    for(int i=0; i<arr->length; i++)
    {
        if(arr->A[i]==key)
        {
            if(i!=0)
            {
                swap(arr->A[i],arr->A[i-1]);
                return i-1;
            }
            else{
                return i;
            }
        }
    }
    return -1;
}  
int Lsearch2(struct array *arr, int key)
{
    for(int i=0; i<arr->length; i++)
    {
        if(arr->A[i]==key)
        {
            if(i!=0)
            {
                swap(arr->A[i],arr->A[0]);
                return 0;
            }
            else{
                return i;
            }
        }
    }
    return -1;
} 
int Bsearch(struct array *arr, int key)
{
    int l=0;
    int h = arr->length-1;
    
    int a = 0;
    int ans = -1;
    while(a!=1)
    {
        int mid = floor((l+h)/2);
        if(l>h)
        {
            ans=-1;
            a=1;
        }
        else
        {
            if(arr->A[mid]!=key)
            {
                if(arr->A[mid]>key)
                {
                    h = mid - 1;
                }
                else if(arr->A[mid]<key)
                {
                    l = mid + 1;
                }
            }
            else
            {
                ans = mid;
                a=1;
                
            }
        }
        
    }
    return ans;
}
void get(struct array *arr, int index)
{
    if (index>=0 && index<=arr->length-1)
    {
        cout<<arr->A[index]<<endl;
    }
    else{
        cout<<"Error: Element Not Found"<<endl;
    }
}
void set(struct array *arr, int index, int val)
{
    if(index>=0 && index<=arr->length-1)
    {
        arr->A[index] = val;
    }
}

void Max(struct array *arr)
{   long long int max = INT64_MIN;
    for(int i=0; i<arr->length; i++)
    {
        if(arr->A[i]>max)
        {
            max = arr->A[i];
        }
    }
    cout<<max<<endl;
}
void Min(struct array *arr)
{   long long int min = INT64_MAX;
    for(int i=0; i<arr->length; i++)
    {
        if(arr->A[i]<min)
        {
            min = arr->A[i];
        }
    }
    cout<<min<<endl;
}
void sum(struct array *arr)
{   int sum;
    for(int i=0;i<arr->length; i++)
    {
        sum = sum + arr->A[i];
    }
    cout<<sum<<endl;
}
void avg(struct array *arr)
{
    int sum;
    for(int i=0;i<arr->length; i++)
    {
        sum = sum + arr->A[i];
    }
    cout<<sum/(arr->length)<<endl;
}
int main()
{
    struct array arr = {{4,8,10,15,18,21,24,27,29,33,34,37,39,41,43},15,15};
    // append(&arr,12);
    // insert(&arr,3,11);
    // Delete(&arr,0);
    // display(&arr);
    // cout<<Lsearch2(&arr,5)<<endl;
    // cout<<Lsearch1(&arr,8)<<endl;
    
    // display(&arr);
    // cout<<Bsearch(&arr,34)<<endl;
    // cout<<arr.RBsearch(0,14,34);
    // get(&arr,5);
    // set(&arr,10,-9);
    // Max(&arr);
    // Min(&arr);
    // display(&arr);
    // sum(&arr);
    // avg(&arr);




     return 0;
}