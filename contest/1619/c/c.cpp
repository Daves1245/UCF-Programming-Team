#include <bits/stdc++.h>

using namespace std;

int tonum(string a, int i, int j) {
    int ret = 0;
    for (int k = i; k <= j; k++) {
        ret *= 10;
        ret += (a[k] - '0');
    }

    // cout << "tonum(" << a << ", " << i << ", " << j << ") = " << ret << endl;
    return ret;
}

void solve(string a, string s) {
    string b;
    int k = a.size() - 1;
    int i = s.size() - 1;
    while (i >= 0 && k >= 0) {
      //  cout << i << endl;
        int d;
        if (s[i] < a[k]) {
            if (i == 0) {
                cout << -1 << endl;
                return;
            }
            d = tonum(s, i - 1, i) - tonum(a, k, k);
            i--;
        } else {
            d = tonum(s, i, i) - tonum(a, k, k);
        }

        if (d < 0 || d > 9) {
            cout << -1 << endl;
            return;
        }

        b += to_string(d);

        // cout << "b: " << b << endl;
        k--;
        i--;
    }

    // cout << i << endl;

    if (k >= 0) {
        cout << -1 << endl;
        return;
    }

    while (i >= 0) {
        b += s[i--];
    }

    reverse(b.begin(), b.end());

    cout << stoll(b) << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string a, s;
        cin >> a >> s;
        solve(a, s);
    }
    return 0;
}

