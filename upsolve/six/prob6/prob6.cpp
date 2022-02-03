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

int main() {
    set<string> morse;

    // pain.
    morse.insert(".");
    morse.insert("..");
    morse.insert("...");
    morse.insert("....");
    morse.insert("-");
    morse.insert("--");
    morse.insert("---");
    morse.insert(".-");
    morse.insert("-...");
    morse.insert("-.-.");
    morse.insert("-..");
    morse.insert("..-.");
    morse.insert("--.");
    morse.insert(".---");
    morse.insert("-.-");
    morse.insert(".-..");
    morse.insert("-.");
    morse.insert(".--.");
    morse.insert("--.-");
    morse.insert(".-.");
    morse.insert("..-");
    morse.insert("...-");
    morse.insert(".--");
    morse.insert("-..-");
    morse.insert("-.--");
    morse.insert("--..");

    string str;
    vi ans;
    while (true) {
        getline(cin, str);
        if (str == "#") break;

        ll dp[str.size() + 1];
        memset(dp, 0, sizeof dp);

        dp[0] = 1;
        for (int i = 0; i < str.size(); i++) {
            for (int j = 1; j <= 4 && i + j <= str.size(); j++) {
                string ss = str.substr(i, j);
                if (morse.count(ss) > 0) {
                    dp[i + j] += dp[i];
                }
            }
        }
        ans.push_back(dp[str.size()]);
    }

    for (int i : ans) {
        cout << i << endl;
    }
    return 0;
}
