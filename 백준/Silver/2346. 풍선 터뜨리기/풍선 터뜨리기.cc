#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> balloons(n);
    for (int i = 0; i < n; ++i) {
        cin >> balloons[i];
    }

    deque<pair<int, int>> dq;
    for (int i = 0; i < n; ++i) {
        dq.push_back({i + 1, balloons[i]});
    }

    while (!dq.empty()) {
        int index = dq.front().first;
        int move = dq.front().second;
        dq.pop_front();

        cout << index << " ";

        if (dq.empty()) break;

        if (move > 0) {
            for (int i = 0; i < move - 1; ++i) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            for (int i = 0; i < (-move); ++i) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    return 0;
}
