#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <ctime>
#include <stdio.h>      /* printf */
#include <stdlib.h>
#include <queue>
#include <bits/stdc++.h>

#ifdef SHOW_DEBUG
#define dbg(a, ...) printf("DEBUG: " a "\n", ##__VA_ARGS__)
#else
#define dbg(...) ((void*)(0))
#endif

using namespace std;
typedef long long ll;
template<typename A, typename B>
using hmap = unordered_map<A, B>;
typedef tuple<int, int> ii;
typedef tuple<ll, ll> lii;
#define PI 3.14159265358979323846
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL

bool is_prime(ll a){
    if (a < 2) return false;
    for (ll i = 2; i*i <= a; i++){
        if (a % i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    string s; getline(cin, s);
    for (ll i = 0; i < n; i++){
        getline(cin, s);
        stringstream ss(s);
        string a, b; ss >> a >> b;
        string ea = "", eb = "";
        for (auto c : a) if (c != '.') ea += c;
        for (auto c : b) if (c != '.') eb += c;

        arr[i] = {stoll(ea), stoll(eb)};
    }

    for (ll i = 0; i < n; i++){
        ll a = arr[i].first;
        ll b = arr[i].second;
        ll the_gcd = __gcd(a,b);
        a /= the_gcd;
        b /= the_gcd;
        if (a == b){
            cout << 2 << " " << 2 << endl;
        } else if (is_prime(a) && is_prime(b)){
            cout << a << " " << b << endl;
        } else {
            cout << "impossible" << endl;
        }
    }

    return 0;
}


struct dsu {
    vi p, rank;
    dsu(int n) {
        p.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) p[i] = i;
    }
    bool join(int u, int v) {
        int x = find(u), y = find(v);
        if (x == y) return 0;
        if (rank[x] < rank[y]) swap(x, y);
        p[y] = p[x];
        if (rank[x] == rank[y]) rank[y]++;
        return 1;
    }
    int find(int i) {
        return i == p[i] ? i : p[i] = find(p[i]);
    }
    bool same_set(int u, int v) {
        return find(u) == find(v);
    }
};
