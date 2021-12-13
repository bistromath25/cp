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
#define dbg(x) {cout << "[" << (#x) << ": "; __dbg(x); cout << "]\n";}
#define dbgarr(a, n) {cout << "[" << (#a) << ": {"; int __n__ = 0; for (const auto &__x__ : a) {__dbg(__x__); ++__n__; if (__n__ >= n) {break;} else {cout << ", ";}} cout << "}]\n";}
#define dbgarr2d(a, r, c) {cout << (#a) << ":\n"; for (int __i__ = 0; __i__ < (r); ++__i__) {for (int __j__ = 0; __j__ < (c); ++__j__) {cout << (a[__i__][__j__]) << " ";} cout << "\n";}}
#define dbgmsg(msg) {cout << msg << "\n";}
#define debug(args...) {__debug_out(__split(#args).begin(), args);}
#else
#define dbg(x)
#define dbgarr(a, n)
#define dbgarr2d(a, r, c)
#define dbgmsg(msg)
#define debug(args...)
#endif


void print_vector(const vector<long long> &v) {
    // no trailing whitespace
    if (v.size() == 1) cout << v[0];
    else {
        cout << v[0];
        for (int i = 1; i < v.size(); ++i) {
            cout << ' ' << v[i];
        }
    }
}

void solve() {
    int N;
    cin >> N;
    vector<long long> cards(N);
    map<long long, int> freq;
    for (int i = 0; i < N; ++i) {
        cin >> cards[i];
        freq[cards[i]]++;
    }

    sort(cards.begin(), cards.end());
    reverse(cards.begin(), cards.end());
    dbgarr(cards, N);

    long long ken = 0, opp = 0;  // ken and opponent sums
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            ken += cards[i];
        }
        else {
            opp += cards[i];
        }
    }

    debug(ken, opp);

    if (ken > opp) {
        dbgmsg("YES");
        print_vector(cards);
        cout << '\n';
        return;
    }

    ken = 0;
    opp = 0;

    bool ok = false;

    for (int i = 1; i < N - 2; ++i) {
        if (cards[i] == cards[i + 1]) continue;

        int f1 = freq[cards[i]];
        int f2 = freq[cards[i + 1]];

        if (f1 % 2 == 0 && f2 % 2 == 0) {
            swap(cards[i], cards[i + 1]);
            ok = true;
            break;
        }
    }

    dbgarr(cards, N);

    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            ken += cards[i];
        }
        else {
            opp += cards[i];
        }
    }

    debug(ken, opp);

    if (ok) {
        dbgmsg("YES");
        print_vector(cards);
        cout << '\n';
    }
    else {
        dbgmsg("NO");
        cout << "-1\n";
    }
}

int main() {
    #if DEBUG
    freopen("input.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        solve();
    }

    return 0;
}
