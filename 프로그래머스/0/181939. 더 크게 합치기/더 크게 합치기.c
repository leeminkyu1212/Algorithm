#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(int a, int b) {
    char ab[10], ba[10];

    sprintf(ab, "%d%d", a, b);
    sprintf(ba, "%d%d", b, a);

    if (atoi(ab) >= atoi(ba)) {
        return atoi(ab);
    } else {
        return atoi(ba);
    }
}