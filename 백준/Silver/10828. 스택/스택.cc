#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> stack;

    int N = 0;
    cin >> N;
    string S = "";
    int X = 0;
    while (N--) {
        cin >> S;
        if (S == "push") {
            cin >> X;
            stack.push(X);
        } else if (S == "top") {
            if (stack.empty()) {
                cout << -1 << endl;
            } else {
                cout << stack.top() << endl;
            }
        } else if (S == "size") {
            cout << stack.size() << endl;
        } else if (S == "empty") {
            cout << stack.empty() << endl;
        } else if (S == "pop") {
            if (stack.empty()) {
                cout << -1 << endl;
            } else {
                cout << stack.top() << endl;
                stack.pop();
            }
        }
    }

    return 0;
}
