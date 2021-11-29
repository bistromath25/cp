#include <bits/stdc++.h>
using namespace std;

inline int getChar();
inline int readChar();
template <typename T = int> inline T readInt();
template <typename T> inline void writeInt(T x, char last = 0);
inline void writeChar(int x);
inline void writeStr(const char *s);

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
