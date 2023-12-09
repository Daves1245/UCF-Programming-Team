#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s = "";
        bool f = (n % 3) == 1;
        while (n) {
            if (f) {
                n--;
                s += "1";
            } else {
                s += "2";
                n -= 2;
            }
            f = !f;
        }

        cout << s << endl;
    }

    return 0;
}
