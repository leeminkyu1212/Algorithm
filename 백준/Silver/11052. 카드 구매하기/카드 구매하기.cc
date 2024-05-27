#include <iostream>

using namespace std;

int N;


int arr[1001] = { 0, };
int dp[1001] = { 0, };


int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (dp[i] < dp[i - j] + arr[j])  dp[i] = dp[i - j] + arr[j];
		}
	}
	cout << dp[N] << endl;
}