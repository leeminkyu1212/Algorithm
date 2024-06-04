#include <iostream>

using namespace std;

int main() {
	string S;
	int T,R;
	int length;
	cin >> T;

	while (T--) {
		
		cin >> R >> S;
		length = S.size();
		for (int i = 0; i < length; ++i) {
			for (int j = 0; j < R; j++) {
				cout << S[i];
			}
		}
		cout << endl;

	}


}