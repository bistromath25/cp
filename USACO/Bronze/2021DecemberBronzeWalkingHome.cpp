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

const int N = 51, K = 4;  // 50 + 1, 3 + 1
int n, k;
char grid[N][N];  // farm contents
int dp[N][N][K][2];  // dp[i][j][k][d] = number of ways to get to (i, j) using exactly k turns and from direction d (1 - down, 0 - right)

bool ok(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 'H') return false;
    else return true;
}

int paths(int i, int j, int k, int d) {  // number of ways to reach (i, j) with exactly k turns and from direction d
    if (k == -1 || !ok(i, j)) {          // 0 = down, 1 = right
        return 0;  // exceeded the alloted turns, and (i, j) is not an OK square to be on
    }

    if (k == 0 && i == n - 1 && j == n - 1) {  // no turns left and we reached bottom right corner anyways
        return 1;
    }

    if (dp[i][j][k][d] != -1) {
        return dp[i][j][k][d];  // return previously computed value
    }

    if (d) {  // recur moving down, and moving right -> k -= 1
        return dp[i][j][k][1] = paths(i + 1, j, k, d) + paths(i, j + 1, k - 1, !d);
    }

    else {  // recur moving right, and moving down -> k -= 1
        return dp[i][j][k][0] = paths(i, j + 1, k, d) + paths(i + 1, j, k - 1, !d);
    }
}

int paths(int k) {
    memset(dp, -1, sizeof(dp));  // initialize values of dp array to -1
    return paths(1, 0, k, 1) + paths(0, 1, k, 0);  // no. paths moving initially down plus no. paths moving right
}

int main() {
    //freopen("input.in", "r", stdin);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n >> k;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        int ans = 0;
        for (int i = 1; i <= k; ++i) {
            ans += paths(i);  // ans += number of ways using exactly i turns
        }

        cout << ans << '\n';
    }


    return 0;
}

