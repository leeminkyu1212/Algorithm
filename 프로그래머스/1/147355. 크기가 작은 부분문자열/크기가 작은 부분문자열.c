#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* t, const char* p) {
    int answer = 0;
    int t_len = strlen(t);
    int p_len = strlen(p);
    long long p_value = atoll(p);

    for (int i = 0; i <= t_len - p_len; i++) {
        char sub[p_len + 1];
        strncpy(sub, t + i, p_len);
        sub[p_len] = '\0';
        long long sub_value = atoll(sub);

        if (sub_value <= p_value) {
            answer++;
        }
    }

    return answer;
}