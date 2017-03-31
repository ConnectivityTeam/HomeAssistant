#include "filehandler.h"

int read(const char *filename, char *result_set)
{
    int succes;
    if(fileexists(filename) < 0)
    {
        succes = FAILURE;
//        fherror = "File %s does not exists", filename;
    }
    else
    {
        FILE *stream;
        stream = fopen(filename, "r");
        result_set = fgetc(stream);
        succes = SUCCESS;
    }
    return succes;
}

int write(const char *filename, char *values, size_t rows)
{
    if(fileexists(filename) < 0)
    {
//        fherror = "File %s does not exists", filename;
        return FAILURE;
    }
    int current_row;
    FILE *stream;
    stream = fopen(filename, "w");
    for(current_row = 0; current_row < rows; current_row++)
    {
        fprintf(stream, "%s\n", values[current_row]);
    }
    fclose(stream);
    return 1;
}

int fileexists(const char *filename)
{
    FILE *file;
    fopen(file, filename);
    int exists;
    if(fopen != NULL)
    {
        fclose(file);
        exists = SUCCESS;
    }
    else
    {
 //       fherror = "File %s does not exists", filename;
        exists = FAILURE;
    }
    return exists;
}
