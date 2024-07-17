#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> items(N);

    for (int i = 0; i < N; ++i) {
        cin >> items[i].first >> items[i].second; 
    }

    vector<int> dp(K + 1, 0);

    for (int i = 0; i < N; ++i) {
        int weight = items[i].first;
        int value = items[i].second;

        for (int j = K; j >= weight; --j) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}
