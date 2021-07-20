/*
 * Author: Zedbar
 * Date: 2020-10-22
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vc(n), vw(m);
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> vw[i];
    }
    sort(vc.begin(), vc.end());
    sort(vw.begin(), vw.end());
    if (vc[n - 1] >= vw[0] || 2 * vc[0] >= vw[0]) {
        cout << -1 << endl;
        return 0;
    }
    if (vc[n - 1] < 2 * vc[0]) {
        cout << 2 * vc[0] << endl;
        return 0;
    }
    cout << vc[n - 1];
    return 0;
}
