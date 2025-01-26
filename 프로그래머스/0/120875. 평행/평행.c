#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


double calculate_slope(int x1, int y1, int x2, int y2) {
    return (double)(y2 - y1) / (x2 - x1);
}

int solution(int** dots, size_t dots_rows, size_t dots_cols) {

    for (int i = 0; i < dots_rows; i++) {
        for (int j = i + 1; j < dots_rows; j++) {
            for (int k = 0; k < dots_rows; k++) {
                if (k == i || k == j) continue;
                for (int l = k + 1; l < dots_rows; l++) {
                    if (l == i || l == j) continue;
                    double slope1 = calculate_slope(dots[i][0], dots[i][1], dots[j][0], dots[j][1]);
                    double slope2 = calculate_slope(dots[k][0], dots[k][1], dots[l][0], dots[l][1]);
                    if (slope1 == slope2) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
