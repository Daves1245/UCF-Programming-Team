/*
 * Author: medbar
 * Date: 2021-07-01
 */

#include <fstream>
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
    cout << endl;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;
    vii v;
    for (int i = 0; i < 2 * n; i++) {
        int tmp;
        in >> tmp;
        v.push_back(pair<int,int>(tmp, i + 1));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < 2 * n; i += 2) {
        if (v[i].first != v[i + 1].first) {
            out << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < 2 * n; i += 2) {
        out << v[i].second << " " << v[i + 1].second << endl;
    }
    
    return 0;
}

