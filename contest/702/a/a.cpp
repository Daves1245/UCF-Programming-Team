#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 10;
vector<int> v(N);
vector<int> memo(N, -1);

int lis(int i) {
    if (i == 0) return 1;
    int &ans = memo[i];
    if (ans != -1) return ans;
    ans = 1;
    for (int j = 0; j < i; j++) {
        if (v[j] < v[i]) {
            ans = max(ans, lis(j) + 1);
        }
    }

    return ans;
}

int main() {
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = 1;
    int cur = 1;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] >= v[i + 1]) {
            cur = 1;
        } else {
            cur++;
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}

