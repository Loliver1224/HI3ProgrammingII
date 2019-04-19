#include <stdio.h>
int main(void){
    FILE *fp;
    char c;
    fp = fopen("alice.txt", "r");
    putchar(fgetc(fp));
    fclose(fp);

    return 0;
}