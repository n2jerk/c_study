#include<cstdio>
#include<cstring>
#include<stack>
#define local
#define N 100
using namespace std;

// 尽可能输出欧拉路径
typedef struct
{
    int u, v;
} path;  //存储路径信息
stack<path> ans;
int n, G[N][N], vis[N][N], f = 0;
void euler(int u)
{
    for (int v = 1; v <= n; ++v)
    {
        if(G[u][v] && (vis[u][v] < G[u][v]))
        {
            vis[u][v]++;
            vis[v][u]++;
            euler(v);
            path k;
            k.u = u, k.v = v;
            ans.push(k);
        }
    }
}
int print_path()
{
    path a, b;
    a.u = a.v = -1;
    int first = 1,ok=1;
    while(!ans.empty())
    {
        b = ans.top();
        ans.pop();
        if(a.v != b.u)
        {
            if (!first)  {printf("\n");ok=0;}
            printf("%d %d ", b.u, b.v);
            first = 0;
        }
        else
            printf("%d ", b.v );
        a = b;
    }
    printf("\n-------------\n");
    return ok;
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
        f = 1;
        while(!ans.empty()) ans.pop();
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
        print_path();
    }
    return 0;
}