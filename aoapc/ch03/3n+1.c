#include <stdio.h>
// 3*n+1 problem
int main(int argc, char const *argv[])
{
    int N = 1 << 31 - 1, i = 0, max_t = 0, cnt, n;
    long long t;
    while(i++ < N)
    {
        t = i, cnt = 0;
        while(t > 1)
        {
            if(t % 1) t = 3 * t + 1;
            else t >>= 1;
            cnt++;
        }
        if (max_t < cnt) n = i, max_t = cnt;
#ifdef show
        printf("<%5d,%5d>", i, cnt);
        if (i % 7 == 0)
            printf("\n");
#endif
    }
    printf("<%d,%d>\n", n, max_t);
    return 0;
}