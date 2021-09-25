#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
    int n;
    cin >> n;
    vi v(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s += v[i];
    }
    sort(v.begin(), v.end(), greater<int>());

    for (int i = 1; i < n; i++) {
        v[i] += v[i - 1];
    }
    /*
    printf("arr: ");
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    printf("s: %d\n", s);
    */
    int i;
    for (i = 0; i < n && v[i] <= s - v[i]; i++) {
    //    printf("\tv[%d] >= %d - %d: %d\n", i, s, v[i]);
    }
    cout << i + 1 << endl;
    return 0;
}
