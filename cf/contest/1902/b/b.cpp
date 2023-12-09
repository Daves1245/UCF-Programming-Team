#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        ll n, p, l, t; cin >> n >> p >> l >> t;
        ll tasks = 1 + (n - 1) / 7;

        ll ans = 0;
        ll full_task_days = tasks / 2;
        ll task_of = tasks % 2;
        ll max_tasks_val = (2 * t + l) * full_task_days + (t + l) * task_of;

        if (p >= max_tasks_val) {
            p -= max_tasks_val;
            ans += full_task_days + task_of;
            ans += ceil(p / (1.0 * l));
        } else {
            ans = ceil(p / (1.0 * (2 * t + l)));
        }

        cout << n - ans << endl;
    }

    return 0;
}
