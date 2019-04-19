#include <stdio.h>
int main(void){
    FILE *fp;
    char ch;

    fopen("tmp.txt", "w");
    fscanf(stdin, "%c", &ch);
    fputc(ch, fp);
    fclose(fp);

    return 0;
}