#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    unordered_set<string> s_set;
    string temp;

    for (int i = 0; i < N; ++i) {
        cin >> temp;
        s_set.insert(temp);
    }

    int count = 0;

    for (int i = 0; i < M; ++i) {
        cin >> temp;
        if (s_set.find(temp) != s_set.end()) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
