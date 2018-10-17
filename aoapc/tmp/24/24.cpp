#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#define mv(a,b) memset(a,b,sizeof(a))
#define local
using namespace std;
int n,ans,steps;
int a[10];
bool flag,vis[10];
void dfs(double s, int cnt)
{
    steps++;
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
            dfs(s * a[i], cnt); //a*b==b*a
            dfs(s / a[i], cnt); // a/b
            dfs(a[i] - s, cnt);// b-a
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
    freopen("24.in", "r", stdin);
    freopen("24.out", "w", stdout);
#endif
    scanf("%d", &T);
    while(T--)
    {
        steps = 0;
        scanf("%d%d", &n, &ans);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
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
        if(flag)  cout << "Yes " << steps << endl;
        else   cout << "No" << endl;
    }
}