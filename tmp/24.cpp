#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define mv(a,b) memset(a,b,sizeof(a))
#define local
using namespace std;
int n;
int ans;
double a[10];
bool flag;
bool vis[10];
int lps;
void dfs(double s, int cnt)
{
    lps++;
    if(cnt == n)                 //n个数，代表只能进行n次操作
    {
        if(fabs(s - ans) < 0.0000001) //运算过程中可能会有小数出现，所以需要处理精度的问题
        {
            flag = true;
            return ;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            vis[i] = true;        //标记，避免重复
            cnt++;
            dfs(s + a[i], cnt);    // 加减乘除  a+b==b+a
            dfs(s - a[i], cnt); // a-b
            dfs(a[i] - s, cnt);// b-a
            dfs(s * a[i], cnt); //a*b==b*a
            dfs(s / a[i], cnt); // a/b
            dfs(a[i] / s, cnt);// b/a
            vis[i] = false;      // 回溯
            cnt--;
        }
    }
}
int main()
{

    int T;
#ifdef local
    freopen("tmp.in", "r", stdin);
    freopen("tmp1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while(T--)
    {
        lps = 0;
        scanf("%d%d", &n, &ans);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lf", &a[i]);
        }
        flag = false;           // 标记是否找到
        for(int i = 1; i <= n; i++)
        {
            if(flag) break;
            else
            {
                mv(vis, false);
                vis[i] = true;
                dfs(a[i], 1);
            }
        }
        if(flag)  cout << "Yes " << lps << endl;
        else   cout << "No" << endl;
    }
}