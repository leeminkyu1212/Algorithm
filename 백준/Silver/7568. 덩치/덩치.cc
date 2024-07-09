#include <iostream>
#include <vector>
using namespace std;

vector<int> calculateRanks(const vector<pair<int, int>>& people) {
    int n = people.size();
    vector<int> ranks(n, 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && people[i].first < people[j].first && people[i].second < people[j].second) {
                ranks[i]++;
            }
        }
    }

    return ranks;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> people(n);

    for (int i = 0; i < n; ++i) {
        cin >> people[i].first >> people[i].second;
    }

    vector<int> ranks = calculateRanks(people);

    for (int rank : ranks) {
        cout << rank << " ";
    }
    cout << endl;

    return 0;
}
