/*
 * Author: Zedbar
 * Date: 2021-06-26
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

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    getline(cin, s);
    getline(cin, s);
    int ps[n + 1] = {0};
    for (int i = 0; i < n; i++) {
        ps[i + 1] = s[i] - 'a' + 1;
        ps[i + 1] += ps[i];
//        cout << ps[i] << " ";
    }
//    cout << ps[n];
//    cout << endl;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << ps[r] - ps[l - 1] << endl;
    }
    return 0;
}
