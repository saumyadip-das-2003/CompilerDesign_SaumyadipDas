#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string input;
    cout<<"Enter a string:"<<endl;
    getline(cin, input);

    int n = 0;
    for(int i=0; i<input.length();i++)
    {
        if(input[i] == '0' || input[i] == '1' || input[i] == '2' || input[i] == '3' ||
           input[i] == '4' || input[i] == '5' || input[i] == '6' || input[i] == '7' ||
           input[i] == '8' || input[i] == '9')
        {
            continue;
        }
        else
        {
            n++;
        }
    }
    if(n==0)
    {
        cout<<"Numerical"<<endl;
    }
    else
    {
        cout<<"Not Numerical"<<endl;
    }
}
