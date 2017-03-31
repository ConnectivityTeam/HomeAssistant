#ifndef _HA_FILEHANDLER_H
#define _HA_FILEHANDLER_H
#include <stdio.h>
#include <sys/types.h>
#define CPP
#define FAILURE -1
#define SUCCESS 1

int fileexists(const char *filename);
int haread(const char *filename, char *result_set);
int hawrite(const char *filename, char *values, size_t rows);

#endif // _HA_FILEHANDLER_H
