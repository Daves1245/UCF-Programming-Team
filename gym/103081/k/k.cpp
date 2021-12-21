#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string sequence; cin >> sequence;

  int lo = 1, hi = sequence.size();
  string unique;
  while (lo < hi) {
    int mid = (hi + lo) / 2;

    map<string, int> counts;

    for (int i = 0; i < sequence.size()-mid; ++i) {
      counts[sequence.substr(i, mid)]++;
    }

    bool unique_found = false;
    for (auto &kvpair : counts) {
      if (kvpair.second == 1) {
        unique = kvpair.first;
        unique_found = true;
        break;
      }
    }

    if (unique_found) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << unique << endl;

  return 0;
}
