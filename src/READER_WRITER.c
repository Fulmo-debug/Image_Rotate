#include <stdio.h>
#include "Enum.h"
#include "ImageDescription.h"
#include "OPEN_CLOSE_FILE.h"
#include <stdlib.h>
//очистку написать 
enum read_status check_header(FILE* in, struct bmp_header* header) {
    fread(header, sizeof(struct bmp_header), 1, in);
    if ((*header).bfType != 0x4d42) {
        return READ_INVALID_SIGNATURE;
    }
    if ((*header).bOffBits != sizeof(struct bmp_header)){
        return READ_INVALID_BITS;
    }
    if ((*header).biBitCount != 24) {
        return READ_INVALID_HEADER;
    }
    if ((*header).biCompression != 0) {
        return READ_INVALID_COMPRESSION;
    }
    if ((*header).biPlanes != 1) {
        return READ_INVALID_PLANES;
    }
    return READ_OK;
}


enum read_status read_rgb(FILE* const in, struct bmp_header const header, struct pixel* const data_rgb){
    uint32_t x = header.biWidth;
    uint32_t y = header.biHeight;
    uint32_t indent = header.bOffBits;
    int32_t padding = (4 - (x * sizeof(struct pixel) % 4)) % 4;
    fseek(in, indent, SEEK_SET);
    for (size_t i = 0; i < y; i++){
        size_t collum = fread(data_rgb+x*i, sizeof(struct pixel), x, in);
        if (collum != x){
            break;
        }
        fseek(in, padding, SEEK_CUR);
    }
    return READ_OK;
}

enum read_status from_bmp(FILE* const in, struct image* img){
    struct bmp_header HEADER;
    enum read_status status_header = check_header(in, &HEADER);
    uint32_t x = HEADER.biWidth;
    uint32_t y = HEADER.biHeight;
    img->height = y;
    img->width = x;
    (*img).data = malloc(x*y*sizeof(struct pixel));
    enum read_status status_rgb = read_rgb(in, HEADER, (*img).data );
    if (status_header){
        return status_header;
    }
    close_file(in);
    return status_rgb;
}

void create_bmp_header(struct bmp_header* header, struct image const* img){
    uint64_t temp_x = img->width;
    uint64_t temp_y = img->height;


    header->bfType = 0x4d42;
    header->bfileSize = 54 + ((3*temp_x+3) & (-4))*temp_y;
    header->bfReserved = 0;
    header->bOffBits = sizeof(struct bmp_header);
    header->biSize = 40;
    header->biWidth = temp_x;
    header->biHeight = temp_y;
    header->biPlanes = 1;
    header->biBitCount = 24;
    header->biCompression = 0;
    header->biSizeImage = temp_x*temp_y*sizeof(struct pixel);
    header->biXPelsPerMeter = 0;
    header->biYPelsPerMeter = 0;
    header->biClrUsed = 0;
    header->biClrImportant = 0;

}

enum write_status to_bmp( FILE* const out, struct image const* img ){
    struct pixel* temp_data = img->data;
    uint64_t temp_x = img->width;
    uint64_t temp_y = img->height;
    int32_t padding = (4 - (temp_x * sizeof(struct pixel) % 4)) % 4;
    struct bmp_header temp_header;
    create_bmp_header(&temp_header,img);
    size_t temp_value = fwrite(&temp_header, sizeof(struct bmp_header), 1, out);
    if(temp_value != sizeof(temp_header) && temp_value == NULL) {
        return WRITE_ERROR;
    }

    for (size_t i = 0; i < temp_y; i++) {
        fwrite(&temp_data[temp_x * i], sizeof(struct pixel), temp_x, out);
        fwrite(&padding, sizeof(padding), 1, out);
    }
    close_file(out);
    return WRITE_OK;
}
