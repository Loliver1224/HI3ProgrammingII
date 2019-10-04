#include <stdio.h>
int main(void){
    int a;
    int b;

    printf("身長と体重を入力");
    scanf("%d%lf", &a, &b);
    printf("%d%f", a, b);

    return 0;
}