#include <cstdio>
//pointer
void swap_int1(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
// reference
void swap_int2(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
//
void swap_int3(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
//
void swap_int4(int *a, int *b)
{
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
    //a^=b^=a^=b;
}
template<typename T>
void swap_object(T *a, T *b)
{
    T t = *a;
    *a = *b;
    *b = t;
}
void test_fun(void (*f)(int *, int *))
{
    int a = 3, b = 4;
    printf("%d %d\n", a, b);
    (*f)(&a, &b);
    printf("%d %d\n", a, b);
}
void test()
{
    test_fun(swap_int1);
    test_fun(swap_int3);
    test_fun(swap_int4);
    test_fun(swap_object);
}
int main(int argc, char const *argv[])
{
    // test();
    int a,b;
    a=3,b=4;
    printf("%d %d\n",a,b );
    swap_int1(&a,&b);
    printf("%d %d\n",a,b );
    a=3,b=4;
    printf("%d %d\n",a,b );
    swap_int2(a,b);
    printf("%d %d\n",a,b );

    return 0;
}