#include<iostream>
#include<cstdlib>
#include<ctime>
#define fo(i,a,b) for(i=a;i<b;i++)
#define fod(i,a,b) for(i=a;i>=b;i--)
#define mclear(q) while(!q.empty()) q.pop();
using namespace std;
template<typename T>
void my_swap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
    return;
}
/* print array */
template<typename T>
void print_array(T *a, T *b, char sep = ' ')
{
    T  *t = a;
    while(t != b)
    {
        if(t + 1 < b)
            cout << *t << sep;
        else
            cout << *t << endl;
        t++;
    }
}
/**
 * generate random array
 * parm:m min number
 * parm:n max number,n>m
 * parm:num length of random array
 */
void gen_random(int *a, int m, int n, int num )
{
    int k = n - m, i = 0;
    while(i < num)
        a[i++] = rand() % k + m;
}
template<typename T>
int is_ascend(T *a, T *b)
{
    T *t = a + 1;
    while(t != b)
    {
        if(*(t - 1) > *t)
            return 0;
        t++;
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    int a[]={1,2,3,4,5,6,7,8,9},mmax=-(1<<31),mmin=1<<31,cnt=0,i;
    do{   
        if (cnt++>100) break;
        fo(i,0,9) printf("%d",a[i]);
        printf("\n");
    }
    while(next_permutation(a,a+9));
    return 0;
}