/*
 * Author: medbar
 * Date: 2021-09-15
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>

#define btoa(x) ((x) ? "YES" : "NO")

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[5] = {0};
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        a[u]++;
    }
    if (a[1] <= a[3]) {
        a[2] = a[2] / 2 + (a[2] % 2);
        cout << a[2] + a[3] + a[4] << endl;
        return 0;
    }
    int ret = a[4];
    int t = min(a[1], a[3]);
    ret += t;
    a[1] -= t;
    a[3] -= t;
    ret += a[3];
    if (a[1] > 0) {
        a[2] += a[1] / 2;
        a[1] %= 2;
    }
    a[2] = (a[2] / 2) + (a[2] % 2);
    cout << ret + a[1] + a[2] << endl;
    return 0;
}
/*
   int ret = a[4];
   int tmp = min(a[1], a[3]);
   a[1] -= tmp;
   a[3] -= tmp;
   ret += tmp;
   ret += a[3];
   tmp = min(a[1] / 2, a[2]);
   ret += tmp;
   a[1] -= 2 * tmp;
   a[2] -= tmp;
   ret += a[1] / 4 + (a[1] % 4);
   cout << ret << endl;
   return 0;
   }
   */
