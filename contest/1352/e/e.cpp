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
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
int solve(ll a[], ll b[], int n) {
    int ret = 0;
    unordered_map<int, int> d;
    for (int j = 0; j < n + 1; j++) {
        for (int k = j + 2; k < n + 1; k++) {
            d[b[k] - b[j]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (d.count(a[i]) > 0) {
            ret++;
        }
    }
    return ret;
}
 
void pa(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
 
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        ll a[n];
        ll b[n + 1];
        b[0] = b[n] = 0;
        cin >> a[0];
        b[1] = a[0];
        for (int j = 1; j < n; j++) {
            cin >> a[j];
            b[j + 1] = a[j] + b[j];
        }
        //        pa(a, n);
        //        pa(b, n + 2);
        cout << solve(a, b, n) << endl;
    }
    return 0;
}
