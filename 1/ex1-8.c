#include <stdio.h>
int main(void){
    FILE *fi, *fo;
    int n;
    fi = fopen("num.txt", "r");
    fo = fopen("tmp.txt", "w");
    fprintf(fo, "%d", fscanf(fi, "%d", &n));
    fclose(fo);
    fclose(fi);

    return 0;
}