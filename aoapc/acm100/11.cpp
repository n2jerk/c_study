#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main(int argc, char const *argv[])
{
    char a[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int mmax = 123456789, mmin = 987654321, t;
    char buf[11];
    do
    {
        sprintf(buf, "%s", a);
        t = atoi(buf);
        if (t % 11 == 0)
        {
            if (mmax < t)mmax = t;
            if (mmin > t)mmin = t;

        }
    }
    while(next_permutation(a, a + 9));
    printf("%d %d\n", mmax, mmin);

    return 0;
}