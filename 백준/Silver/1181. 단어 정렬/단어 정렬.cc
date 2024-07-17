#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool cmp(const string& a, const string& b) {
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

int main() {
    int N;
    cin >> N;

    set<string> word_set; 
    vector<string> words;

    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        word_set.insert(word);
    }

    for (const auto& word : word_set) {
        words.push_back(word);
    }

    sort(words.begin(), words.end(), cmp);

    for (const auto& word : words) {
        cout << word << endl;
    }

    return 0;
}
