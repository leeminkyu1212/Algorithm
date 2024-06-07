#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 200000000;

void dijk(int V, int start, vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(V + 1, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (current_dist > dist[current_vertex]) continue;

        for (auto& edge : graph[current_vertex]) {
            int next_vertex = edge.first;
            int weight = edge.second;
            int distance = current_dist + weight;

            if (distance < dist[next_vertex]) {
                dist[next_vertex] = distance;
                pq.push({ distance, next_vertex });
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF) {
            cout << "INF" << endl;
        }
        else {
            cout << dist[i] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;

    int start;
    cin >> start;

    vector<vector<pair<int, int>>> graph(V + 1);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
    }

    dijk(V, start, graph);

    return 0;
}
