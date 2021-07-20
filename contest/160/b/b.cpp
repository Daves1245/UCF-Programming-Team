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
    vector<char> a(n), b(n);
    string s;
    cin.ignore(100, '\n');
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        a[i] = s[i];
    }
    for (int i = 0; i < n; i++) {
        b[i] = s[i + n];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i;
    for (i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
    }
    if (i == n) {
        cout << "a" << endl;
        goto no;
    }
    for (i = 0; i < n; i++) {
        if (a[i] > b[i]) break;
    }
    if (i == n) {
        goto yes;
    }
    if (i == 0) {
        for (; i < n; i++) {
            if (a[i] < b[i]) goto no;
        }
        goto yes;
    }
    goto no;
yes:
    cout << "YES" << endl;
    return 0;
no:
    cout << "NO" << endl;
    return 0;
}
