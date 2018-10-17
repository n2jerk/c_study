#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 30
/**
 * [add 加法]
 * @param a [description]
 * @param b [description]
 * @param c [description]
 */
void add(char *a, char *b, char *c)
{
    int alen, blen, i, j, k, carry, t;
    alen = strlen(a), blen = strlen(b);
    char d[N];
    k = 0, carry = 0;
    alen--,    blen--;
    while ( alen >= 0 || blen >= 0) //防止i,j 同时为0
    {
        i = alen >= 0 ? a[alen] - '0' : 0;
        j = blen >= 0 ? b[blen] - '0' : 0;
        t = i + j + carry;
        if (t > 9)
        {
            carry = 1;
            t -= 10;
        }
        else
            carry = 0;
        d[k++] = t + '0';
        alen--, blen--;
    }
    //处理尾巴,如果有进位,加1,相反,讲数组下标移至正确位置
    if (carry) d[k++] = '1';
    i = 0;
    while (--k >= 0)
        c[i++] = d[k];
}
/*void swap(char *a, char *b)
{
    char t[N];
    strcpy(t, a);
    strcpy( a, b);
    strcpy(b, t);
}*/
void swap(char *a, char *b)
{
    char t[N];
    memcpy(t, a, N * sizeof(char));
    memcpy( a, b, N * sizeof(char));
    memcpy(b, t, N * sizeof(char));
}
/**
 * [minus 减法]
 * @param a [description]
 * @param b [description]
 * @param c [description]
 */
void minus(char *a, char *b, char *c)
{
    int alen, blen, i, j, k, carry, t, flag = 0;
    alen = strlen(a), blen = strlen(b);
    char d[N];
    if(alen < blen || (alen == blen && (strcmp(b, a) > 0)))
    {
        swap(a, b);
        flag = !flag;
    }
    alen = strlen(a), blen = strlen(b);
    k = 0, carry = 0;
    alen--,    blen--;
    while ( alen >= 0 || blen >= 0) //防止i,j 同时为0
    {
        i = alen >= 0 ? a[alen] - '0' : 0;
        j = blen >= 0 ? b[blen] - '0' : 0;
        t = i - j + carry;
        if (t < 0)
        {
            carry = -1;
            t += 10;
        }
        else
            carry = 0;
        d[k++] = t + '0';
        alen--, blen--;
    }
    i = flag ? 1 : 0;
    while(--k >= 1 && d[k] == '0');
    while (k >= 0)
    {
        c[i++] = d[k--];
    }
    c[i] = '\0';
    if(flag)
    {
        c[0] = '-';
        swap(a, b);
    }
}
void mult(char *a, char *b, char *c)
{
    int alen = strlen(a), blen = strlen(b), i, j, carry, t;
    int ia[alen + 1], ib[blen + 1], ic[alen + blen + 1];
    memset(ic, 0, sizeof(ic));
    for(i = 0; i < alen; i++)
    {
        ia[alen - i ] = a[i] - '0';
    }
    for(i = 0; i < blen; i++)
    {
        ib[blen - i] = b[i] - '0';
    }
    for(i = 1; i < alen + 1; i++)
    {
        carry = 0;
        for(j = 1; j < blen + 1; j++)
        {
            ic[i + j - 1] += (ia[i] * ib[j] + carry);
            carry = ic[i + j - 1] / 10;
            ic[i + j - 1] %= 10;
        }
    }
    ic[alen + blen] += carry;
    int clen = sizeof(ic) / sizeof(int);
    for(i = clen - 1; i > 1 && ic[i] == 0; i--);
    j = 0;
    while(i >= 1)
    {
        c[j++] = ic[i--] + '0';
    }
    c[j] = '\0';
}
int cmp(char *a, int i, int j, char *b, int m, int n)
{
    if(j - i > n - m)
        return 1;
    else if(j - i < n - m) reutrn - 1;
    char t1[N] = {'\0'}, t2[N] = {'\0'};
    int x, y;
    for(x = 0; i < j; i++)
        t1[x++] = a[i];
    for(x = 0; m < n; m++)
        t2[x++] = b[m];
    return strcmp(t1, t2);
}
/**
 * [divd a/b]
 * @param a [description]
 * @param b [description]
 * @param c [description]
 */
void divd(char *a, char *b, char *c)
{
    int alen = strlen(a), blen = strlen(b);
    if[a[0] == '0']
    {
        c[0] = '0';
        c[1] = '\0';
        return ;
    }
    if[b[0] == '0']
    {
        c[0] = 'e';
        c[1] = '\0';
        return ;
    }
    int mod = 1, i = 0, j = 1,  k = 0, r = 0, cnt = 0, dot = 0, maxL = 20;
    char t[N],tmp[N];
    while(cnt++ < maxL)
    {
        if(cmp(a, i, j, b, 0, blen) < 0)
        {
            c[k++] =  '0';
            if(!dot)
            {
                c[k++] = '.';
                dot = !dot;
            }
            a[alen++] = '0';
            j++;
        }
        else if(cmp(a, i, j, b, 0, blen) == 0)
        {
            c[k++] = '1';
            break;
        }
        else
        {
            r=0;
            while()
        }
    }
    c[k] = '\0';
}
int main()
{
    FILE *fin, *fout;
    fin = fopen("big_mult.in", "rb");
    fout = fopen("big_mult.out", "wb");
    char a[N] = {'\0'}, b[N] = {'\0'}, c[N * 2] = {'\0'};
    while (fscanf(fin, "%s%s", a, b) == 2)
    {
        mult(a, b, c);
        fprintf(fout, "%s * %s = %s %d\n", a, b, c, atoi(a)*atoi(b));
    }
    fclose(fin);
    fclose(fout);
    return 0;
}