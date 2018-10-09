#include <cstdio>
int main(int argc, char const *argv[])
{
    int num, legs, rabbit, hen;
    while(scanf("%d%d", &num, &legs) == 2 && num)
    {
        hen = (4 * num - legs) / 2;
        rabbit = num - hen;
        if(legs % 2 || hen < 0 || rabbit < 0)
            printf("no answer\n");
        else
            printf("rabbit=%d hen=%d\n", rabbit, hen);
    }
    return 0;
}