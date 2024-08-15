#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int G, P;
    cin >> G >> P;
    
    parent.resize(G + 1);
    for (int i = 1; i <= G; ++i) {
        parent[i] = i;
    }
    
    int count = 0;
    for (int i = 0; i < P; ++i) {
        int gi;
        cin >> gi;
        
        int docking_gate = find(gi);
        if (docking_gate == 0) {
            break;
        }
        
        unite(docking_gate, docking_gate - 1);
        count++;
    }
    
    cout << count << '\n';
    
    return 0;
}
