#include <stdio.h>
#include <stdint.h>

/* Функция открывает файл   */
FILE* open_file_toREAD(char const* file_name){
    FILE *in;
    in = fopen(file_name, "rb");
    if(in == NULL) {
        printf("File open error");
        printf("\n");
    }
    else{
        printf("File opened successfully");
        printf("\n");
        return in;
    }
}

/* Функция закрывает файл   */
void close_file(FILE* in){
    int8_t status = fclose(in);
    if (status){
        printf("File close error");
        printf("\n");
    }
    else
    {
        printf("File closed successfully");
        printf("\n");
    }
}

FILE* open_file_toWRITE(char const* file_name){
    FILE *out;
    out = fopen(file_name, "w+b");
    if(out == NULL){
        printf("File open error");
        printf("\n");
    }
    else{
        printf("File opened successfully");
        printf("\n");
        return out;
    }
}
