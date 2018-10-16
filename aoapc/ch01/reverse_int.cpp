#include <cstdio>
/**
 * [reverse_int1 reverse 100~999,and print it] 
 * @param a [description]
 */
void reverse_int1(int a)
{	
    printf("%d%d%d\n", a % 10, a / 10 % 10, 1 % 100);
}
/**
 * [reverse_int2 reverse print int number]
 * @param a [int number (a>0)]
 */
void reverse_int2(int a)
{	
    while(a > 0)
    {
        printf("%d", a % 10);
        a /= 10;
    }
    printf("\n");
}
/**
 * [reverse_int3 逆转整数,不输出前导0,可能上溢出]
 * @param a [a>0]
 */
void reverse_int3(int a){
	int s=0;
	while(a>0){
		s=s*10+a%10;
		a/=10;
	}
	printf("%d\n",s);
}
int main(int argc, char const *argv[])
{
	int a;
	while(scanf("%d",&a) && a>0)
		reverse_int2(a),reverse_int3(a);
    return 0;
}