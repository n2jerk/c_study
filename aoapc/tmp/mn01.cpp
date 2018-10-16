/**
 *是否对于任意正整数n，都能找到一个n的倍数，它全都由0和1组成
 *
 *可以这样证明：
随便给一个正整数N，构建序列1, 11, 111, ..., 111...1(N+1个1）
这个序列的每一个数除以N都会有余数，余数的取值有0, 1, ..., N - 1，一共N种
所以由抽屉原理这个序列里必有两个数除以N余数相等，即这两个数相减得到的数全由0和1组成且是N的倍数。
 *
 * 
 */

#include<cstdio>
#include<cmath>
#include<queue>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fod(i,a,b) for(i=a;i>=b;i--)
using namespace std;
typedef long long ll;
int i, j, k, l, t, n, m, now;
queue<int> q;
int a[1000007], sh[1000007], b[1000007];
ll ans;
void gao(int x)
{
    while(x != -1)
    {
        b[++b[0]] = a[x];
        x = sh[x];
    }
    fod(i, b[0], 1)printf("%d", b[i]);
}
int main()
    {       

    while( scanf("%d", &n) && n)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(sh,0,sizeof(sh));
        i=j=k=l=t=m=ans=0;
        while(!q.empty())
            q.pop();
        q.push(1);
        sh[1] = -1;
        a[1] = 1;
        while(!q.empty())
        {
            now = q.front();
            q.pop();
            k = now * 10 % n;
            l = (now * 10 + 1) % n;
            if(!k)
            {
                gao(now);
                printf("0\n");
                break;
            }
            if(!l)
            {
                gao(now);
                printf("1\n");
                break;
            }
            if(!sh[k])
            {
                q.push(k);
                sh[k] = now;
                a[k] = 0;
            }
            if(!sh[l])
            {
                q.push(l);
                sh[l] = now;
                a[l] = 1;
            }
        }
        // printf("%lld\n", ans);
    }
    return 0;
}


/**
 #include<iostream>    //string字符串需要用cout输出
#include<string.h>
#include<stdio.h>
#include<string>
#include<queue>
using namespace std;
 
int book[1000010], n; //book标记余数是否出现
 
struct node
{
    string str;
    int num;
};
 
void bfs()
{
    queue<node>Q;
    node st, en;
    
    st.str = "1"; st.num = 1%n;
    book[st.num] = 1;     //因为十进制数第一位不可能为0，
    Q.push(st);           //所以将1加入队列来延伸
    
    while( !Q.empty() )
    {
        st = Q.front();
        Q.pop();
        if( st.num == 0 )
        {
            cout<<st.str<<endl;
            return ;
        }
        
        en.str = st.str + '0';
        en.num = (st.num*10)%n;    //将余数乘10再计算
        if( !book[en.num] )
        {
            book[en.num] = 1;
            Q.push(en);
        }
        
        en.str = st.str + '1';
        en.num = (st.num*10+1)%n;  //将余数乘10加1在计算
        if( !book[en.num] )
        {
            book[en.num] = 1;
            Q.push(en);
        }
    }
}
 
int main()
{
    while( ~scanf("%d",&n) )
    {
        if( n == 1 )       //若n为1直接输出
            printf("1\n");
        else
        {
            memset(book,0,sizeof(book));
            bfs();         //搜索判断
        }
    }
    return 0;
}

 */