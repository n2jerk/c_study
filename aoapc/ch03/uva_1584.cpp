#include <cstdio>
#include <cstring>
int less(char *s, int p, int q, int len)
{
    for (int i = 0; i < len; ++i)
    {
        if(s[(i + p) % len] != s[(i + q) % len])
            return s[(i + p) % len] < s[(i + q) % len];
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    int len, n = 120, ans;
    char s[n];
    while(scanf("%s", s) != EOF)
    {
        len = strlen(s), ans = 0;
        for (int i = 1; i < len; ++i)
        {
            if(less(s, i, ans, len))
                ans = i;
        }
        for (int i = 0; i < len; ++i)
        {
            printf("%c", s[(i + ans) % len]);
        }
        printf("\n");
        memset(s, '\0', n);
    }
    return 0;
}