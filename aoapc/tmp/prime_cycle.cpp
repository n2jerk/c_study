// AC 回溯法
#include <iostream>
#include <cstring>
using namespace std;
int vis[100];
int ans[100];
int n, cnt;
bool prime[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1};
void DFS( int cur )
{
    if ( cur == n && prime[ ans[ 0 ] + ans[ n - 1 ] ] )
    {
        for( int i = 0; i < n - 1; i++ )
        {
            cout << ans[ i ] << " ";
        }
        cout << ans[ n - 1 ] << endl;
        cnt++;
        return;
    }
    else
    {
        for ( int i = 2; i <= n; i++ )
        {
            if ( vis[i] == 0 && prime[ i + ans[ cur - 1 ] ] )
            {
                ans[ cur ] = i;
                vis[ i ] = 1;
                DFS( cur + 1 );
                vis[ i ] = 0;
            }
        }
    }
}
int main()
{
    int i = 0;
    while ( cin >> n && n != 0 )
    {
        cout << "Case " << ++i << ":" << endl;
        memset( ans, 0, sizeof(ans) );
        memset( vis, 0, sizeof(vis) );
        ans[ 0 ] = 1;
        cnt = 0;
        if ( n % 2 == 0 && n != 1 )
        {
            DFS(1);
        }
        else if ( n == 1 )
        {
            cout << "1" << endl;
        }
        else
            cout << "No Answer" << endl;
    }
    return 0;
}