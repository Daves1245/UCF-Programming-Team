/*
 * Author: medbar
 * Date: 2021-07-17
 */

#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>
#include <queue>
#include <stdint.h>
#include <chrono>
#include <numeric>
#include <unordered_set>

using namespace std;

struct custom_hash {
    // http://xorshift.di.unimi.it/splitmix64.c
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef unordered_map<long long, int, custom_hash> safe_map;

void p(vi v) {
    for (auto i : v) {
        cout << i << " ";
    }
}

int sumarr(vi v) {
//    cout << "V IS:" << endl;
    if (v.size() == 0) {
        return v[0];
    }
    int ret = 0, n = v.size() - 1;
    int stop = v.size() / 4;
    if (stop == 0) {
        return v[n];
    }
    ret = v[n] - v[stop - 1];
    //printf("v[n] = %d, v[stop - 1 = %d] = %d, ret = %d\n", v[n], stop - 1, v[stop - 1], ret);
    return ret;
}

int sumarrdesc(vi v) {
    int ret = 0;
    int stop = (v.size() - v.size() / 4);
    int test = v[0] - v[stop - 1];
    //printf("w[0] = %d, w[stop - 1 = %d] = %d, test = w[0] - w[stop] = %d\n", v[0], stop - 1, v[stop - 1], test);
    return test;
}

int v[100100] = {0};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i < n + 1; i++) {
            cin >> v[i];
        }
        for (int i = 2; i < n + 1; i++) {
            v[i] += v[i - 1];
        }
        sort(v + 1, v + n + 1);
        /*
        printf("v: ");
        for (int i = 0; i < n + 1; i++) {
            printf("%d ", v[i]);
        }
        puts("");
        */
        int score = 0;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            score += tmp;
        }
        int *most = v + n - 1 + 1;
        int *least = v + (n / 4) + 1;
        int i = n + 1;
        while (*most - *least < score) {
//            printf("least: %d, most: %d, most - least: %d\n", *least, *most, *most - *least);
//            printf("score: %d\n", score);
            v[i] = v[i - 1] + 100;
            most++;
            if (i % 4 == 0) {
                least++;
            }
            i++;
        }
        cout << i - n - 1 << endl;
    }
    return 0;
}

