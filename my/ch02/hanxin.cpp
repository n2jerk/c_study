#include <cstdio>
int main(int argc, char const *argv[])
{
    /**
     * a<3;b<5;c<7
     * i∈[10,100]
     */
    int a, b, c, i;
    while(scanf("%d%d%d", &a, &b, &c) == 3)
    {
        for(i = 10; i < 101; i++)
        {
            if (i % 3 == a && i % 5 == b && i % 7 == c)
            {
                printf("%d\n", i);
                break;
            }
        }
        if (i == 101)
            printf("no answer\n");
    }
    return 0;
}