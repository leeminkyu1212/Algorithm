#include <iostream>
#include <string>
using namespace std;



int flag = 0;
string ascending = "1 2 3 4 5 6 7 8";
string descending = "8 7 6 5 4 3 2 1";
string input;
int main() {
	getline(cin, input);


	if (input == ascending) cout << "ascending";
	else if (input == descending)cout << "descending";
	else cout << "mixed";
}