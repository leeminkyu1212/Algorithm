#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool solution(const char *s) {
    int stack = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            stack++;
        } else {
            stack--; // 닫는 괄호는 스택 감소
            if (stack < 0) return false;
        }
    }

    return stack == 0;
}