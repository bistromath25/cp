#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
template<typename T>
void __dbg(const T &__x__) {cout << __x__;}
template<typename T1, typename T2>
void __dbg(const pair<T1, T2> &__x__) {cout << "(" << __x__.first << ", " << __x__.second << ")";}
vector<string> __split(string __s__) {__s__ += ", "; vector<string> __v__; while (!__s__.empty()) {__v__.push_back(__s__.substr(0, __s__.find(','))); __s__ = __s__.substr(__s__.find(',') + 2);} return __v__;}
void __debug_out(vector<string>::iterator __it__) {cout << "\n";}
template<typename T, typename... Args>
void __debug_out(vector<string>::iterator __it__, T t, Args... args) {cout << "[" << *__it__ << ": "; __dbg(t); cout << "] "; __debug_out(++__it__, args...);}
#define dbg(args...) {args;}
#define dbgarr(a, n) {cout << "[" << (#a) << ": {"; int __n__ = 0; for (const auto &__x__ : a) {__dbg(__x__); ++__n__; if (__n__ >= n) {break;} else {cout << ", ";}} cout << "}]\n";}
#define dbgarr2d(a, r, c) {cout << (#a) << ":\n"; for (int __i__ = 0; __i__ < (r); ++__i__) {for (int __j__ = 0; __j__ < (c); ++__j__) {__dbg(a[__i__][__j__]); cout << " ";} cout << "\n";}}
#define dbgmsg(msg) {cout << msg << "\n";}
#define debug(args...) {__debug_out(__split(#args).begin(), args);}
#else
#define dbg(args...)
#define dbgarr(a, n)
#define dbgarr2d(a, r, c)
#define dbgmsg(msg)
#define debug(args...)
#endif

const int N = 1000;
int n, m;
int start[2][2], finish[2][2], dp[N + 1][N + 1];
string john, bessie;

int energy(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int solve(int j, int b, int x1, int y1, int x2, int y2) {
    if (dp[j][b] != -1) return dp[j][b];

    // cases
    // 1 john moves
    // 2 bessie moves
    // 3 both move

    int johnmoves = INT_MAX, bessiemoves = INT_MAX, bothmoves = INT_MAX;

    // john only moves if his position is greater than 0
    // otherwise he's at the start of his path, nothing before that ie not possible
    if (j > 0) {
        char c = john[j - 1];  // previous movement
        if (c == 'N') {
            johnmoves = solve(j - 1, b, x1, y1 - 1, x2, y2);
        }
        else if (c == 'S') {
            johnmoves = solve(j - 1, b, x1, y1 + 1, x2, y2);
        }
        else if (c == 'E') {
            johnmoves = solve(j - 1, b, x1 - 1, y1, x2, y2);
        }
        else {
            johnmoves = solve(j - 1, b, x1 + 1, y1, x2, y2);
        }
        johnmoves += energy(x1, y1, x2, y2);
    }

    // same thing for bessie
    if (b > 0) {
        char c = bessie[b - 1];  // previous movement
        if (c == 'N') {
            bessiemoves = solve(j, b - 1, x1, y1, x2, y2 - 1);
        }
        else if (c == 'S') {
            bessiemoves = solve(j, b - 1, x1, y1, x2, y2 + 1);
        }
        else if (c == 'E') {
            bessiemoves = solve(j, b - 1, x1, y1, x2 - 1, y2);
        }
        else {
            bessiemoves = solve(j, b - 1, x1, y1, x2 + 1, y2);
        }
        bessiemoves += energy(x1, y1, x2, y2);
    }

    // move together
    if (j > 0 && b > 0) {
        int energyused = energy(x1, y1, x2, y2);
        char c1 = john[j - 1], c2 = bessie[b - 1];

        if (c1 == 'N') {
            y1--;
        }
        else if (c1 == 'S') {
            y1++;
        }
        else if (c1 == 'E') {
            x1--;
        }
        else {
            x1++;
        }

        if (c2 == 'N') {
            y2--;
        }
        else if (c2 == 'S') {
            y2++;
        }
        else if (c2 == 'E') {
            x2--;
        }
        else {
            x2++;
        }

        bothmoves = solve(j - 1, b - 1, x1, y1, x2, y2) + energyused;
    }

    return dp[j][b] = min(johnmoves, min(bessiemoves, bothmoves));  // minimum of all 3 options
}

int main() {
    #if DEBUG
    freopen("input.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    #endif

    cin >> n >> m;
    cin >> start[0][0] >> start[0][1];
    cin >> start[1][0] >> start[1][1];
    cin >> john >> bessie;

    finish[0][0] = start[0][0];
    finish[0][1] = start[0][1];
    finish[1][0] = start[1][0];
    finish[1][1] = start[1][1];

    for (int i = 0; i < n; ++i) {  // get farmer john's final coordinates
        if (john[i] == 'N') {
            finish[0][1]++;
        }
        else if (john[i] == 'S') {
            finish[0][1]--;
        }
        else if (john[i] == 'E') {
            finish[0][0]++;
        }
        else {
            finish[0][0]--;
        }
    }
    for (int i = 0; i < m; ++i) {  // get bessie's final coordinates
        if (bessie[i] == 'N') {
            finish[1][1]++;
        }
        else if (bessie[i] == 'S') {
            finish[1][1]--;
        }
        else if (bessie[i] == 'E') {
            finish[1][0]++;
        }
        else {
            finish[1][0]--;
        }
    }

    memset(dp, -1, sizeof(dp));  // have not visited anything yet
    dp[0][0] = 0;
    solve(n, m, finish[0][0], finish[0][1], finish[1][0], finish[1][1]);
    cout << dp[n][m] << '\n';

    return 0;
}
