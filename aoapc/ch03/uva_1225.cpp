#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10000 + 10;
int ans[maxn][10];
int main(int argc, char const *argv[])
{
	int cnt[10]={0},n;
	for (int j,i = 1; i < maxn; ++i)
	{
		j=i;
		while(j)
		{
			cnt[j%10]++;
			j/=10;
		}
		for (j= 0; j < 10; ++j)
			ans[i][j]=cnt[j];
	}
	while(scanf("%d",&n)!=EOF)
	{
		for (int i = 0; i < 10; ++i)
		{
			printf("%d ",ans[n][i] );
		}
		printf("\n");
	}
	return 0;
}