#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp;
    char ch;
    int bytes=0, words=1, lines=1;

    // 例外処理
    if(argc != 2){
        printf("入力された引数が異なります\n");
        exit(1);
    }
    if((fp=fopen(argv[1], "r")) == NULL){
        printf("ファイルをオープンできません\n");
        exit(1);
    }

    // カウント
    while((ch=fgetc(fp)) != EOF){
        bytes++;
        if(ch == ' ' || ch=='\n' || ch=='\t')
            words++;
        if(ch == '\n')
            lines++;
    }

    // output
    printf("%3d %3d %3d %s", lines, words, bytes, argv[1]);

    fclose(fp);
    return 0;
}