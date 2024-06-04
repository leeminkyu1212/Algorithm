#include <iostream>
#include <string>
using namespace std;


string reverse(const string& input) {


	int length = input.size();
	string reverse = input;
	for (int i = length - 1; i >= 0; i--) {
		reverse[i] = input[length - 1 - i];
	}



	return reverse;
}

int main() {
	string input;

	cin >> input;
	while (1) {
		if (input.size() == 1 && input[0] == '0')return 0;
		string rev = reverse(input);
		if (input == rev) cout << "yes\n";
		else cout << "no\n";

		cin >> input;
	}

}