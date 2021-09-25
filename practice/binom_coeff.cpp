#include <iostream>
#include <unordered_map>

using namespace std;

int bin(int n, int k) {
    if (k == 0 || n == k) return 1;
    return bin(n - 1, k - 1) + bin(n - 1, k);
}

int main() {
    int n, k;
    do {
        cin >> n >> k;
        cout << bin(n, k) << endl;
    } while (true);
    return 0;
}
