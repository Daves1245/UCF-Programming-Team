/*
 * Author: medbar
 * Date: 2021-07-30
 */

#include <set>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>
#include <stdint.h>
#include <chrono>
#include <numeric>
#include <unordered_set>
#include <queue>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

vector<string> menu(11);

int count(bool arr[], int n) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i]) ret++;
    }
    return ret;
}

void subsets(int i, int n, int k, bool visited[]) {
    if (i == n) {
        if (count(visited, n) == k) {
            for (int j = 0; j < n; j++) {
                if (visited[j]) {
                    cout << menu[j] << " ";
                }
            }
            cout << "\n";
        }
        return;
    }
    visited[i] = true;
    subsets(i + 1, n, k, visited);
    visited[i] = false;
    subsets(i + 1, n, k, visited);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d\n", &n, &k);
        bool visited[n] = {0};
        string str;
        for (int i = 0; i < n; i++) {
            getline(cin, str);
            menu[i] = str;
        }
        sort(menu.begin(), menu.begin() + n);
        subsets(0, n, k, visited);
        if (t != 0) {
            cout << "\n";
        }
    }
    return 0;
}

