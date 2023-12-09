#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        priority_queue<int> pq;
        vector<int> f(26, 0);
        for (auto c : s) f[c - 'a']++;
        for (auto i : f) if (i) pq.push(i);
        int cnt = 0;
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            cnt += 2;
            if (a - 1)
                pq.push(a - 1);
            if (b - 1)
                pq.push(b - 1);
        }
        cout << n - cnt << endl;
    }

    return 0;
}
