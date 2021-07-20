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
#include <queue>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        int a[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % n != 0) {
            cout << -1 << endl;
            continue;
        }
        int sol = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > (sum / n)) {
                sol++;
            }
        }
        cout << sol << endl;
    }
    return 0;
}

