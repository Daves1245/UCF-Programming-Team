constexpr int MAX_N = 100010;
constexpr int p = 1e9 + 7; // prime > MAX_N
ll mpow(ll a, ll p, ll n) {
    if (p == 1) return a;
    if (p == 0) return 1;
    if (p & 1) {return (a * mpow(a, p - 1, n)) % n;}
    ll sub = mpow(a, p / 2, n);
    return (sub * sub) % n;
}
ll inv(ll a) {
    return mpow(a, p - 2, p);
}

ll fact[MAX_N];

ll C(int n, int k) {
    if (n < k) return 0;
    return (((fact[n] * inv(fact[k])) % p) * inv(fact[n - k])) % p;
}

ll cat[MAX_N];

// O(n) precalculation of n!%p
// inside main()
// binomial coefficients
fact[0] = 1;
for (int i = 1; i < MAX_N; i++)
    fact[i] = (fact[i - 1] * i) % p;
cout << C(100000, 50000) << '\n'; // should be 149033233

// catalan numbers
cat[0] = 1;
for (int n = 0; n < MAX_N - 1; n++)
    cat[n + 1] = ((4 * n + 2) % p * cat[n] % p * inv(n + 2)) % p;
cout << cat[100000] << '\n'; // the answer is 945729344
