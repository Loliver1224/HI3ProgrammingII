#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *fp;
char ch;
int bytes=0, chars=0, words=0, lines=0;

void count(FILE *fp){
    int flg_c=0;
    while((ch=fgetc(fp)) != EOF){
        bytes++;
        if(ch=='\n')
            lines++;
        if(isspace(ch) && flg_c){
            words++;
            flg_c = 0;
        }
        if(isgraph(ch)){
            chars++;
            flg_c = 1;
        }
    }
    printf("%5d %5d %5d ", lines, words, bytes);
}

int main(int argc, char *argv[]){
    int i, b_sum = 0, w_sum = 0, l_sum = 0;

    if(argc==1){
        fp = stdin;
        count(fp);
        puts(argv[1]);
    }

    for(i=1; i<argc; i++){
        fp = fopen(argv[i], "r");
        bytes=0, chars=0, words=0, lines=0;
        count(fp);
        puts(argv[i]);
        b_sum += bytes;
        w_sum += words;
        l_sum += lines;
    }
    if(argc>2)
        printf("%5d %5d %5d 合計\n", l_sum, w_sum, b_sum);
    fclose(fp);

    return 0;
}
