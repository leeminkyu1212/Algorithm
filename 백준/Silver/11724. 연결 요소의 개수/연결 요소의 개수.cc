#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj_list, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj_list[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj_list, visited);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj_list(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<bool> visited(N + 1, false);
    int connected_components = 0;

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i, adj_list, visited);
            connected_components++;
        }
    }

    cout << connected_components << endl;

    return 0;
}
