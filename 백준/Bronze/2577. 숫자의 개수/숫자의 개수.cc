#include <iostream>

using namespace std;


int main(){
	long long A, B, C;
	long long ans;
	cin >> A >> B >> C;

	ans = A * B * C;
	int count[10] = { 0, };
	while (ans) {
		++count[ans % 10];
		ans = ans / 10;
	}
	for (int i = 0; i < 10; ++i) {
		cout << count[i] << endl;
	}
}


