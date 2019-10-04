/* データ読み込み・ソート用のプログラム */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100
#define NAME_LEN 20

typedef struct{
    int number; // 出席番号
    char name[NAME_LEN];
    int result[3]; // ３科目の成績
    // int avg;       // 平均点
} Students;

int cmd;
int cmd4subject;

void output(Students *, int);
int menu(Students *, int );
int cmp(const void *, const void *);

int main(void){
    FILE *fi;
    Students data[N];
    int n;

    if ((fi = fopen("seiseki_data", "rb")) == NULL){
        printf("File not open:seiseki_data\n");
        exit(EXIT_FAILURE);
    }
    // FILEからのブロック入力
    n = fread(data, sizeof(Students), N, fi);
    fclose(fi);

    output(data, n);
    while (menu(data, n) != 0);

    return 0;
}

int menu(Students *data, int n){
    char subjects[][7] = {"国語", "数学", "英語"};

    puts("\n============== Sorting Menu ================");
    puts("    1: 出席番号順(昇順)    2: 名前順(辞書順)");
    puts("    3: 科目成績順(降順)");
    puts("    0: プログラム終了");
    puts("============== Sorting Menu =================");

    reject:
    printf(">> ");
    scanf("%d", &cmd);
    putchar('\n');

    switch (cmd){
        case 1:
            puts("    ----- 出席番号を昇順に整列 ------    "); break;
        case 2:
            puts("    ----- 名前を辞書順に整列 ------    "); break;
        case 3:
            puts("どの科目の成績順にしますか");
            printf("%s...1  %s...2  %s...3\n", subjects[0], subjects[1], subjects[2]);
            printf(">> ");
            scanf("%d", &cmd4subject);
            printf("    ----- %sの成績を降順に整列 -----    \n", subjects[cmd4subject-1]);
            break;
        case 0: puts("Bye."); return 0;
        default:
            puts("\a0 ~ 6の数値を入力してください.");
            goto reject;
    }
    qsort(data, n, sizeof(Students), cmp);
    output(data, n);

    return cmd;
}

/* compare-func4qsort */
int cmp(const void *a, const void *b){
    switch (cmd){
        case 1: return ((Students *)a)->number - ((Students *)b)->number;
        case 2: return strcmp(((Students *)a)->name, ((Students *)b)->name);
        case 3: return ((Students *)b)->result[cmd4subject - 1] - ((Students *)a)->result[cmd4subject - 1];
    }
}

void output(Students *data, int n){
    int i;

    puts("| 出席番号 |    名前    | 国語 | 数学 | 英語 |");
    puts("----------------------------------------------");
    for (i = 0; i < n; i++){
        printf("|%9d | %-10s | %4d | %4d | %4d |\n", data[i].number, data[i].name, data[i].result[0], data[i].result[1], data[i].result[2]);
    }
}
