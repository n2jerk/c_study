 
 #include <iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<math.h>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define local
using namespace std;
const int N=10;
int n;
double num[N],ans;
int lps;
bool judge(double a,double b)
{
    if(fabs(a-b)<1e-6)
        return true;
    return false;
}
bool dfs(int k)
{
    lps++;
    if(k==n)
    {
        if(judge(num[n],ans))
        return true;
        return false;
    }
    for(int i=k;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            double x=num[i],y=num[j];
            num[i]=num[k];
            num[j]=x+y;if(dfs(k+1))return true;
            num[j]=x-y;if(dfs(k+1))return true;
            num[j]=x*y;if(dfs(k+1))return true;
            num[j]=y-x;if(dfs(k+1))return true;
            if(!judge(x,0))
            {
                num[j]=y/x;if(dfs(k+1))return true;
            }
            if(!judge(y,0))
            {
                num[j]=x/y;if(dfs(k+1))return true;
            }
            num[i]=x;num[j]=y;
        }
    }
    return false;
}
int main()
{
    #ifdef local
    freopen("tmp.in","r",stdin);
    freopen("tmp2.out","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    while(t--)
    {   lps=0;
        scanf("%d%lf",&n,&ans);
       for(int i=1;i<=n;i++)
        scanf("%lf",&num[i]);
        if(dfs(1))
            printf("Yes %d\n",lps);
        else
            printf("No\n");
    }
    return 0;
}
