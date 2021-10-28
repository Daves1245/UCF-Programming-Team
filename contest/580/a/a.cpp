/*
 * Author: medbar
 * Date: 2021-10-27
 */

#include <climits>
#include <set>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>
#include <stdint.h>
#include <chrono>
#include <numeric>
#include <unordered_set>
#include <queue>

#define btoa(x) ((x) ? "YES" : "NO")

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

int gcd(int a, int b) {
    return (a == 0) ? b : gcd(b % a, a);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

void p(vi v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
	int n;
	cin >> n;
	vi v(n);
	int mx = 1;
	int l = 1;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i > 0) {
			if (v[i] >= v[i - 1]) {
				l++;
				mx = max(mx, l);
			} else {
				l = 1;
			}
		}
	}
	cout << mx << endl;
    return 0;
}

