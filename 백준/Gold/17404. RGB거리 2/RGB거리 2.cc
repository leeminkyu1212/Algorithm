#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> cost(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    
    int result = 1e9;
    for (int first_color = 0; first_color < 3; first_color++) {
        vector<vector<int>> dp(n, vector<int>(3, 1e9));
        dp[0][first_color] = cost[0][first_color];
        
        for (int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
        }
        
        for (int last_color = 0; last_color < 3; last_color++) {
            if (last_color != first_color) {
                result = min(result, dp[n-1][last_color]);
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}
