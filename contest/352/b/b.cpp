/*
 * Author: Zedbar
 * Date: 2021-06-24
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <utility>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    // x |-> (i, d)
    unordered_map<int, pair<int,int>> m;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int tmp;
        cin >> tmp;
        if (m.count(tmp) && m[tmp].first > 0) {
            if (m[tmp].second == 0) {
                cout << "found second instance of " << tmp << " at" << i + 1 << endl;
                m[tmp].second = i + 1 - m[tmp].first;
            } else if (m[tmp].first + m[tmp].second != i + 1) {
                cout << tmp << "'s curpos is " << i + 1 << " but was last seen at " << m[tmp].first << " with increment " << m[tmp].second << endl;
                m[tmp].first = -1;
            } else {
                m[tmp].first = i + 1;
            }
        } else if (m[tmp].first > 0) {
            cout << "adding " << tmp << " to map" << endl;
            m[tmp];
            m[tmp].first = i + 1;
            m[tmp].second = 0;
        }
    }
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->first << ": " << i->second.first << " " << i->second.second << endl;
        if (i->second.first < 0) {
            m.erase(i->first);
        }
    }
    cout << m.size() << endl;
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->first << " " << i->second.second << endl;
    }
    return 0;
}
