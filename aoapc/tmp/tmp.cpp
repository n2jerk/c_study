#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
#include <stack>
#include <deque>
#define mv(a,b) memset(a,b,sizeof(a))
#define local
using namespace std;
int n, ans, steps;
int a[10];
bool flag, vis[10];
deque<string> path;
stack<char> op;
int pri[128];
int  dfs(double s, int cnt)
{
    char t;
    if(cnt == n)                 //n个数，代表只能进行n次操作
    {
        if(fabs(s - ans) < 0.0000001) //运算过程中可能会有小数出现，所以需要处理精度的问题
        {
            flag = true;
            return 1;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            vis[i] = true;        //标记，避免重复
            cnt++;
            //
            ostringstream  stream;
            string str_tmp ;
            stream << a[i];
            str_tmp = stream.str();
            path.push_back("+" + str_tmp), op.push('+');
            if(dfs(s + a[i], cnt))return 1;
            path.pop_back(), op.pop();
            //
            path.push_back("-" + str_tmp), op.push('-');
            if(dfs(s - a[i], cnt))return 1;
            path.pop_back(), op.pop();
            //
            t = op.top();
            if (pri[t] < pri['*'])
                path.push_back(")*" + str_tmp), path.push_front("(");
            else path.push_back("*" + str_tmp);
            op.push('*');
            if(dfs(s * a[i], cnt))return 1;
            if (pri[t] < pri['*'])
                path.pop_back(), path.pop_front();
            else path.pop_back();
            op.pop();
            //
            t = op.top();
            if (pri[t] < pri['/'])
                path.push_back(")/" + str_tmp), path.push_front("(");
            else path.push_back("/" + str_tmp);
            op.push('/');
            if(dfs(s / a[i], cnt))return 1;
            if (pri[t] < pri['/'])
                path.pop_back(), path.pop_front();
            else path.pop_back();
            op.pop();
            //
            path.push_front(str_tmp + "-("), path.push_back(")"), op.push('-');
            if(dfs(a[i] - s, cnt))return 1;
            path.pop_front(), path.pop_back(), op.pop();
            //
            path.push_front(str_tmp + "/("), path.push_back(")"), op.push('/');
            if(dfs(a[i] / s, cnt))return 1;
            path.pop_front(), path.pop_back(), op.pop();
            vis[i] = false;      // 回溯
            cnt--;
        }
    }
    return 0;
}
int gg()
{
    int T;
#ifdef local
    freopen("24.in", "r", stdin);
#endif
    stringstream stream;
    scanf("%d", &T);
    pri['+'] = 1;
    pri['-'] = 1;
    pri['*'] = 3;
    pri['/'] = 3;
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
                path.clear();
                mv(vis, false);
                vis[i] = true;
                op.push('*');
                stream << a[i];
                path.push_back( stream.str());
                dfs(a[i], 1);
            }
        }
        if(flag)
        {
            while(!path.empty())
            {
                cout << path.front() << ' ';
                path.pop_front();
            }
            cout << " Yes "  << endl;
        }
        else   cout << "No" << endl;
    }
}
int main(int argc, char const *argv[])
{
    gg();
    return 0;
}