#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define mv(a,b) memset(a,b,sizeof(a))
using namespace std;
int n;
int ans;
double a[10];
bool flag;
bool vis[10];
void dfs(double s, int cnt)
{
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
            dfs(s + a[i], cnt);    // 加减乘除
            dfs(s - a[i], cnt);
            dfs(s * a[i], cnt);
            dfs(s / a[i], cnt);
            dfs(a[i] / s, cnt);
            dfs(a[i] - s, cnt);
            vis[i] = false;      // 回溯
            cnt--;
        }
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &ans);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lf", &a[i]);
        }
        flag = false;           // 标记是否找到
        for(int i = 1; i <= n; i++)
        {
            if(flag)
                break;
            else
            {
                mv(vis, false);
                vis[i] = true;
                dfs(a[i], 1);
            }
        }
        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}