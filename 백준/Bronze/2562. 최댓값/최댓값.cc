#include <iostream>

using namespace std;


int arr[9] = { 0, };
int Max = -1;
int index = 0;
int main() {

	for (int i = 0; i < 9;i++) {
		cin >> arr[i];
		if (arr[i] > Max) {
			Max = arr[i];
			index = i;
		}
	}
	cout << Max << endl << index+1;
}