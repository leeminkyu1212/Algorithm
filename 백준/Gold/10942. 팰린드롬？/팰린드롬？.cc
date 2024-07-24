#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 1;
    }

    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i+1]) {
            dp[i][i+1] = 1;
        }
    }

    for (int length = 3; length <= n; ++length) {
        for (int i = 1; i <= n - length + 1; ++i) {
            int j = i + length - 1;
            if (arr[i] == arr[j] && dp[i+1][j-1]) {
                dp[i][j] = 1;
            }
        }
    }

    int m;
    cin >> m;

    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }

    return 0;
}
