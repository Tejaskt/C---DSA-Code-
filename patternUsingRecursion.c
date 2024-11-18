#include <stdio.h>
#include <stdlib.h>

int fun1(int n){
    if(n>1){
        fun1(n-1);
    }
    printf("*\t");

}

int fun2(int n){
    if(n>1){
        fun2(n-1);
    }
    fun1(n);
    printf("\n");
}
int main()
{
    fun2(5);
    return 0;
}
