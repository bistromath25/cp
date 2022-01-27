class SingleBaseHashString {
private:
    static const long long M = 9973;
    static const long long P = 1e9 + 9;
    static vector<long long> pow = {1};
    vector<long long> phash;  // phash[i] = hash of first i chars
public:
    SingleBaseHashString(const string& s) : phash(s.size() + 1) {
        while (pow.size() < s.size()) {
            pow.push_back((pow.back() * P) % M);
        }
        phash[0] = 0;
        for (int i = 0; i < s.size(); ++i) {
            phash[i + 1] = ((phash[i] * P) % M + s[i]) % M;
        }
    }
    long long GetHash(int l, int r) {
        long long value = (phash[r + 1] - (phash[l] * pow[r - l + 1]));
        return (value % M + M) % M;
    }
};
