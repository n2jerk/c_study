#include<cstdio>
#include<stack>
using namespace std;

int main(int argc, char const *argv[])
{
	int a=1,b;
	stack<int> s;
	s.push(1);
	b=s.top();
	printf("%d %d\n",a ,b);
	return 0;
}