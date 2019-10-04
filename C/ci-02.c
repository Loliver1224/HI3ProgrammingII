#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NAMELEN 20

typedef struct data{
    char name[NAMELEN];
    double height;
    struct data *before;
    struct data *next;
} student;

void insert_node(student *start, student *ip){
    student *wkdtp;
    wkdtp = malloc(sizeof(student));
    scanf("%s %lf", wkdtp.name, &wkdtp.height);

    for (ip = start; ip->next != NULL; ip = ip->next){
        if (wkdtp->height < ip->next->height){
            wkdtp->next = ip->next;
			wkdtp->before = ip;
            ip->next = wkdtp;
            break;
        }
    }
    if (ip->next == NULL){
        ip->next = wkdtp;
		wkdtp->before = ip;
        wkdtp->next = NULL;
    }
}

void delete_node(student *start, student *ip){
    char del_name[NAMELEN];

    gets_s(del_name, NAMELEN);
    for (ip = start; ip->next != NULL; ip = ip->next){
        if (strcmp(ip->name, del_name) == 0){
            ip->before->next = ip->next;
			ip->next->before = ip->before->next;
            free(ip);
            break;
        }
    }
}

void print_node(student *start, student *ip){
    for (ip = start->next; ip->next != NULL; ip = ip->next){
        printf("%s %.1f\n", ip->name, ip->height);
        free(ip);
    }
}

int main(void){
    student dmy = {"", 0, NULL, NULL};
    student *start = &dmy;
    student *ip = start;
    bool flg = true;

    while (flg){
        switch (getchar()){
            case 'y': insert_node(start, ip); break;
            case 'd': delete_node(start, ip); break;
            case 'f': print_node(start, ip); flg = false;
            default: break;
        }
    }
    return 0;
}