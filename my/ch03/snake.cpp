#include <cstdio>
#include <cstring>
const int N = 100;
int a[N][N];
int main(int argc, char const *argv[])
{
    int i, j, n,  t;
    while(scanf("%d", &n) && n > 0)
    {
        memset(a, 0, sizeof(a));
        a[i=0][j=0] = t = 1;
        while(t < n * n)
        {
            while(i + 1 < n &&! a[i + 1][j]  )a[++i][j] = ++t;
            while(j + 1 < n && !a[i][j + 1]  )a[i][++j] = ++t;
            while(i - 1 > -1 &&! a[i - 1][j]  )a[--i][j] = ++t;
            while(j - 1 > -1 && !a[i][j - 1]  )a[i][--j] = ++t;
        }
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                printf("%4d", a[i][j]);
            printf("\n");
        }
    }
    return 0;
}