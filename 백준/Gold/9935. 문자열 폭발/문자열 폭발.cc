#include <iostream>
#include <vector>
#include <string>
using namespace std;

string explodeString(const string& str, const string& bomb) {
    vector<char> s;
    int bombLength = bomb.length();

    for (char ch : str) {
        s.push_back(ch);

        if (s.size() >= bombLength) {
            bool isBomb = true;
            for (int i = 0; i < bombLength; i++) {
                if (s[s.size() - bombLength + i] != bomb[i]) {
                    isBomb = false;
                    break;
                }
            }

            if (isBomb) {
                for (int i = 0; i < bombLength; i++) {
                    s.pop_back();
                }
            }
        }
    }

    if (s.empty()) {
        return "FRULA";
    }

    return string(s.begin(), s.end());
}

int main() {
    string str, bomb;
    cin >> str >> bomb;

    cout << explodeString(str, bomb) << endl;

    return 0;
}
