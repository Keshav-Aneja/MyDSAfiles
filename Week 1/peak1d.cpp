#include<iostream>
#include<string>
#include<vector>
using namespace std;
void PeakFinder(vector<int> vec, int n)
{   int mid;
    if(n%2==0)
    {
        mid = n/2;
    }
    else{
       mid = (n+1)/2;
    }
    if(vec(mid)<vec((mid)-1))
    {   int b;
        if(n%2==0)
        {
            b = n/2;
        }
        else{
            b = (n+1)/2;
        }
        PeakFinder(vec,b);
    }
    else if (vec(mid)<vec((mid)+1))
    {

    }
    else
    {
        cout<<"Peak is: "<<vec(mid);
    }
}
int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 5, 4, 3};
    int n = vec.size();

    

    return 0;
}
