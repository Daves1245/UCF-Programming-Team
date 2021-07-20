/*
 * Author: Zedbar
 * Date: 2021-06-25
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>

using namespace std;

typedef long double ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n, k;
        cin >> n >> k;
        cout << (int)ceil(n * k / (n - 1)) - 1 << endl;
    }
    return 0;
}
