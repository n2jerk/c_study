#include <cstdio>
#include <cstring>
#define local
#define base 10000
#define N 10000
int a[N];
void fra(int n)
{
    memset(a, 0,  sizeof(a));
    int k = 1, c;
    a[k] = 1;
    for (int i = 1; i <= n; ++i)
    {
        c = 0;
        for (int j = 1; j <= k; ++j)
        {
            a[j] = a[j] * i + c;
            if(a[j] >= base)
                c = a[j] / base, a[j] %= base;
            else c = 0;
        }
        if(c > 0)a[++k] = c;
    }
    printf("%5d!= ", n);
    for (int i = k; i >= 1; i--)
        printf("%d", a[i]);
    printf("\n");
}
int main(int argc, char const *argv[])
{
#ifdef local
    freopen("fra.in", "r", stdin);
    freopen("fra.out", "w", stdout);
#endif
    int n;
    while(scanf("%d", &n) != EOF)
    {
        fra(n);
    }
    return 0;
}