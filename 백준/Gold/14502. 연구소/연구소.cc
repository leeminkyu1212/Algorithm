#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, m;
vector<vector<int>> lab;
vector<pair<int, int>> virus;
int result = 0;

// 바이러스 확산
void spreadVirus(vector<vector<int>>& tmpLab) {
    queue<pair<int, int>> q;
    for (auto& v : virus) {
        q.push(v);
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && tmpLab[nx][ny] == 0) {
                tmpLab[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
}

// 안전 영역 계산
int getSafeArea(vector<vector<int>>& tmpLab) {
    int safeArea = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (tmpLab[i][j] == 0) {
                ++safeArea;
            }
        }
    }
    return safeArea;
}

// 벽 세우기
void buildWall(int count) {
    if (count == 3) {
        vector<vector<int>> tmpLab = lab;
        spreadVirus(tmpLab);
        result = max(result, getSafeArea(tmpLab));
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (lab[i][j] == 0) {
                lab[i][j] = 1;
                buildWall(count + 1);
                lab[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    lab.resize(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> lab[i][j];
            if (lab[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }

    buildWall(0);
    cout << result << endl;
    return 0;
}
