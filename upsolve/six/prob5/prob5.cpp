/*
 * Author: medbar
 * Date: 2021-11-12
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
typedef long double ld;

typedef pair<ld, ld> vec;
typedef pair<vec, vec> line;

#define xx first
#define yy second

vec operator-(const vec& a, const vec& b) { return vec(a.xx - b.xx, a.yy - b.yy); }
vec operator+(const vec& a, const vec& b) { return vec(a.xx + b.xx, a.yy + b.yy); }
vec operator*(double c, const vec& v) { return vec(c * v.xx, c * v.yy); }

int gcd(int a, int b) {
    return (a == 0) ? b : gcd(b % a, a);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

void switcharoo(ii &v) {
    int tmp = v.first;
    v.first = v.second;
    v.second = tmp;
}

int main() {
    int n, bw, bh;
    cin >> n >> bw >> bh;
    vii boks(n);
    vii boooks(n);
    int w = 0;
    int max_height = 0;
    for (int i = 0; i < n; i++) {
        cin >> boks[i].first >> boks[i].second;
        w += boks[i].first;
        max_height = max(max_height, boks[i].second);
    }

    if (w <= bw && max_height <= bh) {
        cout << -1 << endl;
        return 0;
    }

    sort(boks.begin(), boks.end());

    int cur_weight = 0;
    int i = 0;
    while (cur_weight < bw && w - cur_weight > bw) {
        cur_weight += boks[i].first;
        i++;
    }

    int mh_one = 0, mh_two = 0;
    if (i < n) {
        int tmp = i;
        while (tmp >= 0) {
            mh_one = max(mh_one, boks[tmp].second);
            tmp--;
        }
        tmp = i;
        while (tmp < n) {
            mh_two = max(mh_two, boks[tmp].second);
            tmp++;
        }

        if (mh_one + mh_two <= bh) {
            cout << max(mh_one, mh_two) << endl;
            return 0;
        }
    }

    transform(boks.begin(), boks.end(), boooks.begin(), [](ii &p) -> ii &{
            int tmp = p.first;
            p.first = p.second;
            p.second = tmp;
            return p;
            });

    sort(boooks.begin(), boooks.end(), greater<ii>());
    i = 1;
    while (i < n && boooks[0].first + boooks[i].first > bh) {
        i++;
    }

    if (i < n) {
        // check the width
        int cur_width = 0;
        int tmp = i;
        while (tmp >= 0) {
            cur_width += boooks[i].first;
            tmp--;
        }

        if (cur_width < bw && w - cur_width < bw) {
            cout << boooks[i].first << endl;
        }
    }

    cout << "impossible" << endl;
    return 0;
}

