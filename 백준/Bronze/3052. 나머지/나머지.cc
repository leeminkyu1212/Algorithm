#include <iostream>


using namespace std;

int arr[42] = { 0, };
int input = 0;
int cnt = 0;
int main() {


	for (int i = 0; i < 10; i++) {
		cin >> input;
		arr[input % 42]++;
		if (arr[input % 42] == 1) cnt++;
	}

	cout << cnt;

}