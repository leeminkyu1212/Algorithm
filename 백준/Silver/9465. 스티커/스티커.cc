#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxStickerScore(vector<vector<int>>& stickers, int n) {
    vector<vector<int>> dp(2, vector<int>(n, 0));

    dp[0][0] = stickers[0][0];
    dp[1][0] = stickers[1][0];

    if (n > 1) {
        dp[0][1] = stickers[0][1] + dp[1][0];
        dp[1][1] = stickers[1][1] + dp[0][0];
    }

    for (int j = 2; j < n; ++j) {
        dp[0][j] = stickers[0][j] + max(dp[1][j-1], dp[1][j-2]);
        dp[1][j] = stickers[1][j] + max(dp[0][j-1], dp[0][j-2]);
    }

    return max(dp[0][n-1], dp[1][n-1]);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> stickers(2, vector<int>(n));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> stickers[i][j];
            }
        }

        cout << getMaxStickerScore(stickers, n) << '\n';
    }

    return 0;
}
