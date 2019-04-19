#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fi;
    char ss[1024], ch;
    int bytes=0, words=1, lines=1;

    if(argc != 3){
        printf("入力された引数が異なります\n");
        exit(1);
    }

    if((fi=fopen(argv[1], "r")) == NULL){
        printf("ファイルをオープンできません\n");
        exit(1);
    }

    while((ch=fgetc(fi)) != EOF){
        bytes++;
        if(ch == ' ')
            words++;
        if(ch == '\n')
            lines++;
    }
    printf("%d %d %d\n", lines, words, bytes);

    fclose(fi);

    return 0;
}