#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string input;
    cout<<"Enter a string:"<<endl;
    getline(cin, input);

    char printedOperators[1000];
    int printedCount = 0;
    int opCount =0;

    for(int i=0; i<input.length(); i++)
    {
        char ch = input[i];

        if (ch == '=' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
        {
            bool alreadyPrinted = false;

            for (int j = 0; j < printedCount; j++)
            {
                if (printedOperators[j] == ch)
                {
                    alreadyPrinted = true;
                    break;
                }
            }

            if (!alreadyPrinted)
            {
                printedOperators[printedCount++] = ch;
                cout << "Operator" << ++opCount << " : " << ch << endl;
            }
        }
    }
}

