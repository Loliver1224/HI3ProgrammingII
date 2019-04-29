#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define mystrchr(c) strchr(argv[i], c)
#define mystrstr(s) strstr(argv[i], s)

FILE *fp;
char ch;
int bytes=0, chars=0, words=0, lines=0, line_length=0, max_L=0, options=0;
bool flg_c=false, flg_l=false, flg_m=false, flg_w=false, flg_L=false;
bool flg_help=false, flg_version=false;

void cout(void){
    if(flg_l)
        printf("%5d ", lines);
    if(flg_w)
        printf("%5d ", words);
    if(flg_m)
        printf("%5d ", chars);
    if(flg_c)
        printf("%5d ", bytes);
    if(flg_L)
        printf("%5d ", max_L);
}

void count(FILE *fp){
    bool flg_in_c = false;
    while((ch=fgetc(fp)) != EOF){
        bytes++;
        line_length++;
        if(ch=='\n'){
            lines++;
            max_L = MAX(max_L, line_length);
            line_length = 0;
        }
        if(isspace(ch) && flg_in_c){
            words++;
            flg_in_c = 0;
        }
        if(isgraph(ch)){
            chars++;
            flg_in_c = true;
        }
    }
    cout();
}

int main(int argc, char *argv[]){
    int i, c_sum = 0, l_sum = 0, m_sum=0, w_sum = 0;

    // 標準入力からのは後回し
    /*if(argc==1){
        fp = stdin;
        count(fp);
        puts(argv[1]);
    }*/

    for(i=1; i<argc; i++){
        if(strstr(argv[i], "--help")){
            puts("Usage: wc [OPTION]... [FILE]...");
            puts("  or:  wc [OPTION]... --files0-from=F");
            puts("Print newline, word, and byte counts for each FILE, and a total line if");
            puts("more than one FILE is specified.With no FILE, or when FILE is -,");
            puts("read standard input.");
            puts("  -c, --bytes print the byte counts");
            puts("  -m, --chars print the character counts");
            puts("  -l, --lines print the newline counts");
            puts("      -- files0 - from = F read input from the files specified by");
            puts("                             NUL - terminated names in file F;");
            puts("                             If F is - then read names from standard input");
            puts("  -L, --max - line - length print the length of the longest line");
            puts("  -w, --words print the word counts");
            puts("      -- help この使い方を表示して終了");
            puts("      -- version バージョン情報を表示して終了 ");
            exit(1);
        }
        if(strstr(argv[i], "--version")){
            puts("my_wc 1.0");
            exit(1);
        }
        if(argv[1][0] != '-'){
            flg_c = true;
            flg_w = true;
            flg_l = true;
        }else if(argv[i][0] == '-'){
            options++;
            if (mystrchr('c') || mystrstr("--bytes"))
                flg_c = true;
            if (mystrchr('l') || mystrstr("--lines"))
                flg_l = true;
            if (mystrchr('m') || mystrstr("--chars"))
                flg_m = true;
            if (mystrchr('w') || mystrstr("--words"))
                flg_w = true;
            if (mystrchr('L') || mystrstr("--max-line-length"))
                flg_L = true;
        }
        if(i>options){
            fp = fopen(argv[i], "r");
            bytes=0, chars=0, words=0, lines=0;
            count(fp);
            puts(argv[i]);
            c_sum += bytes;
            l_sum += lines;
            m_sum += chars;
            w_sum += words;
        }
    }
    if(argc-1>options+1)
        printf("%5d %5d %5d 合計\n", l_sum, w_sum, c_sum);
    fclose(fp);

    return 0;
}