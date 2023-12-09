#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
using vll = vector<ll>;
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}
bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}
ull pollard(ull n) {
	auto f = [n](ull x) { return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<int, int> seen, p, count;
        /*
           auto x = factor(3);
           for (auto i : x) cout << i << " ";
           cout << endl;
           */
        auto dfs = [&](auto &&self, int u) -> bool {
            if (!u) return false;
            cout << u << endl;
            if (u == 1) {
                // cout << "jackpot" << endl;
                vll ans;
                ans.reserve(1e7);
                int x = 1;
                ans.push_back(x);
                while (x != n) {
                    x = p[x];
                    ans.push_back(x);
                }
                reverse(ans.begin(), ans.end());
                cout << ans.size() << endl;
                for (auto i : ans) cout << i << " ";
                cout << '\n';
                return true;
            }

            auto f = factor(u);
            f.push_back(1);

            for (auto d : f) {
                if ((d == u) || (count[d] >= 2)) continue;
                count[d]++;
                p[u - d] = u;
                bool ret = self(self, u - d);
                if (ret) return true;
                // cout << endl;
                count[d]--;
            }
            return false;
        };

        dfs(dfs, n);
    }
    return 0;
}
