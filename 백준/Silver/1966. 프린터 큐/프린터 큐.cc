#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n, m;
        cin >> n >> m;

        queue<pair<int, int>> q;
        priority_queue<int> pq;
        vector<int> priorities(n);

        for (int i = 0; i < n; ++i) {
            int priority;
            cin >> priority;
            q.push({priority, i});
            pq.push(priority);
            priorities[i] = priority;
        }

        int print_order = 0;

        while (!q.empty()) {
            int current_priority = q.front().first;
            int current_index = q.front().second;
            q.pop();

            if (current_priority == pq.top()) {
                ++print_order;
                pq.pop();
                if (current_index == m) {
                    cout << print_order << endl;
                    break;
                }
            } else {
                q.push({current_priority, current_index});
            }
        }
    }

    return 0;
}
