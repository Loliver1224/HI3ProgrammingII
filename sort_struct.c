#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SORT qsort(data, n, sizeof(dict), cmp)

typedef struct{
    char name[20];
    float height;
    float weight;
} dict;

int cmd;

void input(dict *data, int n){
    int i;
    for(i=0; i<n; i++)
        scanf("%s %f %f", data[i].name, &data[i].height, &data[i].weight);
}

void output(dict *data, int n){
    int i;
    for(i=0; i<n; i++)
        printf("%s\t%.1f %.1f\n", data[i].name, data[i].height, data[i].weight);
    putchar('\n');
}

int cmp(const void *a, const void *b){
    switch(cmd){
        case 1: return ((dict *)b)->height - ((dict *)a)->height;
        case 2: return ((dict *)a)->height - ((dict *)b)->height;
        case 3: return ((dict *)b)->weight - ((dict *)a)->weight;
        case 4: return ((dict *)a)->weight - ((dict *)b)->weight;
        case 5: return strcmp(((dict *)a)->name, ((dict *)b)->name);
        case 6: return strcmp(((dict *)b)->name, ((dict *)a)->name);
    }
}

int menu(dict *data, int n){
    puts("================= Sorting Menu =============");
    puts("    1:  身長順(高い順)   2:身長順(低い順) ");
    puts("    3:  体重順(重い順)   4:体重順(軽い順) ");
    puts("    5:  名前順(昇順)     6:名前順(降順) ");
    puts("    0:  プログラム終了");
    puts("================= Sorting Menu =============");

    reject:
    printf(">> ");
    scanf("%d", &cmd);
    putchar('\n');

    switch(cmd){
        case 1: puts("----- 身長を降順に整列 ------");
                SORT; break;
        case 2: puts("----- 身長を昇順に整列 ------");
                SORT; break;
        case 3: puts("----- 体重を降順に整列 ------");
                SORT; break;
        case 4: puts("----- 体重を昇順に整列 ------");
                SORT; break;
        case 5: puts("----- 名前を昇順に整列 ------");
                SORT; break;
        case 6: puts("----- 名前を降順に整列 ------");
                SORT; break;
        case 0: return 0;
        default:puts("\a0 ~ 6の数値を入力してください.");
                goto reject;
    }
    output(data, n);
    return cmd;
}

int main(void){
    int n;

    printf("入力するデータ個数を入力: ");
    scanf("%d", &n);
    putchar('\n');
    dict data[n];

    puts("データを入力してください（名前 身長 体重）");
    input(data, n);

    while(menu(data, n) != 0);

    return 0;
}