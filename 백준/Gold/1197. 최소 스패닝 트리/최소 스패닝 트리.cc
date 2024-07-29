#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int from, to, weight;
};

vector<int> parent, Rank;

int find(int x) {
	if (parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void unite(int x, int y) {
	int rootX = find(x);
	int rootY = find(y);
	if (rootX != rootY) {
		if (Rank[rootX] > Rank[rootY]) {
			parent[rootY] = rootX;
		}
		else if (Rank[rootX] < Rank[rootY]) {
			parent[rootX] = rootY;
		}
		else {
			parent[rootY] = rootX;
			Rank[rootX]++;
		}
	}
}

int main() {
	int V, E;
	cin >> V >> E;
	vector<Edge> edges(E);

	for (int i = 0; i < E; ++i) {
		cin >> edges[i].from >> edges[i].to >> edges[i].weight;
	}

	parent.resize(V + 1);
	Rank.resize(V + 1, 0);
	for (int i = 1; i <= V; ++i) {
		parent[i] = i;
	}

	sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
		return a.weight < b.weight;
		});

	int mst_weight = 0;
	int edges_used = 0;

	for (Edge edge : edges) {
		if (find(edge.from) != find(edge.to)) {
			unite(edge.from, edge.to);
			mst_weight += edge.weight;
			edges_used++;
			if (edges_used == V - 1) {
				break;
			}
		}
	}

	cout << mst_weight << endl;
	return 0;
}
