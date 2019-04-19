#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fi;
    char ss[1024], ch;
    int bytes=0, words=1, lines=0;

    if(argc != 2){
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
    printf("%3d %3d %3d %s\n", lines, words, bytes, argv[1]);

    fclose(fi);

    return 0;
}