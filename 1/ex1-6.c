#include <stdio.h>
int main(void){
    FILE *fp;
    char ss[256];

    fopen("tmp.txt", "w");
    fscanf(stdin, "%s", ss);
    fputs(ss, 256, fp);
    fclose(fp);

    return 0;
}