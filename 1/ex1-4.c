#include <stdio.h>
int main(void){
    FILE *fp;
    char ss[256];
    fp = fopen("alice.txt", "r");
    puts(fgets(ss, 256, fp));
    fclose(fp);

    return 0;
}