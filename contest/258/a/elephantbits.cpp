// www.codeforces.com/problemset/problem/258/A

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    string a;
    getline(cin, a);
    bool pot = false;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == '1') {
            if (i == 0) {
                cout << a.substr(0, a.size() - 1) << endl;
                return 0;
            }
            a.replace(max(0, i - 1), 1, "");
            cout << a << endl;
            return 0;
        } 
    }
    return 0;
}
