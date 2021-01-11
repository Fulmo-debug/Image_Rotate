#include <stdio.h>
#ifndef UNTITLED2_OPEN_CLOSE_FILE_H
#define UNTITLED2_OPEN_CLOSE_FILE_H

FILE* open_file_toREAD(char const* file_name);

void close_file(FILE* in);

FILE* open_file_toWRITE(char const* file_name);
#endif //UNTITLED2_OPEN_CLOSE_FILE_H
