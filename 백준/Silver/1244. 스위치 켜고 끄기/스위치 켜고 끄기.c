#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int arr[101] = { 0 };
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	int T;
	scanf("%d", &T);

	while (T--) {
		int gender, number;
		scanf("%d %d", &gender, &number);

		if (gender == 1) {
			for (int i = number; i <= n; i += number) {
				arr[i] = !arr[i];
			}
		}
		else if (gender == 2) {
			arr[number] = !arr[number];
			int left = number - 1;
			int right = number + 1;
			while (left >= 1 && right <= n) {
				if (arr[left] != arr[right]) break;
				arr[left] = !arr[left];
				arr[right] = !arr[right];
				left--;
				right++;
			}

		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", arr[i]);
		if (i % 20 == 0) printf("\n");
	}
	if (n % 20 != 0) printf("\n");

	return 0;
}
