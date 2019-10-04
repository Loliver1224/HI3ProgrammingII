#include <stdio.h>
int main(void){
    FILE *fi, *fo;
    fi = fopen("alice.txt", "r");
    fo = fopen("tmp.txt", "w");
    fputc(fgetc(fi), fo);
    fclose(fo);
    fclose(fi);

    return 0;
}