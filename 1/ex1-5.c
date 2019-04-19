#include <stdio.h>
int main(void){
    FILE *fi, *fo;
    char ss[256];
    fi = fopen("alice.txt", "r");
    fo = fopen("tmp.txt", "w");
    fputs(fgets(ss, 256, fi), fo);
    fclose(fo);
    fclose(fi);

    return 0;
}