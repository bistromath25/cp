#include <bits/stdc++.h>
using namespace std;

string substring(string s, int pos, int len) {
    string sub = "";
    for (int i = 0; i < len; ++i) {
        sub += s[i + pos];
    }
    return sub;
}

string minstr(string a, string b) {
    if (a.length() > b.length()) return b;
    else if (a.length() < b.length()) return a;
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] == b[i]) continue;
        else if (a[i] > b[i]) return b;
        else return a;
    }
    return a;
}

int main() {
    //freopen("input.in", "r", stdin);
    string s;
    int k;
    cin >> s >> k;
    string sub;
    string ans = s;
    for (int i = 0; i + k <= s.length(); ++i) {
        sub = substring(s, i, k);
        //cout << sub << '\n';
        ans = minstr(ans, sub);
    }

    cout << ans << '\n';
    return 0;
}
