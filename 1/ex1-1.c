#include <stdio.h>
int main(void){
    FILE *fp;
    char ch;
    fp = fopen("alice.txt", "r");
    while((ch=fgetc(fp)) != NULL)
        putchar(fgetc(fp));
    fclose(fp);

    return 0;
}