#include <bits/stdc++.h>

using namespace std;

#define other(x) (((x) + 1) % 2)
#define A 0
#define B 1

int main() {
    int blns[2];
    int n; cin >> n >> blns[A] >> blns[B];
    while (cin >> n >> blns[A] >> blns[B] && !(n == 0 && blns[A] == 0 && blns[B] == 0)) {
        long long d = 0;
        using st = tuple<int, int, int, int, int>;
        priority_queue<st> pq;
        for (int i = 0; i < n; i++) {
            int penalty, q, da, db; cin >> q >> da >> db;
            penalty = abs(da - db);
            pq.push(st(penalty, q, da, db, (da < db) ? A : B));
        }

        while (pq.size() && (blns[A] || blns[B])) {
            auto [penalty, q, da, db, choice] = pq.top(); pq.pop();
            int dist;
            if (choice == A) {
                dist = da;
            } else {
                dist = db;
            }
            long long tmp = min(blns[choice], q);
            blns[choice] -= tmp;
            d += tmp * dist;
            q -= tmp;
            if (q > 0) {
                pq.push(st(0, q, da, db, other(choice)));
            }
        }

        cout << d << endl;
    }
    return 0;
}
