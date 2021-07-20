/*
 * Author: Zedbar
 * Date: 2020-11-02
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    int y, k, n;
    cin >> y >> k >> n;
    if ((y - n) < k) {
        cout << -1 << endl;
    }
    for (int i = (int) floor(k * (ceil((y - n) / k))); i >= 0; i -= k) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
