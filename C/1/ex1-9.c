#include <stdio.h>
int main(void){
    FILE *fp;
    int n;

    fscanf(stdin, "%d", &n);
    fopen("tmp.txt", "w");
    fprintf(fp, "%d", n);
    fclose(fp);

    return 0;
}