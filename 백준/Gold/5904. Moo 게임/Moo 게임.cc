#include <iostream>
using namespace std;

long long getLength(int k) {
    if (k == 0) return 3;
    return 2 * getLength(k - 1) + k + 3;
}

char findMooCharacter(long long N, int k) {
    if (k == 0) {
        if (N == 1) return 'm';
        else return 'o';
    }
    
    long long length_k_minus_1 = getLength(k - 1);
    long long middle_length = k + 3;

    if (N <= length_k_minus_1) {
        return findMooCharacter(N, k - 1);
    } else if (N > length_k_minus_1 + middle_length) {
        return findMooCharacter(N - length_k_minus_1 - middle_length, k - 1);
    } else {
        if (N == length_k_minus_1 + 1) return 'm';
        else return 'o';
    }
}

int main() {
    long long N;
    cin >> N;

    int k = 0;
    while (getLength(k) < N) {
        k++;
    }

    cout << findMooCharacter(N, k) << endl;

    return 0;
}
