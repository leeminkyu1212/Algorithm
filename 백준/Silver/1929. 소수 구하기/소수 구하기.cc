#include <iostream>
#include <vector>
using namespace std;

// 소수 판별을 위한 에라토스테네스의 체 함수
void func(int m, int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = m; i <= n; ++i) {
        if (is_prime[i]) {
            cout << i << '\n'; 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int m, n;
    cin >> m >> n;
    func(m, n);
    return 0;
}
