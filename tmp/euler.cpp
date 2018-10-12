#include<cstdio>
#include<cstring>
#define local
#define N 100
int n, G[N][N], vis[N][N],f=0;
void euler(int x)
{       
        
    for (int i = 1; i <= n; ++i)
    {
        if(G[x][i] && (vis[x][i] < G[x][i]))
        {
            vis[x][i]++;
            vis[i][x]++;
            printf("%c -> %d", f?x+48:' ',i);
            if(f) f=0;
            euler(i);
            f=1;
            printf("\n");
        }
    }
}
int main(int argc, char const *argv[])
{
#ifdef local
    freopen("euler.in", "r", stdin);
    // freopen("euler.out", "w", stdout);
#endif
    int T, m, x, y;
    scanf("%d", &T);
    while(T--)
    {   
        f=1;
        memset(G, 0, sizeof(G));
        memset(vis, 0, sizeof(vis));
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &x, &y);
            G[x][y]++;
            G[y][x]++;
        }
        euler(1);
    }
    return 0;
}