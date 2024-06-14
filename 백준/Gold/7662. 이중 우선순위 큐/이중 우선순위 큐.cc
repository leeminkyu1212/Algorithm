#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int k;
        cin >> k;

        multiset<int> dq;

        for (int i = 0; i < k; ++i) {
            char op;
            int n;
            cin >> op >> n;

            if (op == 'I') {
                dq.insert(n);
            } else if (op == 'D') {
                if (dq.empty()) continue;
                if (n == 1) {
                    auto it = dq.end();
                    --it;
                    dq.erase(it);
                } else if (n == -1) {
                    dq.erase(dq.begin());
                }
            }
        }

        if (dq.empty()) {
            cout << "EMPTY" << endl;
        } else {
            auto max_it = dq.end();
            --max_it;
            cout << *max_it << " " << *dq.begin() << endl;
        }
    }

    return 0;
}
