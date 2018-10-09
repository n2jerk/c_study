#include <iostream>
#include <cstdlib>
#include <ctime>
#define FOR(i,a,b) for(i=a;i!=b;i++)
using namespace std;
int add(int a, int  b)
{
    int  tmp;
    while(b)
    {
        tmp = a;
        a = a ^ b;
        b = (tmp & b) << 1;
    }
    return a;
}
int substract(int a, int b)
{
    return add(a, add(~b, 1));
}
int multiply(int x, int y)
{
    int a = x, b = y,s = 0;
    if (a==0||b==0)return 0;
    while(b)
    {
        if (b & 1)
            s += a;
        b >>= 1;
        a <<= 1;
    }
    if((a ^ b) < 0)s = add(~s, 1);
    return s;
}
int divide(int x, int y)
{   int a=x,b=y,ans=0,i=31;
    while(i >= 0)
    {
        //比较x是否大于y*(1<<i)=(y<<i)，避免直接比较，因为不确定y*(1<<i)是否溢出
        if( (a >> i) >= b) //如果够减
        {
            ans = add(ans, (1 << i));
            a = substract(a, (b << i));
        }
        i = substract(i, 1);
    }
    if((x^y) < 0)  ans=add(~ans,1);
    return ans;
}
int main(int argc, char const *argv[])
{
    /* code */
    srand(time(NULL));
    int i, x,y, a,b;
    FOR(i, 1, 10)
    {
        x=23,y=4;
        cout <<x<<' '<<y<<' ' <<divide(x,y) << endl;
    }
    return 0;
}