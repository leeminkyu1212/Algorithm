#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> buildTime(N + 1);
        vector<vector<int>> adj(N + 1);
        vector<int> indegree(N + 1, 0);
        vector<int> dp(N + 1, 0);

        for (int i = 1; i <= N; ++i) {
            cin >> buildTime[i];
        }

        for (int i = 0; i < K; ++i) {
            int X, Y;
            cin >> X >> Y;
            adj[X].push_back(Y);
            indegree[Y]++;
        }

        int W;
        cin >> W;

        queue<int> q;
        
        for (int i = 1; i <= N; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i] = buildTime[i]; 
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int next : adj[curr]) {
                dp[next] = max(dp[next], dp[curr] + buildTime[next]);
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        cout << dp[W] << endl;
    }

    return 0;
}
