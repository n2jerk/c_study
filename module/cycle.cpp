#include<cstdio>
#include<cstring>
#define local
#define N 100
int vis[N], map[N][N], n, path[N];
//输出通过某个顶点简单回路
/**
 * [pathall description]
 * @param u [准备访问的顶点]
 * @param v [目标顶点]
 * @param d [当前长度]
 */
void pathall(int u, int v,  int d)
{
    vis[u] = 1;
    d++;
    path[d] = u;
    for (int i = 0; i < n; ++i)
        if(map[u][i])
        {
            if(i == v && d > 0)
            {
                // d++, path[d] = i;  //可选项,添加目标顶点
                for (int i = 0; i <= d; ++i)
                    printf("%d ", path[i] );
                printf("\n");
            }
            else if (!vis[i])
                pathall(i, v, d);
        }
    vis[u] = 0;
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
        memset(path, 0, sizeof(path));
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &x, &y);
            map[x][y] = 1;
        }
        pathall(0, 0, -1);
    }
    return 0;
}