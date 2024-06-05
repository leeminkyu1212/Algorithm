#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX_V = 100001;
vector<pair<int, int>> adj[MAX_V];
bool visited[MAX_V];
int dist[MAX_V];

pair<int, int> bfs(int start) {
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int farthestNode = start;
    int maxDistance = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (size_t i = 0; i < adj[current].size(); ++i) {
            int next = adj[current][i].first;
            int weight = adj[current][i].second;

            if (!visited[next]) {
                visited[next] = true;
                dist[next] = dist[current] + weight;
                q.push(next);

                if (dist[next] > maxDistance) {
                    maxDistance = dist[next];
                    farthestNode = next;
                }
            }
        }
    }

    return make_pair(farthestNode, maxDistance);
}

int main() {
    int V;
    cin >> V;

    for (int i = 1; i <= V; ++i) {
        int u;
        cin >> u;
        while (true) {
            int v, w;
            cin >> v;
            if (v == -1) break;
            cin >> w;
            adj[u].push_back(make_pair(v, w));
        }
    }

    pair<int, int> result1 = bfs(1);
    pair<int, int> result2 = bfs(result1.first);

    cout << result2.second << endl;

    return 0;
}
