#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lowerBound(vector<int>& v, int target) {
    int left = 0, right = v.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (v[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> lis;
    vector<int> positions(n); 
    
    for (int i = 0; i < n; ++i) {
        int pos = lowerBound(lis, a[i]);
        if (pos < lis.size()) {
            lis[pos] = a[i];
        } else {
            lis.push_back(a[i]);
        }
        positions[i] = pos;
    }

    int lisLength = lis.size();
    cout << lisLength << endl;

    vector<int> result(lisLength);
    for (int i = n - 1, j = lisLength - 1; i >= 0; --i) {
        if (positions[i] == j) {
            result[j--] = a[i];
        }
    }

    for (int i = 0; i < lisLength; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
