#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;

    bool S[21] = { false }; 
    while (M--) {
        string op;
        int x;
        cin >> op;

        if (op == "add") {
            cin >> x;
            S[x] = true;
        } else if (op == "remove") {
            cin >> x;
            S[x] = false;
        } else if (op == "check") {
            cin >> x;
            cout << (S[x] ? 1 : 0) << '\n';
        } else if (op == "toggle") {
            cin >> x;
            S[x] = !S[x];
        } else if (op == "all") {
            for (int i = 1; i <= 20; ++i) {
                S[i] = true;
            }
        } else if (op == "empty") {
            for (int i = 1; i <= 20; ++i) {
                S[i] = false;
            }
        }
    }

    return 0;
}
