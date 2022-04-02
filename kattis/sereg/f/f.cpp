/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int c;
    int n = 0;
    map<char, int> freq;
    while ((c = getchar()) != EOF) {
        if (!isalpha(c)) continue;
        c = toupper(c);
        freq[c]++;
        n++;
    }
    int ret = 0;
    int space = 1;
    int cnt = 0;
    for (auto &i : freq) {
        cout << "i: " << i.first << " " << i.second << endl;
        if (cnt >= (1 << space)) space++;
        int block = i.second * space;
        if (cnt % 2) ret += block * 3;
        else ret += block;
        cout << "ret " << ret << endl;
        cnt++;
    }
    cout << ret + 3 * (n - 1) << endl;
    return 0;
}

