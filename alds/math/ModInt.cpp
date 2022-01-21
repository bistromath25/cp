template<const long long MOD>
class ModInt {
public:
    ModInt<MOD>() : value(0) {}

    ModInt<MOD>(int x) {
        value = (long long) x % MOD;
    }

    ModInt<MOD>(long long x) {
        value = x % MOD;
    }

    void operator = (const int &x) {
        value = x % MOD;
    }

    void operator = (const long long &x) {
        value = x % MOD;
    }

    void operator = (const ModInt<MOD> &x) {
        value = x.value;
    }

    ModInt<MOD> operator + (const ModInt<MOD> &x) const {
        long long result = value + x.value;
        return ModInt<MOD> (result >= MOD ? result - MOD : result);
    }

    ModInt<MOD> operator - (const ModInt<MOD> &x) const {
        long long result = value - x.value;
        return ModInt<MOD> (result < 0 ? result + MOD : result);
    }

    ModInt<MOD> operator * (const ModInt<MOD> &x) const {
        long long result = value * x.value % MOD;
        return ModInt<MOD> (result < 0 ? result += MOD : result);
    }

    ModInt<MOD> operator / (const ModInt<MOD> &x) const {
        return *this * x.inv();
    }

    /* Shorthand methods */
    void operator += (const ModInt<MOD> &x) {
        value += x.value;
        if (value >= MOD) {
            value -= MOD;
        }
    }

    void operator -= (const ModInt<MOD> &x) {
        value -= x.value;
        if (value < 0) {
            value += MOD;
        }
    }

    void operator *= (const ModInt<MOD> &x) {
        value *= x.value;
        value %= MOD;
        if (value < 0) {
            value += MOD;
        }
    }

    ModInt<MOD> operator /= (const ModInt<MOD> &x) const {
        return *this *= x.inv();
    }

    ModInt<MOD> operator - () const {
        return ModInt<MOD> (value != 0 ? MOD - value : 0);
    }

    ModInt<MOD> pow(long long p) const {
        assert(0 <= p);
        ModInt<MOD> x = *this, result = 1;
        for (; p; p >>= 1) {
            if (p & 1) {
                result *= x;
            }
            x *= x;
        }
        return result;
    }

    ModInt<MOD> inv() const {
        return pow(MOD - 2);  // MOD is prime
    }

    bool operator == (const ModInt<MOD> &x) const {
        return value == x.value;
    }

    bool operator != (const ModInt<MOD> &x) const {
        return value != x.value;
    }

    bool operator ! () const {
        return !value;
    }

    long long base() {
        return (long long) MOD;
    }

    friend istream & operator >> (istream &in, const ModInt<MOD> &x) {
        long long t;
        cin >> t;
        x.value = t;
        return in;
    }

    friend ostream & operator << (ostream &out, const ModInt<MOD> &x) {
        out << x.value;
        return out;
    }

private:
    static_assert(MOD > 0, "MOD must be greater than 0");
    long long value;
};
