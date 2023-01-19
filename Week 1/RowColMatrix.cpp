#include<iostream>
#include<string>
#include<vector>
using namespace std;

//The following Search will only work in case of Row & Col wise sorted Matrix but not efficient for the sorted array. as this method has O(N) time complexity

void search(vector<vector<int>> matrix, int target, vector<int> *store)
{
    int col = matrix.size() - 1; int row = 0;
    int ans = 0;
    while(((row>=0 && col>=0) || (row<=3 && col<=3)) && ans==0)
    {
        
        if(matrix[row][col]==target)
        {
            // cout<<"{ "<<row<<","<<col<<" }";
            store->push_back(row);
            store->push_back(col);
            ans = 1;
        }
        if(matrix[row][col]>target)
        {
            col--;
        }
        else
        {
            row++;
        }

    }
    
    if(ans==0)
    {
        store->push_back(-1);
        store->push_back(-1);
    }
}

int main()
{
    vector<vector<int>> matrix = {{10,20,30,40},{15,25,35,45},{28,29,37,49},{33,34,38,50}};
    vector<vector<int>> mar = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> store;
    search(mar,9,&store);
    cout<<store[0]<<" "<<store[1];
    return 0;
}