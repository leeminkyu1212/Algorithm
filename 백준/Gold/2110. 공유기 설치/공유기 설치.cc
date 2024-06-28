#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceRouters(const vector<int>& houses, int C, int minDist) {
	int count = 1;
	int lastInstalled = houses[0];
	for (int i = 1; i < houses.size(); i++) {
		if (houses[i] - lastInstalled >= minDist) {
			count++;
			lastInstalled = houses[i];
		}
	}

	return count >= C;
}


int findMaxDistance(vector <int>& houses, int C) {
	int left = 1;
	int right = houses.back() - houses.front();
	int result = 0;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (canPlaceRouters(houses, C, mid)) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return result;
}



int main() {
	int N, C;
	cin >> N >> C;
	vector <int> houses(N);

	for (auto& i : houses) {
		cin >> i;
	}

	sort(houses.begin(), houses.end());

	cout << findMaxDistance(houses, C) << '\n';

}
