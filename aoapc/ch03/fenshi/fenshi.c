#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
int main()
{
    /* code */
    FILE *fin, *fout;
    fin = fopen("fenshi.in", "rb");
    fout = fopen("fenshi.out", "wb");
    char a[N], b[N], c[2 * N];
    memset(a, '\0', N),    memset(b, '\0', N);
    int cs=1;
    while (fscanf(fin, "%s%s", a, b) == 2)
    {
        int len1, len2, n1, n2, tot, i, j;
        len1 = strlen(a), len2 = strlen(b);
        tot = len1 + len2 + 2;
        n1 = atoi(a),n2 = atoi(b);
        fprintf(fout, "Case:%d\n\n%*s\n",cs++, tot, a );
        fprintf(fout, "x%*s\n----------\n", tot - 1, b );
        for (i = len2 - 1; i >= 0; i--)
        {
            j = n1 * (b[i] - '0');
            fprintf(fout, "%*.*d\n", tot - (len2 - i - 1), len1, j );
        }
        fprintf(fout, "----------\n%*d\n\n", tot, n1 * n2 );
        memset(a, '\0', N), memset(b, '\0', N);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
