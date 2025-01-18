#include<iostream>
using namespace std;
int main()
{
    int num1,num2,num3;
    cout<<"Enter 1st Number:";
    cin>>num1;
    cout<<"Enter 2nd Number:";
    cin>>num2;
    cout<<"Enter 3rd Number:";
    cin>>num3;

    if(num1>num2)
    {
        if(num1>num3)
        {
            cout<<"Largest number amoung 3 numbers="<<num1;
        }
        else
        {
            cout<<"Largest number amoung 3 numbers="<<num3;
        }
    }
    else
    {
        if(num2>num3)
        {
            cout<<"Largest number amoung 3 numbers="<<num2;
        }
        else
        {
            cout<<"Largest number amoung 3 numbers="<<num3;
        }
    }

    return 0;
}