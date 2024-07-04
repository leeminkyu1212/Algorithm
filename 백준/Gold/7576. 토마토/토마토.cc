#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int Max = 0;

int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };
int M, N;

bool ripeCheck(vector<vector<int>>& box, vector<vector<int>>& level) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (box[i][j] == 0) return false;
            if (level[i][j] > Max) Max = level[i][j];
        }
    }
    return true;
}

int main() {
    cin >> M >> N;
    vector<vector<int>> box(N, vector<int>(M, 0));
    vector<vector<int>> level(N, vector<int>(M, -1));

    queue<pair<int, int>> q;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int input;
            cin >> input;
            box[i][j] = input;
            if (input == 1) {
                q.emplace(i, j);
                level[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int idy = y + dy[i];
            int idx = x + dx[i];
            if (idy >= 0 && idx >= 0 && idy < N && idx < M) {
                if (box[idy][idx] == 0 && level[idy][idx] == -1) {
                    level[idy][idx] = level[y][x] + 1;
                    box[idy][idx] = 1;
                    q.emplace(idy, idx);
                }
            }
        }
    }

    if (ripeCheck(box, level)) {
        cout << Max;
    }
    else {
        cout << -1;
    }

    return 0;
}
