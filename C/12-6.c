#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
    char name[30];
    int age;
    struct person *next;
} Person;

int main(void){
    Person dmy = {"", 0, NULL};
    Person *start = &dmy;
    Person *wkdtp;
    Person *ip;
    char name[30], age_ss[10];

    while (1){
        printf("名前=");
        fgets(name, 30, stdin);
        if (strcmp(name, "\n") == 0) break;
        printf("年齢=");
        fgets(age_ss, 10, stdin);

        wkdtp = (Person *)malloc(sizeof(Person));
        if (wkdtp == NULL){
            printf("メモリ確保できません.\n");
            exit(1);
        }

        strcpy(wkdtp->name, name);
        wkdtp->age = atoi(age_ss);

        for (ip = start; ip->next != NULL; ip = ip->next){
            if (wkdtp->age < ip->next->age){
                wkdtp->next = ip->next;
                ip->next = wkdtp;
                break;
            }
        }

        if (ip->next == NULL){
            ip->next = wkdtp;
            wkdtp->next = NULL;
        }
    }

    for (ip = start->next; ip != NULL; ip = ip->next){
        printf("%s %d\n", ip->name, ip->age);
        free(ip);
    }

    return 0;
}