#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int n = (int) s.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') {
                    count++;
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}

