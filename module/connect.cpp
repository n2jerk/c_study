#include<cstdio>
#include<cstring>
#define local
#define N 100
int vis[N], map[N][N], n;
//判断图是否连通
/**
 * [dfs description]
 * @param v [准备访问的顶点]
 * @param cnt [已访问的顶点数量]
 */
void dfs(int v, int cnt )
{
    vis[v] = 1;
    cnt++;
    if(cnt == n) return;
    for (int i = 1; i <= n; ++i)
    {
        if(map[v][i]) dfs(i, cnt);
    }
}
int main(int argc, char const *argv[])
{
#ifdef local
    freopen("tmp.in", "r", stdin);
    freopen("tmp.out", "w", stdout);
#endif
    int m, x, y;
    //n个顶点,m条边
    while(scanf("%d%d", &n, &m) == 2 && n)
    {
        memset(vis, 0, sizeof(vis));
        memset(map, 0, sizeof(map));
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &x, &y);
            map[x][y] = 1;
        }
        dfs(1, 0);
        int flag = 1;
        for (int i = 1; i <= n; ++i)
            if(!vis[i])
            {
                flag = 0;
                break;
            }
        if (flag)printf("connect\n");
        else printf("no connect\n" );
    }
    return 0;
}