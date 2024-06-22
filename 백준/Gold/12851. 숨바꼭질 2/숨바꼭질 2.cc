#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    const int MAX = 100001;
    vector<int> visited(MAX, -1);
    vector<int> ways(MAX, 0);

    queue<int> q;
    q.push(N);
    visited[N] = 0;
    ways[N] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == K) break;

        for (int next : {current - 1, current + 1, current * 2}) {
            if (next >= 0 && next < MAX) {
                if (visited[next] == -1) {
                    visited[next] = visited[current] + 1;
                    ways[next] = ways[current];
                    q.push(next);
                } else if (visited[next] == visited[current] + 1) {
                    ways[next] += ways[current];
                }
            }
        }
    }

    cout << visited[K] << '\n';
    cout << ways[K] << '\n';

    return 0;
}
