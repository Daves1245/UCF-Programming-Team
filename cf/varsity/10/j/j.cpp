#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    if (n <= 25) {
        cout << 'a' << (char)(n + 'a') << endl;
        return 0;
    }
    string s = "";
    int l = 1 + ceil(n / 25.0);
    s += 'a';
    s += 'n' + (n % 25) / 2;
    for (int i = 0; i < l - 3; i++)
        s += ((i & 1) ? 'z' : 'a');
    s += (s.back() == 'a' ? (n & 1)["yx"] : (n & 1)["ab"]);
    cout << s << endl;
    return 0;
}
