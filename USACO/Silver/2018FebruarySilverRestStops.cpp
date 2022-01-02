#include <bits/stdc++.h>
using namespace std;

#define int long long  // answer too big!

int L, N, rF, rB;
vector<pair<int, int>> stops, best;

/*
Always visit rest stops with the maximum tastiness value.
Find these "best" rest stops starting right-to-left, at each
stop if it's got the highest tastiness so far, put it into
the best collection.
Then visit all the best stops. Bessie should stay until John
catches up to her. She will gain c * (ftime - btime) tastiness
points where ftime is the time it takes John to arrive and btime
is the time Bessie takes to arrive at the stop.
*/

signed main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);

    cin >> L >> N >> rF >> rB;
    stops.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> stops[i].first >> stops[i].second;
    }

    int mx = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (mx < stops[i].second) {
            best.push_back(stops[i]);
            mx = stops[i].second;
        }
    }

    int B = best.size();

    reverse(best.begin(), best.end());


    int score = 0;
    int prev = 0;
    int traveldist = 0;
    int btime = 0, ftime = 0;
    int resttime = 0;
    for (int i = 0; i < B; ++i) {
        int x = best[i].first, c = best[i].second;
        traveldist = x - prev;
        ftime = traveldist * rF;
        btime = traveldist * rB;
        resttime = ftime - btime;
        score += resttime * c;
        prev = x;
    }

    cout << score << '\n';

    return 0;
}
