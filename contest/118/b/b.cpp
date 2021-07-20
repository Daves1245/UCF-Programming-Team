/*
 * Author: Zedbar
 * Date: 2020-11-04
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    int n;
    cin >> n;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for (int j = 0; j < i; j++) {
            printf("%d", arr[j]);
            if (i != 0) {
                printf(" ");
            }
        }
        for (int j = i; j >= 0; j--) {
            printf("%d", arr[j]);
            if (j != 0) {
                printf(" ");
            }
        }
        /*for (int j = 0; j < n - i; j++) {
            printf("  ");
        }*/
        printf("\n");
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for (int j = 0; j < i; j++) {
            printf("%d", arr[j]);
            if (j != i + 1) {
                printf(" ");
            }
        }
        for (int j = i; j >= 0; j--) {
            printf("%d", arr[j]);
            if (j != 0) {
                printf(" ");
            }
        }
        /*for (int j = 0; j <= n - i; j++) {
            printf("  ");
        }*/
        printf("\n");
    }
    return 0;
}
