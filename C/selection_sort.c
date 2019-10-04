#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTS 100  // 要素数
#define DIGIT 100    // 要素内の数値の上限-1

void store_data_random(int *data, int size){
    int i;
    srand((unsigned)time(NULL));

    // 0 ~ digitの範囲で生成した乱数を順に格納
    for(i=0; i<size; i++)
        data[i] = rand() % DIGIT;
}

void output(int *data, int n){
    int i;
    putchar('{');
    for(i=0; i<n; i++)
        printf(i < n-1 ? "%3d," : "%3d}\n", data[i]);
}

void swap(int *i, int *j){
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

// 昇順に選択ソート
void up_sort(int *data, int n){
    int i, j, min;
    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++)
            if(data[j] <= data[min])
                min = j;
        swap(&data[i], &data[min]);
    }
}

// 降順に選択ソート
void down_sort(int *data, int n){
    int i, j, max;
    for(i=0; i<n-1; i++){
        max = i;
        for(j=i+1; j<n; j++)
            if(data[j] >= data[max])
                max = j;
        swap(&data[i], &data[max]);
    }
}

int main(void){
    int data[ELEMENTS], size;

    printf("Input elements (max = %d): ", ELEMENTS);
    scanf("%d", &size);
    store_data_random(data, size);

    printf("Before: \t");
    output(data, size);
    puts("---- After ----");

    printf("up_sort:\t");
    up_sort(data, size);
    output(data, size);

    printf("down_sort:\t");
    down_sort(data, size);
    output(data, size);

    return 0;
}