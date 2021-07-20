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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            putchar(' ');
            if (((n / 2) - i) * ((n / 2) - i) + ((n / 2) - j) * ((n / 2) - j) <= (n / 2) * (n / 2)) {
                putchar('1'); // + (int)(sqrt(((n / 2) - i) * ((n / 2) - i) + ((n / 2) - j) * ((n / 2) - j))));
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    return 0;
}
