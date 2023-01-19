#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    //code1
        // int *p;
        // p = new int[5];
        // p[0] = 10;
        // p[1]  = 20;

        // cout<<p[1];
        // delete[]p;
    //code2
        int *p;
        p = new int[5];
        p[0]= 100; p[1]=200; p[2]=300; p[3]=400; p[4]=500;
        cout<<&p<<endl;
        int *q;
        q = new int[10];
        q[5] = 600;
        for(int i=0; i<5; i++)
        {
            q[i] = p[i];
        }
        delete []p;
        p=q;
        q = NULL;
        cout<<&p<<endl;
        cout<<p[5];
    return 0;
}