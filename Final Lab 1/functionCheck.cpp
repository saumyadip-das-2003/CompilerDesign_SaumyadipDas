#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isLetter(char c)
{
    return (c>='a'&&c<='z') || (c>='A'&&c<='Z');
}

bool isDigit(char c)
{
    return (c>='0'&&c<='9');
}

bool isUnderscore(char c)
{
    return c=='_';
}

bool isSpace(char c)
{
    return c==' ' || c=='\t' || c=='\r' || c=='\n';
}

bool isTypeToken(const string& s)
{
    return (s == "int" || s == "float" || s == "double" || s == "char" || s == "void");
}


bool isIdentifier(const string& s)
{
    if (s.length()==0)
    {
        return false;
    }
    if (!(isLetter(s[0]) || isUnderscore(s[0])))
    {
        return false;
    }
    for (int i=1;i<(int)s.length();++i)
    {
        char c=s[i];
        if (!(isLetter(c)||isDigit(c)||isUnderscore(c)))
        {
            return false;
        }
    }
    return true;
}

void isFunction(string line)
{
    int n = line.length();
    int i = 0;

    while (i<n && isSpace(line[i]))
    {
        i++;
    }

    string dtype = "";

    while (i<n && (isLetter(line[i]) || isUnderscore(line[i]) || isDigit(line[i])))
    {
        dtype += line[i];
        i++;
    }

    if (!isTypeToken(dtype))
    {
        cout << "Incorrect Declaration\n";
        return;
    }

    bool hadSpaceAfterType = false;

    while (i<n && isSpace(line[i]))
    {
        hadSpaceAfterType = true;
        i++;
    }

    if (!hadSpaceAfterType)
    {
        cout << "Incorrect Declaration\n";
        return;
    }

    string fname = "";

    if (i<n && (isLetter(line[i]) || isUnderscore(line[i])))
    {
        while (i<n && (isLetter(line[i]) || isUnderscore(line[i]) || isDigit(line[i])))
        {
            fname += line[i]; i++;
        }
    }

    else
    {
        cout << "Incorrect Declaration\n";
        return;
    }

    if (!isIdentifier(fname))
    {
        cout << "Incorrect Declaration\n";
        return;
    }

    while (i<n && isSpace(line[i]))
    {
        i++;
    }

    if (!(i<n && line[i]=='('))
    {
        cout << "Incorrect Declaration\n";
        return;
    }

    i++;

    bool foundCloseParen = false;

    while (i<n)
    {
        if (line[i]==')')
        {
            foundCloseParen = true;
            i++;
            break;
        }
        i++;
    }

    if (!foundCloseParen)
    {
        cout << "Incorrect Declaration\n";
        return;
    }

    while (i<n && isSpace(line[i]))
    {
        i++;
    }

    if (i>=n)
    {
        cout << "Incorrect Declaration\n";
        return;
    }

    if (line[i]==';')
    {
        i++;
        while (i<n && isSpace(line[i]))
        {
            i++;
        }
        if (i==n)
        {
            cout << "Correct Declaration\n";
        }
        else
        {
            cout << "Incorrect Declaration\n";
        }
        return;
    }
    if (line[i]=='{')
    {
        i++;
        while (i<n && isSpace(line[i]))
        {
             i++;
        }

        bool foundRightBrace = false;

        while (i<n)
        {
            if (line[i]=='}')
            {
                foundRightBrace = true;
                i++;
                break;
            }
            i++;
        }

        if (foundRightBrace)
        {
            while (i<n && isSpace(line[i]))
            {
               i++;
            }
            if (i==n)
            {
                cout << "Correct Definition\n";
            }
            else
            {
                cout << "Incorrect Definition\n";
            }
        }
        else
        {
            cout << "Incorrect Definition\n";
        }
        return;
    }
    cout << "Incorrect Declaration\n";
}

int main(){
    ifstream file("test.txt");
    if (!file)
    {
        cout << "File not found!\n";
    }
    string line;
    while (getline(file, line))
    {
        isFunction(line);
    }
    file.close();
    return 0;
}
