#include <cstdio>
int main(int argc, char const *argv[])
{
    int n, i, t;
    while(scanf("%d", &n) && n)
    {
        t = n;
        while(t > 0)
        {
            for(i = 0; i < n - t; i++)
                printf(" ");
            for (i = 0; i < 2 * t - 1; i++)
                printf("%c", '#' );
            printf("\n");
            t--;
        }
    }
    return 0;
}