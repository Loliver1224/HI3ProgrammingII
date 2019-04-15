#include <stdio.h>

int factrial(int n){
    int ans=1;
    do{
        ans *= n--;
    }while(n);
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