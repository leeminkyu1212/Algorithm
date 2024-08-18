#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> wires(n);
    for (int i = 0; i < n; ++i) {
        cin >> wires[i].first >> wires[i].second;
    }
    
    sort(wires.begin(), wires.end());
    
    vector<int> lis;
    vector<int> lisIndex(n);
    
    for (int i = 0; i < n; ++i) {
        int b = wires[i].second;
        auto it = lower_bound(lis.begin(), lis.end(), b);
        if (it == lis.end()) {
            lis.push_back(b);
            lisIndex[i] = lis.size() - 1;
        } else {
            *it = b;
            lisIndex[i] = it - lis.begin();
        }
    }
    
    int lisLength = lis.size();
    
    cout << n - lisLength << '\n';
    
    vector<int> toRemove;
    int lisCurrentLength = lisLength - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (lisIndex[i] == lisCurrentLength) {
            lisCurrentLength--;
        } else {
            toRemove.push_back(wires[i].first);
        }
    }
    
    sort(toRemove.begin(), toRemove.end());
    for (int a : toRemove) {
        cout << a << '\n';
    }
    
    return 0;
}
