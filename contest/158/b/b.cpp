#include <bits/stdc++.h>
using namespace std;
#define for(n) for(int i = 0; i < (n); i++) 
int main() {
    int n; cin >> n;
    int v[5] = {0};
    for(n) {
        int t; cin >> t;
        v[t]++;
    }
    int ret = v[4];
    int tmp;
    ret += tmp = min(v[1], v[3]);
    v[1] -= tmp, v[3] -= tmp;
    ret += v[3];
    ret += v[2] / 2;
    v[2] %= 2;
    
    if (v[2]) {
        ret++;
        v[1] -= min(v[1], 2);
    } 
    if (v[1]) {
        ret += v[1] / 4;
        if (v[1] % 4) ret++;
    }

    cout << ret << endl;
    return 0;
}
