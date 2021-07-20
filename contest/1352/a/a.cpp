/*
 * Author: Zedbar
 * Date: 2021-06-25
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

int round(int a, int b) {
    int ret = a;
    for (int i = 0; i < b; i++) {
        ret *= 10;
    }
    return ret;
}

int nz(int n) {
    int ret = 0;
    while (n > 0) {
        if (n % 10 != 0) {
            ret++;
        }
        n /= 10;
    }
    return ret;
}

void sol(int n) {
    cout << nz(n) << endl;
    for (int i = 0; n > 0; i++) {
        if (n % 10 != 0) {
            cout << round(n % 10, i) << " ";
        }
        n /= 10;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        sol(n);
    }
    return 0;
}
