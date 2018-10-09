#include <cstdio>
#include <cstring>
using namespace std;
//molar mass
int main(int argc, char const *argv[])
{
    double m[128], mass = 0;
    m['C'] = 12.01, m['H'] = 1.008, m['O'] = 16.00, m['N'] = 14.01;
    char s[100] = {'\0'}, ele;
    int n, i, len;
    while(scanf("%s", s) != EOF)
    {
        len = strlen(s);
        mass = 0, i = 0;
        while(i < len)
        {
            ele = s[i], n = 0;
            i++;
            while(s[i] >= '0' && s[i] <= '9')
                n = n * 10 + s[i] - '0', i++;
            if (!n)n = 1;
            mass += m[ele] * n;
        }
        printf("%.3f\n", mass);
        memset(s, '\0', sizeof(s));
    }
    return 0;
}