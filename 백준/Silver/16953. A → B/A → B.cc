#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int min_operations(int a, int b) {
    unordered_set<long long> visited;
    queue<pair<long long, int>> q;
    q.push({b, 1});
    visited.insert(b);

    while (!q.empty()) {
        long long current = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (current == a) {
            return steps;
        }

        if (current % 2 == 0) {
            long long next = current / 2;
            if (visited.find(next) == visited.end()) {
                q.push({next, steps + 1});
                visited.insert(next);
            }
        }
        
        if (current % 10 == 1) {
            long long next = current / 10;
            if (visited.find(next) == visited.end()) {
                q.push({next, steps + 1});
                visited.insert(next);
            }
        }
    }

    return -1;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << min_operations(a, b) << endl;
    return 0;
}
