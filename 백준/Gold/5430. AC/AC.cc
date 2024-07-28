#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void process_test_case() {
    string p;
    cin >> p;

    int n;
    cin >> n;

    string array_input;
    cin >> array_input;

    deque<int> arr;
    if (n > 0) {
        array_input = array_input.substr(1, array_input.length() - 2);
        stringstream ss(array_input);
        string item;
        while (getline(ss, item, ',')) {
            arr.push_back(stoi(item));
        }
    }

    bool is_reversed = false;
    bool is_error = false;

    for (char cmd : p) {
        if (cmd == 'R') {
            is_reversed = !is_reversed;
        } else if (cmd == 'D') {
            if (arr.empty()) {
                is_error = true;
                break;
            } else {
                if (is_reversed) {
                    arr.pop_back();
                } else {
                    arr.pop_front();
                }
            }
        }
    }

    if (is_error) {
        cout << "error" << endl;
    } else {
        cout << "[";
        if (is_reversed) {
            reverse(arr.begin(), arr.end());
        }
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << arr[i];
            if (i < arr.size() - 1) {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        process_test_case();
    }

    return 0;
}
