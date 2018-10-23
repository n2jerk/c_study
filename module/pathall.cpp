#include<cstdio>
#include<cstring>
#define local
#define N 100
int vis[N], G[N][N], n, path[N];
//输出从顶点u到v所有路径长度为l的路径
/**
 * [pathall description]
 * @param u [准备访问的顶点]
 * @param v [目标顶点]
 * @param l [目标路径长度]
 * @param d [当前长度]
 */
void pathall(int u, int v, int l, int d)
{
    vis[u]=1;
    d++;
    path[d]=u;
    if(u==v&&d==l){
        for (int i = 0; i <= l; ++i)
            printf("%d ",path[i] );
        printf("\n");
    }
    for (int i = 0; i < n; ++i)
        if(G[u][i]&& (!vis[i])) pathall(i,v,l,d); //如果存在路径且未访问,则访问
    vis[u]=0;
}
//输出从顶点u到v所有路径长度为l的路径
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
        memset(G, 0, sizeof(G));
        memset(path, 0, sizeof(path));
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &x, &y);
            G[x][y] = 1;
        }
        pathall(0, 3, 3, -1);
    }
    return 0;
}