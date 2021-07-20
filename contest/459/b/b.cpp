/*
 * Author: Zedbar
 * Date: 2020-11-06
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <utility>
#include <math.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    long long int n;
    cin >> n;
    vector<int> a(n);
    map<ll, ll> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    sort(a.begin(), a.end());
    ll d = a[n - 1] - a[0];
    ll c = 0;
    map<ll, ll> mcpy = m;
    for (map<ll,ll>::const_iterator i = m.begin(); i != m.end(); i++) {
        c += mcpy[i->first] * mcpy[i->first + d];
        //c += mcpy[i->first] * mcpy[i->first - d];
        /*c += m[a[i]] * m[d + a[i]];
        c += m[a[i]] * m[d - a[i]];*/
    }
    cout << d << " ";
    if (d != 0) {
        cout << c << endl;
    } else {
        cout << n * (n - 1) / 2 << endl;
    }
    return 0;
}
