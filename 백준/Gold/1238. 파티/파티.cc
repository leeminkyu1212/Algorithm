#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <climits>

using namespace std;

const int INF = INT_MAX;

vector<int> dijkstra(int start, const vector<vector<pair<int, int>>>& graph, int n) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();
        
        if (current_dist > dist[current]) continue;
        
        for (auto& edge : graph[current]) {
            int next = edge.first;
            int next_dist = current_dist + edge.second;
            
            if (next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }
    
    return dist;
}

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<vector<pair<int, int>>> reverse_graph(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        graph[u].emplace_back(v, t);
        reverse_graph[v].emplace_back(u, t);
    }
    
    vector<int> dist_from_x = dijkstra(x, graph, n);
    vector<int> dist_to_x = dijkstra(x, reverse_graph, n);
    
    int max_time = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == x) continue;
        max_time = max(max_time, dist_from_x[i] + dist_to_x[i]);
    }
    
    cout << max_time << endl;
    return 0;
}
