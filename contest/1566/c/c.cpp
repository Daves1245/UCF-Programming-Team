/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        getline(cin, a);

        getline(cin, a);
        getline(cin, b);
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = a[i] - '0' + 2 * (b[i] - '0');
            //cout << v[i] << " ";
        }
        //cout << endl;
        int sum = 0;
        int i = 0;
        while (i < n) {
            if (v[i] == 0) {
                if (i + 1 >= n) {
                    sum += 1;
                    break;
                }
                if (v[i + 1] == 3) {
                    sum += 2;
                    i += 2;
                    if (i >= n) break;
                }
                sum += 1;
                i++;
            }

            if (v[i] == 1 || v[i] == 2) {
                sum += 2;
                i++;
                if (i >= n) break;
            }

            if (v[i] == 3) {
                while (i < n && v[i] == 3) i++;
                if (i < n) sum += 2;
                i++;
                if (i >= n) break;
            }
        }

        cout << sum << endl;
    }

    return 0;
}

