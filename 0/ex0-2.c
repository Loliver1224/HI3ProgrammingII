#include <stdio.h>

int factrial(int n){
    // return n==1 ? 1 : n*factrial(n-1);
    int ans=1;
    while(n)
        ans *= n--;
    return ans;
}

int main(void){
    int n;
    do{
        scanf("%d", &n);
    }while(n<0 || n>12);
    printf("%d\n", factrial(n));
    return 0;
}