struct mint {
    int x;
    explicit operator int() const { return x; }
    mint() : x(0) {}
    mint(long long _x) : x(int(_x % MOD)) { x += (x < 0) * MOD; }
    mint& operator += (mint& a, mint b) {
        if ((a.x += b.x) >= MOD) a.x -= MOD;
        return a;
    }
    mint& operator -= (mint& a, mint b) {
        if ((a.x -= b.x) >= MOD) a.x += MOD;
        return a;
    }
    mint operator + (mint a, mint b) { return a += b; }
    mint operator - (mint a, mint b) { return a -= b; }
    mint operator * (mint a, mint b) { return mint((long long) a.x * b.x); }
    mint operator / (mint a, mint b) { return a * inv(b); }
    mint& operator *= (mint& a, mint b) { return a = a * b; }
    mint& operator /= (mint& a, mint b) { return a = a / b; }
    mint pow(mint a, long long n) {
        assert(n >= 0);
        return n == 0 ? 1 : pow(a * a, n / 2) * (n & 1 ? a : 1);
    }
    mint inv(mint a) {
        assert(a.x != 0);
        return pow(a, MOD - 2);
    }
    bool operator == (mint a, mint b) { return a.x == b.x; }
    bool operator != (mint a, mint b) { return a.x != b.x; }
};
