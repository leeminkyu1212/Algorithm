#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2000000000;
int N;
vector<vector<int>> W; 
vector<vector<int>> dp; 

int tsp(int mask, int pos) {
    if (mask == (1 << N) - 1) {
        return W[pos][0] ? W[pos][0] : INF;
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;
    for (int city = 0; city < N; ++city) {
        if (!(mask & (1 << city)) && W[pos][city]) {
            ans = min(ans, W[pos][city] + tsp(mask | (1 << city), city));
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    W.resize(N, vector<int>(N));
    dp.resize(1 << N, vector<int>(N, -1));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> W[i][j];
        }
    }

    cout << tsp(1, 0) << '\n';
    return 0;
}
