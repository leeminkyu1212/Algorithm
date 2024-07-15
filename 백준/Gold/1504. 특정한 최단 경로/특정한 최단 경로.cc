#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
int N, E;

void dijkstra(int start, vector<int>& dist) {
    dist.assign(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (currDist > dist[curr]) continue;

        for (auto& edge : graph[curr]) {
            int next = edge.first;
            int nextDist = edge.second;
            if (dist[curr] + nextDist < dist[next]) {
                dist[next] = dist[curr] + nextDist;
                pq.push({ dist[next], next });
            }
        }
    }
}

int main() {
    cin >> N >> E;
    graph.resize(N + 1);

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> dist1, dist_v1, dist_v2;
    dijkstra(1, dist1);
    dijkstra(v1, dist_v1);
    dijkstra(v2, dist_v2);

    int dist1_v1 = dist1[v1];
    int dist1_v2 = dist1[v2];
    int dist_v1_v2 = dist_v1[v2];
    int dist_v1_N = dist_v1[N];
    int dist_v2_N = dist_v2[N];

    int path1 = INF, path2 = INF;

    if (dist1_v1 != INF && dist_v1_v2 != INF && dist_v2_N != INF) {
        path1 = dist1_v1 + dist_v1_v2 + dist_v2_N;
    }

    if (dist1_v2 != INF && dist_v1_v2 != INF && dist_v1_N != INF) {
        path2 = dist1_v2 + dist_v1_v2 + dist_v1_N;
    }

    int result = min(path1, path2);

    if (result >= INF) {
        cout << -1 << endl;
    }
    else {
        cout << result << endl;
    }

    return 0;
}
