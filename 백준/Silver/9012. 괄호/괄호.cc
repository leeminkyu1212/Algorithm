#include <iostream>
#include <stack>
using namespace std;






int main() {

	int T;
	cin >> T;

	string S;
	int size;
	while (T--) {
		stack <int> left;
		stack <int> right;
		cin >> S;
		size = S.size();

		for (int i = 0; i < size; i++) {
			if (S[i] == '(') {
				left.push(1);
			}
			else {
				right.push(1);
				if (left.empty() == true) {
					cout << "NO\n";
					goto end;
				}
				left.pop();
				right.pop();
			}
		}
		if (left.empty() == true) cout << "YES\n";
		else cout << "NO\n";
	end:;
	}
}