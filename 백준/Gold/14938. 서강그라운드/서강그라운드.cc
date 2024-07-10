#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> dijkstra(int start, int n, const vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();

        int currentDist = current.first;
        int currentNode = current.second;

        if (currentDist > dist[currentNode]) continue;

        for (const auto& neighbor : graph[currentNode]) {
            int nextNode = neighbor.first;
            int length = neighbor.second;
            int nextDist = currentDist + length;
            if (nextDist < dist[nextNode]) {
                dist[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }

    return dist;
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<int> items(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> items[i];
    }

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < r; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].emplace_back(b, l);
        graph[b].emplace_back(a, l);
    }

    int maxItems = 0;
    for (int i = 1; i <= n; ++i) {
        vector<int> dist = dijkstra(i, n, graph);
        int totalItems = 0;
        for (int j = 1; j <= n; ++j) {
            if (dist[j] <= m) {
                totalItems += items[j];
            }
        }
        maxItems = max(maxItems, totalItems);
    }

    cout << maxItems << endl;
    return 0;
}
