#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2001;
int N;
vector<pair<int, int>> points(MAXN);
vector<pair<pair<int, int>, int>> edges;  // edges between points
int best[MAXN];  // max no. locations visited starting from each location
int pbest[MAXN];  // previous best
int pdist[MAXN];  // previous location's distance

bool cmp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
    return a.second < b.second;
}

int main() {
    freopen("input.in", "r", stdin);

    cin >> N;
    points.resize(N + 1);
    points[0] = {0, 0};  // start at the origin
    for (int i = 1; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    for (int i = 0; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            int dx = points[i].first - points[j].first;
            int dy = points[i].second - points[j].second;
            edges.push_back({{i, j}, dx * dx + dy * dy});  // push city ids and dist between
        }
    }

    sort(edges.begin(), edges.end(), cmp);  // sort by distance

    memset(best, 0, sizeof(best));  // initialize all to 0
    memset(pbest, 0, sizeof(pbest));
    memset(pdist, 0, sizeof(pdist));

    for (const pair<pair<int, int>, int> &p : edges) {
        int a = p.first.first, b = p.first.second;
        int d = p.second;

        if (d != pdist[a]) {
            pdist[a] = d;  // update previous distance
            pbest[a] = best[a];  // update previous best
        }
        if (d != pdist[b]) {
            pdist[b] = d;
            pbest[b] = best[b];
        }

        if (a == 0) {  // cannot re-visit origin, update only the best
            best[a] = max(best[a], pbest[b]);
        }
        else {
            best[a] = max(best[a], pbest[b] + 1);  // update best, +1 since we reached new location
            best[b] = max(best[b], pbest[a] + 1);
        }
    }

    cout << best[0] + 1 << '\n';

    return 0;
}
