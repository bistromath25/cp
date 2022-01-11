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


const int MAXN = 1e5 + 1, INF = 1e9;
int N;
int score[MAXN];     // scores
int pref[MAXN];      // prefix sum array for scores
int minscore[MAXN];  // minscore[i] = minimum score of first i papers starting from N (right to left)

int main() {
    #if DEBUG
    freopen("input.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    #endif

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> score[i];
    }

    pref[0] = 0;
    for (int i = 1; i <= N; ++i) {
        pref[i] = pref[i - 1] + score[i];
    }

    minscore[N] = score[N];
    for (int i = N - 1; i >= 1; --i) {
        minscore[i] = min(score[i], minscore[i + 1]);
    }

    dbgarr(score, N + 1);
    dbgarr(minscore, N + 1);
    dbgarr(pref, N + 1);

    set<int> ans;
    double best = 0;
    // try eating the first K papers, K from 1 to N - 2
    for (int K = 1; K <= N - 2; ++K) {
        int totalscore = pref[N] - pref[K];
        int minimum = minscore[K + 1];  // the smallest score right after the Kth paper

        // avg is (totalscore - min) / (N - K - 1)
        double avg = (1.0 * (totalscore - minimum)) / (N - K - 1);

        debug(K, totalscore, minimum, avg);

        if (avg > best) {
            best = avg;
            ans.clear();
            ans.insert(K);
        }
        else if (avg == best) {
            ans.insert(K);
        }
    }

    for (set<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
        cout << *it << '\n';
    }

    return 0;
}
