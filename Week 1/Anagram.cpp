#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool Anagram(string s1, string s2) //This works for Lowercase Letters For uppercase we have to use a bigger hashtable
{
    int arr[26] = {0};
    if(s1.size()!=s2.size())
    {
        return false;
    }
    else
    {
    for(int i=0; s1[i]!='\0'; i++)
    {
        arr[(s1[i] - 97)] += 1;
    }
    for(int j=0; s2[j]!='\0';j++)
    {
        arr[(s2[j] - 97)] -= 1;
    }
    for(auto &x : arr) //Searching in the Hash Table for any anomaly
    {
        if(x!=0)
        {
            return false;
        }
    }
    }
    return true;
}
int main()
{
    string s1 = "decimal";
    string s2 = "medical";
    cout<<Anagram(s1,s2);
    return 0;
}