#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

bool isDelimiter(const string& token)
{
    string delimiters[] = {";", "(", ")", "{", "}", "[", "]", ",", ".", "/", "()", "{}" , "[]", "//", "/*" , "*/"};

    for (int i = 0; i < sizeof(delimiters)/sizeof(delimiters[0]); i++)
    {
        if (token == delimiters[i])
            return true;
    }

    return false;
}

bool isInteger(const string& token)
{
    for (int i = 0; i < token.length(); i++)
    {
        if (!isdigit(token[i]))
            return false;
    }
    return true;
}

bool isRealNumber(const string& token)
{
    int dotCount = 0;

    for (int i = 0; i < token.length(); i++)
    {
        if (token[i] == '.') {
            dotCount++;
        }
        else if (!isdigit(token[i])) {
            return false;
        }
    }

    return dotCount == 1;
}

int main()
{
    ifstream file("abc.txt");
    string word;

    if (!file)
    {
        cout << "File not found!" << endl;
        return 1;
    }

    while (file >> word)
    {
            if (isDelimiter(word))
            {
                cout << "Delimiter: " << word << endl;
            }
            else if (isInteger(word))
            {
                cout << "Integer: " << word << endl;
            }
            else if (isRealNumber(word))
            {
                cout << "Real Number: " << word << endl;
            }

    }

    file.close();
    return 0;
}
