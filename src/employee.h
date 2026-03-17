#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50
#define DEPT_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char department[DEPT_LENGTH];
    int age;
} Employee;

void initEmployees(Employee employees[], int *count);
void addEmployee(Employee employees[], int *count);
void listEmployees(const Employee employees[], int count);
void searchEmployeeById(const Employee employees[], int count);
void deleteEmployeeById(Employee employees[], int *count);

#endif