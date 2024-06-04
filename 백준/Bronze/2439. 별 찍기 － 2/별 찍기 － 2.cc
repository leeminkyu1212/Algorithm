#include <iostream>

using namespace std;

int main() {
	int input;

	cin >> input;
	char blank = ' ';
	for (int i = 1; i <= input; i++) {
		for (int j = input-i; j > 0; j--) {
			cout << blank;
		}
		for (int j = 1; j <= i; j++) {
			cout << '*';
		}
		cout << endl;
	}
}