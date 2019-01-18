#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

const int MOD = 1000;
const int LENGTH = 30;

int *generate_random_values(int *p_values, int length) {

    time_t t = time(NULL);
    srand(t);

    for (int i = 0; i < length; ++i) {

        p_values[i] = rand() % MOD;
    }

    return p_values;
}


int *quick_sort(int *p_values, int length) {

    int key, start = 0, end = length - 1;

    key = p_values[start];

    while (start != end) {

        while (key <= p_values[end] && end > start) {
            --end;
        }

        p_values[start] = p_values[end];

        while (key >= p_values[start] && end > start) {
            ++start;
        }

        p_values[end] = p_values[start];
    }

    p_values[start] = key;

    if (end > 0) {

        quick_sort(p_values, end);
    }

    if (length - end - 1 > 0) {

        quick_sort(p_values + end + 1, length - end - 1);
    }

    return p_values;
}

void show_values(int *p_values, int length) {

    for (int i = 0; i < length; ++i) {

        printf("%02d ", p_values[i]);
    }

    printf("\n");
}


int main() {

    int *p_values = malloc(sizeof(int) * LENGTH);
    p_values = generate_random_values(p_values, LENGTH);
    show_values(p_values, LENGTH);
    p_values = quick_sort(p_values, LENGTH);
    show_values(p_values, LENGTH);

    return 0;
}