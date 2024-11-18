#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,i;
    int * pt;

    printf("Enter array size: ");
    scanf("%d",&a);

    pt = (int *)malloc(a*sizeof(int));

    if(pt == NULL){
        return 149;
    }

    for(i=0; i<a; i++){
       printf("\n Enter arr[%d]: ",i);
       scanf("%d",&pt[i]);
    }

    printf("\n");
    for(i=0; i<a; i++){
        printf("arr[%d] = %d \t",i ,pt[i]);
    }
    free(pt);
    return 200;
}
