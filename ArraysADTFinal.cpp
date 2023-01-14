#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

struct array{
 
    int A[20];
    int size;
    int length;
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
//SELF CODED
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


int main()
{
    struct array arr = {{4,8,10,15,18,21,24,27,29,33,34,37,39,41,43},15,15};
    // append(&arr,12);
    // insert(&arr,3,11);
    // Delete(&arr,0);
    // display(&arr);
    // cout<<Lsearch2(&arr,5)<<endl;
    // cout<<Lsearch1(&arr,8)<<endl;
    
    display(&arr);
    cout<<Bsearch(&arr,27)<<endl;



     return 0;
}