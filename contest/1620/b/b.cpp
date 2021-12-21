#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll max(ll a, ll b, ll c, ll d) {
    return max(max(a, b), max(c, d));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll  w, h;
        cin >> w >> h;
        int k;
        cin >> k;
        vector<ll> x1(k);
        for (int i = 0; i < k; i++) {
            cin >> x1[i];
        }

        cin >> k;
        vector<ll> x2(k);
        for (int i = 0; i < k; i++) {
            cin >> x2[i];
        }

        cin >> k;
        vector<ll> y1(k);
        for (int i = 0; i < k; i++) {
            cin >> y1[i];
        }

        cin >> k;
        vector<ll> y2(k);
        for (int i = 0; i < k; i++) {
            cin >> y2[i];
        }

        sort(x1.begin(), x1.end());
        sort(x2.begin(), x2.end());
        sort(y1.begin(), y1.end());
        sort(y2.begin(), y2.end());

        ll dx1 = x1[x1.size() - 1] - x1[0];
        ll dy1 = y1[y1.size() - 1] - y1[0];
        ll dx2 = x2[x2.size() - 1] - x2[0];
        ll dy2 = y2[y2.size() - 1] - y2[0];

        ll ans;
        ans = max(h * dx1, h * dx2, w * dy1, w * dy2);

        cout << ans << endl;
    }
    return 0;
}

