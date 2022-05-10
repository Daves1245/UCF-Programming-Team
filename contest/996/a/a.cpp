#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ret = 0;
    while (n >= 100) ret += n / 100, n %= 100;
    while (n >= 20) ret += n / 20, n %= 20;
    while (n >= 10) ret += n / 10, n %= 10;
    while (n >= 5) ret += n / 5, n %= 5;
    ret += n;

    cout << ret << endl;
    return 0;
}
