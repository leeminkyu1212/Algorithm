#include <iostream>
#include <vector>

using namespace std;

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false; 
        if (rank[u] > rank[v]) swap(u, v);
        if (rank[u] == rank[v]) ++rank[v];
        parent[u] = v;
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    UnionFind uf(n);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        if (!uf.unite(u, v)) {
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}
