/*
 * Author: Zedbar
 * Date: 2021-06-21
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

int main() {
    unsigned long long int a, b, n;
    cin >> a >> b >> n;
    for (int i = 0; i < n; i++) {
        int tmp = a;
        for (int j = a * 10; j < (tmp + 1) * 10; j++) {
            if (j % b == 0) {
                a = j;
                break;
            }
        }
        if (a == tmp) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << a << endl;
    return 0;
}
