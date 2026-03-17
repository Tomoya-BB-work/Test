#include <stdio.h>
#include "employee.h"
#include "fileio.h"

#define DATA_FILE "employees.txt"

static void printMenu(void) {
    printf("\n===== 社員管理システム =====\n");
    printf("1. 社員追加\n");
    printf("2. 社員一覧表示\n");
    printf("3. 社員検索(ID)\n");
    printf("4. 社員削除(ID)\n");
    printf("5. 保存\n");
    printf("6. 終了\n");
    printf("選択してください: ");
}

// }

int main(void) {
    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    initEmployees(employees, &count);
    loadFromFile(DATA_FILE, employees, &count);

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                listEmployees(employees, count);
                break;
            case 3:
                searchEmployeeById(employees, count);
                break;
            case 4:
                deleteEmployeeById(employees, &count);
                break;
            case 5:
                saveToFile(DATA_FILE, employees, count);
                break;
            case 6:
                printf("終了します。\n");
                break;
            default:
                printf("無効な選択です。\n");
                break;
        }
    } while (choice != 6);

    return 0;
}