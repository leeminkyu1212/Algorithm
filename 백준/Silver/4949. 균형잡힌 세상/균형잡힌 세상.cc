#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& str) {
    stack<char> s;
    for (char ch : str) {
        if (ch == '(' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')') {
            if (s.empty() || s.top() != '(') {
                return false;
            }
            s.pop();
        }
        else if (ch == ']') {
            if (s.empty() || s.top() != '[') {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    string line;
    while (true) {
        string temp;
        getline(cin, temp);
        if (temp == ".") break;
        line += temp;

        if (isBalanced(line)) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
        line.clear();
    }
    return 0;
}
