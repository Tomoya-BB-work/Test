#ifndef FILEIO_H
#define FILEIO_H

#include "employee.h"

void saveToFile(const char *filename, const Employee employees[], int count);
void loadFromFile(const char *filename, Employee employees[], int *count);

#endif