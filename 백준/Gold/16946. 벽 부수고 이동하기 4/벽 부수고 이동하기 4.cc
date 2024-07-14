#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_set>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M;
vector<vector<int>> map;
vector<vector<int>> group;

int bfs(int x, int y, int group_id) {
    int size = 0;
    queue<pair<int, int>> q;
    q.emplace(x, y);
    group[x][y] = group_id;
    
    while (!q.empty()) {
        int cx, cy;
        tie(cx, cy) = q.front();
        q.pop();
        size++;
        
        for (int i = 0; i < 4; i++) {
            int idx = cx + dx[i];
            int idy = cy + dy[i];
            
            if (idx >= 0 && idx < N && idy >= 0 && idy < M && map[idx][idy] == 0 && group[idx][idy] == -1) {
                group[idx][idy] = group_id;
                q.emplace(idx, idy);
            }
        }
    }
    
    return size;
}

int main() {
    cin >> N >> M;
    map.assign(N, vector<int>(M));
    group.assign(N, vector<int>(M, -1));
    vector<int> group_size;
    
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            map[i][j] = line[j] - '0';
        }
    }
    
    int group_id = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0 && group[i][j] == -1) {
                int size = bfs(i, j, group_id);
                group_size.push_back(size);
                group_id++;
            }
        }
    }
    
    vector<vector<int>> result(N, vector<int>(M, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1) {
                unordered_set<int> adjacent_groups;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && group[nx][ny] != -1) {
                        adjacent_groups.emplace(group[nx][ny]);
                    }
                }
                
                int move_count = 1;
                for (int group_id : adjacent_groups) {
                    move_count += group_size[group_id];
                }
                
                result[i][j] = move_count % 10;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
