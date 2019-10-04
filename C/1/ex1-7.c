#include <stdio.h>
int main(void){
    FILE *fp;
    int n;
    fp = fopen("tmp.txt", "r");
    printf("%d\n", fscanf(fp, "%d", &n));
    fclose(fp);

    return 0;
}