#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int destination, cost;
};

vector<vector<Edge>> graph;
vector<int> dist, parent;

void dijkstra(int start) {
    int n = graph.size();
    dist.assign(n, INT_MAX);
    parent.assign(n, -1);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();

        if (current_dist > dist[current]) continue;
        for (auto& edge : graph[current]) {
            int next = edge.destination;
            int cost = edge.cost;
            if (dist[current] + cost < dist[next]) {
                dist[next] = dist[current] + cost;
                parent[next] = current;
                pq.push({dist[next], next});
            }
        }
    }
}

vector<int> get_path(int start, int end) {
    vector<int> path;
    for (int at = end; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
    }

    int start, end;
    cin >> start >> end;

    dijkstra(start);

    int minimum_cost = dist[end];
    vector<int> path = get_path(start, end);

    cout << minimum_cost << endl;
    cout << path.size() << endl;
    for (int city : path) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}
