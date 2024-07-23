#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100005;
vector<int> tree[MAX_N];
int subtree_size[MAX_N];

int dfs(int node, int parent) {
    int size = 1;  
    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            size += dfs(neighbor, node);
        }
    }
    subtree_size[node] = size;
    return size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R, Q;
    cin >> N >> R >> Q;

    for (int i = 0; i < N - 1; ++i) {
        int U, V;
        cin >> U >> V;
        tree[U].push_back(V);
        tree[V].push_back(U);
    }

    dfs(R, -1);

    for (int i = 0; i < Q; ++i) {
        int U;
        cin >> U;
        cout << subtree_size[U] << '\n';
    }

    return 0;
}
