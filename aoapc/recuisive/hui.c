#include <stdio.h>
#include <string.h>
#define N 100
char a[N][N];
void draw_hui(int n, int r, int c, int xx, int yy)
{
	int size = n * 2, i;
	//构造四个顶点
	// a[r][c] =a[r][c + size - 1] =a[r + size - 1][c] =a[r + size - 1][c + size - 1] = '+';
	if (n == 1)
		return;
	//构造四条边
	for (i = r + 1; i < r + size - 1; ++i)
		a[i][c] = a[i][c + size - 1] = '|';
	for (i = c + 1; i < c + size - 1; ++i)
		a[r][i] = a[r + size - 1][i] = '-';
	draw_hui(n - 1, r + xx, c + yy, xx, yy); //递归构造
}
void test_hui(int xx, int yy)
{
	int i, j, n = 12;
	draw_hui(n, 0, 0, xx, yy);
	for ( i = 0; i < 2 * n; ++i)
	{
		for ( j = 0; j <2 * n; ++j)
			printf("%c", a[i][j] == '\0' ? ' ' : a[i][j] );
		printf("\n");
	}
}
int main(int argc, char const *argv[])
{
	// freopen("hui6.txt","w",stdout);
	int i, j, count = 5;
	for ( i = 0; i < count; ++i)
	{	for ( j = 0; j < count; ++j)
		{
			memset(a, '\0', sizeof(a));
			printf("%d %d\n\n", i, j );
			test_hui(i, j);
		}
	}
	return 0;
}