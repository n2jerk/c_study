#include <cstdio>
#define N 9
#define base 1000
long a[8916]={1,0},n,i,c,len; 
int main(void)  
{ 
    n=N; 
    for ( len=1;n>1; n--) 
    { 
        for (c=0,i=0; i<len;i++ ) 
        { 
            a[i]= ( c+= a[i]*n ) % base; c/=base; 
        } 
         
        ((a[i]=c)>0)?len++:0; 
 
    }    
    for( len--,printf("%d",a[len--]);len>=0; len--) printf("%04d",a[len]); 
         
    return 0; 
}
 
