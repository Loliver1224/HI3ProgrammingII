#include <stdio.h>

int sum(int n){
    // return n==1 ? 1 : n + sum(n-1);
    int sum=0;
    for(; n; n--)
        sum += n;
    return sum;
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("%d\n", sum(n));
    return 0;
}