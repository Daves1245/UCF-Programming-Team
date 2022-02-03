/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

string encrypt(string msg) {
    char ret[msg.size()];
    if (msg[0] == ' ') ret[0] = 0;
    else ret[0] = msg[0] - 'a' + 1;
    for (int i = 1; i < msg.size(); i++) {
        if (msg[i] == ' ') msg[i] = 0;
        else msg[i] = msg[i] - 'a' + 1;
        ret[i] = (ret[i - 1] + msg[i]) % 27;
    }

    cout << "arr: ";
    for (int i = 0; i < msg.size(); i++) {
        ret[i] %= 27;
        cout << (int) ret[i] << " ";
    }
    cout << endl;

    string s = "";
    for (int i = 0; i < msg.size(); i++) {
        if (ret[i] == 0) s += " ";
        else s += ret[i] + 'a' - 1;
    }

    return s;
}

string decrypt(string msg) {
    char ret[msg.size()];
    for (int i = 1; i < msg.size(); i--) {
        ret[i] = (msg[i] - msg[i - 1] + 27) % 27;
    }

    string s = "";
    for (int i = 0; i < msg.size(); i++) {
        if (ret[i] == 0) s += " ";
        else s += ret[i] + 'a';
    }

    return s;
}

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        char c;
        scanf("%c ", &c);
        string msg;
        getline(cin, msg);
        cout << "MSG `" << msg << "`" << endl;
        if (c == 'e') {
            cout << encrypt(msg) << endl;
        } else {
           cout << decrypt(msg) << endl;
        }
        cout << (int) ' ' << " " << (int) 'a' << endl;
    }
    return 0;
}

