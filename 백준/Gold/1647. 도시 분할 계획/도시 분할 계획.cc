#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, cost;
    bool operator<(const Edge &other) const {
        return cost < other.cost;
    }
};

vector<int> parent, Rank;

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (Rank[u] < Rank[v]) {
            swap(u, v);
        }
        parent[v] = u;
        if (Rank[u] == Rank[v]) {
            Rank[u]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges(m);
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }
    
    sort(edges.begin(), edges.end());
    
    parent.resize(n + 1);
    Rank.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    int total_cost = 0;
    int max_cost = 0;
    

    for (const auto &edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            unite(edge.u, edge.v);
            total_cost += edge.cost;
            max_cost = edge.cost;
        }
    }
    

    cout << total_cost - max_cost << endl;
    
    return 0;
}

