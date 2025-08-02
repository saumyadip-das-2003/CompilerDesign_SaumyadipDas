#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isIdentifier(string token)
{
    if (token.length() == 0 || !(token[0] >= 'a' && token[0] <= 'z') && !(token[0] >= 'A' && token[0] <= 'Z') && token[0] != '_')
        return false;
    for (int i = 0; i < token.length(); i++)
    {
        if (!( (token[i] >= 'a' && token[i] <= 'z') || (token[i] >= 'A' && token[i] <= 'Z') || (token[i] >= '0' && token[i] <= '9') || token[i] == '_'))
        {
            return false;
        }
    }
    return true;
}

bool isOperator(string token)
{
    if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%" ||
        token == "++" || token == "--" || token == "=" || token == "==" || token == "!=" ||
        token == "<" || token == ">" || token == "<=" || token == ">=" || token == "&&" || token == "||")
    {
        return true;
    }
    return false;
}

bool isKeyword(string token)
{
    string keywords[] = {"int", "char", "float", "double", "if", "else", "while", "for", "return", "void", "main"};
    for (int i = 0; i < 11; i++)
    {
        if (token == keywords[i]) return true;
    }
    return false;
}

bool isPunctuation(string token)
{
    string punctuations[] = {";", "(", ")", "{", "}", "[", "]", ":", ","};
    for (int i = 0; i < 8; i++)
    {
        if (token == punctuations[i])
            return true;
    }
    if (token == "()" || token == "[]")
        return true;

    return false;
}

bool isComment(string token)
{
    if (token == "//") {
        return true;
    }
    return false;
}

int main()
{
    ifstream file("test.txt");
    string word;

    if (!file)
    {
        cout << "File not found!" << endl;
        return 1;
    }

    while (file >> word)
    {
        bool isValid = false;

        if (isKeyword(word))
        {
            cout << "Keyword: " << word << endl;
            isValid = true;
        }
        else if (isPunctuation(word))
        {
            cout << "Punctuation: " << word << endl;
            isValid = true;
        }
        else if (word == "(" || word == ")") {
            cout << "Punctuation: " << word << endl;
            isValid = true;
        }
        else if (isIdentifier(word)) {
            cout << "Identifier: " << word << endl;
            isValid = true;
        }
        else if (isOperator(word))
        {
            cout << "Operator: " << word << endl;
            isValid = true;
        }
        else if (isComment(word))
        {
             cout << "Comment: " << word << endl;
            isValid = true;
        }

        if (!isValid)
        {
            cout << "Invalid: " << word << endl;
        }
    }

    file.close();
    return 0;
}
