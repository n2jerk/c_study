#include<stdio.h>
int main() {
	FILE *fin, *fout;
	int a, b, c, q;
	fin = fopen("fen2xiaoshu.in", "rb");
	fout = fopen("fen2xiaoshu.out", "wb");
	while (fscanf(fin, "%d%d%d", &a, &b, &c) == 3)
	{
		fprintf(fout, "%d%c", a / b,c>0?'.':' ');
		a %= b;
		while (c--) {
			a *= 10;
			q = a / b;
			a %= b;
			if (c == 0 && a * 10 / b >= 5) q++;
			fprintf(fout, "%d", q );
		}
		fprintf(fout, "\n" );
	}
	fclose(fin);
	fclose(fout);
	return 0;
}