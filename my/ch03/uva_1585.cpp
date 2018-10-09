#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int score=0,s=0,i=0;
	char c[100];
	cin>>c;
	while(c[i])
	{
		s=c[i]=='O'?s+1:0;
		score+=s;
		i++;
	}
	cout<<score<<endl;
	return 0;
}