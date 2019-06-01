#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100
#define M 20

char name[N][M];
double height[N], weight[N];
int cmd;

void io(int n, int in){
    int i;
    for(i=0; i<n; i++)
        if(in)
            scanf("%s %lf %lf", name[i], &height[i], &weight[i]);
        else
            printf("%s %.1f %.1f\n",name[i], height[i], weight[i]);
    putchar('\n');
}

int cmp(const void *a, const void *b){
	switch(cmd){
        case 1:
        case 3: return *(double *)b - *(double *)a;
        case 2:
        case 4: return *(double *)a - *(double *)b;
	}
	return 0;
}

void double_swap(double *a, double *b){
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap(int a, int b){
    char tmp[M];

    double_swap(&height[a], &height[b]);
    double_swap(&weight[a], &weight[b]);
    strcpy(tmp, name[a]);
    strncpy(name[a], name[b], M);
    strncpy(name[b], tmp, M);
}

void qsort_double(double *data, int left, int right){
    int i, j, ref = (left + right) / 2;
    double pivot;

    if (right < 2)
        return;
    pivot = data[ref];

    for (i = left, j = right;; i++, j--){
        while (cmp(&data[i], &pivot) < 0)
            i++;
        while (cmp(&data[j], &pivot) > 0)
            j--;
        if (i >= j)
            break;
        swap(i, j);
    }
    if (left + 1 < ref)
        qsort_double(data, left, ref+1);
    if (right - 1 > ref)
        qsort_double(data, ref, right);
}

void qsort_string(int high, int low){
    int i, j, ref = (high + low) / 2;
    char pivot[M];

    if (low < 2)
        return;
    strcpy(pivot, name[ref]);

    for (i = high, j = low;; i++, j--){
        if (cmd==5){
            while(strcmp(name[i], pivot) < 0) i++;
            while(strcmp(name[j], pivot) > 0) j--;
        }else{
            while(strcmp(pivot, name[i]) < 0) i++;
            while(strcmp(pivot, name[j]) > 0) j--;
        }
        if (i >= j)
            break;
        swap(i, j);
    }
    if (high + 1 < ref)
        qsort_string(high, ref + 1);
    if (low - 1 > ref)
        qsort_string(ref, low);
}

int menu(int n){
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

	switch(cmd){
		case 1: puts("----- 身長を降順に整列 ------");
		    	qsort_double(height, 0, n-1); break;
		case 2: puts("----- 身長を昇順に整列 ------");
				qsort_double(height, 0, n-1); break;
		case 3: puts("----- 体重を降順に整列 ------");
                qsort_double(weight, 0, n-1); break;
		case 4: puts("----- 体重を昇順に整列 ------");
                qsort_double(weight, 0, n-1); break;
        case 5: puts("----- 名前を昇順に整列 ------");
                qsort_string(0, n-1); break;
        case 6: puts("----- 名前を降順に整列 ------");
                qsort_string(0, n-1); break;
		case 0: return 0;
		default:puts("\a0 ~ 6の数値を入力してください.");
				goto reject;
	}
	io(n, 0);
    return cmd;
}

int main(void){
	int n;

	printf("入力するデータ個数を入力: ");
	scanf("%d", &n);
    puts("\n\nデータを入力してください（名前 身長 体重）");
	io(n, 1);
	while(menu(n) != 0);

	return 0;
}