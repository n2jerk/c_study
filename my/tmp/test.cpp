#include <iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int a[]={1,2,3};
	int b=3;
	bool s=typeid(b)==typeid(int);
    return 0;
}