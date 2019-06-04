#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000
#define M 20
#define DATA name,height,weight,sex

void io(char name[][M], double *height, double *weight, int *sex, int n, int is_in){
    int i;
    for (i = 0; i < n; i++)
        if (is_in)
            scanf("%s %lf %lf %c", name[i], &height[i], &weight[i], &sex[i]);
        else
            printf("%s\t| %.1f\t| %.1f\t|  %c\n", name[i], height[i], weight[i], sex[i]);
    putchar('\n');
}

int cmp(double a, double b, int cmd){
    switch (cmd){
        case 1:
        case 3: return b - a >= 0 ? 1 : 0;
        case 2:
        case 4: return a - b >= 0 ? 1 : 0;
    }
}

void swap_double(double *l, double *r){
    double tmp = *l;
    *l = *r;
    *r = tmp;
}

void swap_data(char name[][M], double *height, double *weight, int *sex, int l, int r){
    char tmp_name[M], tmp_sex;

    swap_double(&height[l], &height[r]);
    swap_double(&weight[l], &weight[r]);
    strcpy(tmp_name, name[l]);
    strncpy(name[l], name[r], M);
    strncpy(name[r], tmp_name, M);
    tmp_sex = sex[l];
    sex[l] = sex[r];
    sex[r] = tmp_sex;
}

void sort(char name[][M], double *height, double *weight, int *sex, int n, int cmd){
    int i, j, cmp_result;
    double *data = cmd <= 2 ? height : weight;

    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if(cmd <= 4){
                if (cmp(data[j], data[j + 1], cmd))
                    swap_data(DATA, j, j + 1);
            }else{
                cmp_result = strcmp(name[j], name[j + 1]);
                if (cmd%5 ? cmp_result < 0 : cmp_result > 0)
                    swap_data(DATA, j, j + 1);
            }
}

int menu(char name[][M], double *height, double *weight, int *sex, int n){
    int cmd;

    puts("=============== Sorting Menu ===============");
    puts("    1:  身長順(高い順)   2:身長順(低い順) ");
    puts("    3:  体重順(重い順)   4:体重順(軽い順) ");
    puts("    5:  名前順(昇順)     6:名前順(降順) ");
    puts("    0:  プログラム終了");
    puts("=============== Sorting Menu ===============");
    reject:
    printf(">> ");
    scanf("%d", &cmd);
    putchar('\n');

    switch (cmd){
        case 1: puts("------ 身長を降順に整列 ------"); break;
        case 2: puts("------ 身長を昇順に整列 ------"); break;
        case 3: puts("------ 体重を降順に整列 ------"); break;
        case 4: puts("------ 体重を昇順に整列 ------"); break;
        case 5: puts("------ 名前を昇順に整列 ------"); break;
        case 6: puts("------ 名前を降順に整列 ------"); break;
        case 0: return 0;
        default:puts("\a0 ~ 6の数値を入力してください.");
                goto reject;
    }
    sort(DATA, n, cmd);
    puts("名前\t|  身長\t|  体重\t| 性別");
    puts("------------------------------");
    io(DATA, n, 0);
    return cmd;
}

int main(void){
    int n, sex[N];
    char name[N][M];
    double height[N], weight[N];

    printf("入力するデータ個数を入力: ");
    scanf("%d", &n);
    puts("\nデータを以下の形式で一行ごとに入力してください");
    puts("名前 身長 体重 性別（M / F）");
    io(DATA, n, 1);
    while (menu(DATA, n) != 0);

    return 0;
}