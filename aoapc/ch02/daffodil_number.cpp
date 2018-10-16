#include <cstdio>
//daffodil number

int main(int argc, char const *argv[])
{	int t,s,q;
	//i ∈[100,1000)
	for (int i=100;i<1000;i++)
	{	t=i,s=0;
		while(t>0)
		{
			q=t%10;
			s=s+q*q*q;
			t/=10;
		}
		if (s==i)
			printf("%d\n",s );
	}
	return 0;
}