#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<int, int> board;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        board[x] = y;
    }

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        board[u] = v;
    }

    vector<int> dist(101, -1);
    queue<int> q;

    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int dice = 1; dice <= 6; ++dice) {
            int next = current + dice;
            if (next > 100) continue;

            if (board.find(next) != board.end()) {
                next = board[next];
            }

            if (dist[next] == -1) {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }

    cout << dist[100] << endl;

    return 0;
}
