#include <stdio.h>
int main()
{
    int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    printf("%p\n",a);
    printf("%d\n",*(*a));
    printf("%p\n",&a[0][1]);
    printf("%d\n",a[0][1]);
    printf("%p\n",&a[0][0]);
    printf("%d\n",*(&a[0][0]));
    //printf("%p\n",&a[1][0]);
    printf("%p\n",(&(a[0][0])+1));
    printf("%d\n",*(&(a[0][0])+1));
    printf("%p\n",a+1);
    printf("%d\n",*(*(a+1)+1));
    printf("%p\n",&a[0]+1);
    printf("%d\n",*(*(&a[0]+1)));
    


}