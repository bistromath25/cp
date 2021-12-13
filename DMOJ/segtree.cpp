#include <bits/stdc++.h>
using namespace std;

inline int getChar();
inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt(T x, char last = 0);
inline void writeChar(int x);
inline void writeStr(const char *s);

static const int buffer_size = 4096;

inline int getChar() {
	static char buffer[buffer_size];
	static int len = 0, pos = 0;
	if (pos == len) {
		pos = 0;
		len = fread(buffer, 1, buffer_size, stdin);
	}
	if (pos == len) {
		return -1;
	}
	return buffer[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32) {
		c = getChar();
	}
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-') {
		s = -1;
		c = getChar();
	}
	while ('0' <= c && c <= '9') {
		x = x * 10 + c - '0';
		c = getChar();
	}
	return s == 1 ? x : -x;
}

static int write_pos = 0;
static char write_buffer[buffer_size];

inline void writeChar(int x) {
	if (write_pos == buffer_size) {
		fwrite(write_buffer, 1, buffer_size, stdout);
		write_pos = 0;
	}
	write_buffer[write_pos++] = x;
}

template <class T>
inline void writeInt(T x, char last) {
	if (x < 0) {
		writeChar('-');
		x = -x;
    }
	char s[24];
	int n = 0;
	while (x || !n) {
		s[n++] = '0' + x % 10;
		x /= 10;
	}
	while (n--) {
		writeChar(s[n]);
	}
	if (last) {
		writeChar(last);
	}
}

inline void writeStr(const char *s) {
	while (*s) {
		writeChar(*s++);
	}
}

struct Flusher {
	~Flusher() {
		if (write_pos) {
			fwrite(write_buffer, 1, write_pos, stdout);
			write_pos = 0;
		}
	}
} flusher;

template<class T>
struct SegTree {
    const T ZERO = 1e9;
    T f(T a, T b) {
        return min(a, b);
    }
    int n;
    vector<T> segtree;
    void init(int _n) {
        n = _n;
        segtree.assign(2 * n, ZERO);
    }
    void build() {
        for (int i = n - 1; i > 0; --i) {
            segtree[i] = f(segtree[i << 1], segtree[(i << 1) | 1]);
        }
    }
    void pull(int p) {
        segtree[p] = f(segtree[2 * p], segtree[2 * p + 1]);
    }
    void update(int p, T v) {
        segtree[p += n] = v;
        for (p /= 2; p; p /= 2) {
            pull(p);
        }
    }
    T query(int a, int b) {
        T ra = ZERO, rb = ZERO;
        for (a += n, b += n + 1; a < b; a /= 2, b /= 2) {
            if (a & 1) {
                ra = f(ra, segtree[a++]);
            }
            if (b & 1) {
                rb = f(segtree[--b], rb);
            }
        }
        return f(ra, rb);
    }
    void print() {
        for (const int &x : segtree) {
            cout << x << ' ';
        }
        cout << '\n';
    }
};

SegTree<int> st;

int main() {
    int n, q, a, b;
    char c;
    n = readInt();
    q = readInt();
    st.init(n);
    for (int i = 0; i < n; ++i) {
        st.segtree[n + i] = readInt();
        //st.update(i, x);
    }
    st.build();
    for (int i = 1; i <= q; ++i) {
        c = readChar();
        a = readInt();
        b = readInt();
        if (c == 'M') {
            st.update(a, b);
        }
        else {
            writeInt(st.query(a, b));
            writeChar('\n');
        }
    }
}
