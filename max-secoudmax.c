#include<stdio.h>
#include<stdlib.h>

int main() {

    int a[10]={9,8,6,5,4,3,2,89,3,1};
    int max=a[0], smax=a[0];

    for(int i=0; i<10; ++i)
    {

       if (max<a[i])
       {
            smax=max;
            max=a[i];
       }
       else if(smax<a[i])
       {
           smax=a[i];
       }
    }

    printf("%d \n",max);
    printf("%d",smax);

    return 0;
}