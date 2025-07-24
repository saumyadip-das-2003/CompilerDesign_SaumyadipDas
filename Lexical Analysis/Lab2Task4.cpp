#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    cout << "Enter a single word: ";
    cin >> word;

    string keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while", "bool", "class", "public",
        "private", "protected", "new", "delete", "try", "catch", "throw",
        "this", "using", "namespace", "include", "nullptr", "true", "false"
    };

    bool isKeyword = false;
    int totalKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < totalKeywords; i++)
    {
        if (keywords[i] == word)
        {
            isKeyword = true;
            break;
        }
    }

    if (isKeyword)
    {
        cout << "Not Identifier (Keyword)" << endl;
    }
    else
    {
        bool isValid = true;

        if (!((word[0] >= 'A' && word[0] <= 'Z') || (word[0] >= 'a' && word[0] <= 'z') || word[0] == '_'))
        {
            isValid = false;
        }
        else
        {
            for (int i = 1; i < word.length(); i++)
            {
                if (!((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z') ||
                      (word[i] >= '0' && word[i] <= '9') || word[i] == '_'))
                {
                    isValid = false;
                    break;
                }
            }
        }

        if (isValid)
            cout << "Valid Identifier" << endl;
        else
            cout << "Invalid Identifier" << endl;
    }

    return 0;
}
