#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {

	int n;
	cin >> n;

	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}

	vector <int> diff(n);
	for (auto& i : diff) {
		cin >> i;
	}
	sort(diff.begin(), diff.end());

	int cutoff = round(n * 0.15);
	int sum = 0;

	for (int i = cutoff; i < n - cutoff; i++) {
		sum += diff[i];
	}

	double average = sum / static_cast<double>(n - 2 * cutoff);
	cout << round(average);


}