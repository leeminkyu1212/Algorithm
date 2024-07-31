#include <iostream>
#include <string>
#include <cmath>
using namespace std;


long long M = 1234567891;
int L = 0;
string S;

long long hashing() {

	long long value = 0;

	for (int i = 0; i < L; ++i) {
		value += pow(31, i) * (S[i] - 'a' + 1);
	}
	return value % M;
}



int main() {

	cin >> L >> S;

	cout << hashing();
}