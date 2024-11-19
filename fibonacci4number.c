#include <stdio.h>

// fibonacci using recursion and untill 4 number
int fibonacci(int n) {
    if (n <= 1)
        return n;
    if(n == 2){
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    else if( n == 3){
        return fibonacci(n - 1) + fibonacci(n - 2) + fibonacci(n - 3);
     }
    else{
        return fibonacci(n - 1) + fibonacci(n - 2) + fibonacci(n - 3) + fibonacci(n - 4);
    }
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}
