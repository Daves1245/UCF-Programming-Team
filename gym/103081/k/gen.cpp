#include <bits/stdc++.h>

using namespace std;

int main() {
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        printf("%c", 'A' + (rand() % 26));
    }
    printf("\n");
    return 0;
}
