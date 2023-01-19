#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    // char name[5] = {'A','B','C','\0'};
    // cout<<name<<endl;

    // char myName[] = "keshav aneja";
    // cout<<myName<<" "<<myName[3]<<endl;

    //Creating A string in a Heap, Although this is forbidden by ISO, it works in C but not in C++
    char *thing = "Red John Says Hi!";
    //Now if we print this, without any breakage it will print the whole sentence
    cout<<thing<<endl;

    //But if We take a string seperated by space as input then print it, it will only print the first word
    char x[20];
    cin>>x; //The cin only stores the first word and the leftover word is left in the input stream to be read later
    cout<<x<<endl; //only prints first word
    cout<<gets(x)<<endl; //To print the remaining word left in the input stream we use this gets function

    //Now to simply store the whole sentence in the variable using cin is simple, we can use the getline(cin, storage_var) function
    string y; //Here you can't use a character array you have to use the string here.
    getline(cin,y); //This Also stores the whitespaces, so you can access those too.
    cout<<y[2];

    return 0;
}