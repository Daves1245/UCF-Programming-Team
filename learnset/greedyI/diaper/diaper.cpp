#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, d; cin >> n >> d;
        using st = tuple<int, double, int>;
        vector<st> boxes(d);
        for (int i = 0; i < d; i++) {
            auto &[n, price, cap] = boxes[i];
            cin >> n >> price >> cap;
        }
        vector<int> waste(n);
        for (int i = 0; i < n; i++) {
            cin >> waste[i];
        }

        double cost = INT_MAX;
        int ansi = 0;
        for (int i = 0; i < d; i++) {
            auto [nd, price, cap] = boxes[i];
            bool good = true;
            int diaper = 0;
            int used = 1;
            int nboxes = 1;
            for (int j = 0; j < n && good; j++) {
                if (waste[j] > cap) {
                    good = false;
                    break;
                }

                if (diaper + waste[j] > cap) {
                    used++;
                    diaper = 0;
                    if (used > nd) {
                        nboxes++;
                        used = 1;
                    }
                }

                diaper += waste[j];

            }
            if (good)
                if (nboxes * price < cost) {
                    cost = nboxes * price;
                    ansi = i;
                }
        }

        cout << setprecision(2) << fixed << "Diaper Scenario #" << t << ": Buying box " << (ansi + 1) << ", you spend $" << cost << "." << endl;
    }
    return 0;
}

