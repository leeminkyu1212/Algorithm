#include <iostream>
#include <stack>
#include <string>

using namespace std;

int first(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(const string& infix) {
    string postfix = "";
    stack<char> s;

    for (char ch : infix) {
        if (isalpha(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); 
        }
        else {
            while (!s.empty() && first(s.top()) >= first(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cin >> infix;
    cout << infixToPostfix(infix) << endl;
    return 0;
}
