/* データ登録用のプログラム */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000
#define NAME_LEN 20

typedef struct{
    int number;  // 出席番号
    char name[NAME_LEN];
    int result[3];  // ３科目の成績
    // int avg;  // 平均点
} Dict;

// void output(data[], int);
void add_data(Dict *, int *);

int main(void){

    FILE *fi;
    FILE *fo;
    Dict data[N];
    int n;

    if ((fi = fopen("data_file_s", "rb")) == NULL){
        printf("File not open:data_file\n");
        exit(EXIT_FAILURE);
    }
    // FILEからのブロック入力
    n = fread(data, sizeof(Dict), N, fi);
    fclose(fi);

    // output(data, n); // データの画面出力

    add_data(data, &n); // データの追加

    // output(data, n); // データの画面出力

    if ((fo = fopen("seiseki_data", "wb")) == NULL){
        printf("File not open:seiseki_data\n");
        exit(EXIT_FAILURE);
    }
    // FILEへのブロック出力
    fwrite(data, sizeof(Dict), n, fo);
    fclose(fo);

    return 0;
}

// データの追加
void add_data(Dict *data, int *n){
    Dict tmp;

    puts("------ データの追加 -----------");
    puts("出席番号　名前　成績1　成績2　成績3");
    // printf("    追加終了:^dを入力\n");
    while (scanf("%d %s %d %d %d", &tmp.number, tmp.name, &tmp.result[0], &tmp.result[1], &tmp.result[2]) != EOF){
        if (*n >= N)
            break; // 配列領域を超える場合は終了
        data[*n] = tmp;
        (*n)++;
    }
}
