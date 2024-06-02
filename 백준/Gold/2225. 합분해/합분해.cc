#include <iostream>
using namespace std;

const int MOD = 1000000000;
int dp[201][201];

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		dp[i][1] = 1;
	}
	for (int j = 1; j <= K; j++) {
		dp[0][j] = 1;
	}

	for (int j = 2; j <= K; j++) {
		for (int i = 1; i <= N; i++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}

	}
	cout << dp[N][K] % MOD << endl;
	return 0;
}