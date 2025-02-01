#include <stdio.h>
#include <stdlib.h>

#define INF 2000000000

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findClosestPair(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int bestSum = INF;
    int ans1 = 0, ans2 = 0;

    while (left < right) {
        int sum = arr[left] + arr[right];


        if (abs(sum) < abs(bestSum)) {
            bestSum = sum;
            ans1 = arr[left];
            ans2 = arr[right];
        }


        if (sum < 0) left++;
        else right--;
    }


    printf("%d %d\n", ans1, ans2);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findClosestPair(arr, n);
    return 0;
}
