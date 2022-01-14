#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int N;

struct City {
    string name, code, id = "", di = "";
    void read() {
        cin >> name >> code;
        id += name[0]; id += name[1]; id += code;
        di += code; di += name[0]; di += name[1];
    }
};

vector<City> cities(MAXN);
map<string, int> cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    cin >> N;
    cities.resize(N);
    for (int i = 0; i < N; ++i) {
        cities[i].read();
        cnt[cities[i].id]++;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (cities[i].id == cities[i].di) continue;
        ans += cnt[cities[i].di];
    }

    cout << ans / 2 << '\n';

    return 0;
}
