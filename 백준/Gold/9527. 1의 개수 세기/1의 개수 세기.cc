#include <iostream>

using namespace std;

using ll = long long;

ll count_ones(ll x) {
    if (x == 0) return 0;
    
    ll count = 0;
    ll highest_bit = 0;

    while ((1LL << (highest_bit + 1)) <= x) {
        highest_bit++;
    }

    ll remaining = x - (1LL << highest_bit);
    count += highest_bit * (1LL << (highest_bit - 1)) + (remaining + 1);
    count += count_ones(remaining);

    return count;
}

int main() {
    ll A, B;
    cin >> A >> B;
    
    ll result = count_ones(B) - count_ones(A - 1);
    
    cout << result << endl;
    return 0;
}
