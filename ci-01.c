#include <stdio.h>
#include <string.h>

typedef struct travel{
    char city[100];
    int length;
} Travel;

int main(void){
    Travel data[101];
    Travel *pt = data;
    int i, n=0, sum=0;

    while(1){
        scanf("%s", pt->city);
        if(!strcmp(pt->city, "END")) break;
        scanf("%d", &pt->length);
        pt++;
        n++;
    }
    for(i=0, pt=data; i<n; i++){
        printf("%s %d\n", pt->city, pt->length);
        sum += pt->length;
        pt++;
    }
    printf("\n%d\n", sum);

    return 0;
}