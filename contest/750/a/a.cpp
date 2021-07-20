/*
 * Author: Zedbar
 * Date: 2021-06-28
 */

#include <iostream>
#include <stdio.h>
#include <math.h>

static inline int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", min(n, floor((-1 + floor(sqrt(1 + 8 * (240 - k) / 5))) / 2)));
    return 0;
}

