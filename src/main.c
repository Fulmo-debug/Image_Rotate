#include <stdio.h>
#include "READER_WRITER.h"
#include "OPEN_CLOSE_FILE.h"
#include "ImageDescription.h"
#include "rotate.h"


int main(int argc, char* argv[]) {
    if (argc < 3){
        printf(stderr,"Not enough arguments.\n");
        fprintf(stderr,"Check if you entered file paths.!\n");
    }

    struct image temp_img;
    enum read_status temp_read_status = from_bmp(open_file_toREAD(argv[1]), &temp_img);
    if (temp_read_status){
        fprintf(stderr,"reading ERROR\n");
    }

    struct image rotate_img = rotate(temp_img);
    enum read_status temp_write_status = to_bmp(open_file_toWRITE(argv[2]), &rotate_img);
    if (temp_write_status){
        fprintf(stderr,"writing ERROR\n");
    }
    return 0;
}
