#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void DFS(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
    visited[v] = true;
    result.push_back(v);

    for (int u : adj[v]) {
        if (!visited[u]) {
            DFS(u, adj, visited, result);
        }
    }
}

void BFS(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);

        for (int u : adj[current]) {
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
            }
        }
    }
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    vector<bool> visited(N + 1, false);
    vector<int> dfs_result;
    DFS(V, adj, visited, dfs_result);

    for (int v : dfs_result) {
        cout << v << " ";
    }
    cout << endl;

    visited.assign(N + 1, false);
    vector<int> bfs_result;
    BFS(V, adj, visited, bfs_result);

    for (int v : bfs_result) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
