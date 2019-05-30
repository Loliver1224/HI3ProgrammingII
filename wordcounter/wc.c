#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define mystrchr(c) strchr(argv[i], c)
#define mystrstr(s) strstr(argv[i], s)

FILE *fp;
int bytes, chars, words, lines, line_len, max_L;
int c_sum, l_sum, m_sum, w_sum, total_maxL = -1;
bool flg_c, flg_l, flg_m, flg_w, flg_L;

output(bool sum){
    if(flg_l)
        printf("%5d ", sum ? l_sum : lines);
    if(flg_w)
        printf("%5d ", sum ? w_sum : words);
    if(flg_m)
        printf("%5d ", sum ? m_sum : chars);
    if(flg_c)
        printf("%5d ", sum ? c_sum : bytes);
    if(flg_L)
        printf("%5d ", sum ? total_maxL : max_L);
    if(sum)
        puts("合計");
}

count(bool s_in){
    int ch;
    bool flg_in_c = false;
    bytes=0, chars=0, words=0, lines=0;
    max_L = -1;

    while((ch=fgetc(fp)) != EOF){
        bytes++;
        line_len++;
        if(ch=='\n'){
            lines++;
            max_L = MAX(max_L, line_len-1);
            line_len = 0;
        }
        if(isspace(ch) && flg_in_c){
            words++;
            flg_in_c = false;
        }
        if(isgraph(ch))
            flg_in_c = true;
        if(ch<0x80 || ch>0xBF)
            chars++;
    }
    if(max_L < 0)
        max_L = line_len;
    total_maxL = MAX(total_maxL, max_L);
    if(s_in)
        words++;
    output(false);
}

print_help(){
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
}

main(int argc, char **argv){
    int i, opt_args=0;

    for(i=1; i<=argc; i++){
        if(i<argc && argc>1){
            if(mystrstr("--help")){
                print_help();
                exit(0);
            }
            if(mystrstr("--version")){
                puts("my_wc 1.0");
                exit(0);
            }
        }
        if(argc==1 || (argc>1 && i<argc && argv[1][0] != '-')){
            flg_c = true;
            flg_w = true;
            flg_l = true;
        }else if(i<argc && argv[i][0] == '-'){
            opt_args++;
            if((mystrchr('c') && !mystrstr("ch")) || mystrstr("--bytes"))
                flg_c = true;
            if((mystrchr('l') && !mystrstr("li") && !mystrstr("le")) || mystrstr("--lines"))
                flg_l = true;
            if((mystrchr('m') && !mystrstr("max")) || mystrstr("--chars"))
                flg_m = true;
            if(mystrchr('w') || mystrstr("--words"))
                flg_w = true;
            if(mystrchr('L') || mystrstr("--max-line-length"))
                flg_L = true;
        }
        if(argc-opt_args == 1){
            fp = stdin;
            count(true);
            puts("");
            exit(0);
        }else if(i<argc && argv[i][0] != '-'){
            if((fp=fopen(argv[i], "r")) == NULL){
                puts("Cannot open file.");
                exit(1);
            }
            count(false);
            puts(argv[i]);
            fclose(fp);
            c_sum += bytes;
            l_sum += lines;
            m_sum += chars;
            w_sum += words;
        }
    }
    if(argc-1 > opt_args+1)
        output(true);
}