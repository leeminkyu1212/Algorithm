#include <stdio.h>

int solution(int numbers[], int numbers_len) {
    int total_sum = 45; 
    int numbers_sum = 0;

    for (int i = 0; i < numbers_len; i++) {
        numbers_sum += numbers[i];
    }

    return total_sum - numbers_sum;
}
