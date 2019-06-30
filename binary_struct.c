#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000
#define NAME_LEN 20

typedef struct dtype{
    char name[NAME_LEN];
    int age;
    double height, weight;
    int sex;
} Dtype;

void output(Dtype[], int);
void add_data(Dtype[], int *);

int main(void){

    FILE *fi;
    FILE *fo;
    Dtype data[N];
    int n;

    printf("size of struct: %ld\n", sizeof(Dtype));

    if ((fi = fopen("data_file_s", "rb")) == NULL){
        printf("File not open:data_file\n");
        exit(EXIT_FAILURE);
    }
    // FILEからのブロック入力
    n = fread(data, sizeof(Dtype), N, fi);
    fclose(fi);

    output(data, n); // データの画面出力

    add_data(data, &n); // データの追加

    output(data, n); // データの画面出力

    if ((fo = fopen("data_file_s", "wb")) == NULL){
        printf("File not open:data_file\n");
        exit(EXIT_FAILURE);
    }
    // FILEへのブロック出力
    fwrite(data, sizeof(Dtype), n, fo);
    fclose(fo);

    return 0;
}

// データの画面出力
void output(Dtype data[], int n){
    int i;

    printf("------------------- dataの内容 ---------------------\n");
    for (i = 0; i < n; i++){
        printf("%-20s %4d %5.1f %5.1f %c\n", data[i].name, data[i].age, data[i].height, data[i].weight, data[i].sex);
    }
    printf("\n----------------------------------------------------\n");
}

// データの追加
void add_data(Dtype data[], int *n){
    Dtype tmp;

    printf("------ データの追加 -----------\n");
    printf("    追加終了:^dを入力\n");
    while (scanf("%s %d %lf %lf %lc", tmp.name, &tmp.age, &tmp.height, &tmp.weight, &tmp.sex) != EOF){
        if (*n >= N)
            break; // 配列領域を超える場合は終了
        data[*n] = tmp;
        (*n)++;
    }
}

// データの比較
/*
int cmp(const void *a, const void *b){
    switch (cmd){
    case 1: // name辞書順
        return strcmp(((Dtype *)a)->name, ((Dtype *)b)->name);
    case 2: // name逆順
        return strcmp(((Dtype *)b)->name, ((Dtype *)a)->name);
    case 3: // age降順
        return ((Dtype *)b)->age - ((Dtype *)a)->age;
    case 4: // age 昇順
        return ((Dtype *)a)->age - ((Dtype *)b)->age;
    }
}
*/