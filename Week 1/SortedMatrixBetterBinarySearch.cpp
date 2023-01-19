#include<iostream>
#include<string>
#include<vector>
using namespace std;
//The following Searching Algorithm for Searching in 2D Matrix has a time complexity of O(log(m) + log(n))
//While the previous approach for RowColMatrix.cpp was O(N)
int * BinarySearch(vector<vector<int>> matrix, int row, int colS, int colE, int target)
{
    int *p;
    p = new int[2];
    p[0] = -1;
    p[1] = -1;
    while(colS<=colE)
    {
        int mid = colS + (colE - colS)/2;
        if(matrix[row][mid]==target)
        {
            p[0] = row; p[1] = mid;
            return p;
        }
        if(matrix[row][mid] < target)
        {
            colS = mid + 1;
        }
        else
        {
            colE = mid - 1;
        }
    }
    return p;
}

int * Search(vector<vector<int>> matrix, int target)
{
    int *z; z = new int[2]; z[0] = -1; z[1] = -1;
    int rows = matrix.size();
    int cols = matrix[0].size();
    if(cols == 0) //Checking for the end cases
    {
        return z;
    }
    if(rows==1) //If rows  =  1 then a simple Binary Search would be sufficient
    {
        return BinarySearch(matrix, 0, 0, cols - 1, target);
    }

    int rStart = 0;
    int rEnd = rows - 1;
    int cMid = cols/2;

    while(rStart < rEnd - 1) // This Reduces the rows number to 2
    {
        int mid = rStart + (rEnd - rStart)/2;
        if(matrix[mid][cMid] == target)
        {
            z[0] = mid; z[1] = cMid;
            return z;
        }
        if(matrix[mid][cMid] > target)
        {
            rEnd = mid;
        }
        else{
            rStart = mid;
        }
    }

    if(matrix[rStart][cMid] == target) // After 2 rows are remaining we are checking the middle column for target
    {
        z[0] = rStart; z[1] = cMid;
        return z;
    }
    if(matrix[rStart+1][cMid] == target)
    {
        z[0] = rStart + 1; z[1] = cMid;
        return z;
    }
    //If the target is not found in the middle column then we will search in the remaining 4 halfs of the matrix
    //search in 1st Half
    if(target <= matrix[rStart][cMid - 1])
    {
        return BinarySearch(matrix, rStart, 0, cMid - 1, target);
    }
    //Search in the 2nd Half
    if(target >= matrix[rStart][cMid+1] && target<= matrix[rStart][cols-1])
    {
        return BinarySearch(matrix, rStart, cMid+1, cols - 1, target);
    }
    //Search in the 3rd Hald
    if(target <= matrix[rStart + 1][cMid - 1])
    {
        return BinarySearch(matrix, rStart+1, 0, cMid-1, target);
    }
    else{
        return BinarySearch(matrix, rStart+1, cMid+1, cols - 1, target);
    }
    return z;
}
int main()
{
    vector<vector<int>> Matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int *a = Search(Matrix,9);
    cout<<"{"<<a[0]<<","<<a[1]<<"}";
    return 0;
}