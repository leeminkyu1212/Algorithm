#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    unordered_map<char, int> char_count; 
    int max_length = 0;
    int left = 0; 

    for (int right = 0; right < s.size(); ++right) {
        char_count[s[right]]++;

        while (char_count.size() > n) {
            char_count[s[left]]--;
            if (char_count[s[left]] == 0) {
                char_count.erase(s[left]);
            }
            left++;
        }

        max_length = max(max_length, right - left + 1);
    }

    cout << max_length << endl;

    return 0;
}
