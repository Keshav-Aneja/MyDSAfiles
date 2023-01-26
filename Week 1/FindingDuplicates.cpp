#include<iostream>
#include<string>
#include<vector>
using namespace std;

void Duplicate(string &name) // This Prints which character is repeated and by how many times, this also takes care of the Ucase & Lcase
{   //The Time Complexity for this would be O(n+n) == O(n), so this is a better approach than that of searching for the element one by one
    int arr[26] = {0};
    for(int i=0; name[i] != '\0'; i++)
    {
        int x;
        if(name[i]>=65 && name[i]<=90)
        {
            x = name[i] - 65;
            arr[x] +=1;

        }
        else if(name[i]>=97 && name[i]<=122)
        {
            x = name[i] - 97;
            arr[x] +=1;
        }
    }
    for(int j=0; j<26; j++)
    {
        if(arr[j] > 1)
        {
            char a = j + 65;
            cout << a << " is repeating "<<arr[j] <<" times"<<endl;
        }
    }
}
void DuplicateBits(string &name) //This has a very good space complexity as it only uses a single integer for the calculation.
{ //But this doesn't count the number of repetitions of the character also it print multiple similar outputs.
//Time Complexity is O(n)
    long int H = 0;
    long int x;

    for(int i=0; i<name.size(); i++)
    {
        x = 1;
        x = x << (name[i] - 'a');
        if((x & H) > 0)
        {
            cout<<name[i]<<" has a duplicate."<<endl;
        }
        else
        {
            H = x | H;
        }
    }
}
int main()
{
    string name = "riding bike";
    Duplicate(name);
    cout<<"---------------"<<endl;
    DuplicateBits(name);
    return 0;
}