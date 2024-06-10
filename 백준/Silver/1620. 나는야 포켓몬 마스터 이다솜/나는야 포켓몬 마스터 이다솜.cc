#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector <string> pokemon;
unordered_map <int, string> key_value;
unordered_map <string, int> value_key;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {


		string name;
		cin >> name;
		key_value[i] = name;
		value_key[name] = i;

	}


	while (M--) {
		string ans;
		cin >> ans;
		if (ans[0] >= 'A' && ans[0] <= 'Z') {
			cout << value_key[ans] << '\n';
		}
		else cout << key_value[stoi(ans)] << '\n';
	}



}