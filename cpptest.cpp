/*
**
**  Morris b415: output optimization
**
**  use buffer to accelerate code, since printf() and cout is- 
**  slower than write buffer yourself and use fread in c++/getchar in c/c++ to buffer.
**
**  origin problem is to out psuedo-random number using given seed and number of times to output
**  according to Blum Blum Shub (BBS) Generator, but only (x.next = (x*x)%p)
**
*/


#include <bits/stdc++.h>    //< header of all c++ standard header
  
namespace mLocalStream {    //< namespace containing all function needed to inplement this method,-
                            //  can put in .h and use in other file.
    inline int readchar() {
        const int N = 1048576;
        static char buf[N];
        static char *p = buf, *end = buf;   //< because need to call many times and set to global is not practical-
                                            //  in terms of portability. Its making a buffer after all.
        if(p == end) {
            if((end = buf + fread(buf, 1, N, stdin)) == buf) return EOF;    //< fread return char read, not EOF(-1)
                                                                            //  sizeof(char)=1, its called to read all in buffer when first called
                                                                            //  s.t. calls after can just take things in buffer
            p = buf;
        }
        return *p++;
    }
    inline int ReadInt(int *x) {    //< x to return read int, function return indicate read/EOF
        static char c, neg;
        while((c = readchar()) < '-')    {if(c == EOF) return 0;}   //< EOF
        neg = (c == '-') ? -1 : 1;  //< deal with negative sign
        *x = (neg == 1) ? c-'0' : 0;    //< if positive, then char read is number, read it.
        while((c = readchar()) >= '0')
            *x = (*x << 3) + (*x << 1) + c-'0'; //< 10x + (int)c
        *x *= neg;  //< deal w/ neg
        return 1;
    }
    class Print {
    public:
        static const int N = 1048576;
        char buf[N], *p, *end;
        Print() {   //< initialize
            p = buf, end = buf + N - 1;
        }
        void printInt(int x, char padding) {    //< padding act like space or some sort
            static char stk[16];
            int idx = 0;
            stk[idx++] = padding;
            if (!x)	
                stk[idx++] = '0';
            while (x)   //< quite good, put x while x still >0, operated by operator / 
                stk[idx++] = x%10 + '0', x /= 10;   //< comma operator enables multiple statement in places
                                                    //  only one statement is expected, return right-most value/return
            while (idx) {
                if (p == end) {
                    *p = '\0';
                    printf("%s", buf), p = buf;
                }
                *p = stk[--idx], p++;
            }
        }
        static inline void online_printInt(int x) {
            static char ch[16];
            static int idx;
            idx = 0;
            if (x == 0)	ch[++idx] = 0;
            while (x > 0) ch[++idx] = x % 10, x /= 10;
            while (idx) 
                putchar(ch[idx--]+48);
        }
        ~Print() {
            *p = '\0';
            printf("%s", buf);
        }
    } bprint;   //< only instance in whole program, basically we only deal w/ this instance in application,
                //  and in reality the above readInt thing is just written to complete all I/O optimation, if one actually needed.
}

int main() {
    int x0, p, n;
    while (scanf("%d %d %d", &x0, &p, &n) == 3) {
        for (int i = 0; i < n; i++) {
            mLocalStream::bprint.printInt(x0, i == n-1 ? '\n' : ' ');
//			mLocalStream::Print::online_printInt(x0);
//			putchar(i == n-1 ? '\n' : ' ');
            x0 = ((long long) x0 * x0)%p;
        }
    }
    return 0;
}