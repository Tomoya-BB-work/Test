fileio#include <stdio.h>
#include "fileio.h"

//ojama simasu!!

//waaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

//ojama simasita!!!









void saveToFile(const char *filename, const Employee employees[], int count) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("ファイルを開けませんでした\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d,%s,%s,%d\n",
                employees[i].id,
                employees[i].name,
                employees[i].department,
                employees[i].age);
    }

    fclose(fp);
    printf("ファイルに保存しました。\n");
}

void loadFromFile(const char *filename, Employee employees[], int *count) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("保存ファイルが見つかりません。新規開始します。\n");
        *count = 0;
        return;
    }

    *count = 0;

    while (*count < MAX_EMPLOYEES &&
           fscanf(fp, "%d,%49[^,],%49[^,],%d\n",
                  &employees[*count].id,
                  employees[*count].name,
                  employees[*count].department,
                  &employees[*count].age) == 4) {
        (*count)++;
    }

    fclose(fp);
    printf("ファイルから読み込みました。\n");
}