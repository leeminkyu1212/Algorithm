#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {

    int N;
    cin >> N;

    vector<tuple<int, int, string>> members;

    for (int i = 0; i < N; ++i) {
        int age;
        string name;
        cin >> age >> name;
        members.emplace_back(age, i, name);
    }

    sort(members.begin(), members.end());

    for (auto i : members) {
        cout << get<0>(i) << " " << get<2>(i) << endl;
    }

}
