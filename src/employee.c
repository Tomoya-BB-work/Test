#include <stdio.h>
#include <string.h>
#include "employee.h"

void initEmployees(Employee employees[], int *count) {
    *count = 0;
}

void addEmployee(Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("これ以上社員を追加できません。\n");
        return;
    }

    Employee emp;

    printf("社員IDを入力してください！！: ");
    scanf("%d", &emp.id);

    printf("名前を入力してください: ");
    scanf("%49s", emp.name);

    printf("部署名を入力してください: ");
    scanf("%49s", emp.department);

    printf("年齢を入力してください: ");
    scanf("%d", &emp.age);

    employees[*count] = emp;
    (*count)++;

    printf("社員を追加しました。\n");
}

void listEmployees(const Employee employees[], int count) {
    if (count == 0) {
        printf("社員データがありません。\n");
        return;
    }

    printf("\n--- 社員一覧 ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | 名前: %s | 部署: %s | 年齢: %d\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].age);
    }
}

void searchEmployeeById(const Employee employees[], int count) {
    int id;
    int found = 0;

    printf("検索する社員IDを入力してください: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("社員が見つかりました。\n");
            printf("ID: %d | 名前: %s | 部署: %s | 年齢: %d\n",
                   employees[i].id,
                   employees[i].name,
                   employees[i].department,
                   employees[i].age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("該当する社員は見つかりませんでした。\n");
    }
}

void deleteEmployeeById(Employee employees[], int *count) {
    int id;
    int foundIndex = -1;

    printf("削除する社員IDを入力してください: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (employees[i].id == id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("該当する社員は見つかりませんでした。\n");
        return;
    }

    for (int i = foundIndex; i < *count - 1; i++) {
        employees[i] = employees[i + 1];
    }

    (*count)--;
    printf("社員を削除しました。\n");
}