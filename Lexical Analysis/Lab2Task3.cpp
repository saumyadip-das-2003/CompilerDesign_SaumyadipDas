#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string input;
    cout<<"Enter a string:"<<endl;
    getline(cin, input);

    bool commentsfound = false;
    for(int i=0; i<input.length(); i++)
    {
        if(input[i]== '/')
        {
            if(input[i+1]=='/')
            {
                commentsfound = true;
                cout<<"Single Line Comment"<<endl;
                break;
            }
            else if(input[i+1]== '*')
            {
                bool endFound = false;
                for (int j = i + 2; j < input.length() - 1; j++)
                {
                    if (input[j] == '*' && input[j + 1] == '/')
                    {
                        endFound = true;
                        break;
                    }
                }

                if (endFound)
                {
                    commentsfound = true;
                    cout << "Multi-line Comment" << endl;
                    break;
                }
                else
                {
                    commentsfound = true;
                    cout << "Multi-line Comment but not closed" << endl;
                    break;
                }
            }
        }

    }
    if(!commentsfound)
    {
        cout<<"No Comments"<<endl;
    }
}




