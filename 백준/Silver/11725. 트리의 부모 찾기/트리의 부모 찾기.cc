#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void findParents(int N, const vector<vector<int>>& adjList) {
    vector<int> parents(N + 1, 0);
    queue<int> q;
    vector<bool> visited(N + 1, false);

    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parents[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << parents[i] << '\n';
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> adjList(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    findParents(N, adjList);

    return 0;
}
