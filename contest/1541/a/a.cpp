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

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void swap(int *a, int *b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void p(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        int j;
        for (j = 0; j + 1 < n; j += 2) {
            swap(&a[j], &a[j + 1]);
        }
        if (n % 2) {
            swap(&a[j], &a[j - 1]);
        }
        p(a, n);
    }
    return 0;
}
