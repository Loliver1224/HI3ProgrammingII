#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp;
    char ch;
    int bytes=0, words=1, lines=1;

    // exception
    if(argc != 2){
        puts("The input argument is incorrect.");
        exit(1);
    }
    if((fp=fopen(argv[1], "r")) == NULL){
        puts("Cannot open file.");
        exit(1);
    }

    // count
    while((ch=fgetc(fp)) != EOF){
        bytes++;
        if(ch == ' ' || ch=='\n' || ch=='\t')
            words++;
        if(ch == '\n')
            lines++;
    }

    // output
    printf("%3d %3d %3d %s\n", lines, words, bytes, argv[1]);

    fclose(fp);
    return 0;
}