#include <bits/stdc++.h>
using namespace std;

#define int long long

#define readfile(filename) freopen(filename, "r", stdin)
#define writefile(filename) freopen(filename, "w", stdout)

int N, B;
vector<pair<int, int>> boots;  // {max depth, max step size}
vector<int> snow;

signed main() {
    readfile("snowboots.in");
    writefile("snowboots.out");

    cin >> N >> B;
    snow.resize(N);
    boots.resize(B);
    for (int i = 0; i < N; ++i) {
        cin >> snow[i];
    }
    for (int i = 0; i < B; ++i) {
        cin >> boots[i].first >> boots[i].second;
    }

    int pos = 0, wasted = 0, bidx = 0;
    while (pos != N - 1) {
        int snow_depth = snow[pos];
        int boot_depth = boots[bidx].first, boot_step = boots[bidx].second;

        bool moved = false;
        for (int step = boot_step; step >= 1 && !moved; --step) {
            if (pos + step == N - 1) {  // moved to the last tile
                cout << wasted << '\n';
                return 0;
            }
            else if (pos + step >= N) {  // out-of-bounds, can't move there
                continue;
            }
            else if (snow[pos + step] <= boot_depth) {
                pos += step;
                moved = true;  // moved step steps forward
            }
        }

        if (!moved) {  // if still haven't moved then throw away current boot and try next boot
            bidx++;
            wasted++;
        }
    }

    cout << wasted << '\n';

    return 0;
}
