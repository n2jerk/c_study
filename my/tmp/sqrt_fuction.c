#include<stdio.h>
#include<math.h>
//牛顿迭代法求开平方
int main(int argc, char const *argv[])
{
    int n, xi, t;
    double x, y, m = 1e-10;
    while(scanf("%d %d", &n, &xi) == 2 && n > 0)
    {
        x = xi, y = x + 1;
        t=0;
        while(fabs(x - y) > m)
        {
            y = x;
            x = (x + n / x) / 2.0;
            t++;
        }
        printf("%d %lf %lf  %d\n", n, x, sqrt(n),t);
    }
    return 0;
}