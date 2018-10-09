#include <stdio.h>
#define N 100
char a[N][N];
void draw_bagua(int n, int r, int c)
{
	int  vl = 2 * n, size = vl * 3 + 2, i, t = (size - vl) / 2, x;
	if (n == 0)
		return;
	for (i = 0; i < vl; ++i) {
//上下横线
		a[r][c + t + i] = a[r + size - 1][c + t + i] = '-';
//左右竖线
		a[r + t + i][c] = a[r + t + i][c - 1 + size] = '|';
// 上半部斜线
		a[r + 1 + i][c + t - i - 1] = '/';
		a[r + 1 + i][c + t + vl + i ] = '\\';
//下半部斜线
		a[r + t + vl + i][c  + 1 + i] = '\\';
		a[r + t + vl + i][c + size - 2 - i ] = '/';
	}
	draw_bagua(n - 1, r + 3, c + 3);
} 
void test_bagua()  /* code */
{
	int i, j, n = 4;
	draw_bagua(n, 0, 0);
	for ( i = 0; i < 6 * n + 2; ++i)
	{
		for ( j = 0; j < 6 * n + 2; ++j)
			printf("%c", a[i][j] == '\0' ? ' ' : a[i][j] );
		printf("\n");
	}
}
int main(int argc, char const *argv[])
{
	test_bagua();
	return 0;
}