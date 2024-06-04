#include <iostream>
#include <cstring>
using namespace std;

string S;
int alphabet[200];
int main() {
	memset(alphabet, -1, sizeof(alphabet));

	cin >> S;
	int length = S.size();
		
	for (int i = length - 1; i >= 0; i--) {
		alphabet[S[i]] = i;
	}
	for (int i = 'a'; i <= 'z'; i++) {
		cout << alphabet[i] << " ";
	}
}