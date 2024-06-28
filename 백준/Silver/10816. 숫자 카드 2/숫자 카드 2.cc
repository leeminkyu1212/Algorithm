#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int N, M;
    cin >> N;

    vector<int> cards(N);
    for (int i = 0; i < N; ++i) {
        cin >> cards[i];
    }

    cin >> M;
    vector<int> queries(M);
    for (int i = 0; i < M; ++i) {
        cin >> queries[i];
    }

    sort(cards.begin(), cards.end());

    for (int i = 0; i < M; ++i) {
        int query = queries[i];
        int low = lower_bound(cards.begin(), cards.end(), query) - cards.begin();
        int high = upper_bound(cards.begin(), cards.end(), query) - cards.begin();
        cout << (high - low) << ' ';
    }
    cout << '\n';

    return 0;
}
