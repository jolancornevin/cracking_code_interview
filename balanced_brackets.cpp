// https://www.hackerrank.com/challenges/ctci-balanced-brackets/problem

#include <bits/stdc++.h>
#include <stack>
#include <map>

using namespace std;

void is_balanced(string expression) {
    stack<char> charStack;
    map<char, char> charCorrespondance;

    charCorrespondance['}'] = '{';
    charCorrespondance[']'] = '[';
    charCorrespondance[')'] = '(';

    for (int iterChar = 0; iterChar < expression.size(); ++iterChar) {
        char currentChar = expression[iterChar];
        switch(currentChar) {
            case '{':
            case '[':
            case '(':
                charStack.push(currentChar);
                break;
            case '}':
            case ']':
            case ')':
                if (charStack.empty() || charCorrespondance[currentChar] != charStack.top()) {
                    cout << "NO" << '\n';
                    return;
                }
                charStack.pop();
                break;
        }
    }

    if (charStack.empty())
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string expression;
        getline(cin, expression);
        is_balanced(expression);
    }

    return 0;
}
