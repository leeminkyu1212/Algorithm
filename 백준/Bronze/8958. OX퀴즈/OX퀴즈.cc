#include <iostream>

using namespace std;

string input;
int length = 0;
int cnt = 0;
int sum = 0;
int main() {
	int T;
	cin >> T;
	while (T--) {

		sum = 0;
		cnt = 0;

		cin >> input;
		length = input.size();

		for (int i = 0; i<length; ++i) {
			if (input[i] == 'O') {
				++cnt;
			}
			else cnt = 0;
			sum += cnt;
		}
		cout << sum << endl;
	}

}