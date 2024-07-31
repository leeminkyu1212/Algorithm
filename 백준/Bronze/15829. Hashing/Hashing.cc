#include <iostream>
#include <string>
using namespace std;

const long long M = 1234567891;
const int r = 31;
int L = 0;
string S;

long long hashing() {
    long long value = 0;
    long long r_power = 1;

    for (int i = 0; i < L; ++i) {
        value = (value + (S[i] - 'a' + 1) * r_power % M) % M;
        r_power = (r_power * r) % M;
    }

    return value;
}

int main() {
    cin >> L >> S;
    cout << hashing() << endl;
    return 0;
}
