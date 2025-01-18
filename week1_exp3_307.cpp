#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter Number:";
    cin>>num;
    cout<<"Multiplication table of "<<num<<" ="<<"\n";
    for(int i=1;i<11;i++)
    {
        cout<<num<<"*"<<i<<"="<<num*i<<"\n";
    }
    return 0;
}