#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int a,b,c,q;
	while(scanf("%d%d%d",&a,&b,&c)&&!(a==0&&b==0&&c==0) )
	{
		printf("%d.",a/b );
		a%=b;
		while(c--)
		{	a*=10;
			q=a/b;
			// 四舍五入
			if(c==0&&(a%b*10/b>=5))q++;
			printf("%d",q );
			a%=b;
		}
		printf("\n");
	}
}