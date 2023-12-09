#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        string str; cin >> str;
        ll pos; cin >> pos; pos--;
        int m = str.size();
        int i = 0;
        while (pos >= m) {
            pos -= m;
            m--;
            i++;
        }

        list<char> s;
        for (auto c : str) s.push_back(c);

        auto it = begin(s);
        int icp = i;
        while (icp-- > 0) {
            while (it != end(s) && next(it) != end(s) && *it <= *next(it)) it++;
            it = s.erase(it);
            if (it != begin(s)) it--;
        }

        it = s.begin();
        while (pos--) it++;
        cout << *it;
    }
    cout << endl;
    return 0;
}
