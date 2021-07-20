/*
 * Author: Zedbar
 * Date: 2021-06-28
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>
#include <queue>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void p(vi v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    map<char, int> m;
    int c;
    while ((c = getchar()) != '\n') {
        if (m.count(c) > 0) {
            m[c]++;
        } else {
            m[c] = 1;
        }
    }
    auto p = m.rbegin();
    for (int i = 0; i < p->second; i++) {
        printf("%c", p->first);
    }
    printf("\n");
    return 0;
}

