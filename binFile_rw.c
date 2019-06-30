#include <stdio.h>
#include <stdlib.h>

#define N 100

void output(int [], int);
void add_data(int [], int *);

int main(void){

    FILE *fi;
    FILE *fo;
    int data[N];
    int n;

    if ((fi = fopen("data_file","rb")) == NULL) {
        printf("File not open:data_file\n");
        exit(EXIT_FAILURE);
    }
    // FILEからのブロック入力
    n = fread(data,sizeof(int), N, fi);
    fclose(fi);

    output(data, n);    //データの画面出力

    add_data(data, &n); //データの追加

    output(data, n);    //データの画面出力

    if ((fo = fopen("data_file","wb")) == NULL) {
        printf("File not open:data_file\n");
        exit(EXIT_FAILURE);
    }
    // FILEへのブロック出力
    fwrite(data, sizeof(int), n, fo);
    fclose(fo);

    return 0;
}

//データの画面出力
void output(int data[], int n){
    int i;

    printf("------------------- dataの内容 ---------------------\n");
    for (i=0; i<n; i++){
        if (i % 10 == 0) putchar('\n'); //10個出力毎に改行する
        printf(" %4d", data[i]);
    }
    printf("\n----------------------------------------------------\n");
}

//データの追加
void add_data(int data[], int *n){
    int tmp;

    printf("------ データの追加 -----------\n");
    printf("    追加終了^dを入力\n");
    while (scanf("%d", &tmp) != EOF){
        if (*n >= N) break;     //配列領域を超える場合は終了
        data[*n] = tmp;
        (*n)++;
    }
}