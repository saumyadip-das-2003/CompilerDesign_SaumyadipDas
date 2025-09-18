
#include <iostream>
#include <string>
using namespace std;

// 1. a(a+b)*
bool matchRegex1(const string &s) {
    if (s.empty() || s[0] != 'a') {
        return false;
    }

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            return false;
        }
    }

    return true;
}

// 2. a(a+b)* + b
bool matchRegex2(const string &s) {
    if (s == "b") {
        return true;
    }

    if (s.empty() || s[0] != 'a') {
        return false;
    }

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            return false;
        }
    }

    return true;
}

// 3. a(a+b)* + b*
bool matchRegex3(const string &s) {
    if (s.empty() || s[0] == 'b') {
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != 'b') {
                return false;
            }
        }
        return true;
    }

    if (s[0] != 'a') {
        return false;
    }

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            return false;
        }
    }

    return true;
}

int main() {
    string test;
    cout << "Enter a string: ";
    cin >> test;

    // Check regex 1: a(a+b)*
    cout << "Checking regex 1 (a(a+b)*): "
         << (matchRegex1(test) ? "Match" : "No Match") << endl;

    // Check regex 2: a(a+b)* + b
    cout << "Checking regex 2 (a(a+b)* + b): "
         << (matchRegex2(test) ? "Match" : "No Match") << endl;

    // Check regex 3: a(a+b)* + b*
    cout << "Checking regex 3 (a(a+b)* + b*): "
         << (matchRegex3(test) ? "Match" : "No Match") << endl;

    return 0;
}
