/*
 * Author: medbar
 * Date: 2021-11-11
 */

#include <bits/stdc++.h>

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

bool valid(int n) {
    n--;
    while (n > 0) {
        if (n & 1 == 0) return false;
        n >>= 1;
    }
    return true;
}

#define wins first
#define losses second
#define INF 1000000010

ii simulate(vii &v, int i, int j) {
    if (j == i) {
        return v[j];
    }

    int m = (i + j) / 2;
    ii left = simulate(v, i, m);
    ii right = simulate(v, m + 1, j);

    ii &winner = (left.wins > right.wins) ? left : right;
    ii &loser = (left.wins < right.wins) ? left : right;

    winner.wins -= loser.losses;
    winner.losses -= loser.wins;

    if (winner.wins < 0 || winner.losses < 0 || loser.losses != 4
            || loser.wins > 3) {
        return ii(INF, INF);
    }

    return winner;
}

bool solve(vii &v, int n) {
    ii w = simulate(v, 0, n - 1);
    // cout << endl;
    return w.wins == 0 && w.losses == 0;
    /*
    for (int i = 0; i < n; i++) {
        cout << i << ": " << v[i].wins << ", " << v[i].losses << endl;
        //if (v[i].wins != 0 || v[i].losses != 0) return false;
    }
    */
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        vii v(n, ii(0, 0));
        for (int i = 0; i < n; i++) {
            cin >> v[i].wins >> v[i].losses;
        }

        if (!valid(n)) {
            goto fail;
        }

        cout << "Tournament #" << t << ": ";
        if (solve(v, n)) {
fail:
            cout << "Possible";
        } else {
            cout << "Impossible";
        }
        cout << "\n\n";
    }
    return 0;
}

