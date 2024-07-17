#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;



int main() {
    int N;
    cin >> N;

    set<string> word_set; 
    vector<pair<int,string>> words;

    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        word_set.insert(word);
    }

    for (const auto& word : word_set) {
        words.emplace_back(word.size(),word);
    }

    sort(words.begin(), words.end());

    for (auto& word : words) {
        cout << word.second << endl;
    }

    return 0;
}
