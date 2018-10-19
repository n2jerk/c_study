#include <iostream>
#include <cstdlib>
#include<vector>
using namespace std;
typedef struct  data
{
    int d;
    struct data *l, *r;
}node ;
void print_tree(node b)
{
    if(b != NULL)
    {
        printf("%d ", b->d-'0');
        if(b->l != NULL)
            print_tree(b->l);
        if(b->r != NULL)
            print_tree(b->r);
    }
}
node *create_tree(char a[], int n, int N)
{
    if (a[n] == '#' || n > N) return NULL;
    node *b = (node *) malloc(sizeof(node));
    b->d= a[n];
    b->l = create_tree(a, 2 * n, N);
    b->r = create_tree(a, 2 * n + 1, N);
    return b;
}
int main(int argc, char const *argv[])
{
    char c[] = {'#', '1', '2', '3', '#', '4', '5', '6'};
    node *b = create_tree(c, 1, 7);
     print_tree(b);
    return 0;
}