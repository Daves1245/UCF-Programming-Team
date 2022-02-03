/*
 * FML list
 *
 * 1. Breathe
 * 2. Clear data structures after every iteration
 * 3. Iterate desired amount
 * 4. git gud scrub
 * 5. check array types
 * 6.5 change 5s to 6s
 * 7. check signs
 * 8. check epsilon
 * 9. don't be a dumbass
 * 11. there is no #10
 * 12. there is no hope
 * 13. hopefully you fixed it by now because this is the end
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> w(n, 0);
        vector<int> b(n, 0);
        int c = 0, d = 0;
        char prev = -1;
        bool firstw = true, firstb = true;
        for (int i = 0; i < n; i++) {
            int k;
            char type;
            cin >> k >> type;

            if (type == 'W') {
                if (prev == 'B' && !firstw) {
                    c++;
                    w[c] += w[c - 1];
                }
                w[c] += k;
                firstw = false;
            } else if (type == 'B') {
                if (prev == 'W' && !firstb) {
                    d++;
                    b[d] += b[d - 1];
                }
                b[d] += k;
                firstb = false;
            }

            prev = type;
        }

        w.resize(c + 1);
        b.resize(d + 1);

        cout << "b[" << d + 1 << "]: ";
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << endl;

        cout << "w[" << c + 1 << "]: ";
        for (int i = 0; i < w.size(); i++) {
            cout << w[i] << " ";
        }
        cout << endl;

        cout << "slope: " << num << "/" << den << endl;

        // TODO check horizontal and vertical case
        int num = b[b.size() - 1];
        int den = w[w.size() - 1];

        if (num == 0 || den == 0) {
            cout << 1 << endl;
            continue;
        }

        for (int i = 0; i < w.size() + b.size(); i++) {
            int intercept;
            int f;

            if (i % 2) {
                f = w[i / 2];
            } else {
                f = b[1 + i / 2];
            }

            /*
            if (f * num % den != 0) {
                cout << 1 << endl;
                break;
            }
            */

            int g = gcd(f * num, den);
        }

        cout << "w: " << w.size() << endl;
        cout << "b: " << b.size() << endl;
        /*
        */

        cout << (w.size() + b.size()) / 2 << endl;
    }

    return 0;
}

