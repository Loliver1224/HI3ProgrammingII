#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTS 100  // 要素数
#define DIGIT 100    // 要素内の数値の上限-1

void store_data_random(int *data, int size){
    // 起動毎に異なる乱数を発生
    srand((unsigned)time(NULL));
    // 0 ~ digitの範囲で生成した乱数を順に格納
    for (int i = 0; i < size; i++)
        data[i] = rand() % DIGIT;
}

void output(int *data, int n){
    putchar('{');
    for (int i=0; i<n; i++)
        if (i < n-1)
            printf("%2d, ", data[i]);
        else
            printf("%2d}\n", data[i]);
}

void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

// 昇順に選択ソート
void up_sort(int *data, int n){
    int i, j, k, min;
    for(i=0; i<n-1; i++){
        min = data[i];
        k = i;
        for(j=i+1; j<n; j++){
            if(data[j] <= min){
                min = data[j];
                k = j;
            }
        }
        swap(&data[i], &data[k]);
    }
}

// 降順に選択ソート
void down_sort(int *data, int n){
    int i, j, k, max;
    for(i=0; i<n-1; i++){
        max = data[i];
        k = i;
        for(j=i+1; j<n; j++){
            if(data[j] >= max){
                max = data[j];
                k = j;
            }
        }
        swap(&data[i], &data[k]);
    }
}

int main(void){
    int data[ELEMENTS], size;

    printf("Input elements(max = %d): ", ELEMENTS);
    scanf("%d", &size);
    store_data_random(data, size);

    printf("Before: ");
    output(data, size);
    up_sort(data, size);
    printf("up_sort : ");
    output(data, size);
    down_sort(data, size);
    printf("down_sort: ");
    output(data, size);

    return 0;
}