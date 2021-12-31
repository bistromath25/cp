#include <iostream>
using namespace std;

const int N = 500005;
int n;
string s;
int cntH[N], cntG[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    cntH[0] = 0;
    cntG[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'H') {
            cntH[i + 1] = cntH[i] + 1;
            cntG[i + 1] = cntG[i];
        }
        else {
            cntH[i + 1] = cntH[i];
            cntG[i + 1] = cntG[i] + 1;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 2; j <= n; ++j) {  //
            if ((cntH[j] - cntH[i - 1]) == 1 || (cntG[j] - cntG[i - 1]) == 1) ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
