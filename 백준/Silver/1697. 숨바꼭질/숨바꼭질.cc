#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(int n, int k) {
    const int MAX = 100001;
    vector<int> visited(MAX, -1);
    queue<int> q;
    
    visited[n] = 0;
    q.push(n);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        if (current == k) {
            return visited[current];
        }
        
        int next_positions[3] = {current - 1, current + 1, current * 2};
        
        for (int i = 0; i < 3; ++i) {
            int next = next_positions[i];
            if (next >= 0 && next < MAX && visited[next] == -1) {
                visited[next] = visited[current] + 1;
                q.push(next);
            }
        }
    }
    
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k) << endl;
    return 0;
}
