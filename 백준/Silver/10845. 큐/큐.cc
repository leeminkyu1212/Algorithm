#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> q;
    string S;

    for (int i = 0; i < N; ++i) {
        cin >> S;

        if (S == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (S == "pop") {
            if (q.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if (S == "size") {
            cout << q.size() << endl;
        }
        else if (S == "empty") {
            cout << (q.empty() ? 1 : 0) << endl;
        }
        else if (S == "front") {
            if (q.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << q.front() << endl;
            }
        }
        else if (S == "back") {
            if (q.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << q.back() << endl;
            }
        }
    }

    return 0;
}
