#include <bits/stdc++.h>
using namespace std;

inline int getChar();
inline int readChar();
template <typename T = int> inline T readInt();
inline double readDouble();
inline string readStr();

template <typename T> inline void writeInt(T x, char c = 0);
inline void writeDouble(double x, int d = 10, char c = 0);
inline void writeChar(int x);
inline void writeStr(string s);

static const int buffer_size = 4096;
static int write_pos = 0;
static char write_buffer[buffer_size];

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

template <typename T>
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

inline double readDouble() {
	int s = 1, c = readChar();
	double x = 0;
	if (c == '-') {
		s = -1;
		c = getChar();
	}
	while ('0' <= c && c <= '9') {
		x = x * 10 + c - '0';
		c = getChar();
	}
	if (c == '.') {
		c = getChar();
		double a = 1;
		while ('0' <= c && c <= '9') {
			x += (c - '0') * (a *= 1e-1);
			c = getChar();
		}
	}
	return s == 1 ? x : -x;
}

inline string readStr() {
    int c = getChar();
    string s = "";
    while (c != -1 && c != '\n') {
        s += c;
        c = getChar();
    }
    return s;
}

inline void writeChar(int x) {
    if (write_pos == buffer_size) {
        fwrite(write_buffer, 1, buffer_size, stdout);
        write_pos = 0;
    }
    write_buffer[write_pos++] = x;
}

template <typename T>
inline void writeInt(T x, char c) {
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
    if (c) {
        writeChar(c);
    }
}

inline void writeDouble(double x, int d, char c) {
    if (x < 0) {
        writeChar('-');
        x = -x;
    }
    // assert(x <= (1LLU << 63) - 1);
    long long t = (long long) x;
    writeInt<long long>(t);
    x -= t;
    writeChar('.');
    for (int i = d - 1; i > 0; --i) {
        x *= 10;
        t = min(9, (int) x);
        writeChar('0' + t);
        x -= t;
    }
    x *= 10;
    t = min(9, (int) (x + 0.5));
    writeChar('0' + t);
    if (c) {
        writeChar(c);
    }
}

inline void writeStr(string s) {
    for (const char &c : s) {
        writeChar(c);
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
