/* データ読み込み・ソート用のプログラム */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000
#define NAME_LEN 20

typedef struct{
    int number; // 出席番号
    char name[NAME_LEN];
    int result[3]; // ３科目の成績
    // int avg;       // 平均点
} Dict;

int cmd;
int subCmd;

void output(Dict *, int);
int menu(Dict *, int );
int cmp(const void *, const void *);

int main(void){
    FILE *fi;
    Dict data[N];
    int n;

    if ((fi = fopen("data_file_s", "rb")) == NULL){
        printf("File not open:data_file\n");
        exit(EXIT_FAILURE);
    }
    // FILEからのブロック入力
    n = fread(data, sizeof(Dict), N, fi);
    fclose(fi);

    output(data, n);
    while (menu(data, n) != 0);

    return 0;
}

int menu(Dict *data, int n){
    char subjects[][8] = {"国語", "数学", "英語"};

    puts("\n============== Sorting Menu =============");
    puts("    1:  出席番号順(昇順)    2:名前順(辞書順)");
    puts("    3:  科目成績順(降順)");
    puts("    0:  プログラム終了");
    puts("============== Sorting Menu ==============");

    reject:
    printf(">> ");
    scanf("%d", &cmd);
    putchar('\n');

    switch (cmd){
    case 1:
        puts("----- 出席番号を昇順に整列 ------"); break;
    case 2:
        puts("----- 名前を辞書順に整列 ------"); break;
    case 3:
        puts("どの科目の成績順にしますか");
        puts("国語...1  数学...2  英語...3");
        scanf("%d", &subCmd);
        printf("----- %sの成績を降順に整列 ------\n", subjects[subCmd-1]); break;
    case 0: return 0;
    default:
        puts("\a0 ~ 6の数値を入力してください.");
        goto reject;
    }
    qsort(data, n, sizeof(Dict), cmp);
    output(data, n);

    return cmd;
}

int cmp(const void *a, const void *b){
    switch (cmd){
        case 1: return ((Dict *)a)->number - ((Dict *)b)->number;
        case 2: return strcmp(((Dict *)a)->name, ((Dict *)b)->name);
        case 3: return ((Dict *)b)->result[subCmd - 1] - ((Dict *)a)->result[subCmd - 1];
    }
}

// データの画面出力
void output(Dict *data, int n){
    int i;

    puts("| 出席番号 |    名前    | 国語 | 数学 | 英語 |");
    puts("-------------------------------------------");
    for (i = 0; i < n; i++){
        printf("|%9d | %-10s | %4d | %4d | %4d |\n", data[i].number, data[i].name, data[i].result[0], data[i].result[1], data[i].result[2]);
    }
}
