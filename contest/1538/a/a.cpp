/*
 * Author: Zedbar
 * Date: 2021-06-27
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int min(int a, int b) {
    return a < b ? a : b;
}
int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int a[n];
        ll minv = 110, mini = 0;
        ll maxv = -1, maxi = 0;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
            if (a[j] < minv) {
                mini = j;
                minv = a[j];
            }
            if (a[j] > maxv) {
                maxi = j;
                maxv = a[j];
            }
        }
//        cout << "\t\tDEBUG: min of " << minv << " at " << mini << endl;
//        cout << "\t\tDEBUG: max of " << maxv << " at " << maxi << endl;

        ll l, r;
        if (mini < maxi) {
            l = mini;
            r = maxi;
        } else {
            l = maxi;
            r = mini;
        }
        ll leftmost = 1 + r;
        ll leftright = 1 + l + n - r;
        ll rightmost = n - l;
        cout << min(min(leftmost, rightmost), leftright) << endl;
    }
    return 0;
}
