/*
 * Author: Zedbar
 * Date: 2020-11-06
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <utility>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX 100100

int main() {
    int n;
    cin >> n;
    vector<int> v(2 * MAX);
    map<int, vi> m;
    int p = 0;
    for (int i = 0; i < 2 * n; i++) {
        cin >> v[i];
        m[v[i]].push_back(i);
        if (m[v[i]].size() % 2 == 1) {
            p++;
        } else {
            p--;
        }
    }
    if (p) {
        cout << -1 << endl;
    }
    for (auto const& i : m) {
        for (int j = 0; j < i.second.size() - 1; j += 2) {
            cout << i.second[j] + 1 << " " << i.second[j + 1] + 1 << endl;
        }
    }
    return 0;
}
