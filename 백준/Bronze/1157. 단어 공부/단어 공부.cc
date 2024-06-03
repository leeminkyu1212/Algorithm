#include <iostream>
#include <string>

using namespace std;

void upper(string& input) {
    for (char& i : input) {
        if (i >= 'a' && i <= 'z') {
            i = i - 'a' + 'A';
        }
    }
}

int main() {
    string input;
    cin >> input;
    upper(input);

    int arr[26] = { 0 };

    int Max = 0;
    bool same = false;
    for (char i : input) {
        if (i >= 'A' && i <= 'Z') {
            int index = i - 'A';
            ++arr[index];
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (arr[i] > arr[Max]) {
            Max = i;
            same = false;
        }
        else if (arr[i] == arr[Max] && i != Max) {
            same = true;
        }
    }

    if (same) {
        cout << "?" << endl;
    }
    else {
        cout << char(Max + 'A') << endl;
    }

    return 0;
}
