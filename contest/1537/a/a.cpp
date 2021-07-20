/*
 * Author: Zedbar
 * Date: 2021-06-29
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>
#include <queue>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void p(vi v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            sum += tmp;
        }
        if (sum == n) {
//            printf("equal: ");
            cout << 0;
        } else if (sum < n) {
//            printf("lt: ");
            cout << 1;
        } else {
//            printf("gt: ");
            cout << sum - n;
        }
        cout << endl;
    }
    return 0;
}

