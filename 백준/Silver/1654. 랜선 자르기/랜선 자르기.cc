#include <iostream>
#include <algorithm>

using namespace std;

long long ans;
long long N, K;
long long list[10000];

int main()
{
	cin >> K >> N;
	long long Max = 0;
	for (int i = 0; i < K; i++)
	{
		cin >> list[i];
		Max = max(Max, list[i]);
	}

	long long left = 1, right = Max, mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		long long now = 0;
		for (int i = 0; i < K; i++){
			now += list[i] / mid;
		}
		if (now >= N){
			left = mid + 1;
			ans = max(ans, mid);
		}
		else{
			right = mid - 1;
		}
	}

	cout << ans << '\n';
}