#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2000000000;

vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();
        
        if (current_dist > dist[current])
            continue;
        
        for (auto &edge : graph[current]) {
            int next = edge.first;
            int weight = edge.second;
            int next_dist = current_dist + weight;
            
            if (next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);
    dist.resize(N + 1, INF);

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int start, end;
    cin >> start >> end;

    dijkstra(start);

    cout << dist[end] << '\n';

    return 0;
}
