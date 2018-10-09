#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10000;
int ans[maxn];
int ok(int a, int b, int idx)
{
    int repeat = 10, t;
    while(repeat--)
    {
        for (int i = 0; i < idx; ++i)
        {
            a *= 10;
            t = a / b;
            a %= b;
            if (ans[i] != t)
                return 0;
        }
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    int a, b,  idx;
    while(scanf("%d %d", &a, &b) != EOF)
    {
        memset(ans, 0, sizeof(ans));
        printf("%d.", a / b );
        a %= b;
        idx = 0;
        while(idx < maxn)
        {
            ans[idx] = a * 10 / b;
            if (idx>0&&ans[0] == ans[idx])
            {
                if(ok(a, b, idx))
                {
                    for (int i = 0; i < idx; ++i)
                    {
                        printf("%d", ans[i] );
                    }
                    printf(" %d\n", idx );
                    break;
                }
            }
            a *= 10;
            a %= b;
            idx++;
            if(a==0)
            	{
            		for (int i = 0; i < idx; ++i)
                    {
                        printf("%d", ans[i] );
                    }
                    printf(" %d\n", idx );
                    break;
            	}
        }
    }
    return 0;
}