#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{

    vector<string> store;
    for(int i=0; i<3; i++)
    {
        string temp;
        //Now Let's say i write "The Quick.Brown Fox.Jumps over.The Little Lazy Dog." So it works for a paragraph, you can store
        //each sentence in a vector and you can access different sentences on your whim
        getline(cin,temp,'.'); 
        //after taking the first sentence as an input the rest of the input remains in the terminal area and when the next time getline
        //is used then the rest of the sentence gets stored in it.
        store.push_back(temp);
    }
    for(auto &x : store)
    {
        cout<<x<<endl;
    }
    return 0;
}
