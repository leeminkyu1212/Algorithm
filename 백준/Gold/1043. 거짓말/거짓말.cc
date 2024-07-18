#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else {
                parent[rootU] = rootV;
                if (rank[rootU] == rank[rootV])
                    rank[rootV]++;
            }
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    UnionFind uf(N + 1);
    vector<int> truth;
    int truthCount;
    cin >> truthCount;
    for (int i = 0; i < truthCount; ++i) {
        int person;
        cin >> person;
        truth.push_back(person);
    }

    vector<vector<int>> parties(M);
    for (int i = 0; i < M; ++i) {
        int partySize;
        cin >> partySize;
        parties[i].resize(partySize);
        for (int j = 0; j < partySize; ++j) {
            cin >> parties[i][j];
        }
        for (int j = 1; j < partySize; ++j) {
            uf.unite(parties[i][0], parties[i][j]);
        }
    }

    vector<bool> canLie(M, true);
    for (int i = 0; i < M; ++i) {
        for (int person : truth) {
            if (uf.find(person) == uf.find(parties[i][0])) {
                canLie[i] = false;
                break;
            }
        }
    }

    int lieCount = count(canLie.begin(), canLie.end(), true);
    cout << lieCount << endl;

    return 0;
}
