#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        double r_diff = fabs(r1 - r2);
        double r_sum = r1 + r2;

        if (x1 == x2 && y1 == y2 && r1 == r2) {
            printf("-1\n"); 
        }
        else if (d > r_sum || d < r_diff) {
            printf("0\n");
        }
        else if (d == r_sum || d == r_diff) {
            printf("1\n");
        }
        else {
            printf("2\n");
        }
    }
    return 0;
}
