#include <stdio.h>
#include <stdint.h>

/* Функция открывает файл для чтения   */
FILE* open_file_toREAD(char const* file_name){
    FILE *in;
    in = fopen(file_name, "rb");
    if(in == NULL) {
    if(in == NULL) {
        fprintf(stderr,"File open error\n");
    }
    return in;
}

/* Функция закрывает файл   */
void close_file(FILE* in){
    int8_t status = fclose(in);
    if (status){
        fprintf(stderr,"File close error\n");
    }
}
/* Функция открывает файл для записи   */
FILE* open_file_toWRITE(char const* file_name){
    FILE *out;
    out = fopen(file_name, "w+b");
    if(out == NULL){
        fprintf(stderr,"File open error\n");
    }
}
