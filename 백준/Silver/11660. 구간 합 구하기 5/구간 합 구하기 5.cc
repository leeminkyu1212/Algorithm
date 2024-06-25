#include <iostream>
#include <vector>

using namespace std;

void computePrefixSum(const vector<vector<int>>& grid, vector<vector<int>>& S, int N) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            S[i][j] = grid[i][j] + S[i-1][j] + S[i][j-1] - S[i-1][j-1];
        }
    }
}

int getRangeSum(const vector<vector<int>>& S, int x1, int y1, int x2, int y2) {
    return S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> grid(N+1, vector<int>(N+1));
    vector<vector<int>> S(N+1, vector<int>(N+1, 0));
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> grid[i][j];
        }
    }
    
    computePrefixSum(grid, S, N);
    
    for (int i = 0; i < M; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << getRangeSum(S, x1, y1, x2, y2) << '\n';
    }
    
    return 0;
}
