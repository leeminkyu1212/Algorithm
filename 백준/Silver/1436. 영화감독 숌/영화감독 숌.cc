#include <iostream>
#include <string>

using namespace std;

int main() {

	int title;
	string str;
	int check = 0;
	int N;

	cin >> N;

	for (title = 666; ; title++) {
		str = to_string(title);
		if (str.find("666") != -1) {
			check++;
			if (check == N) {
				cout << title;
				break;
			}
		}
	}
	return 0;
}
