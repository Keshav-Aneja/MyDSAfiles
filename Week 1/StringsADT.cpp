//size() of a string
//ChangeCase() of a string
//count() counting the vowels, consonants & words
//Valid() 
//Reverse()
//Palindrome()

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct strings
{
      char A[100];
      int size;
      int vowels = 0;
      int consonants = 0;
      int words = 0;
};
int size(struct strings *name)
{
    int i=0;
    while(name->A[i]!='\0')
    {
        name->size++;
        i++;
    }
    return name->size;
}
void ChangeCase(struct strings *name)
{
    for(int i=0; i<name->size; i++)
    {
        if(name->A[i] <= 90 && name->A[i] >= 65)
        {
            name->A[i] += 32;
        }
        else if(name->A[i] >= 90 && name->A[i] <=122)
        {
            name->A[i] -= 32;
        }
        
    }
}
void count(struct strings *name)
{
    int spaces = 0;
    int white = 0;
    for(int i=0; i<name->size; i++)
    {
        
        if(name->A[i] == 'a' || name->A[i] == 'e' || name->A[i] == 'i' || name->A[i] == 'o' || name->A[i] == 'u' || 
           name->A[i] == 'A' || name->A[i] == 'E' || name->A[i] == 'I' || name->A[i] == 'O' || name->A[i] == 'U')
           {
                name->vowels++;
           }
        else if(name->A[i]==' ')
        {
            if(i>white+1) //This takes care of the white spaces present in the string
            {
                spaces++;
            }
            white = i;
        }
        else if((name->A[i] >= 65 && name->A[i] <=90) || (name->A[i] >=97 && name->A[i] <=122)) 
        {
            name->consonants++;
        }
    }
    name->words += spaces + 1;
}
bool valid(struct strings *name)
{
    for(int i=0; i<name->size; i++)
    {
        if(!(name->A[i] >= 65 && name->A[i] <=90) && !(name->A[i] >=97 && name->A[i] <=122) && !(name->A[i] >=48 && name->A[i]<=57))
        {
            return false;
        }
    }
    return true;
}
void reverse(struct strings *name)
{
    int i = 0;
    int j = name->size - 1;
    while(i<=j)
    {
        swap(name->A[i],name->A[j]);
        i++;
        j--;
    }
}
bool palindrome(struct strings *name)
{
    int i=0;
    int j=name->size - 1;
    while(i<=j)
    {
        if(name->A[i] != name->A[j])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    //This is Self-Built for Finding the length of the string
    struct strings name = {"Keshav Aneja"};
    struct strings pali = {"MADAM"};
    cout<<size(&name)<<endl;
    //This is the In-Built Function for finding the length of the string
    string ans = "ABCDEF";
    cout<<ans.size()<<endl;

    //This Will change the case of the string, if the character is in lowercase then it will turn into Uppercase and vice versa
    ChangeCase(&name);
    cout<<name.A<<endl;

    //This will count the number of vowels , consonants and words in a string
    count(&name);
    cout<<"There are "<<name.vowels<<" vowels in the string."<<endl;
    cout<<"There are "<<name.consonants<<" consonants in the string."<<endl;
    cout<<"There are "<<name.words<<" words in the string."<<endl;

    //This will check if the given string is a valid name / username or not, i.e. it should not contain anything beside A,a,123.
    cout<<valid(&name)<<endl;

    //Reversing an array, without copying the array in a different string.
    reverse(&name);
    cout<<name.A<<endl;

    //Checking if the string is Palindrome or not
    cout<<palindrome(&pali)<<endl;

    return 0;
}