#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[8], res[8]; // arr : 입력받은 수열, res : 길이 m인 수열(출력)
bool chk[8] = { false }; // 중복확인

void generateSequence(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            printf("%d ", res[i]);
        printf("\n");
        return;
    }
    int last = -1; // 마지막에 사용된 숫자를 추적하여 중복을 피함
    for (int i = 0; i < n; i++) {
        if (!chk[i] && arr[i] != last) {
            res[cnt] = arr[i];
            last = arr[i];
            chk[i] = true;
            generateSequence(cnt + 1);
            chk[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    generateSequence(0);
    return 0;
}
