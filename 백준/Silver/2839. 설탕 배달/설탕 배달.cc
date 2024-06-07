#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int num_bag = -1;

	for (int i = N / 5; i >= 0; --i) {
		int remainder = N - i * 5;
		if (remainder % 3 == 0) {
			num_bag = i + remainder / 3;
			break;
		}
	}

	cout << num_bag << endl;
	return 0;
}
